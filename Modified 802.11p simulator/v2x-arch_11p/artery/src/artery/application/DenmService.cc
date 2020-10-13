//~ joaquim for network-wide denm_latencies
#include "artery/application/GlobalListener.h"
#include "artery/application/Asn1PacketVisitor.h"
#include "artery/application/DenmObject.h"
#include "artery/application/DenmService.h"
#include "artery/application/MyService.h"
#include "artery/application/LocalDynamicMap.h"
#include "artery/application/Timer.h"
#include "artery/application/ImpactReductionUseCase.h"
#include "artery/application/TrafficJamUseCase.h"
#include "artery/storyboard/StoryboardSignal.h"
#include <boost/units/base_units/metric/hour.hpp>
#include <boost/units/systems/si/prefixes.hpp>
#include <omnetpp/checkandcast.h>
#include <vanetza/asn1/denm.hpp>
#include <vanetza/btp/ports.hpp>

// TODO wrap all Artery classes by namespace
using namespace artery;
using namespace omnetpp;

Define_Module(DenmService)

static const simsignal_t denmReceivedSignal = cComponent::registerSignal("DenmService.received");
static const simsignal_t myReceivedSignal = cComponent::registerSignal("MyService.received");
static const simsignal_t storyboardSignal = cComponent::registerSignal("StoryboardSignal");
//~ error: if putting signals here which you do not use


static const auto microdegree = vanetza::units::degree * boost::units::si::micro;
static const auto decidegree = vanetza::units::degree * boost::units::si::deci;
static const auto centimeter_per_second = vanetza::units::si::meter_per_second * boost::units::si::centi;

DenmService::DenmService() :
    mTimer(nullptr), mSequenceNumber(0)
{
}

void DenmService::initialize()
{
    ItsG5BaseService::initialize();
    mTimer = &getFacilities().get_const<Timer>();
    mDenmMemory.reset(new artery::denm::Memory(*mTimer));

    subscribe(storyboardSignal);

    const VehicleDataProvider& vdp = getFacilities().get_const<VehicleDataProvider>();
    std::unique_ptr<TrafficJamEndOfQueue> endOfQueue { new TrafficJamEndOfQueue(vdp, *mDenmMemory) };
    endOfQueue->setNonUrbanEnvironment(par("assumeNonUrbanEnvironment").boolValue());
    mUseCases.push_front(endOfQueue.release());

    auto& ldm = getFacilities().get_const<artery::LocalDynamicMap>();
    std::unique_ptr<TrafficJamAhead> jamAhead { new TrafficJamAhead(vdp, *mDenmMemory, ldm) };
    jamAhead->setNonUrbanEnvironment(par("assumeNonUrbanEnvironment").boolValue());
    mUseCases.push_front(jamAhead.release());

    std::unique_ptr<ImpactReductionContainerExchange> irc { new ImpactReductionContainerExchange(vdp) };
    mUseCases.push_front(irc.release());
}

void DenmService::receiveSignal(cComponent*, simsignal_t signal, cObject* obj, cObject*)
{
    if (signal == storyboardSignal) {
        StoryboardSignal* storyboardSignalObj = check_and_cast<StoryboardSignal*>(obj);
        for (auto& use_case : mUseCases) {
            use_case.handleStoryboardTrigger(*storyboardSignalObj);
        }
    }
}

void DenmService::indicate(const vanetza::btp::DataIndication& indication, std::unique_ptr<vanetza::UpPacket> packet)
{
    Asn1PacketVisitor<vanetza::asn1::Denm> visitor;
    const vanetza::asn1::Denm* denm = boost::apply_visitor(visitor, *packet);
    const VehicleDataProvider& vdp = getFacilities().getVehicleDataProvider();
    if (denm && (*denm)->header.stationID != vdp.station_id()) {
        DenmObject obj = visitor.shared_wrapper;
        mDenmMemory->received(obj);
        emit(denmReceivedSignal, &obj);


        //~ check if pkt from ambulance (eventType.causeCode == CauseCodeType_emergencyVehicleApproaching == 95)
        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        auto& vehicle = getFacilities().get_mutable<traci::VehicleController>();
        if ((*denm)->denm.situation->eventType.causeCode == CauseCodeType_emergencyVehicleApproaching)
        {
            EV_WARN << "~~ DenmService - rx & fwding DENM packet from ambulance to myService." << endl;
            emit(myReceivedSignal, &obj);
        }
        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

        
        // any RX node: track STOP_latency for (remote_vdp, my_name)
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        {
            cModule *gL_mod = getModuleByPath("globalListener");
            GlobalListener * globalListener;
            if(gL_mod)  globalListener = check_and_cast<GlobalListener *>(gL_mod);  
            else        throw cRuntimeError("Invalid cast from mod globalListener to pointer.");
            globalListener->denm_finishLatency((*denm)->header.stationID, findHost()->getFullName());
        }
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

        for (auto& use_case : mUseCases) {
            if (use_case.handleMessageReception(obj)) {
                sendDenm(use_case);
            }
        }
    }
}

void DenmService::trigger()
{
    mDenmMemory->drop();

    for (auto& use_case : mUseCases) {
        if (use_case.check()) {
            sendDenm(use_case);
        }
    }
}

void DenmService::sendDenm(artery::denm::UseCase& use_case)
{
    auto denm = createDenm(use_case);
    auto request = createRequest(use_case);


    //~ only RSUs bc memory saving: track own START as transmitting node (my_vdp, my_name)
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    {
        auto& vehicle = getFacilities().get_mutable<traci::VehicleController>();
        if ("rsu" == vehicle.getTypeId())
        {
            cModule *gL_mod = getModuleByPath("globalListener");
            GlobalListener * globalListener;
            if(gL_mod)  globalListener = check_and_cast<GlobalListener *>(gL_mod);  
            else        throw cRuntimeError("Invalid cast from mod globalListener to pointer.");
            const VehicleDataProvider& vdp = getFacilities().getVehicleDataProvider();
            long vdp_id = vdp.station_id();;
            globalListener->denm_startLatency(vdp_id, findHost()->getFullName());
        }
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    using namespace vanetza;
    std::unique_ptr<geonet::DownPacket> payload { new geonet::DownPacket };
    payload->layer(OsiLayer::Application) = std::move(denm);
    this->request(request, std::move(payload));
}

vanetza::btp::DataRequestB DenmService::createRequest(artery::denm::UseCase& uc)
{
    using namespace vanetza;
    btp::DataRequestB request;
    uc.dissemination(request);

    request.destination_port = btp::ports::DENM;
    request.gn.security_profile = security::Profile::DENM;
    request.gn.transport_type = geonet::TransportType::GBC;
    request.gn.communication_profile = geonet::CommunicationProfile::ITS_G5;

    return request;
}

vanetza::asn1::Denm DenmService::createDenm(artery::denm::UseCase& uc)
{
    vanetza::asn1::Denm message;
    uc.message(message);

    const VehicleDataProvider& vdp = getFacilities().getVehicleDataProvider();
    message->header.messageID = ItsPduHeader__messageID_denm;
    message->header.protocolVersion = ItsPduHeader__protocolVersion_currentVersion;
    message->header.stationID = vdp.station_id();

    message->denm.management.actionID.originatingStationID = vdp.station_id();
    message->denm.management.actionID.sequenceNumber = ++mSequenceNumber;
    int ret = 0;
    const auto taiTime = countTaiMilliseconds(mTimer->getTimeFor(vdp.simtime()));
    ret += asn_long2INTEGER(&message->denm.management.detectionTime, taiTime);
    ret += asn_long2INTEGER(&message->denm.management.referenceTime, taiTime);
    assert(ret == 0);
    message->denm.management.eventPosition.altitude.altitudeValue = AltitudeValue_unavailable;
    message->denm.management.eventPosition.altitude.altitudeConfidence = AltitudeConfidence_unavailable;
    message->denm.management.eventPosition.longitude = (vdp.longitude() / microdegree).value() * Longitude_oneMicrodegreeEast;
    message->denm.management.eventPosition.latitude = (vdp.latitude() / microdegree).value() * Latitude_oneMicrodegreeNorth;
    message->denm.management.eventPosition.positionConfidenceEllipse.semiMajorOrientation = HeadingValue_unavailable;
    message->denm.management.eventPosition.positionConfidenceEllipse.semiMajorConfidence = SemiAxisLength_unavailable;
    message->denm.management.eventPosition.positionConfidenceEllipse.semiMinorConfidence = SemiAxisLength_unavailable;

    message->denm.location = vanetza::asn1::allocate<LocationContainer_t>();
    message->denm.location->eventSpeed = vanetza::asn1::allocate<Speed>();
    message->denm.location->eventSpeed->speedValue = std::abs((vdp.speed() / centimeter_per_second).value()) * SpeedValue_oneCentimeterPerSec;
    message->denm.location->eventSpeed->speedConfidence = SpeedConfidence_equalOrWithinOneCentimeterPerSec * 3;
    message->denm.location->eventPositionHeading = vanetza::asn1::allocate<Heading>();
    message->denm.location->eventPositionHeading->headingValue = (vdp.heading() / decidegree).value();
    message->denm.location->eventPositionHeading->headingConfidence = HeadingConfidence_equalOrWithinOneDegree;

    // TODO fill path history
    auto path_history = vanetza::asn1::allocate<PathHistory_t>();
    asn_sequence_add(&message->denm.location->traces, path_history);

    return message;
}

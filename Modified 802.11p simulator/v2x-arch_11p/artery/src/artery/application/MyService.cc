#include "artery/application/Asn1PacketVisitor.h"
#include "artery/application/DenmObject.h"
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


using namespace artery;
using namespace omnetpp;


Define_Module(MyService)


static const simsignal_t myReceivedSignal = cComponent::registerSignal("MyService.received");
static const auto microdegree = vanetza::units::degree * boost::units::si::micro;
static const auto decidegree = vanetza::units::degree * boost::units::si::deci;
static const auto centimeter_per_second = vanetza::units::si::meter_per_second * boost::units::si::centi;



MyService::MyService()
{
    timeoutEvent = nullptr;
    mSequenceNumber = 0;
    mTimer = nullptr;
}



MyService::~MyService()
{
    cancelAndDelete(timeoutEvent);
}



void MyService::initialize()
{
    ItsG5BaseService::initialize();
    mTimer = &getFacilities().get_const<Timer>();
    const VehicleDataProvider& vdp = getFacilities().get_const<VehicleDataProvider>();
    auto& ldm = getFacilities().get_const<artery::LocalDynamicMap>();


    // init variables, subscribe to signal from DENM service
    // ------------------------------------------------------
    timeout = 0.5;
    timeoutEvent = new cMessage("timeoutEvent");
    subscribe(myReceivedSignal);
    myservice_start_time = simTime();
    am_I_an_ambulance = false;
    am_I_a_car = false;
    am_I_a_rsu = false;
    is_there_emergency = par("par_is_there_emergency").boolValue();
    is_there_speed = par("par_is_there_speed").boolValue();
    car_attending_emergency = false;
    car_loops_attending_emergency = 0;


    // self messages start
    // -------------------
    auto& vehicle = getFacilities().get_mutable<traci::VehicleController>();
    if (vehicle.getTypeId() == "ambu")
    {
        scheduleAt(simTime() + timeout, timeoutEvent);
        am_I_an_ambulance = true;
    }
    else if (vehicle.getTypeId() == "rsu")
    {
        am_I_a_rsu = true;
    }
    else 
    {
        // obtain vehicle type = speed code
        scheduleAt(simTime() + timeout, timeoutEvent);
        am_I_a_car = true;
    }
}



void MyService::handleMessage(cMessage *msg)
{
    auto& vehicle = getFacilities().get_mutable<traci::VehicleController>();

    // periodic message for cars
    // -------------------------
    if ((msg == timeoutEvent) && am_I_a_car)
    {
        // simulation "par_is_there_emergency" parameter = NO or car has NOT rxed DENM yet
        if (!car_attending_emergency)
        {
            if (vehicle.getTypeId() == "type1")
            {
                if ((vehicle.my_getRoadID() == "31267167")     ||
                    (vehicle.my_getRoadID() == "310929483#1-AddedOnRampEdge") ||
                    (vehicle.my_getRoadID() == "310929483#1")  ||
                    (vehicle.my_getRoadID() == "18524608#1.0") ||
                    (vehicle.my_getRoadID() == "18524630#1"))
                {
                    vehicle.my_changeLane(0); 
                }
            }
            else if (vehicle.getTypeId() == "type2")
            {
                if ((vehicle.my_getRoadID() == "31267167")     ||
                    (vehicle.my_getRoadID() == "310929483#1-AddedOnRampEdge") ||
                    (vehicle.my_getRoadID() == "310929483#1")  ||
                    (vehicle.my_getRoadID() == "18524608#1.0") ||
                    (vehicle.my_getRoadID() == "18524630#1"))
                {
                    vehicle.my_changeLane(1); 
                }
            }
        }
        // car rxed ambulance DENM at least once in ReceiveSignal
        else
        {
            // make car cooperativeness last...
            if (car_loops_attending_emergency < timeout.dbl() * 10)
            {
                vehicle.my_changeLane(0);
                vehicle.my_slowdown();
                vehicle.my_changeColor();
                car_loops_attending_emergency++;
            }
            // but not forever
            else
            {
                car_attending_emergency = false;
                car_loops_attending_emergency = 0; 
            }
        }
        // re-send periodic message for this car
        scheduleAt(simTime() + timeout, timeoutEvent);
    }


    // periodic message for ambulance
    // --------------------------------
    if ((msg == timeoutEvent) && am_I_an_ambulance) 
    {
        // simulation "par_is_there_emergency" parameter = YES
        if (is_there_emergency)
        {
            EV_ERROR << "--> MyService - Sending MY_msg, edge " << vehicle.my_getRoadID() << endl;
            sendDenm();
            if ((vehicle.my_getRoadID() == "31267167")     ||
                (vehicle.my_getRoadID() == "310929483#1-AddedOnRampEdge") ||
                (vehicle.my_getRoadID() == "310929483#1")  ||
                (vehicle.my_getRoadID() == "18524608#1.0") ||
                (vehicle.my_getRoadID() == "18524630#1"))
            {
                vehicle.my_changeLane(1);
            }
        }
        // simulation input parameter = NO emergency
        else
        {
            vehicle.my_changeLane(0);
        }
        // re-sent periodic message
        scheduleAt(simTime() + timeout, timeoutEvent);       
    }
}


void MyService::receiveSignal(cComponent*, simsignal_t signal, cObject* obj, cObject*)
{

    // DenmService forwards here if car receiving a packet from ambulance
    if ((signal == myReceivedSignal) && (am_I_a_car)) 
    {
        EV_ERROR << "--> MyService - CAR Received MY_msg" << endl;
        if (par("par_is_there_emergency").boolValue() == true)
        {
            // re-start event detection
            car_attending_emergency = true;
            car_loops_attending_emergency = 0;    
        }    
    }
}


//~ error: if not defining in .h/.cc all different "receiveSignal" prototypes
void MyService::receiveSignal(cComponent* source, simsignal_t signal, const char *value, cObject*) {}
void MyService::indicate(const vanetza::btp::DataIndication& indication, std::unique_ptr<vanetza::UpPacket> packet) {}
void MyService::trigger() 
{
    //~ this service does not require mW to trigger it
}



void MyService::sendDenm()
{
    //~ send a DENM including an emergency code
    //-------------------------------------------
    auto denm = createDenm();
    auto request = createRequest();

    using namespace vanetza;
    std::unique_ptr<geonet::DownPacket> payload { new geonet::DownPacket };
    payload->layer(OsiLayer::Application) = std::move(denm);
    this->request(request, std::move(payload));
}



vanetza::btp::DataRequestB MyService::createRequest()
{
    using namespace vanetza;
    using vanetza::units::si::meter;
    using vanetza::units::si::seconds;

    btp::DataRequestB request;

    request.destination_port = btp::ports::DENM;
    request.gn.security_profile = security::Profile::DENM;
    request.gn.transport_type = geonet::TransportType::GBC;
    request.gn.communication_profile = geonet::CommunicationProfile::ITS_G5;


    //~ instead of uc.dissemination, we call this right here
    //------------------------------------------------------
    const VehicleDataProvider& vdp = getFacilities().get_const<VehicleDataProvider>();

    request.gn.traffic_class.tc_id(0);
    request.gn.maximum_hop_limit = 1;

    // reduce range, the one due to ambulance transceiver is enough
    geonet::DataRequest::Repetition repetition;
    repetition.interval = 1 * seconds;
    repetition.maximum = 1 * seconds;
    request.gn.repetition = repetition;

    geonet::Area destination;
    geonet::Circle destination_shape;
    destination_shape.r = 10.0 * meter;
    destination.shape = destination_shape;
    destination.position.latitude = vdp.latitude();
    destination.position.longitude = vdp.longitude();
    request.gn.destination = destination;

    return request;
}



void MyService::missatge(vanetza::asn1::Denm& msg)
{
    msg->denm.management.relevanceDistance = vanetza::asn1::allocate<RelevanceDistance_t>();
    //*msg->denm.management.relevanceDistance = RelevanceDistance_lessThan1000m;
    *msg->denm.management.relevanceDistance = RelevanceDistance_lessThan50m;

    msg->denm.management.relevanceTrafficDirection = vanetza::asn1::allocate<RelevanceTrafficDirection_t>();
    *msg->denm.management.relevanceTrafficDirection = RelevanceTrafficDirection_upstreamTraffic;
    msg->denm.management.validityDuration = vanetza::asn1::allocate<ValidityDuration_t>();
    *msg->denm.management.validityDuration = 60;
    msg->denm.management.stationType = StationType_unknown; // TODO retrieve type from SUMO

    msg->denm.situation = vanetza::asn1::allocate<SituationContainer_t>();
    msg->denm.situation->informationQuality = 1;
    msg->denm.situation->eventType.causeCode = CauseCodeType_emergencyVehicleApproaching;  // <-- ambulance code
    msg->denm.situation->eventType.subCauseCode = 0;

    // TODO set road type in Location container
    // TODO set lane position in Alacarte container
}

vanetza::asn1::Denm MyService::createDenm()
{
    vanetza::asn1::Denm message;
    missatge(message);

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
    asn_sequence_add(&message->denm.location->traces, +path_history);

    return message;
}


void MyService::finish()
{
    myservice_final_time = simTime();

    // record stuff
    if (am_I_an_ambulance == true)
    {
        recordScalar("myservice_ambu_final_time", myservice_final_time);
        recordScalar("myservice_ambu_start_time", myservice_start_time);
        recordScalar("myservice_ambu_whole_time", myservice_final_time - myservice_start_time);
    }
    else if (am_I_a_car == true)
    {
        recordScalar("myservice_cars_final_time", myservice_final_time);
        recordScalar("myservice_cars_start_time", myservice_start_time);
        recordScalar("myservice_cars_whole_time", myservice_final_time - myservice_start_time);
    }
}




//
// Copyright (C) 2014 Raphael Riebl <raphael.riebl@thi.de>
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty ofsubs
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#include "artery/application/ItsG5Middleware.h"
#include "artery/application/ItsG5PromiscuousService.h"
#include "artery/application/ItsG5Service.h"
#include "artery/mac/AccessCategories.h"
#include "artery/mac/AccessCategoriesVanetza.h"
#include "artery/messages/GeoNetPacket_m.h"
#include "artery/netw/GeoNetIndication.h"
#include "artery/netw/GeoNetRequest.h"
#include "artery/nic/RadioDriverBase.h"
#include "artery/traci/ControllableVehicle.h"
#include "artery/utility/IdentityRegistry.h"
#include "artery/utility/FilterRules.h"
#include "inet/common/ModuleAccess.h"
#include "inet/mobility/contract/IMobility.h"
#include <vanetza/btp/header.hpp>
#include <vanetza/btp/header_conversion.hpp>
#include <vanetza/btp/ports.hpp>
#include <vanetza/geonet/data_confirm.hpp>
#include <vanetza/geonet/packet.hpp>
#include <vanetza/geonet/position_vector.hpp>
#include <vanetza/security/null_certificate_manager.hpp>
#include <vanetza/net/mac_address.hpp>
#include <algorithm>
#include <chrono>
#include <string>


Define_Module(ItsG5Middleware)

ItsG5Middleware::ItsG5Middleware() :
		mRadioDriver(nullptr), mRadioDriverIn(nullptr), mRadioDriverOut(nullptr),
		mLocalDynamicMap(mTimer), mDccScheduler(mDccFsm, mRuntime.now())
{
}

void ItsG5Middleware::request(const vanetza::access::DataRequest& req,
		std::unique_ptr<vanetza::geonet::DownPacket> payload)
{
	Enter_Method_Silent();
	if ((*payload)[vanetza::OsiLayer::Network].ptr() == nullptr) {
		throw cRuntimeError("Missing network layer payload in middleware request");
	}

	GeoNetPacket* net = new GeoNetPacket("GeoNet packet");
	net->setByteLength(payload->size());
	net->setPayload(GeoNetPacketWrapper(std::move(payload)));
	net->setControlInfo(new GeoNetRequest(req));

	send(net, mRadioDriverOut);
}

void ItsG5Middleware::request(const vanetza::btp::DataRequestB& req, std::unique_ptr<vanetza::DownPacket> payload)
{

	Enter_Method("request");
	using namespace vanetza;
	btp::HeaderB btp_header;
	btp_header.destination_port = req.destination_port;
	btp_header.destination_port_info = req.destination_port_info;
	payload->layer(OsiLayer::Transport) = btp_header;

	geonet::DataConfirm confirm;
	switch (req.gn.transport_type) {
		case geonet::TransportType::SHB: {
			geonet::ShbDataRequest request(mGeoMib);
			copy_request_parameters(req, request);
			confirm = mGeoRouter->request(request, std::move(payload));
		}
			break;
		case geonet::TransportType::GBC: {
			geonet::GbcDataRequest request(mGeoMib);
			copy_request_parameters(req, request);
			confirm = mGeoRouter->request(request, std::move(payload));
		}
			break;
		default:
			throw cRuntimeError("Unknown or unimplemented transport type");
			break;
	}

	if (confirm.rejected()) {
		throw cRuntimeError("GN-Data.request rejected");
	}

	scheduleRuntime();
}

int ItsG5Middleware::numInitStages() const
{
	return 3;
}

void ItsG5Middleware::initialize(int stage)
{
	switch (stage) {
		case 0:
			initializeMiddleware();
			break;
		case 1:
			initializeServices();
			break;
		case 2: {
				// start update cycle with random jitter to avoid unrealistic node synchronization
				//~ const auto jitter = uniform(SimTime(0, SIMTIME_MS), mUpdateInterval);
				const auto jitter = uniform(SimTime(0, SIMTIME_MS), par("my_jitter"));
				scheduleAt(simTime() + jitter + mUpdateInterval, mUpdateMessage);
				scheduleRuntime();
			}
			break;
		default:
			break;
	}
}

void ItsG5Middleware::initializeMiddleware()
{
	mTimer.setTimebase(par("datetime"));

	mRadioDriver = inet::findModuleFromPar<RadioDriverBase>(par("radioDriverModule"), findHost());
	mRadioDriverIn = gate("radioDriverIn");
	mRadioDriverOut = gate("radioDriverOut");
	mRadioDriver->subscribe(RadioDriverBase::ChannelLoadSignal, this);

	initializeVehicleController();
	mFacilities.register_mutable(mVehicleController);
	mFacilities.register_const(&mVehicleDataProvider);
	mFacilities.register_const(&mDccFsm);
	mFacilities.register_mutable(&mDccScheduler);
	mFacilities.register_const(&mTimer);
	mFacilities.register_mutable(&mLocalDynamicMap);

	mRuntime.reset(mTimer.getCurrentTime());
	mUpdateInterval = par("updateInterval").doubleValue();
	mUpdateMessage = new cMessage("middleware update");
	mUpdateRuntimeMessage = new cMessage("runtime update");
	findHost()->subscribe(inet::IMobility::mobilityStateChangedSignal, this);
	initializeSecurity();

	mGeoMib.itsGnDefaultTrafficClass.tc_id(3); // send BEACONs with DP3
	mGeoMib.itsGnSecurity = par("vanetzaEnableSecurity").boolValue();

	using vanetza::geonet::UpperProtocol;
	vanetza::geonet::Address gn_addr;
	gn_addr.is_manually_configured(true);
	gn_addr.station_type(vanetza::geonet::StationType::PASSENGER_CAR);
	gn_addr.country_code(0);
	gn_addr.mid(mRadioDriver->getMacAddress());

	mGeoRouter.reset(new vanetza::geonet::Router {mRuntime, mGeoMib});
	mGeoRouter->set_address(gn_addr);
	mDccControl.reset(new vanetza::dcc::FlowControl {mRuntime, mDccScheduler, *this});
	mDccControl->queue_length(par("vanetzaDccQueueLength"));
	mGeoRouter->set_access_interface(mDccControl.get());
	mGeoRouter->set_transport_handler(UpperProtocol::BTP_B, &mBtpPortDispatcher);
	mGeoRouter->set_security_entity(mSecurityEntity.get());

	mIdentity.traci = mVehicleController->getVehicleId();
	mIdentity.application = mVehicleDataProvider.station_id();
	mIdentity.geonet = gn_addr;
	emit(artery::IdentityRegistry::updateSignal, &mIdentity);
}

void ItsG5Middleware::initializeSecurity()
{
	using namespace vanetza::security;
	const char* vanetzaCryptoBackend = par("vanetzaCryptoBackend");
	mSecurityBackend = create_backend(vanetzaCryptoBackend);
	if (!mSecurityBackend) {
		throw cRuntimeError("No security backend found with name \"%s\"", vanetzaCryptoBackend);
	}
	const char* vanetzaCertificateManager = par("vanetzaCertificateManager");
	mSecurityCertificates = builtin_certificate_managers().create(vanetzaCertificateManager, mRuntime);
	if (!mSecurityCertificates) {
		throw cRuntimeError("No certificate manager found with name \"%s\"", vanetzaCertificateManager);
	}

	SignService sign_service;
	const std::string vanetzaSecuritySignService = par("vanetzaSecuritySignService");
	if (vanetzaSecuritySignService == "straight") {
		sign_service = straight_sign_service(mRuntime, *mSecurityCertificates, *mSecurityBackend);
		VerifyService verify_service = straight_verify_service(mRuntime, *mSecurityCertificates, *mSecurityBackend);
	} else if (vanetzaSecuritySignService == "deferred") {
		sign_service = deferred_sign_service(mRuntime, *mSecurityCertificates, *mSecurityBackend);
		VerifyService verify_service = straight_verify_service(mRuntime, *mSecurityCertificates, *mSecurityBackend);
	} else if (vanetzaSecuritySignService == "dummy") {
		sign_service = dummy_sign_service(mRuntime, NullCertificateManager::null_certificate());
	} else {
		throw cRuntimeError("No security sign service available with name \"%s\"", vanetzaSecuritySignService);
	}

	VerifyService verify_service;
	const std::string vanetzaSecurityVerifyService = par("vanetzaSecurityVerifyService");
	if (vanetzaSecurityVerifyService == "straight") {
		verify_service = straight_verify_service(mRuntime, *mSecurityCertificates, *mSecurityBackend);
	} else if (vanetzaSecurityVerifyService == "dummy") {
		verify_service = dummy_verify_service(VerificationReport::Success, CertificateValidity::valid());
	} else {
		throw cRuntimeError("No security verify service available with name \"%s\"", vanetzaSecurityVerifyService);
	}

	mSecurityEntity.reset(new SecurityEntity(sign_service, verify_service));
}

void ItsG5Middleware::initializeVehicleController()
{
	auto mobility = inet::getModuleFromPar<ControllableVehicle>(par("mobilityModule"), findHost());
	mVehicleController = mobility->getVehicleController();
	ASSERT(mVehicleController);
}

void ItsG5Middleware::initializeServices()
{
	cXMLElement* config = par("services").xmlValue();
	for (cXMLElement* service_cfg : config->getChildrenByTagName("service")) {
		cModuleType* module_type = cModuleType::get(service_cfg->getAttribute("type"));
		const char* service_name = service_cfg->getAttribute("name") ?
				service_cfg->getAttribute("name") :
				service_cfg->getAttribute("type");

		cXMLElement* service_filters = service_cfg->getFirstChildWithTag("filters");
		bool service_applicable = true;
		if (service_filters) {
			ASSERT(mVehicleController);
			artery::FilterRules rules(getRNG(0), *mVehicleController);
			service_applicable = rules.applyFilterConfig(*service_filters);
		}

	
		if (service_applicable) {
			cModule* module = module_type->createScheduleInit(service_name, this);
			ItsG5BaseService* service = dynamic_cast<ItsG5BaseService*>(module);

			if (service) {
				cXMLElement* listener = service_cfg->getFirstChildWithTag("listener");
				if (listener && listener->getAttribute("port")) {
					port_type port = boost::lexical_cast<port_type>(listener->getAttribute("port"));
					mServices.emplace(service, port);
					mBtpPortDispatcher.set_non_interactive_handler(vanetza::host_cast<port_type>(port), service);
				} else if (!service->requiresListener()) {
					mServices.emplace(service, 0);
				} else {
					auto promiscuous = dynamic_cast<ItsG5PromiscuousService*>(service);
					if (promiscuous != nullptr) {
						mServices.emplace(service, 0);
						mBtpPortDispatcher.add_promiscuous_hook(promiscuous);
					} else {
						throw cRuntimeError("No listener port defined for %s", service_name);
					}
				}
			} else {
				throw cRuntimeError("%s is not of type ItsG5BaseService", module_type->getFullName());
			}
		}
	}
}

void ItsG5Middleware::finish()
{
	cancelAndDelete(mUpdateMessage);
	cancelAndDelete(mUpdateRuntimeMessage);
	findHost()->unsubscribe(inet::IMobility::mobilityStateChangedSignal, this);
	emit(artery::IdentityRegistry::removeSignal, &mIdentity);
}

void ItsG5Middleware::handleMessage(cMessage *msg)
{
	// Update clock before anything else is executed (which might read the clock)
	mRuntime.trigger(mTimer.getCurrentTime());

	if (msg->isSelfMessage()) {
		handleSelfMsg(msg);
	} else {
		ASSERT(msg->getArrivalGate() == mRadioDriverIn);
		handleLowerMsg(msg);
	}
}

void ItsG5Middleware::handleSelfMsg(cMessage *msg)
{
	if (msg == mUpdateMessage) {
		update();
	} else if (msg == mUpdateRuntimeMessage) {
		// runtime is triggered each handleMessage invocation
	} else {
		throw cRuntimeError("Unknown self-message in ITS-G5");
	}
}

void ItsG5Middleware::handleLowerMsg(cMessage *msg)
{
	auto* packet = check_and_cast<GeoNetPacket*>(msg);
	auto& wrapper = packet->getPayload();
	auto* indication = check_and_cast<GeoNetIndication*>(packet->getControlInfo());
	mGeoRouter->indicate(wrapper.extract_up_packet(), indication->source, indication->destination);
	scheduleRuntime();
	delete msg;
}

cModule* ItsG5Middleware::findHost()
{
	return inet::getContainingNode(this);
}

void ItsG5Middleware::update()
{
	updatePosition();
	updateServices();
	scheduleAt(simTime() + mUpdateInterval, mUpdateMessage);
}

void ItsG5Middleware::receiveSignal(cComponent* component, simsignal_t signal, cObject* obj, cObject* details)
{
	if (signal == inet::IMobility::mobilityStateChangedSignal) {
		mVehicleDataProvider.update(mVehicleController);
	}
}

void ItsG5Middleware::receiveSignal(cComponent* component, simsignal_t signal, double value, cObject* details)
{
	if (signal == RadioDriverBase::ChannelLoadSignal) 
	{
		ASSERT(value >= 0.0 && value <= 1.0);
		unsigned busy_samples = 12500.0 * value;
		vanetza::dcc::ChannelLoad cl { busy_samples, 12500 };
		ASSERT(abs(channel_load.fraction() - value) < 1.0e-6);
		mDccFsm.update(cl);
	}
}


void ItsG5Middleware::scheduleRuntime()
{
	cancelEvent(mUpdateRuntimeMessage);
	auto next_time_point = mRuntime.next();
	while (next_time_point < vanetza::Clock::time_point::max()) {
		if (next_time_point > mRuntime.now()) {
			scheduleAt(convertSimTime(next_time_point), mUpdateRuntimeMessage);
			break;
		} else {
			mRuntime.trigger(mRuntime.now());
			next_time_point = mRuntime.next();
		}
	}
}

void ItsG5Middleware::updatePosition()
{
	vanetza::geonet::LongPositionVector lpv;
	lpv.timestamp = vanetza::geonet::Timestamp(mRuntime.now());
	//lpv.latitude = static_cast<decltype(lpv.latitude)>(mVehicleDataProvider.latitude());
	//lpv.longitude = static_cast<decltype(lpv.longitude)>(mVehicleDataProvider.longitude());
	lpv.heading = static_cast<decltype(lpv.heading)>(mVehicleDataProvider.heading());
	lpv.speed = static_cast<decltype(lpv.speed)>(mVehicleDataProvider.speed());
	lpv.position_accuracy_indicator = true;
	mGeoRouter->update(lpv);
}

void ItsG5Middleware::updateServices()
{
	mLocalDynamicMap.dropExpired();
	for (auto& kv : mServices) {
		kv.first->trigger();
	}
}

ItsG5Middleware::port_type ItsG5Middleware::getPortNumber(const ItsG5BaseService* service) const
{
	port_type port = 0;
	auto it = mServices.find(const_cast<ItsG5BaseService*>(service));
	if (it != mServices.end()) {
		port = it->second;
	}
	return port;
}

SimTime ItsG5Middleware::convertSimTime(vanetza::Clock::time_point tp) const
{
	using namespace std::chrono;
	const auto d = duration_cast<microseconds>(tp - mRuntime.now());
	return SimTime { simTime().inUnit(SIMTIME_US) + d.count(), SIMTIME_US };
}


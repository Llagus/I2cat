/*
 * Artery V2X Simulation Framework
 * Copyright 2016-2017 Raphael Riebl
 * Licensed under GPLv2, see COPYING file for detailed license and warranty terms.
 */

#ifndef ARTERY_MYSERVICE_H_
#define ARTERY_MYSERVICE_H_

#include "artery/application/DenmMemory.h"
#include "artery/application/DenmUseCase.h"
#include "artery/application/ItsG5BaseService.h"
#include <boost/ptr_container/ptr_list.hpp>
#include <vanetza/asn1/denm.hpp>
#include <vanetza/btp/data_indication.hpp>
#include <cstdint>
#include <list>
#include <memory>
#include <omnetpp.h>                            //~ cMessage
#include <boost/units/systems/si/velocity.hpp>  //~ Velocity

typedef boost::units::quantity<boost::units::si::velocity> Velocity;


using namespace omnetpp;

class Timer;

class MyService : public ItsG5BaseService
{
    public:
        MyService();
        ~MyService();
        void initialize() override;
        void receiveSignal(cComponent*, omnetpp::simsignal_t, cObject*, cObject*) override;
        void receiveSignal(cComponent*, omnetpp::simsignal_t, const char*, cObject*) override;
        void indicate(const vanetza::btp::DataIndication&, std::unique_ptr<vanetza::UpPacket>) override;
        void trigger() override;
        void finish() override;


    private:
        void sendDenm();
        void handleMessage(cMessage *msg);
        void missatge(vanetza::asn1::Denm& msg);
        vanetza::btp::DataRequestB createRequest();
        vanetza::asn1::Denm createDenm();

        //~ ambulance time
        simtime_t myservice_final_time;
        simtime_t myservice_start_time;
        bool am_I_an_ambulance;
        bool am_I_a_car;
        bool am_I_a_rsu;
        bool is_there_emergency;
        bool car_attending_emergency;
        int car_loops_attending_emergency;
        bool is_there_speed;
        simtime_t timeout;  // timeout
        cMessage *timeoutEvent;  // holds pointer to the timeout self-message


        const Timer* mTimer;
        int mSequenceNumber;
};

#endif

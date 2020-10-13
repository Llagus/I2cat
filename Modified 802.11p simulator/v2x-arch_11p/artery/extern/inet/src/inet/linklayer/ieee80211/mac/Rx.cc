//
// Copyright (C) 2015 Andras Varga
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//
// Author: Andras Varga
//

#include "Rx.h"
#include "IContention.h"
#include "ITx.h"
#include "IUpperMac.h"
#include "IStatistics.h"

//~ for distance errors
//---------------------
#include "inet/common/ModuleAccess.h"
#include "inet/mobility/contract/IMobility.h"
#include "../../../src/artery/application/GlobalMapper.h"

#include "../../../src/artery/application/SystemMonitor.h"

namespace inet {
namespace ieee80211 {

Define_Module(Rx);

Rx::Rx()
{
}

Rx::~Rx()
{
    delete cancelEvent(endNavTimer);
    delete [] contention;
}

void Rx::initialize()
{
    upperMac = check_and_cast<IUpperMac *>(getModuleByPath(par("upperMacModule")));
    collectContentionModules(getModuleByPath(par("firstContentionModule")), contention);
    statistics = check_and_cast<IStatistics *>(getModuleByPath(par("statisticsModule")));
    endNavTimer = new cMessage("NAV");
    recomputeMediumFree();

    WATCH(address);
    WATCH(receptionState);
    WATCH(transmissionState);
    WATCH(mediumFree);

    //~ for distance errors
    //---------------------
    histo_per_distance.setNumCells(30);
    histo_per_distance.setRange(0,300);
    histo_per_speed.setNumCells(49);
    histo_per_speed.setRange(1,50);

    databaseCheck = new cMessage("databaseCheck");
    scheduleAt(simTime()+0.1, databaseCheck);

    cModule * modSystemMonitor = getModuleByPath("<root>.SystemMonitor");
    if (modSystemMonitor) {
        systemMonitor = dynamic_cast<SystemMonitor*>(modSystemMonitor);
    } else {
        error("No SystemMonitor module.");
    }

    statRegionHighwayStart = par("statRegionHighwayStart").doubleValue();
    statRegionHighwayEnd = par("statRegionHighwayEnd").doubleValue();
    statRegionGridStartX = par("statRegionGridStartX").doubleValue();
    statRegionGridEndX = par("statRegionGridEndX").doubleValue();
    statRegionGridStartY = par("statRegionGridStartY").doubleValue();
    statRegionGridEndY = par("statRegionGridEndY").doubleValue();
}

//lastKnownPos database
void Rx::lastKnownPos_update(std::string mac, lastKnownPos_database_t nodeX)
{
    Enter_Method_Silent();
    mac_lastKnownPos_table[mac] = nodeX;
}

simtime_t Rx::lastKnownPos_get_startEntry(std::string mac)
{
    Enter_Method_Silent();
    return mac_lastKnownPos_table[mac].startEntry;
}

inet::Coord Rx::lastKnownPos_get_lastPos(std::string mac)
{
    Enter_Method_Silent();
    return mac_lastKnownPos_table[mac].lastPos;
}

double Rx::lastKnownPos_get_TxRxDist(std::string mac)
{
    Enter_Method_Silent();
    return mac_lastKnownPos_table[mac].TxRxDist;
}

void Rx::handleMessage(cMessage *msg)
{
    //Periodically check the node's lastKnownPos database
    if (msg == databaseCheck){

        //globalMapper
        cModule *gL_map = getModuleByPath("globalMapper");
        GlobalMapper * globalMapper;
        if(gL_map)  globalMapper = check_and_cast<GlobalMapper *>(gL_map);
        else        throw cRuntimeError("Invalid cast from mod globalMapper to pointer.");

        for(std::map<std::string, lastKnownPos_database_t>::iterator mapIterator = mac_lastKnownPos_table.begin(); mapIterator != mac_lastKnownPos_table.end(); ++mapIterator){

            //mapIterator->first corresponds to the Tx MAC address in the database
            //Check expiration of database entry (2seconds max)
            if ( (simTime() - mac_lastKnownPos_table[mapIterator->first].startEntry) > 2){
                mac_lastKnownPos_table.erase(mapIterator++->first);
                continue;
            }

            //Check GlobalMapper database if node is present in the scenario
            if (globalMapper->gm_get_database_name(mapIterator->first) != nullptr){
                const char *node = globalMapper->gm_get_database_name(mapIterator->first);

                //Check lastKnownPos database if node is present in the scenario
                if (lastKnownPos_get_lastPos(mapIterator->first) != inet::Coord(0,0,0) ){
                    inet::Coord lastPos = lastKnownPos_get_lastPos(mapIterator->first); //Last known position of Tx

                    cModule* hostTx = globalMapper->gm_get_database_mod(mapIterator->first);
                    inet::IMobility *modTx = check_and_cast<inet::IMobility *>(hostTx->getSubmodule("mobility"));
                    inet::Coord CurrentPos = modTx->getCurrentPosition(); //Current position of Tx

                    cModule* hostRx = inet::getContainingNode(this);
                    inet::IMobility *modRx = check_and_cast<inet::IMobility *>(hostRx->getSubmodule("mobility"));
                    inet::Coord my_pos = modRx->getCurrentPosition(); //Current position of Rx

                    double deltaPos;
                    deltaPos = std::abs(globalMapper->gm_get_distance(lastPos, CurrentPos) );

                    double TxRxDist_old;
                    TxRxDist_old = globalMapper->gm_get_distance(my_pos, lastPos);

                    double TxRxDist_new;
                    TxRxDist_new = globalMapper->gm_get_distance(my_pos, CurrentPos);

                    double deltaTxRxDist;
                    deltaTxRxDist = std::abs(TxRxDist_new - TxRxDist_old);

                    if (my_pos.x > statRegionHighwayStart && my_pos.x < statRegionHighwayEnd){  //Statistical Region
//                    if (my_pos.x > statRegionGridStartX && my_pos.x < statRegionGridEndX && my_pos.y > statRegionGridStartY && my_pos.y < statRegionGridEndY){

                        systemMonitor->recordDeltaPosition(deltaPos, TxRxDist_new);
                        systemMonitor->recordDeltaDistance(deltaTxRxDist, TxRxDist_new);

                        //NAR Perceived
                        inet::Coord GMPos = globalMapper->gm_get_database_TxPos(mapIterator->first);
                        double NARPerceived_distance;
                        NARPerceived_distance = std::abs(globalMapper->gm_get_distance(GMPos, my_pos) );
                        systemMonitor->NARPerceived(NARPerceived_distance);
                    } //statistics

                }
            } //check presence of node

        } //for loop

        //NAR Actual
        cModule* hostRx2 = inet::getContainingNode(this);
        inet::IMobility *modRx2 = check_and_cast<inet::IMobility *>(hostRx2->getSubmodule("mobility"));
        inet::Coord my_pos2 = modRx2->getCurrentPosition(); //Current position of Rx

        if (my_pos2.x > statRegionHighwayStart && my_pos2.x < statRegionHighwayEnd) {  //Statistical Region
//        if (my_pos2.x > statRegionGridStartX && my_pos2.x < statRegionGridEndX && my_pos2.y > statRegionGridStartY && my_pos2.y < statRegionGridEndY){
            globalMapper->gm_traverse(my_pos2, hostRx2);
        }

        scheduleAt(simTime()+0.1, databaseCheck);
    }
    else if (msg == endNavTimer) {
        EV_INFO << "The radio channel has become free according to the NAV" << std::endl;
        recomputeMediumFree();
    }
    else
        throw cRuntimeError("Unexpected self message");
}

void Rx::lowerFrameReceived(Ieee80211Frame *frame)
{
    Enter_Method("lowerFrameReceived(\"%s\")", frame->getName());
    take(frame);

//    std::cout << "Rx.cc: " << frame->getByteLength() << std::endl;

// ---------Total number of frames received according to Tx-Rx distance-----------------------------------

    //globalMapper
    cModule *gL_map = getModuleByPath("globalMapper");
    GlobalMapper * globalMapper;
    if(gL_map)  globalMapper = check_and_cast<GlobalMapper *>(gL_map);
    else        throw cRuntimeError("Invalid cast from mod globalMapper to pointer.");

    cModule* hostRx = inet::getContainingNode(this);
    inet::IMobility *mod = check_and_cast<inet::IMobility *>(hostRx->getSubmodule("mobility"));
    inet::Coord my_pos = mod->getCurrentPosition(); //Current position of Rx

    std::string tx_mac_str = statistics->stat_get_txmac_str(frame);
    cModule* hostTx = globalMapper->gm_get_database_mod(tx_mac_str);
    inet::Coord TxPos_Tx = globalMapper->gm_get_database_TxPos(tx_mac_str); //Tx position when CAM is sent (indicated in CAM)

    double distance;
    distance = globalMapper->gm_get_meters_btw(tx_mac_str, my_pos);

    if (my_pos.x > statRegionHighwayStart && my_pos.x < statRegionHighwayEnd){  //Statistical Region
//    if (my_pos.x > statRegionGridStartX && my_pos.x < statRegionGridEndX && my_pos.y > statRegionGridStartY && my_pos.y < statRegionGridEndY){
        systemMonitor->recordRxFrames(distance);
    }

    bool isFrameOk = isFcsOk(frame);
    if (isFrameOk) 
    {
        if (frame->getReceiverAddress() != address)
            setOrExtendNav(frame->getDuration());
        statistics->frameReceived(frame);
        upperMac->lowerFrameReceived(frame);

// ---------Total number of OK frames received according to Tx-Rx distance-----------------------------------

        //globalMapper
        cModule *gL_map = getModuleByPath("globalMapper");
        GlobalMapper * globalMapper;
        if(gL_map)  globalMapper = check_and_cast<GlobalMapper *>(gL_map);
        else        throw cRuntimeError("Invalid cast from mod globalMapper to pointer.");

        cModule* hostRx = inet::getContainingNode(this);
        inet::IMobility *mod = check_and_cast<inet::IMobility *>(hostRx->getSubmodule("mobility"));
        inet::Coord my_pos = mod->getCurrentPosition(); //Current position of Rx

        std::string tx_mac_str = statistics->stat_get_txmac_str(frame);
        cModule* hostTx = globalMapper->gm_get_database_mod(tx_mac_str);
        inet::Coord TxPos_Tx = globalMapper->gm_get_database_TxPos(tx_mac_str); //Tx position when CAM is sent (indicated in CAM)

        double distance;
        distance = globalMapper->gm_get_meters_btw(tx_mac_str, my_pos);

        if (my_pos.x > statRegionHighwayStart && my_pos.x < statRegionHighwayEnd){  //Statistical Region
//        if (my_pos.x > statRegionGridStartX && my_pos.x < statRegionGridEndX && my_pos.y > statRegionGridStartY && my_pos.y < statRegionGridEndY){
            systemMonitor->recordRxFramesOK(distance);
        }

        //Populate lastKnownPos database
        lastKnownPos_update(tx_mac_str, {simTime(), TxPos_Tx, distance});
    }
    else 
    {
        EV_ERROR << "Received an erroneous frame from PHY, dropping it." << std::endl;
        {

// ---------Total number of NG frames received according to Tx-Rx distance-----------------------------------

            //globalMapper
            cModule *gL_map = getModuleByPath("globalMapper");
            GlobalMapper * globalMapper;
            if(gL_map)  globalMapper = check_and_cast<GlobalMapper *>(gL_map);
            else        throw cRuntimeError("Invalid cast from mod globalMapper to pointer.");

            cModule* hostRx = inet::getContainingNode(this);
            inet::IMobility *mod = check_and_cast<inet::IMobility *>(hostRx->getSubmodule("mobility"));
            inet::Coord my_pos = mod->getCurrentPosition(); //Current position of Rx

            std::string tx_mac_str = statistics->stat_get_txmac_str(frame);
            cModule* hostTx = globalMapper->gm_get_database_mod(tx_mac_str);
            inet::Coord TxPos_Tx = globalMapper->gm_get_database_TxPos(tx_mac_str); //Tx position when CAM is sent (indicated in CAM)

            double distance;
            distance = globalMapper->gm_get_meters_btw(tx_mac_str, my_pos);

            double speed;
            speed = globalMapper->gm_get_database_TxVel(tx_mac_str);

            if (my_pos.x > statRegionHighwayStart && my_pos.x < statRegionHighwayEnd){  //Statistical Region
//            if (my_pos.x > statRegionGridStartX && my_pos.x < statRegionGridEndX && my_pos.y > statRegionGridStartY && my_pos.y < statRegionGridEndY){

                systemMonitor->recordRxFramesNG(distance);

                //~ put in my <error, distance> histogram
                //---------------------------------------
                if (simTime() >= getSimulation()->getWarmupPeriod())
                {
                    histo_per_distance.collect(int(distance));
                    histo_per_speed.collect(int(speed));
                }
            }
        }
        delete frame;
        for (int i = 0; contention[i]; i++)
            contention[i]->corruptedFrameReceived();
        upperMac->corruptedFrameReceived();
        statistics->erroneousFrameReceived();
    }
}

void Rx::frameTransmitted(simtime_t durationField)
{
    Enter_Method_Silent();
    // the txIndex that transmitted the frame should already own the TXOP, so
    // it has no need to (and should not) check the NAV.
    setOrExtendNav(durationField);
}

bool Rx::isReceptionInProgress() const
{
    return receptionState == IRadio::RECEPTION_STATE_RECEIVING &&
           (receivedPart == IRadioSignal::SIGNAL_PART_WHOLE || receivedPart == IRadioSignal::SIGNAL_PART_DATA);
}

bool Rx::isFcsOk(Ieee80211Frame *frame) const
{
    return !frame->hasBitError();
}

void Rx::recomputeMediumFree()
{
    bool oldMediumFree = mediumFree;
    // note: the duration of mode switching (rx-to-tx or tx-to-rx) should also count as busy
    mediumFree = receptionState == IRadio::RECEPTION_STATE_IDLE && transmissionState == IRadio::TRANSMISSION_STATE_UNDEFINED && !endNavTimer->isScheduled();
    if (mediumFree != oldMediumFree) {
        for (int i = 0; contention[i]; i++)
            contention[i]->mediumStateChanged(mediumFree);
    }
}

void Rx::receptionStateChanged(IRadio::ReceptionState state)
{
    Enter_Method_Silent();
    receptionState = state;
    recomputeMediumFree();
}

void Rx::receivedSignalPartChanged(IRadioSignal::SignalPart part)
{
    Enter_Method_Silent();
    receivedPart = part;
    recomputeMediumFree();
}

void Rx::transmissionStateChanged(IRadio::TransmissionState state)
{
    Enter_Method_Silent();
    transmissionState = state;
    recomputeMediumFree();
}

void Rx::setOrExtendNav(simtime_t navInterval)
{
    ASSERT(navInterval >= 0);
    if (navInterval > 0) {
        simtime_t endNav = simTime() + navInterval;
        if (endNavTimer->isScheduled()) {
            simtime_t oldEndNav = endNavTimer->getArrivalTime();
            if (endNav < oldEndNav)
                return;    // never decrease NAV
            cancelEvent(endNavTimer);
        }
        EV_INFO << "Setting NAV to " << navInterval << std::endl;
        scheduleAt(endNav, endNavTimer);
        recomputeMediumFree();
    }
}

void Rx::refreshDisplay() const
{
    if (mediumFree)
        getDisplayString().setTagArg("t", 0, "FREE");
    else {
        std::stringstream os;
        os << "BUSY (";
        bool addSpace = false;
        if (transmissionState != IRadio::TRANSMISSION_STATE_UNDEFINED) {
            switch (transmissionState) {
                case IRadio::IRadio::TRANSMISSION_STATE_UNDEFINED: break; // cannot happen
                case IRadio::IRadio::TRANSMISSION_STATE_IDLE: os << "Tx-Idle"; break;
                case IRadio::IRadio::TRANSMISSION_STATE_TRANSMITTING: os << "Tx"; break;
            }
            addSpace = true;
        }
        else {
            switch (receptionState) {
                case IRadio::RECEPTION_STATE_UNDEFINED: os << "Switching"; break;
                case IRadio::RECEPTION_STATE_IDLE: os << "Rx-Idle"; break; // cannot happen
                case IRadio::RECEPTION_STATE_BUSY: os << "Noise"; break;
                case IRadio::RECEPTION_STATE_RECEIVING: os << "Recv"; break;
            }
            addSpace = true;
        }
        if (endNavTimer->isScheduled()) {
            os << (addSpace ? " " : "") << "NAV";
        }
        os << ")";
        getDisplayString().setTagArg("t", 0, os.str().c_str());
    }
}

void Rx::finish()
{
    histo_per_distance.recordAs("errors_per_distance:histogram");
    histo_per_speed.recordAs("errors_per_speed:histogram");
}

} // namespace ieee80211
} // namespace inet

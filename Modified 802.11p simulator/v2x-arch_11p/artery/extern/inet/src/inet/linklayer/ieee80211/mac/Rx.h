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

#ifndef __INET_RX_H
#define __INET_RX_H


#include "IRx.h"
#include "inet/physicallayer/contract/packetlevel/IRadio.h"
#include "Ieee80211Frame_m.h"

#include "../../../src/artery/application/SystemMonitor.h"

namespace inet {
namespace ieee80211 {

//lastKnownPos database
struct lastKnownPos_database_t{
    simtime_t startEntry;
    inet::Coord lastPos;
    double TxRxDist;
};
typedef std::map<std::string, lastKnownPos_database_t> mac_lastKnownPos_table_t;

class IUpperMac;
class ITx;
class IContention;
class IStatistics;

/**
 * The default implementation of IRx.
 */
class INET_API Rx : public cSimpleModule, public IRx
{
    protected:
        IUpperMac *upperMac = nullptr;
        IContention **contention = nullptr; // nullptr-terminated pointer array
        IStatistics *statistics = nullptr;

        MACAddress address;
        cMessage *endNavTimer = nullptr;
        IRadio::ReceptionState receptionState = IRadio::RECEPTION_STATE_UNDEFINED;
        IRadio::TransmissionState transmissionState = IRadio::TRANSMISSION_STATE_UNDEFINED;
        IRadioSignal::SignalPart receivedPart = IRadioSignal::SIGNAL_PART_NONE;
        bool mediumFree = true;  // cached state

        //~ for distance errors
        //---------------------
        cLongHistogram histo_per_distance;
        cLongHistogram histo_per_speed;

        double statRegionHighwayStart = 300;
        double statRegionHighwayEnd = 700;
        double statRegionGridStartX = 70;
        double statRegionGridEndX = 375;
        double statRegionGridStartY = 111.25;
        double statRegionGridEndY = 333.75;

        SystemMonitor * systemMonitor;

    protected:
        virtual void initialize() override;
        virtual void handleMessage(cMessage *msg) override;
        virtual void setOrExtendNav(simtime_t navInterval);
        virtual bool isFcsOk(Ieee80211Frame *frame) const;
        virtual void recomputeMediumFree();
        virtual void refreshDisplay() const override;

        //~ for distance errors
        //---------------------
        virtual void finish() override;

    private:
        mac_lastKnownPos_table_t mac_lastKnownPos_table;
        cMessage *databaseCheck = nullptr;

    public:
        Rx();
        ~Rx();

        virtual void setAddress(const MACAddress& address) override { this->address = address; }
        virtual bool isReceptionInProgress() const override;
        virtual bool isMediumFree() const override { return mediumFree; }
        virtual void receptionStateChanged(IRadio::ReceptionState newReceptionState) override;
        virtual void transmissionStateChanged(IRadio::TransmissionState transmissionState) override;
        virtual void receivedSignalPartChanged(IRadioSignal::SignalPart part) override;
        virtual void lowerFrameReceived(Ieee80211Frame *frame) override;
        virtual void frameTransmitted(simtime_t durationField) override;

        void lastKnownPos_update(std::string, lastKnownPos_database_t);
        simtime_t lastKnownPos_get_startEntry(std::string);
        inet::Coord lastKnownPos_get_lastPos(std::string);
        double lastKnownPos_get_TxRxDist(std::string);
};

} // namespace ieee80211
} // namespace inet

#endif

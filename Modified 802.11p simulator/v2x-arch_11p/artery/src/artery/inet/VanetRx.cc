#include "artery/inet/VanetRx.h"
#include <cstdint>

// ./extern/inet/src/inet/linklayer/ieee80211/mac/Rx.h

using namespace omnetpp;

Define_Module(VanetRx)


const simsignal_t VanetRx::ChannelLoadSignal = cComponent::registerSignal("ChannelLoad");

VanetRx::VanetRx()
{
}

VanetRx::~VanetRx()
{
    cancelAndDelete(channelReportTrigger);
}

void VanetRx::initialize()
{
    Rx::initialize();
    channelLoadSamples.resize(12500);
    channelLoadLastUpdate = simTime();
    channelBusyRatio = 0.0;
    channelReportInterval = simtime_t { 100, SIMTIME_MS };
    channelReportTrigger = new cMessage("report CL");
    scheduleAt(simTime() + channelReportInterval, channelReportTrigger);

    WATCH(channelBusyRatio);

    //~ statistics for channelLoad
    vec_channel_load = new cOutVector("vec_channel_load");
    his_channel_load = new cHistogram("histogram", 20, cHistogram::MODE_DOUBLES);
    his_channel_load->setRange(0,1);
}

void VanetRx::handleMessage(cMessage* msg)
{
    if (msg == channelReportTrigger) {
        reportChannelLoad();
        scheduleAt(simTime() + channelReportInterval, channelReportTrigger);
    } else {
        Rx::handleMessage(msg);
    }
}

void VanetRx::recomputeMediumFree()
{
    static const simtime_t symbolPeriod { 8, SIMTIME_US };
    const auto updateDelta = simTime() - channelLoadLastUpdate;
    if (updateDelta >= symbolPeriod) {
        const std::size_t fillSamples = updateDelta / symbolPeriod;
        channelLoadSamples.insert(channelLoadSamples.end(), fillSamples, !mediumFree);
        channelLoadLastUpdate = simTime();
    }

    Rx::recomputeMediumFree();
}

void VanetRx::reportChannelLoad()
{
    const auto busy = std::count(channelLoadSamples.begin(), channelLoadSamples.end(), true);
    const auto total = channelLoadSamples.size();
    channelBusyRatio = busy;
    channelBusyRatio /= total;

    //~ statistics for channelLoad
    vec_channel_load->record(channelBusyRatio);
    if (simTime() >= getSimulation()->getWarmupPeriod())
        his_channel_load->collect(channelBusyRatio);

    emit(ChannelLoadSignal, channelBusyRatio);
}


//~ added to log histos
//---------------------
void VanetRx::finish()
{
    Rx::finish();
    his_channel_load->recordAs("channelBusyRatio");

    delete his_channel_load;
    delete vec_channel_load;
}

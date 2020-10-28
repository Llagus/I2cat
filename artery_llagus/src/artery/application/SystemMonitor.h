//
// Created by wng on 21/01/19.
//

#ifndef ARTERY_SYSTEMMONITOR_H
#define ARTERY_SYSTEMMONITOR_H

#include <omnetpp.h>

using namespace omnetpp;

class SystemMonitor  : public cSimpleModule
{
protected:

    double warmupTime = 10;
    std::string outputFileName;

    cHistogram histogram_deltaPosition;
    cHistogram histogram_deltaDistance;
    std::vector<double> vector_deltaPosition;
    std::vector<double> vector_deltaPositionTxRxDistance;
    std::vector<double> vector_deltaDistance;
    std::vector<double> vector_deltaDistanceTxRxDistance;

    cHistogram histogram_RxFrames;
    cHistogram histogram_RxFramesOK;
    cHistogram histogram_RxFramesNG;

    cHistogram histogram_NARActual;
    cHistogram histogram_NARPerceived;

    simsignal_t numCamSentSignal;

    virtual void initialize();
    virtual void finish();

public:

    SystemMonitor();
    virtual ~SystemMonitor();

    virtual void recordDeltaPosition(double deltaPosition, double txRxDistance);
    virtual void recordDeltaDistance(double deltaDistance, double txRxDistance);
    virtual void recordRxFrames(double txRxDistance);
    virtual void recordRxFramesOK(double txRxDistance);
    virtual void recordRxFramesNG(double txRxDistance);
    virtual void NARActual(double txRxDistance);
    virtual void NARPerceived(double txRxDistance);
    virtual void numCamSent();

    virtual void handleMessage(cMessage *msg);

private:
    cMessage *systemMonitorEvent = nullptr;
};


#endif //ARTERY_SYSTEMMONITOR_H

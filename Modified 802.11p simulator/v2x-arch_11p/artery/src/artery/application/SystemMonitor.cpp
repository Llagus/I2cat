//
// Created by wng on 21/01/19.
//

#include "SystemMonitor.h"
#include <fstream>

using namespace omnetpp;

Define_Module(SystemMonitor);

SystemMonitor::SystemMonitor()
{
}

SystemMonitor::~SystemMonitor()
{
}

void SystemMonitor::initialize()
{
    warmupTime = par("warmupTime").doubleValue();
    outputFileName = par("outputFileName").stringValue();

    histogram_deltaPosition.setNumCells(250);
    histogram_deltaPosition.setRange(0, 500);
    histogram_deltaDistance.setNumCells(250);
    histogram_deltaDistance.setRange(0, 500);

    histogram_RxFrames.setNumCells(25);
    histogram_RxFrames.setRange(0, 500);
    histogram_RxFramesOK.setNumCells(25);
    histogram_RxFramesOK.setRange(0, 500);
    histogram_RxFramesNG.setNumCells(25);
    histogram_RxFramesNG.setRange(0, 500);

    histogram_NARActual.setNumCells(25);
    histogram_NARActual.setRange(0, 500);

    histogram_NARPerceived.setNumCells(25);
    histogram_NARPerceived.setRange(0, 500);

    systemMonitorEvent = new cMessage("systemMonitorEvent");
    scheduleAt(simTime()+0.1, systemMonitorEvent);

    numCamSentSignal = registerSignal("numCamSent");
}

void SystemMonitor::finish()
{
    histogram_deltaPosition.recordAs("deltaPosition:histogram");
    histogram_deltaDistance.recordAs("deltaDistance:histogram");

    histogram_RxFrames.recordAs("RxFrames:histogram");
    histogram_RxFramesOK.recordAs("RxFramesOK:histogram");
    histogram_RxFramesNG.recordAs("RxFramesNG:histogram");

    histogram_NARActual.recordAs("NARActual:histogram");
    histogram_NARPerceived.recordAs("NARPerceived:histogram");

    std::ofstream output_file("./" + outputFileName + "_delta.csv");

    for (unsigned int n = 0 ; n < vector_deltaPosition.size() ; n++){
        output_file << vector_deltaPosition[n] << "," << vector_deltaPositionTxRxDistance[n] << "," << vector_deltaDistance[n] << "," << vector_deltaDistanceTxRxDistance[n] << std::endl;
    }
}

void SystemMonitor::recordDeltaPosition(double deltaPosition, double txRxDistance)
{
    if (simTime().dbl() >= warmupTime){
        histogram_deltaPosition.collect(deltaPosition);
        vector_deltaPosition.push_back (deltaPosition);
        vector_deltaPositionTxRxDistance.push_back(txRxDistance);
    }
}

void SystemMonitor::recordDeltaDistance(double deltaDistance, double txRxDistance)
{
    if (simTime().dbl() >= warmupTime){
        histogram_deltaDistance.collect(deltaDistance);
        vector_deltaDistance.push_back (deltaDistance);
        vector_deltaDistanceTxRxDistance.push_back(txRxDistance);
    }
}

void SystemMonitor::recordRxFrames(double txRxDistance)
{
    if (simTime().dbl() >= warmupTime){
        histogram_RxFrames.collect(txRxDistance);
    }
}

void SystemMonitor::recordRxFramesOK(double txRxDistance)
{
    if (simTime().dbl() >= warmupTime){
        histogram_RxFramesOK.collect(txRxDistance);
    }
}

void SystemMonitor::recordRxFramesNG(double txRxDistance)
{
    if (simTime().dbl() >= warmupTime){
        histogram_RxFramesNG.collect(txRxDistance);
    }
}

void SystemMonitor::NARActual(double txRxDistance)
{
    if (simTime().dbl() >= warmupTime){
        histogram_NARActual.collect(txRxDistance);
    }
}

void SystemMonitor::NARPerceived(double txRxDistance)
{
    if (simTime().dbl() >= warmupTime){
        histogram_NARPerceived.collect(txRxDistance);
    }
}

void SystemMonitor::handleMessage(cMessage *msg)
{
    if (msg == systemMonitorEvent){
        scheduleAt(simTime()+0.1,systemMonitorEvent);
    }
}

void SystemMonitor::numCamSent()
{
    if (simTime().dbl() >= warmupTime){
        emit(numCamSentSignal, 1);
    }
}
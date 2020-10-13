package artery.inet;

import artery.storyboard.Storyboard;
import inet.node.inet.INetworkNode;
import inet.physicallayer.contract.packetlevel.IRadioMedium;
import traci.Manager;
import inet.environment.common.PhysicalEnvironment;
import artery.application.GlobalListener;
import artery.application.GlobalMapper;
import inet.visualizer.integrated.IntegratedCanvasVisualizer;

import artery.application.SystemMonitor;

network World
{
    parameters:

        @statistic[numCamSent](title="Number of CAMs sent"; source="numCamSent"; record=stats; interpolationmode=none);

        bool withStoryboard = default(false);
        @display("bgb=500,500");

        // ----------------------------------------------
        // 			type of nodes (.mobility in Car.ned)
        // ----------------------------------------------
        traci.mapper.vehicleType = default("artery.inet.Car");
        traci.nodes.vehicleSinkModule = default(".mobility");

        // ------------------------------------------
        //          set parameters deeper modules
        // ------------------------------------------
        storyboard.middlewareModule = default(".middleware");

    submodules:

        SystemMonitor: SystemMonitor {
            @display("p=668,212;i=abstract/penguin");
        }

        // ------------------------------------------
        //    to link with SUMO
        // ------------------------------------------
        traci: Manager {
            parameters:
                @display("p=0,500");
        }

        // ----------------------------
        // where airframes take place
        // ----------------------------
        radioMedium: <default("Ieee80211ScalarRadioMedium")> like IRadioMedium {
            parameters:
                @display("p=100,500");
                mediumLimitCache.carrierFrequency = 5.9GHz;
        }

        // --------------------------
        // 'withStoryBoard' is above
        // --------------------------
        storyboard: Storyboard if withStoryboard {
            parameters:
                @display("p=200,500");
        }

        // ----------------------------------
        // for latencies for unacked packets
        // ----------------------------------
        globalListener: GlobalListener {
            parameters:
                @display("p=300,500;i=block/control;is=s");
        }

        // ----------------------------------
        // for positions of the nodes
        // ----------------------------------
        globalMapper: GlobalMapper {
            parameters:
                @display("p=350,500;i=block/control;is=s");
        }

		// ------------------------------------------------------------
		// VISUALIZER, only to check, disable or "segmentation fault"
		// ------------------------------------------------------------
        //visualizer: IntegratedCanvasVisualizer {
        //    @display("p=400,500");
        //}

        // ----------------------------------
        // for ground, heights, etc...
        // ----------------------------------
        physicalEnvironment: PhysicalEnvironment {
            parameters:
                @display("p=500,500");
        }
}

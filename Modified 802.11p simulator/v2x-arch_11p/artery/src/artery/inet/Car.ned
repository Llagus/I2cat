package artery.inet;

import artery.application.ItsG5Middleware;
import artery.nic.IRadioDriver;
import inet.node.inet.INetworkNode;
import inet.linklayer.contract.IWirelessNic;
import inet.mobility.contract.IMobility;
import inet.networklayer.common.InterfaceTable;

module Car like INetworkNode
{


    parameters:

        @display("i=block/wrxtx;is=vs");
        @networkNode;
        @labels(node,ethernet-node,wireless-node);
        int numRadios = default(1);
        *.interfaceTableModule = default(absPath(".interfaceTable"));
        mobility.visualRepresentation = "^";



    gates:

        input radioIn[numRadios] @directIn;
        inout pppg[] @labels(PPPFrame-conn);
        inout ethg[] @labels(EtherFrame-conn);



    submodules:

        // -----------------------------------
        //      @IP and @MAC
        // -----------------------------------
        interfaceTable: InterfaceTable {
            parameters:
                @display("p=53,300;is=s");
        }


		// -----------------------------------
		// 			Nic
		// -----------------------------------
        wlan[numRadios]: <default("VanetNic")> like IWirelessNic {
            parameters:
                @display("p=216,406,row,60;q=queue");
        }


        // -----------------------------------
        //          mobility
        // -----------------------------------
        mobility: <default("artery.inet.Mobility")> like IMobility {
            parameters:
                @display("p=53,200");
        }


		// ----------------------------------------------
		//        radioDriver is just below middleware
		// ----------------------------------------------
        radioDriver[numRadios]: InetRadioDriver {
            parameters:
                macModule = ".wlan[" + string(index) + "].mac";
                @display("p=216,269");
        }


		// -----------------------------------------------
		//	       application layer
		// -----------------------------------------------
        middleware: ItsG5Middleware {
            parameters:
                // radioDriver is above
                radioDriverModule = ".radioDriver[0]";
                mobilityModule = ".mobility";
                @display("p=216,139");
        }



    // -------------------------------------------------
    //  frame path: middleware <-> radioDriver <-> wlan         
    // -------------------------------------------------
    connections:

        // ·······································································
        // LOWER part of radioDriver ("radioIn" is gate here, "wlan" is VanetNIC)
        // ·························..............................................
        for i=0..sizeof(radioIn)-1 
        {
            radioIn[i] --> { @display("m=s"); } --> wlan[i].radioIn;
            wlan[i].upperLayerOut --> radioDriver[i].lowerLayerIn;
            wlan[i].upperLayerIn <-- radioDriver[i].lowerLayerOut;
        }


        // ··················································
        // UPPER part of radioDriver, $naming, when "inout"
        // ··················································
        middleware.radioDriverOut --> radioDriver[0].middleware$i;
        middleware.radioDriverIn <-- radioDriver[0].middleware$o;
}

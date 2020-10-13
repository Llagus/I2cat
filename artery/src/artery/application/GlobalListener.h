//~ joaquim: listener for packet latencies


#ifndef __ARTERY_GLOBALLISTENER_H_
#define __ARTERY_GLOBALLISTENER_H_

#include <omnetpp.h>

using namespace omnetpp;



// maps: long vdp.id (sumo) to node_name (omnet) &&  node_name (omnet) to node_latencies 
typedef std::map<long, std::string>             cam_VDP_2_node_Table;

typedef std::map<std::string, simtime_t>        cam_nodesLatencies;
typedef std::map<std::string, bool>             cam_nodesLatenciesFlags;
typedef std::map<std::string, cOutVector>       cam_nodesLatenciesVectors;
typedef std::map<std::string, cLongHistogram>   cam_nodesLatenciesHistogs;

typedef std::map<std::string, int>              cam_nodesLostinARow;
typedef std::map<std::string, bool>             cam_nodesLostFlags;
typedef std::map<std::string, cOutVector>       cam_nodesLostInARowVectors;
typedef std::map<std::string, cLongHistogram>   cam_nodesLostInARowHistogs;


typedef std::map<long, std::string>             denm_VDP_2_node_Table;
typedef std::map<std::string, simtime_t>        denm_nodesLatencies;
typedef std::map<std::string, bool>             denm_nodesLatenciesFlags;
typedef std::map<std::string, int>              denm_nodesLostinARow;
typedef std::map<std::string, cOutVector>       denm_nodesLatenciesVectors;
typedef std::map<std::string, cLongHistogram>   denm_nodesLostInARowHistogs;




class GlobalListener: public cSimpleModule 
{
protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void finish();

    cam_VDP_2_node_Table 		cam_vdp_node_table;
    
    cam_nodesLatencies 			cam_nodes_latencies_values;
    cam_nodesLatenciesFlags		cam_nodes_latencies_flags;
    cam_nodesLatenciesVectors   cam_nodes_latencies_vectors;
    cam_nodesLatenciesHistogs   cam_nodes_latencies_histograms;
    
    cam_nodesLostinARow         cam_nodes_lost_in_a_row;
    cam_nodesLostFlags          cam_nodes_lose_this_packet;
    cam_nodesLostInARowVectors  cam_nodes_lost_in_a_row_vectors;
    cam_nodesLostInARowHistogs  cam_nodes_lost_in_a_row_histograms;
    

    denm_VDP_2_node_Table        denm_vdp_node_table;
    denm_nodesLatencies          denm_nodes_latencies_values;
    denm_nodesLatenciesFlags     denm_nodes_latencies_flags;
    denm_nodesLostinARow         denm_nodes_lost_in_a_row;
    denm_nodesLatenciesVectors   denm_nodes_latencies_vectors;
    denm_nodesLostInARowHistogs  denm_nodes_lost_in_a_row_histograms;


public:
	GlobalListener();
    void cam_startLatency(long vdp_id, std::string node_id);
    void cam_finishLatency(long vdp_id, std::string node_id);

    void denm_startLatency(long vdp_id, std::string node_id);
    void denm_finishLatency(long vdp_id, std::string node_id);};


#endif

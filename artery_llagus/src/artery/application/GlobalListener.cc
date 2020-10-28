#include "GlobalListener.h"


using namespace omnetpp;

Define_Module(GlobalListener);

GlobalListener::GlobalListener(){}

void GlobalListener::initialize() {}

void GlobalListener::handleMessage(cMessage *msg) {}


// "vdp_id" is sumo ID of the local node, "node_id" is the OMNET ID of the local node
void GlobalListener::cam_startLatency(long vdp_id, std::string node_id)
{
    Enter_Method_Silent();

    bool newly_added_node = false;

    // when a node is newly seen
    if (cam_vdp_node_table.find(vdp_id) == cam_vdp_node_table.end())
    {
        // insert it in database
        cam_vdp_node_table[vdp_id] = node_id;
        newly_added_node           = true;

        // aesthetics + appearance for vectors & histograms
        EV_WARN << "--> GlobalListener_CAM - inserting new node (" << vdp_id  << ", " << node_id << ")" << endl;
        cam_nodes_latencies_vectors[node_id].setName((node_id + "_cam_latency:vector").c_str());
        cam_nodes_lost_in_a_row_vectors[node_id].setName((node_id + "_cam_lostinarow:vector").c_str());
        cam_nodes_lost_in_a_row_histograms[node_id].setNumCells(8);
        cam_nodes_lost_in_a_row_histograms[node_id].setRange(1,9);
        cam_nodes_latencies_histograms[node_id].setNumCells(30);
        cam_nodes_latencies_histograms[node_id].setRange(0, 3000);
    }


    // provoke errors on purpose? this OR SENSITIVITY
    cam_nodes_lose_this_packet[node_id] = false;
    double my_error_rate = par("par_my_error_rate");
    if (uniform(0,1) < my_error_rate)
    {
        cam_nodes_lose_this_packet[node_id] = true;
    }


    // last packet was received OR node is brand new
    if (cam_nodes_latencies_flags[node_id] || newly_added_node)
    {
        // NO cumulative statistics for "lost_in_a_row"
        cam_nodes_lost_in_a_row_vectors[node_id].record(cam_nodes_lost_in_a_row[node_id]);
        if (simTime() >= getSimulation()->getWarmupPeriod())
            cam_nodes_lost_in_a_row_histograms[node_id].collect(cam_nodes_lost_in_a_row[node_id]);

        // start new packet tracking, stats already recorded in "finish_latency()" method
        cam_nodes_lost_in_a_row[node_id]    = 0;
        cam_nodes_latencies_flags[node_id]  = false;
        cam_nodes_latencies_values[node_id] = simTime();

        EV_WARN << "--> GlobalListener_CAM ("  << node_id  
                << ", "                        << vdp_id   
                << ") starting latency == "    << cam_nodes_latencies_values[node_id]
                << ", lose_this_packet == "    << cam_nodes_lose_this_packet[node_id]
                << endl;   
    }
    // last packet was lost, account for bad statistic
    else
    {
        if (simTime() >= getSimulation()->getWarmupPeriod())
            cam_nodes_lost_in_a_row[node_id] += 1;

        //~ including next line makes NO cumulative latencies upon error
        cam_nodes_latencies_values[node_id] = simTime();
    }
}



// start tracking a latency for a packet for a certain host
void GlobalListener::denm_startLatency(long vdp_id, std::string node_id) {}


// "vdp_id" is sumo ID of the remote node, "node_id" (not used) is the OMNET ID of the local node
void GlobalListener::cam_finishLatency(long vdp_id, std::string node_id)
{
    Enter_Method_Silent();

    // get remote node ("node_id" is the node in OMNET's naming convention)
    std::string remote_node_id   = cam_vdp_node_table[vdp_id];
    simtime_t original_latency   = cam_nodes_latencies_values[remote_node_id];
    simtime_t now_latency        = simTime();
    simtime_t calculated_latency = now_latency - original_latency;


    if (!cam_nodes_latencies_flags[remote_node_id])
    {
        // update latency value and statistics
        if (!cam_nodes_lose_this_packet[remote_node_id])
        {
            // signal packet as received and set calculated latency
            cam_nodes_latencies_flags[remote_node_id]  = true;
            cam_nodes_latencies_values[remote_node_id] = calculated_latency;

            // statistics for latencies
            cam_nodes_latencies_vectors[remote_node_id].record(calculated_latency);
            if (simTime() >= getSimulation()->getWarmupPeriod())
                cam_nodes_latencies_histograms[remote_node_id].collect(calculated_latency.dbl() * 1000000);
        }

        EV_WARN << "--> GlobalListener_CAM - "             << node_id  
                << ", recorded CALCULATED_latency for ("   << vdp_id
                << ", "                                    << remote_node_id  
                << ") is " << now_latency 
                << " - "   << original_latency  
                << " == "  << calculated_latency       
                << endl;
    }
}


void GlobalListener::denm_finishLatency(long vdp_id, std::string node_id) {}


// record the histograms
void GlobalListener::finish()
{
    for (auto it : cam_nodes_lost_in_a_row_histograms)
    {
        it.second.recordAs((it.first + "_cam_lost_in_a_row:histogram").c_str());
    }
    for (auto it : cam_nodes_latencies_histograms)
    {
        it.second.recordAs((it.first + "_cam_latencies:histogram").c_str());
    }
}

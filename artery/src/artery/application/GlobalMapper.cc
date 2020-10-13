#include "GlobalMapper.h"

#include "../../../src/artery/application/SystemMonitor.h"

using namespace omnetpp;

Define_Module(GlobalMapper);

GlobalMapper::GlobalMapper()
{
	node_number = 0;
	timeoutEvent = nullptr;	
}

void GlobalMapper::initialize() 
{
	timeout = 1.0;
    timeoutEvent = new cMessage("timeoutEvent");
    scheduleAt(simTime()+ timeout, timeoutEvent);
    num_nodes_vector.setName("num_nodes_vector");

    cModule * modSystemMonitor = getModuleByPath("<root>.SystemMonitor");
    if (modSystemMonitor) {
        systemMonitor = dynamic_cast<SystemMonitor*>(modSystemMonitor);
    } else {
        error("No SystemMonitor module.");
    }
}

void GlobalMapper::handleMessage(cMessage *msg) 
{
    if (msg == timeoutEvent) 
    {
        EV_ERROR << "--> GlobalMapper, node number = " << node_number << endl;
        scheduleAt(simTime()+timeout, timeoutEvent);
        num_nodes_vector.record(node_number);
    }
}

// updates this sending node to its latest position
void GlobalMapper::gm_update_pos(std::string mac, inet::Coord pos)
{
    Enter_Method_Silent();
    // EV_ERROR << "--> GlobalMapper updating " << mac << " to position " << pos << endl;
    mac_pos_table[mac] = pos;
}

inet::Coord GlobalMapper::gm_get_remote_pos(std::string mac)
{
    Enter_Method_Silent();
    // EV_ERROR << "--> GlobalMapper retrieving pos " << mac_pos_table[mac] << " for mac " << mac << endl;
    return mac_pos_table[mac];
}

// updates this sending node to its latest speed
void GlobalMapper::gm_update_vel(std::string mac, double vel)
{
    Enter_Method_Silent();
    // EV_ERROR << "--> GlobalMapper updating " << mac << " to speed " << vel << endl;
    mac_vel_table[mac] = vel;
}

double GlobalMapper::gm_get_remote_vel(std::string mac)
{
    Enter_Method_Silent();
    // EV_ERROR << "--> GlobalMapper retrieving vel " << mac_vel_table[mac] << " for mac " << mac << endl;
    return mac_vel_table[mac];
}

double GlobalMapper::gm_get_meters_btw(std::string mac, inet::Coord pos)
{
    Enter_Method_Silent();
    // EV_ERROR << "--> GlobalMapper error distance is " << pos.distance(mac_pos_table[mac]) << " meters away" << endl;
    return pos.distance(mac_pos_table[mac]);
}

void GlobalMapper::gm_increase_node_number()
{
    Enter_Method_Silent();
    node_number++;
    // EV_ERROR << "--> GlobalMapper, node number = " << node_number << endl;
}

void GlobalMapper::gm_decrease_node_number()
{
    Enter_Method_Silent();
    node_number--;
    // EV_ERROR << "--> GlobalMapper, node number = " << node_number << endl;
}

void GlobalMapper::finish()
{
    cancelAndDelete(timeoutEvent);
}

//GlobalMapper database
void GlobalMapper::gm_update_database(std::string mac, gm_database_t nodeX)
{
    Enter_Method_Silent();
    mac_database_table[mac] = nodeX;
}

cModule* GlobalMapper::gm_get_database_mod(std::string mac)
{
    Enter_Method_Silent();
    return mac_database_table[mac].mod;
}

const char* GlobalMapper::gm_get_database_name(std::string mac)
{
    Enter_Method_Silent();
    return mac_database_table[mac].name;
}

simtime_t GlobalMapper::gm_get_database_TxTime(std::string mac)
{
    Enter_Method_Silent();
    return mac_database_table[mac].TxTime;
}

inet::Coord GlobalMapper::gm_get_database_TxPos(std::string mac)
{
    Enter_Method_Silent();
    return mac_database_table[mac].TxPos;
}

double GlobalMapper::gm_get_database_TxVel(std::string mac)
{
    Enter_Method_Silent();
    return mac_database_table[mac].TxVel;
}

void GlobalMapper::gm_del_entry(std::string mac)
{
    mac_database_table.erase(mac);
}

double GlobalMapper::gm_get_distance(inet::Coord pos1, inet::Coord pos2)
{
    Enter_Method_Silent();
    return pos1.distance(pos2);
}

void GlobalMapper::gm_traverse(inet::Coord mypos2, cModule* hostRx2)
{
    for(std::map<std::string, gm_database_t>::iterator mapIterator = mac_database_table.begin(); mapIterator != mac_database_table.end(); ++mapIterator)
    {
        if (mac_database_table[mapIterator->first].mod == nullptr){
            continue;
        }

        if (mac_database_table[mapIterator->first].mod == hostRx2){
            continue;
        }

        double NARActual_distance;
        NARActual_distance = std::abs(gm_get_distance(mypos2, mac_database_table[mapIterator->first].TxPos) );
        systemMonitor->NARActual(NARActual_distance);
    }
}
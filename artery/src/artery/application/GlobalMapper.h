//~ joaquim: listener for packet latencies

#ifndef __ARTERY_GLOBALMAPPER_H_
#define __ARTERY_GLOBALMAPPER_H_

#include <omnetpp.h>
#include "inet/mobility/contract/IMobility.h"

#include "../../../src/artery/application/SystemMonitor.h"

using namespace omnetpp;

// maps Mac@ to latest known position
typedef std::map<std::string, inet::Coord> mac_pos_table_t;
typedef std::map<std::string, double>      mac_vel_table_t;

//GlobalMapper database
struct gm_database_t{
    cModule* mod;
    const char* name;
    simtime_t TxTime;
    inet::Coord TxPos;
    double TxVel;
};
typedef std::map<std::string, gm_database_t> mac_database_table_t;

class GlobalMapper: public cSimpleModule 
{
private:
	mac_pos_table_t mac_pos_table; 
    mac_vel_table_t mac_vel_table;
    mac_database_table_t mac_database_table;

    int node_number;
    simtime_t timeout;  // timeout
    cMessage *timeoutEvent;  // holds pointer to the timeout self-message
    cOutVector num_nodes_vector;

protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void finish();

    SystemMonitor * systemMonitor;

public:
	GlobalMapper();

    void gm_update_pos(std::string, inet::Coord);
    void gm_update_vel(std::string, double);
    inet::Coord gm_get_remote_pos(std::string);
    double gm_get_remote_vel(std::string);
    double gm_get_meters_btw(std::string, inet::Coord);
    void gm_increase_node_number();
    void gm_decrease_node_number();

    void gm_update_database(std::string, gm_database_t);
    cModule* gm_get_database_mod(std::string);
    const char* gm_get_database_name(std::string);
    simtime_t gm_get_database_TxTime(std::string);
    inet::Coord gm_get_database_TxPos(std::string);
    double gm_get_database_TxVel(std::string);
    void gm_del_entry(std::string);

    double gm_get_distance(inet::Coord, inet::Coord);
    void gm_traverse(inet::Coord, cModule*);
};

#endif

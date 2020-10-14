//
// Generated file, do not edit! Created by nedtool 5.6 from /home/aniol/Documents/I2cat/artery/extern/inet/src/inet/routing/bgpv4/BGPCommon.msg.
//

#ifndef __INET__BGP_BGPCOMMON_M_H
#define __INET__BGP_BGPCOMMON_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0506
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif


namespace inet {
namespace bgp {

/**
 * Enum generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/routing/bgpv4/BGPCommon.msg:22</tt> by nedtool.
 * <pre>
 * enum BGPSessionType
 * {
 *     IGP = 0;
 *     EGP = 1;
 *     INCOMPLETE = 2;
 * }
 * </pre>
 */
enum BGPSessionType {
    IGP = 0,
    EGP = 1,
    INCOMPLETE = 2
};

/**
 * Enum generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/routing/bgpv4/BGPCommon.msg:29</tt> by nedtool.
 * <pre>
 * enum BGPPathSegmentType
 * {
 *     AS_SET = 1;
 *     AS_SEQUENCE = 2;
 * }
 * </pre>
 */
enum BGPPathSegmentType {
    AS_SET = 1,
    AS_SEQUENCE = 2
};

} // namespace bgp
} // namespace inet

#endif // ifndef __INET__BGP_BGPCOMMON_M_H


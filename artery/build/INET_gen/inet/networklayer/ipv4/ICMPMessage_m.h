//
// Generated file, do not edit! Created by nedtool 5.6 from /home/aniol/Documents/I2cat/artery/extern/inet/src/inet/networklayer/ipv4/ICMPMessage.msg.
//

#ifndef __INET_ICMPMESSAGE_M_H
#define __INET_ICMPMESSAGE_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0506
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif

// cplusplus {{
#include "inet/common/INETDefs.h"
// }}


namespace inet {

/**
 * Enum generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/networklayer/ipv4/ICMPMessage.msg:30</tt> by nedtool.
 * <pre>
 * //
 * // The real ICMP codes
 * //
 * enum ICMPType
 * {
 *     ICMP_DESTINATION_UNREACHABLE = 3;
 *     ICMP_SOURCEQUENCH = 4;               // packet lost, slow down
 *     ICMP_REDIRECT = 5;
 *     ICMP_ECHO_REQUEST = 8;
 *     ICMP_ROUTER_ADVERTISEMENT = 9;    // router advertisement
 *     ICMP_ROUTER_SOLICITATION = 10;    // router solicitation
 *     ICMP_TIME_EXCEEDED = 11;
 *     ICMP_PARAMETER_PROBLEM = 12;
 * 
 *     ICMP_ECHO_REPLY = 0;
 *     ICMP_TIMESTAMP_REQUEST = 13;
 *     ICMP_TIMESTAMP_REPLY = 14;
 *     ICMP_INFORMATION_REQUEST = 15;    // information request
 *     ICMP_INFORMATION_REPLY = 16;    // information reply
 *     ICMP_MASK_REQUEST = 17;    // address mask request
 *     ICMP_MASK_REPLY = 18;    // address mask reply
 * }
 * </pre>
 */
enum ICMPType {
    ICMP_DESTINATION_UNREACHABLE = 3,
    ICMP_SOURCEQUENCH = 4,
    ICMP_REDIRECT = 5,
    ICMP_ECHO_REQUEST = 8,
    ICMP_ROUTER_ADVERTISEMENT = 9,
    ICMP_ROUTER_SOLICITATION = 10,
    ICMP_TIME_EXCEEDED = 11,
    ICMP_PARAMETER_PROBLEM = 12,
    ICMP_ECHO_REPLY = 0,
    ICMP_TIMESTAMP_REQUEST = 13,
    ICMP_TIMESTAMP_REPLY = 14,
    ICMP_INFORMATION_REQUEST = 15,
    ICMP_INFORMATION_REPLY = 16,
    ICMP_MASK_REQUEST = 17,
    ICMP_MASK_REPLY = 18
};

/**
 * Enum generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/networklayer/ipv4/ICMPMessage.msg:51</tt> by nedtool.
 * <pre>
 * enum ICMPRedirectSubcodes
 * {
 *     ICMP_REDIRECT_NET = 0;    // for network
 *     ICMP_REDIRECT_HOST = 1;    // for host
 *     ICMP_REDIRECT_TOSNET = 2;    // for tos and net
 *     ICMP_REDIRECT_TOSHOST = 3;    // for tos and host
 * }
 * </pre>
 */
enum ICMPRedirectSubcodes {
    ICMP_REDIRECT_NET = 0,
    ICMP_REDIRECT_HOST = 1,
    ICMP_REDIRECT_TOSNET = 2,
    ICMP_REDIRECT_TOSHOST = 3
};

/**
 * Enum generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/networklayer/ipv4/ICMPMessage.msg:59</tt> by nedtool.
 * <pre>
 * enum ICMPTimeExceededSubcodes
 * {
 *     ICMP_TIMXCEED_INTRANS = 0;               // ttl==0 in transit
 *     ICMP_TIMXCEED_REASS = 1;               // ttl==0 in reass
 * }
 * </pre>
 */
enum ICMPTimeExceededSubcodes {
    ICMP_TIMXCEED_INTRANS = 0,
    ICMP_TIMXCEED_REASS = 1
};

/**
 * Enum generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/networklayer/ipv4/ICMPMessage.msg:65</tt> by nedtool.
 * <pre>
 * enum ICMPParameterProblemSubcodes
 * {
 *     ICMP_PARAMPROB_ERRATPTR = 0;    // error at param ptr
 *     ICMP_PARAMPROB_OPTABSENT = 1;    // req. opt. absent
 *     ICMP_PARAMPROB_LENGTH = 2;    // bad length
 * }
 * </pre>
 */
enum ICMPParameterProblemSubcodes {
    ICMP_PARAMPROB_ERRATPTR = 0,
    ICMP_PARAMPROB_OPTABSENT = 1,
    ICMP_PARAMPROB_LENGTH = 2
};

/**
 * Enum generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/networklayer/ipv4/ICMPMessage.msg:75</tt> by nedtool.
 * <pre>
 * //
 * // Codes for type ICMP_DESTINATION_UNREACHABLE
 * //
 * enum ICMPDestinationUnreachableCodes
 * {
 *     ICMP_DU_NETWORK_UNREACHABLE = 0;
 *     ICMP_DU_HOST_UNREACHABLE = 1;
 *     ICMP_DU_PROTOCOL_UNREACHABLE = 2;
 *     ICMP_DU_PORT_UNREACHABLE = 3;
 *     ICMP_DU_FRAGMENTATION_NEEDED = 4;
 *     ICMP_DU_SOURCE_ROUTE_FAILED = 5;
 *     ICMP_DU_DESTINATION_NETWORK_UNKNOWN = 6;
 *     ICMP_DU_DESTINATION_HOST_UNKNOWN = 7;
 *     ICMP_DU_SOURCE_HOST_ISOLATED = 8;
 *     ICMP_DU_NETWORK_PROHIBITED = 9;
 *     ICMP_DU_HOST_PROHIBITED = 10;
 *     ICMP_DU_NETWORK_UNREACHABLE_FOR_TYPE_OF_SERVICE = 11;
 *     ICMP_DU_HOST_UNREACHABLE_FOR_TYPE_OF_SERVICE = 12;
 *     ICMP_DU_COMMUNICATION_PROHIBITED = 13;
 *     ICMP_DU_HOST_PRECEDENCE_VIOLATION = 14;
 *     ICMP_DU_PRECEDENCE_CUTOFF_IN_EFFECT = 15;
 *     ICMP_AODV_QUEUE_FULL = 16;
 * }
 * </pre>
 */
enum ICMPDestinationUnreachableCodes {
    ICMP_DU_NETWORK_UNREACHABLE = 0,
    ICMP_DU_HOST_UNREACHABLE = 1,
    ICMP_DU_PROTOCOL_UNREACHABLE = 2,
    ICMP_DU_PORT_UNREACHABLE = 3,
    ICMP_DU_FRAGMENTATION_NEEDED = 4,
    ICMP_DU_SOURCE_ROUTE_FAILED = 5,
    ICMP_DU_DESTINATION_NETWORK_UNKNOWN = 6,
    ICMP_DU_DESTINATION_HOST_UNKNOWN = 7,
    ICMP_DU_SOURCE_HOST_ISOLATED = 8,
    ICMP_DU_NETWORK_PROHIBITED = 9,
    ICMP_DU_HOST_PROHIBITED = 10,
    ICMP_DU_NETWORK_UNREACHABLE_FOR_TYPE_OF_SERVICE = 11,
    ICMP_DU_HOST_UNREACHABLE_FOR_TYPE_OF_SERVICE = 12,
    ICMP_DU_COMMUNICATION_PROHIBITED = 13,
    ICMP_DU_HOST_PRECEDENCE_VIOLATION = 14,
    ICMP_DU_PRECEDENCE_CUTOFF_IN_EFFECT = 15,
    ICMP_AODV_QUEUE_FULL = 16
};

// cplusplus {{
typedef int ICMPCode;

inline bool isIcmpInfoType(int type)
{
    return (type == ICMP_ECHO_REPLY
            || type == ICMP_ECHO_REQUEST
            || type == ICMP_ROUTER_ADVERTISEMENT
            || type == ICMP_ROUTER_SOLICITATION
            || type == ICMP_TIMESTAMP_REQUEST
            || type == ICMP_TIMESTAMP_REPLY
            || type == ICMP_INFORMATION_REQUEST
            || type == ICMP_INFORMATION_REPLY
            || type == ICMP_MASK_REQUEST
            || type == ICMP_MASK_REPLY);
}
// }}

/**
 * Class generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/networklayer/ipv4/ICMPMessage.msg:123</tt> by nedtool.
 * <pre>
 * //
 * // ICMP message class
 * //
 * // Note: receiver MUST NOT decapsulate the datagram from ICMP error messages,
 * // because their contents is conceptually truncated. decapsulate() would result
 * // in a "length became negative" error; use getEncapsulatedMsg() instead.
 * //
 * // TODO: add originator id and sequence number and create an ICMPControlInfo
 * packet ICMPMessage
 * {
 *     int type \@enum(ICMPType);
 *     int code;
 * }
 * </pre>
 */
class ICMPMessage : public ::omnetpp::cPacket
{
  protected:
    int type;
    int code;

  private:
    void copy(const ICMPMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const ICMPMessage&);

  public:
    ICMPMessage(const char *name=nullptr, short kind=0);
    ICMPMessage(const ICMPMessage& other);
    virtual ~ICMPMessage();
    ICMPMessage& operator=(const ICMPMessage& other);
    virtual ICMPMessage *dup() const override {return new ICMPMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getType() const;
    virtual void setType(int type);
    virtual int getCode() const;
    virtual void setCode(int code);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const ICMPMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, ICMPMessage& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_ICMPMESSAGE_M_H


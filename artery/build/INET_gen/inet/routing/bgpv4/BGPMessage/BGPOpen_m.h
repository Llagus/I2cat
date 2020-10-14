//
// Generated file, do not edit! Created by nedtool 5.6 from /home/aniol/Documents/I2cat/artery/extern/inet/src/inet/routing/bgpv4/BGPMessage/BGPOpen.msg.
//

#ifndef __INET__BGP_BGPOPEN_M_H
#define __INET__BGP_BGPOPEN_M_H

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
#include "inet/routing/bgpv4/BGPMessage/BGPHeader_m.h"
#include "inet/networklayer/contract/ipv4/IPv4Address.h"

namespace inet { namespace bgp { const int BGP_OPEN_OCTETS = 10; } }
// }}


namespace inet {
namespace bgp {

/**
 * Struct generated from /home/aniol/Documents/I2cat/artery/extern/inet/src/inet/routing/bgpv4/BGPMessage/BGPOpen.msg:34 by nedtool.
 */
struct BGPParameterValues
{
    BGPParameterValues();
    short authCode;
    long authenticationData;
};

// helpers for local use
void __doPacking(omnetpp::cCommBuffer *b, const BGPParameterValues& a);
void __doUnpacking(omnetpp::cCommBuffer *b, BGPParameterValues& a);

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BGPParameterValues& obj) { __doPacking(b, obj); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BGPParameterValues& obj) { __doUnpacking(b, obj); }

/**
 * Struct generated from /home/aniol/Documents/I2cat/artery/extern/inet/src/inet/routing/bgpv4/BGPMessage/BGPOpen.msg:40 by nedtool.
 */
struct BGPOptionalParameters
{
    BGPOptionalParameters();
    short parameterType;
    unsigned short parameterLength;
    BGPParameterValues parameterValues;
};

// helpers for local use
void __doPacking(omnetpp::cCommBuffer *b, const BGPOptionalParameters& a);
void __doUnpacking(omnetpp::cCommBuffer *b, BGPOptionalParameters& a);

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BGPOptionalParameters& obj) { __doPacking(b, obj); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BGPOptionalParameters& obj) { __doUnpacking(b, obj); }

/**
 * Class generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/routing/bgpv4/BGPMessage/BGPOpen.msg:64</tt> by nedtool.
 * <pre>
 * //
 * // Represents a BGPv4 OPEN message.
 * //
 * // Fields modelled:
 * // - Version: 1 octet (BGP version)
 * // - My Autonomous system: 2 octets  (AS of the sender)
 * // - Hold Time: 2 octets (nbr de secondes que l'emetteur propose pour le compteur de renetue)
 * // - BGP Identifier: 4 octets
 * // - Optional Param Length: 1 octet (if = 0, no optional parameters)
 * // - Optional Parameters:
 * //    - Parameter Type
 * //    - Parameter Length
 * //    - Parameter Values (variable size)
 * //    - Auth code
 * //    - Authentication Data
 * //
 * packet BGPOpenMessage extends BGPHeader
 * {
 *     \@omitGetVerb(true);
 *     \@fieldNameSuffix("_var");
 *     type = BGP_OPEN;
 *     byteLength = BGP_HEADER_OCTETS + BGP_OPEN_OCTETS;
 * 
 *     char version = 4;
 *     unsigned short myAS;
 *     simtime_t holdTime;
 *     IPv4Address BGPIdentifier;
 *     BGPOptionalParameters optionalParameters[];
 * }
 * </pre>
 */
class BGPOpenMessage : public ::inet::bgp::BGPHeader
{
  protected:
    char version_var;
    unsigned short myAS_var;
    ::omnetpp::simtime_t holdTime_var;
    IPv4Address BGPIdentifier_var;
    BGPOptionalParameters *optionalParameters_var; // array ptr
    unsigned int optionalParameters_arraysize;

  private:
    void copy(const BGPOpenMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const BGPOpenMessage&);

  public:
    BGPOpenMessage(const char *name=nullptr, short kind=0);
    BGPOpenMessage(const BGPOpenMessage& other);
    virtual ~BGPOpenMessage();
    BGPOpenMessage& operator=(const BGPOpenMessage& other);
    virtual BGPOpenMessage *dup() const override {return new BGPOpenMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual char version() const;
    virtual void setVersion(char version);
    virtual unsigned short myAS() const;
    virtual void setMyAS(unsigned short myAS);
    virtual ::omnetpp::simtime_t holdTime() const;
    virtual void setHoldTime(::omnetpp::simtime_t holdTime);
    virtual IPv4Address& BGPIdentifier();
    virtual const IPv4Address& BGPIdentifier() const {return const_cast<BGPOpenMessage*>(this)->BGPIdentifier();}
    virtual void setBGPIdentifier(const IPv4Address& BGPIdentifier);
    virtual void setOptionalParametersArraySize(unsigned int size);
    virtual unsigned int optionalParametersArraySize() const;
    virtual BGPOptionalParameters& optionalParameters(unsigned int k);
    virtual const BGPOptionalParameters& optionalParameters(unsigned int k) const {return const_cast<BGPOpenMessage*>(this)->optionalParameters(k);}
    virtual void setOptionalParameters(unsigned int k, const BGPOptionalParameters& optionalParameters);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BGPOpenMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BGPOpenMessage& obj) {obj.parsimUnpack(b);}

} // namespace bgp
} // namespace inet

#endif // ifndef __INET__BGP_BGPOPEN_M_H


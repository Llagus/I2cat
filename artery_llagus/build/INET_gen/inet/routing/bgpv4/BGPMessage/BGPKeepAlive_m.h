//
// Generated file, do not edit! Created by nedtool 5.6 from /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/inet/src/inet/routing/bgpv4/BGPMessage/BGPKeepAlive.msg.
//

#ifndef __INET__BGP_BGPKEEPALIVE_M_H
#define __INET__BGP_BGPKEEPALIVE_M_H

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
// }}


namespace inet {
namespace bgp {

/**
 * Class generated from <tt>/home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/inet/src/inet/routing/bgpv4/BGPMessage/BGPKeepAlive.msg:33</tt> by nedtool.
 * <pre>
 * //
 * // Represents a BGPv4 KEEPALIVE message.
 * //
 * // KEEPALIVE messages are exchanged as often as necessary between systems
 * // to avoid exceeding the BGP Hold Timer (constant defined in BGPOpen).
 * //
 * packet BGPKeepAliveMessage extends BGPHeader
 * {
 *     type = BGP_KEEPALIVE;
 * }
 * </pre>
 */
class BGPKeepAliveMessage : public ::inet::bgp::BGPHeader
{
  protected:

  private:
    void copy(const BGPKeepAliveMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const BGPKeepAliveMessage&);

  public:
    BGPKeepAliveMessage(const char *name=nullptr, short kind=0);
    BGPKeepAliveMessage(const BGPKeepAliveMessage& other);
    virtual ~BGPKeepAliveMessage();
    BGPKeepAliveMessage& operator=(const BGPKeepAliveMessage& other);
    virtual BGPKeepAliveMessage *dup() const override {return new BGPKeepAliveMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BGPKeepAliveMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BGPKeepAliveMessage& obj) {obj.parsimUnpack(b);}

} // namespace bgp
} // namespace inet

#endif // ifndef __INET__BGP_BGPKEEPALIVE_M_H


//
// Generated file, do not edit! Created by nedtool 5.6 from /home/aniol/Documents/I2cat/artery/extern/inet/src/inet/networklayer/contract/ipv4/IPv4ControlInfo.msg.
//

#ifndef __INET_IPV4CONTROLINFO_M_H
#define __INET_IPV4CONTROLINFO_M_H

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
#include "inet/networklayer/contract/ipv4/IPv4Address.h"
#include "inet/networklayer/common/IPProtocolId_m.h"
#include "inet/linklayer/common/MACAddress.h"
// }}


namespace inet {

/**
 * Class generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/networklayer/contract/ipv4/IPv4ControlInfo.msg:63</tt> by nedtool.
 * <pre>
 * //
 * // Control information for sending/receiving packets over IPv4.
 * //
 * // To send a packet over IPv4, fill in an ~IPv4ControlInfo object,
 * // attach it to the packet with the C++ method setControlInfo(),
 * // the send it to the ~IPv4 module.
 * //
 * // When sending, the following fields are required:
 * // - protocol: a value from ~IPProtocolId
 * // - destAddr
 * //
 * // Optional fields:
 * // - srcAddr: it will be set to the address of the outgoing interface
 * // - typeOfService: (default: 0)
 * // - timeToLive: default defined as module parameter
 * // - dontFragment: default: false
 * //
 * // Not supported:
 * // - options: IPv4 Options currently not used
 * // - Identifier is currently always chosen by the IPv4 layer
 * //
 * // When ~IPv4 delivers a packet to higher layers, it also attaches an ~IPv4ControlInfo
 * // to it. It fills in the following fields:
 * //  - srcAddr, destAddr, protocol, TypeOfService: values from the original datagram
 * //  - interfaceId: the interface on which the datagram arrived, or -1 if it was
 * //    created locally
 * //
 * // ~IPv4 also puts the original datagram object into the control info, because
 * // it may be needed by higher layers (for example, by ~ICMP for error reporting).
 * //
 * class IPv4ControlInfo
 * {
 *     \@customize(true);
 *     IPv4Address destAddr;   // destination IPv4 address
 *     IPv4Address srcAddr;    // source IPv4 address
 *     int interfaceId = -1; // interface on which the datagram was received, or
 *                           // should be sent (see ~InterfaceTable)
 *     bool multicastLoop;   // if true, sent multicast datagrams will be looped back
 *     short protocol \@enum(IPProtocolId);  // encapsulated protocol
 *     unsigned char typeOfService;  // Type of Service byte (low 6 bits: DSCP)
 *     abstract int diffServCodePoint;  // maps to bits 0-5 of trafficClass
 *     abstract int explicitCongestionNotification;  // maps to bits 6-7 of trafficClass
 *     short timeToLive;     // maximum hop count
 *     bool dontFragment;    // "don't fragment" bit
 * }
 * </pre>
 *
 * IPv4ControlInfo_Base is only useful if it gets subclassed, and IPv4ControlInfo is derived from it.
 * The minimum code to be written for IPv4ControlInfo is the following:
 *
 * <pre>
 * class IPv4ControlInfo : public IPv4ControlInfo_Base
 * {
 *   private:
 *     void copy(const IPv4ControlInfo& other) { ... }

 *   public:
 *     IPv4ControlInfo() : IPv4ControlInfo_Base() {}
 *     IPv4ControlInfo(const IPv4ControlInfo& other) : IPv4ControlInfo_Base(other) {copy(other);}
 *     IPv4ControlInfo& operator=(const IPv4ControlInfo& other) {if (this==&other) return *this; IPv4ControlInfo_Base::operator=(other); copy(other); return *this;}
 *     virtual IPv4ControlInfo *dup() const override {return new IPv4ControlInfo(*this);}
 *     // ADD CODE HERE to redefine and implement pure virtual functions from IPv4ControlInfo_Base
 * };
 * </pre>
 *
 * The following should go into a .cc (.cpp) file:
 *
 * <pre>
 * Register_Class(IPv4ControlInfo)
 * </pre>
 */
class IPv4ControlInfo_Base : public ::omnetpp::cObject
{
  protected:
    IPv4Address destAddr;
    IPv4Address srcAddr;
    int interfaceId;
    bool multicastLoop;
    short protocol;
    unsigned char typeOfService;
    short timeToLive;
    bool dontFragment;

  private:
    void copy(const IPv4ControlInfo_Base& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const IPv4ControlInfo_Base&);
    // make constructors protected to avoid instantiation
    IPv4ControlInfo_Base();
    IPv4ControlInfo_Base(const IPv4ControlInfo_Base& other);
    // make assignment operator protected to force the user override it
    IPv4ControlInfo_Base& operator=(const IPv4ControlInfo_Base& other);

  public:
    virtual ~IPv4ControlInfo_Base();
    virtual IPv4ControlInfo_Base *dup() const override {throw omnetpp::cRuntimeError("You forgot to manually add a dup() function to class IPv4ControlInfo");}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual IPv4Address& getDestAddr();
    virtual const IPv4Address& getDestAddr() const {return const_cast<IPv4ControlInfo_Base*>(this)->getDestAddr();}
    virtual void setDestAddr(const IPv4Address& destAddr);
    virtual IPv4Address& getSrcAddr();
    virtual const IPv4Address& getSrcAddr() const {return const_cast<IPv4ControlInfo_Base*>(this)->getSrcAddr();}
    virtual void setSrcAddr(const IPv4Address& srcAddr);
    virtual int getInterfaceId() const;
    virtual void setInterfaceId(int interfaceId);
    virtual bool getMulticastLoop() const;
    virtual void setMulticastLoop(bool multicastLoop);
    virtual short getProtocol() const;
    virtual void setProtocol(short protocol);
    virtual unsigned char getTypeOfService() const;
    virtual void setTypeOfService(unsigned char typeOfService);
    virtual int getDiffServCodePoint() const = 0;
    virtual void setDiffServCodePoint(int diffServCodePoint) = 0;
    virtual int getExplicitCongestionNotification() const = 0;
    virtual void setExplicitCongestionNotification(int explicitCongestionNotification) = 0;
    virtual short getTimeToLive() const;
    virtual void setTimeToLive(short timeToLive);
    virtual bool getDontFragment() const;
    virtual void setDontFragment(bool dontFragment);
};

} // namespace inet

#endif // ifndef __INET_IPV4CONTROLINFO_M_H


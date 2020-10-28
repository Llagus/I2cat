//
// Generated file, do not edit! Created by nedtool 5.6 from /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/inet/src/inet/linklayer/base/MACFrameBase.msg.
//

#ifndef __INET_MACFRAMEBASE_M_H
#define __INET_MACFRAMEBASE_M_H

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
   #include "inet/linklayer/common/MACAddress.h"
// }}


namespace inet {

/**
 * Class generated from <tt>/home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/inet/src/inet/linklayer/base/MACFrameBase.msg:27</tt> by nedtool.
 * <pre>
 * packet MACFrameBase
 * {
 *     MACAddress srcAddr;
 *     MACAddress destAddr;
 * }
 * </pre>
 */
class MACFrameBase : public ::omnetpp::cPacket
{
  protected:
    MACAddress srcAddr;
    MACAddress destAddr;

  private:
    void copy(const MACFrameBase& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const MACFrameBase&);

  public:
    MACFrameBase(const char *name=nullptr, short kind=0);
    MACFrameBase(const MACFrameBase& other);
    virtual ~MACFrameBase();
    MACFrameBase& operator=(const MACFrameBase& other);
    virtual MACFrameBase *dup() const override {return new MACFrameBase(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual MACAddress& getSrcAddr();
    virtual const MACAddress& getSrcAddr() const {return const_cast<MACFrameBase*>(this)->getSrcAddr();}
    virtual void setSrcAddr(const MACAddress& srcAddr);
    virtual MACAddress& getDestAddr();
    virtual const MACAddress& getDestAddr() const {return const_cast<MACFrameBase*>(this)->getDestAddr();}
    virtual void setDestAddr(const MACAddress& destAddr);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const MACFrameBase& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, MACFrameBase& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_MACFRAMEBASE_M_H


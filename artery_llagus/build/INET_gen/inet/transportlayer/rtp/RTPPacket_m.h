//
// Generated file, do not edit! Created by nedtool 5.6 from /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/inet/src/inet/transportlayer/rtp/RTPPacket.msg.
//

#ifndef __INET__RTP_RTPPACKET_M_H
#define __INET__RTP_RTPPACKET_M_H

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
namespace rtp {

/**
 * Enum generated from <tt>/home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/inet/src/inet/transportlayer/rtp/RTPPacket.msg:27</tt> by nedtool.
 * <pre>
 * enum RTPPacketEnums
 * {
 *     RTPPACKET_FIX_HEADERLENGTH = 12;
 * }
 * </pre>
 */
enum RTPPacketEnums {
    RTPPACKET_FIX_HEADERLENGTH = 12
};

/**
 * Class generated from <tt>/home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/inet/src/inet/transportlayer/rtp/RTPPacket.msg:40</tt> by nedtool.
 * <pre>
 * //
 * // This class represents an RTP data packet. Real data can either
 * // be encapsulated, or simulated by adding length.
 * //
 * // The following RTP header fields exist but aren't used:
 * // padding, extension, csrcCount. The csrcList can't be used
 * // because csrcCount is always 0.
 * //
 * packet RTPPacket
 * {
 *     \@customize(true);  // see the generated C++ header for more info
 * 
 *     byteLength = RTPPACKET_FIX_HEADERLENGTH;  // 12-byte fixed header
 * 
 *     // The rtp version of this ~RTPPacket.
 *     uint8 version = 2;
 * 
 *     // Set to 1 if padding is used in this ~RTPPacket, 0 otherwise.
 *     // This implementation doesn't use padding bytes, so it is always 0.
 *     bool padding = false;
 * 
 *     // Set to 1, if this ~RTPPacket contains an rtp header extension, 0 otherwise.
 *     // This implementation doesn't support rtp header extensions, so it is always 0.
 *     bool extension = false;
 * 
 *     // The marker.
 *     bool marker = false;
 * 
 *     // The type of payload carried in this ~RTPPacket.
 *     int8 payloadType;
 * 
 *     // The sequence number of this ~RTPPacket.
 *     uint16 sequenceNumber;
 * 
 *     // The rtp time stamp of this ~RTPPacket.
 *     uint32 timeStamp;
 * 
 *     // The ssrc identifier of the creator of this ~RTPPacket.
 *     uint32 ssrc;
 * 
 *     // no mixers, no contributing sources
 *     uint32 csrc[];
 * 
 *     abstract int headerLength;
 * 
 *     abstract int payloadLength;
 * }
 * </pre>
 *
 * RTPPacket_Base is only useful if it gets subclassed, and RTPPacket is derived from it.
 * The minimum code to be written for RTPPacket is the following:
 *
 * <pre>
 * class RTPPacket : public RTPPacket_Base
 * {
 *   private:
 *     void copy(const RTPPacket& other) { ... }

 *   public:
 *     RTPPacket(const char *name=nullptr, short kind=0) : RTPPacket_Base(name,kind) {}
 *     RTPPacket(const RTPPacket& other) : RTPPacket_Base(other) {copy(other);}
 *     RTPPacket& operator=(const RTPPacket& other) {if (this==&other) return *this; RTPPacket_Base::operator=(other); copy(other); return *this;}
 *     virtual RTPPacket *dup() const override {return new RTPPacket(*this);}
 *     // ADD CODE HERE to redefine and implement pure virtual functions from RTPPacket_Base
 * };
 * </pre>
 *
 * The following should go into a .cc (.cpp) file:
 *
 * <pre>
 * Register_Class(RTPPacket)
 * </pre>
 */
class RTPPacket_Base : public ::omnetpp::cPacket
{
  protected:
    uint8_t version;
    bool padding;
    bool extension;
    bool marker;
    int8_t payloadType;
    uint16_t sequenceNumber;
    uint32_t timeStamp;
    uint32_t ssrc;
    uint32_t *csrc; // array ptr
    unsigned int csrc_arraysize;

  private:
    void copy(const RTPPacket_Base& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const RTPPacket_Base&);
    // make constructors protected to avoid instantiation
    RTPPacket_Base(const char *name=nullptr, short kind=0);
    RTPPacket_Base(const RTPPacket_Base& other);
    // make assignment operator protected to force the user override it
    RTPPacket_Base& operator=(const RTPPacket_Base& other);

  public:
    virtual ~RTPPacket_Base();
    virtual RTPPacket_Base *dup() const override {throw omnetpp::cRuntimeError("You forgot to manually add a dup() function to class RTPPacket");}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual uint8_t getVersion() const;
    virtual void setVersion(uint8_t version);
    virtual bool getPadding() const;
    virtual void setPadding(bool padding);
    virtual bool getExtension() const;
    virtual void setExtension(bool extension);
    virtual bool getMarker() const;
    virtual void setMarker(bool marker);
    virtual int8_t getPayloadType() const;
    virtual void setPayloadType(int8_t payloadType);
    virtual uint16_t getSequenceNumber() const;
    virtual void setSequenceNumber(uint16_t sequenceNumber);
    virtual uint32_t getTimeStamp() const;
    virtual void setTimeStamp(uint32_t timeStamp);
    virtual uint32_t getSsrc() const;
    virtual void setSsrc(uint32_t ssrc);
    virtual void setCsrcArraySize(unsigned int size);
    virtual unsigned int getCsrcArraySize() const;
    virtual uint32_t getCsrc(unsigned int k) const;
    virtual void setCsrc(unsigned int k, uint32_t csrc);
    virtual int getHeaderLength() const = 0;
    virtual void setHeaderLength(int headerLength) = 0;
    virtual int getPayloadLength() const = 0;
    virtual void setPayloadLength(int payloadLength) = 0;
};

} // namespace rtp
} // namespace inet

#endif // ifndef __INET__RTP_RTPPACKET_M_H


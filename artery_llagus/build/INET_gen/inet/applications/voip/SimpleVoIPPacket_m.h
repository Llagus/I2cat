//
// Generated file, do not edit! Created by nedtool 5.6 from /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/inet/src/inet/applications/voip/SimpleVoIPPacket.msg.
//

#ifndef __INET_SIMPLEVOIPPACKET_M_H
#define __INET_SIMPLEVOIPPACKET_M_H

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

/**
 * Class generated from <tt>/home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/inet/src/inet/applications/voip/SimpleVoIPPacket.msg:25</tt> by nedtool.
 * <pre>
 * //
 * // Represents a voice packet used by SimpleVoIPSender / SimpleVoIPReceiver 
 * //
 * packet SimpleVoIPPacket
 * {
 *     unsigned int talkspurtID;          // identifies the talkspurt
 *     unsigned int talkspurtNumPackets;  // number of all packets of current talkspurt
 *     unsigned int packetID;             // 0..talkspurtNumPackets-1
 *     simtime_t voipTimestamp;            // "mouth" timestamp of begin of voice in this packet
 *     simtime_t voiceDuration;            // duration of voice in this packet
 * }
 * </pre>
 */
class SimpleVoIPPacket : public ::omnetpp::cPacket
{
  protected:
    unsigned int talkspurtID;
    unsigned int talkspurtNumPackets;
    unsigned int packetID;
    ::omnetpp::simtime_t voipTimestamp;
    ::omnetpp::simtime_t voiceDuration;

  private:
    void copy(const SimpleVoIPPacket& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SimpleVoIPPacket&);

  public:
    SimpleVoIPPacket(const char *name=nullptr, short kind=0);
    SimpleVoIPPacket(const SimpleVoIPPacket& other);
    virtual ~SimpleVoIPPacket();
    SimpleVoIPPacket& operator=(const SimpleVoIPPacket& other);
    virtual SimpleVoIPPacket *dup() const override {return new SimpleVoIPPacket(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual unsigned int getTalkspurtID() const;
    virtual void setTalkspurtID(unsigned int talkspurtID);
    virtual unsigned int getTalkspurtNumPackets() const;
    virtual void setTalkspurtNumPackets(unsigned int talkspurtNumPackets);
    virtual unsigned int getPacketID() const;
    virtual void setPacketID(unsigned int packetID);
    virtual ::omnetpp::simtime_t getVoipTimestamp() const;
    virtual void setVoipTimestamp(::omnetpp::simtime_t voipTimestamp);
    virtual ::omnetpp::simtime_t getVoiceDuration() const;
    virtual void setVoiceDuration(::omnetpp::simtime_t voiceDuration);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SimpleVoIPPacket& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SimpleVoIPPacket& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_SIMPLEVOIPPACKET_M_H


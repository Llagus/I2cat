//
// Generated file, do not edit! Created by nedtool 5.6 from /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/inet/src/inet/applications/ethernet/EtherApp.msg.
//

#ifndef __INET_ETHERAPP_M_H
#define __INET_ETHERAPP_M_H

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

#define ETHERAPP_CLI_SAP  0xf0
#define ETHERAPP_SRV_SAP  0xf1
// }}


namespace inet {

/**
 * Class generated from <tt>/home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/inet/src/inet/applications/ethernet/EtherApp.msg:33</tt> by nedtool.
 * <pre>
 * //
 * // Request packet sent by ~EtherAppCli. Contains the number of bytes to be
 * // sent back as response; if this value is greater than ~1400, the reply
 * // will consist of several Ethernet frames. See also ~EtherAppResp.
 * //
 * packet EtherAppReq
 * {
 *     long requestId;
 *     long responseBytes;
 * }
 * </pre>
 */
class EtherAppReq : public ::omnetpp::cPacket
{
  protected:
    long requestId;
    long responseBytes;

  private:
    void copy(const EtherAppReq& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const EtherAppReq&);

  public:
    EtherAppReq(const char *name=nullptr, short kind=0);
    EtherAppReq(const EtherAppReq& other);
    virtual ~EtherAppReq();
    EtherAppReq& operator=(const EtherAppReq& other);
    virtual EtherAppReq *dup() const override {return new EtherAppReq(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual long getRequestId() const;
    virtual void setRequestId(long requestId);
    virtual long getResponseBytes() const;
    virtual void setResponseBytes(long responseBytes);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const EtherAppReq& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, EtherAppReq& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>/home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/inet/src/inet/applications/ethernet/EtherApp.msg:42</tt> by nedtool.
 * <pre>
 * //
 * // Packet sent back by ~EtherAppSrv in response to an ~EtherAppReq.
 * //
 * packet EtherAppResp
 * {
 *     int requestId;
 *     int numFrames;
 * }
 * </pre>
 */
class EtherAppResp : public ::omnetpp::cPacket
{
  protected:
    int requestId;
    int numFrames;

  private:
    void copy(const EtherAppResp& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const EtherAppResp&);

  public:
    EtherAppResp(const char *name=nullptr, short kind=0);
    EtherAppResp(const EtherAppResp& other);
    virtual ~EtherAppResp();
    EtherAppResp& operator=(const EtherAppResp& other);
    virtual EtherAppResp *dup() const override {return new EtherAppResp(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getRequestId() const;
    virtual void setRequestId(int requestId);
    virtual int getNumFrames() const;
    virtual void setNumFrames(int numFrames);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const EtherAppResp& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, EtherAppResp& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_ETHERAPP_M_H


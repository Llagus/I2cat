//
// Generated file, do not edit! Created by nedtool 5.6 from /home/aniol/Documents/I2cat/artery/extern/inet/src/inet/transportlayer/contract/sctp/SCTPCommand.msg.
//

#ifndef __INET_SCTPCOMMAND_M_H
#define __INET_SCTPCOMMAND_M_H

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
#include <vector>

#include "inet/networklayer/common/L3Address.h"
#include "inet/transportlayer/contract/sctp/SCTPCommand.h"
// }}


namespace inet {

// cplusplus {{
typedef std::vector<L3Address> AddressVector;
// }}

/**
 * Enum generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/transportlayer/contract/sctp/SCTPCommand.msg:41</tt> by nedtool.
 * <pre>
 * //
 * // Currently not in use.
 * //
 * enum SCTPErrorCode
 * {
 * }
 * </pre>
 */
enum SCTPErrorCode {
};

/**
 * Class generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/transportlayer/contract/sctp/SCTPCommand.msg:59</tt> by nedtool.
 * <pre>
 * //
 * // Control info for SCTP connections. This message is to be set as control info
 * // (see cMessage::setControlInfo()) on all messages exchanged between ~SCTP and
 * // application, in both directions. Some commands and indications
 * // (SCTP_C_OPEN_xxx, SCTP_I_STATUS) use submessagees.
 * //
 * // connId identifies the connection locally within the application (internally,
 * // ~SCTP uses the (app gate index, connId) pair to identify the socket).
 * // connId is to be chosen by the application in the open command.
 * //
 * // \@see ~SctpCommandCode, ~SctpStatusInd, ~SCTPOpenCommand, ~SCTPStatusInfo, SCTPMain
 * //
 * packet SCTPCommand
 * {
 *     int assocId = -1;   // identifies the socket within the application
 *     int sid = -1;
 *     int numMsgs = 1;
 *     int ssn = -1;
 *     unsigned short sendUnordered = false;
 *     double prValue = 0;
 *     L3Address localAddr;
 *     L3Address remoteAddr;
 *     int localPort = -1;
 *     int remotePort = -1;
 *     int gate = -1;
 *     int fd = -1;
 * }
 * </pre>
 */
class SCTPCommand : public ::omnetpp::cPacket
{
  protected:
    int assocId;
    int sid;
    int numMsgs;
    int ssn;
    unsigned short sendUnordered;
    double prValue;
    L3Address localAddr;
    L3Address remoteAddr;
    int localPort;
    int remotePort;
    int gate;
    int fd;

  private:
    void copy(const SCTPCommand& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPCommand&);

  public:
    SCTPCommand(const char *name=nullptr, short kind=0);
    SCTPCommand(const SCTPCommand& other);
    virtual ~SCTPCommand();
    SCTPCommand& operator=(const SCTPCommand& other);
    virtual SCTPCommand *dup() const override {return new SCTPCommand(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getAssocId() const;
    virtual void setAssocId(int assocId);
    virtual int getSid() const;
    virtual void setSid(int sid);
    virtual int getNumMsgs() const;
    virtual void setNumMsgs(int numMsgs);
    virtual int getSsn() const;
    virtual void setSsn(int ssn);
    virtual unsigned short getSendUnordered() const;
    virtual void setSendUnordered(unsigned short sendUnordered);
    virtual double getPrValue() const;
    virtual void setPrValue(double prValue);
    virtual L3Address& getLocalAddr();
    virtual const L3Address& getLocalAddr() const {return const_cast<SCTPCommand*>(this)->getLocalAddr();}
    virtual void setLocalAddr(const L3Address& localAddr);
    virtual L3Address& getRemoteAddr();
    virtual const L3Address& getRemoteAddr() const {return const_cast<SCTPCommand*>(this)->getRemoteAddr();}
    virtual void setRemoteAddr(const L3Address& remoteAddr);
    virtual int getLocalPort() const;
    virtual void setLocalPort(int localPort);
    virtual int getRemotePort() const;
    virtual void setRemotePort(int remotePort);
    virtual int getGate() const;
    virtual void setGate(int gate);
    virtual int getFd() const;
    virtual void setFd(int fd);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SCTPCommand& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SCTPCommand& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/transportlayer/contract/sctp/SCTPCommand.msg:78</tt> by nedtool.
 * <pre>
 * //
 * // Currently not in use.
 * //
 * message SCTPErrorInfo extends SCTPCommand
 * {
 *     int errorCode \@enum(SCTPErrorCode);
 *     string messageText;
 * }
 * </pre>
 */
class SCTPErrorInfo : public ::inet::SCTPCommand
{
  protected:
    int errorCode;
    ::omnetpp::opp_string messageText;

  private:
    void copy(const SCTPErrorInfo& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPErrorInfo&);

  public:
    SCTPErrorInfo(const char *name=nullptr, short kind=0);
    SCTPErrorInfo(const SCTPErrorInfo& other);
    virtual ~SCTPErrorInfo();
    SCTPErrorInfo& operator=(const SCTPErrorInfo& other);
    virtual SCTPErrorInfo *dup() const override {return new SCTPErrorInfo(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getErrorCode() const;
    virtual void setErrorCode(int errorCode);
    virtual const char * getMessageText() const;
    virtual void setMessageText(const char * messageText);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SCTPErrorInfo& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SCTPErrorInfo& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/transportlayer/contract/sctp/SCTPCommand.msg:110</tt> by nedtool.
 * <pre>
 * //
 * // Control info to be used for active or passive ~SCTP open.
 * //
 * // localAddr, remoteAddr, localPort, remotePort should be self-explanatory.
 * // localAddr is optional because ~SCTP can learn it from IP when a packet
 * // is received from the peer; localPort is optional because ~SCTP supports
 * // ephemeral ports.
 * //
 * // The sendQueueClass, receiveQueueClass and sctpAlgorithmClass fields
 * // allow per-connection ~SCTP configuration. These fields may contain
 * // names of messagees submessageed from SCTPSendQueue, SCTPReceiveQueue
 * // and SCTPAlgorithm, respectively. If not set, module parameters with
 * // similar names are used.
 * //
 * // The fork parameter is used with passive open, and controls what happens
 * // when an incoming connection is received. With fork=true, it emulates
 * // the Unix accept(2) syscall semantics: a new connection structure
 * // is created for the connection (with a new connId, see in ~SCTPCommand),
 * // and the connection structure with the old connId remains listening.
 * // With fork=false, all the above does not happen: the first connection
 * // is accepted (with the original connId), and further incoming connections
 * // will be refused by ~SCTP by sending an RST segment.
 * //
 * // \@see ~SctpCommandCode, ~SCTP
 * //
 * message SCTPOpenCommand extends SCTPCommand
 * {
 *     AddressVector localAddresses;
 *     AddressVector remoteAddresses;
 *     bool fork = false;               // used only for passive open
 *     string queueClass = "SCTPQueue"; // may be left empty
 *     string sctpAlgorithmClass;       // may be left empty
 *     uint32 inboundStreams;
 *     uint32 outboundStreams;
 *     bool streamReset;
 *     bool appLimited;
 *     int prMethod;
 *     uint32 numRequests;
 *     uint32 messagesToPush;
 * }
 * </pre>
 */
class SCTPOpenCommand : public ::inet::SCTPCommand
{
  protected:
    AddressVector localAddresses;
    AddressVector remoteAddresses;
    bool fork;
    ::omnetpp::opp_string queueClass;
    ::omnetpp::opp_string sctpAlgorithmClass;
    uint32_t inboundStreams;
    uint32_t outboundStreams;
    bool streamReset;
    bool appLimited;
    int prMethod;
    uint32_t numRequests;
    uint32_t messagesToPush;

  private:
    void copy(const SCTPOpenCommand& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPOpenCommand&);

  public:
    SCTPOpenCommand(const char *name=nullptr, short kind=0);
    SCTPOpenCommand(const SCTPOpenCommand& other);
    virtual ~SCTPOpenCommand();
    SCTPOpenCommand& operator=(const SCTPOpenCommand& other);
    virtual SCTPOpenCommand *dup() const override {return new SCTPOpenCommand(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual AddressVector& getLocalAddresses();
    virtual const AddressVector& getLocalAddresses() const {return const_cast<SCTPOpenCommand*>(this)->getLocalAddresses();}
    virtual void setLocalAddresses(const AddressVector& localAddresses);
    virtual AddressVector& getRemoteAddresses();
    virtual const AddressVector& getRemoteAddresses() const {return const_cast<SCTPOpenCommand*>(this)->getRemoteAddresses();}
    virtual void setRemoteAddresses(const AddressVector& remoteAddresses);
    virtual bool getFork() const;
    virtual void setFork(bool fork);
    virtual const char * getQueueClass() const;
    virtual void setQueueClass(const char * queueClass);
    virtual const char * getSctpAlgorithmClass() const;
    virtual void setSctpAlgorithmClass(const char * sctpAlgorithmClass);
    virtual uint32_t getInboundStreams() const;
    virtual void setInboundStreams(uint32_t inboundStreams);
    virtual uint32_t getOutboundStreams() const;
    virtual void setOutboundStreams(uint32_t outboundStreams);
    virtual bool getStreamReset() const;
    virtual void setStreamReset(bool streamReset);
    virtual bool getAppLimited() const;
    virtual void setAppLimited(bool appLimited);
    virtual int getPrMethod() const;
    virtual void setPrMethod(int prMethod);
    virtual uint32_t getNumRequests() const;
    virtual void setNumRequests(uint32_t numRequests);
    virtual uint32_t getMessagesToPush() const;
    virtual void setMessagesToPush(uint32_t messagesToPush);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SCTPOpenCommand& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SCTPOpenCommand& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/transportlayer/contract/sctp/SCTPCommand.msg:132</tt> by nedtool.
 * <pre>
 * //
 * // Control info to be used with the SEND command.
 * //
 * // \@see ~SctpCommandCode, ~SCTP
 * //
 * message SCTPSendInfo extends SCTPCommand
 * {
 *     unsigned int prMethod;
 *     bool last;
 *     unsigned int ppid = 0;
 *     bool primary = true;
 *     bool sackNow = false;
 * }
 * </pre>
 */
class SCTPSendInfo : public ::inet::SCTPCommand
{
  protected:
    unsigned int prMethod;
    bool last;
    unsigned int ppid;
    bool primary;
    bool sackNow;

  private:
    void copy(const SCTPSendInfo& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPSendInfo&);

  public:
    SCTPSendInfo(const char *name=nullptr, short kind=0);
    SCTPSendInfo(const SCTPSendInfo& other);
    virtual ~SCTPSendInfo();
    SCTPSendInfo& operator=(const SCTPSendInfo& other);
    virtual SCTPSendInfo *dup() const override {return new SCTPSendInfo(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual unsigned int getPrMethod() const;
    virtual void setPrMethod(unsigned int prMethod);
    virtual bool getLast() const;
    virtual void setLast(bool last);
    virtual unsigned int getPpid() const;
    virtual void setPpid(unsigned int ppid);
    virtual bool getPrimary() const;
    virtual void setPrimary(bool primary);
    virtual bool getSackNow() const;
    virtual void setSackNow(bool sackNow);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SCTPSendInfo& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SCTPSendInfo& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/transportlayer/contract/sctp/SCTPCommand.msg:146</tt> by nedtool.
 * <pre>
 * //
 * // Control info to be used when setsockopt changes RtoInfo.
 * //
 * // \@see ~SctpCommandCode, ~SCTP
 * //
 * message SCTPRtoInfo extends SCTPCommand
 * {
 *     double rtoInitial;
 *     double rtoMin;
 *     double rtoMax;
 * }
 * </pre>
 */
class SCTPRtoInfo : public ::inet::SCTPCommand
{
  protected:
    double rtoInitial;
    double rtoMin;
    double rtoMax;

  private:
    void copy(const SCTPRtoInfo& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPRtoInfo&);

  public:
    SCTPRtoInfo(const char *name=nullptr, short kind=0);
    SCTPRtoInfo(const SCTPRtoInfo& other);
    virtual ~SCTPRtoInfo();
    SCTPRtoInfo& operator=(const SCTPRtoInfo& other);
    virtual SCTPRtoInfo *dup() const override {return new SCTPRtoInfo(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual double getRtoInitial() const;
    virtual void setRtoInitial(double rtoInitial);
    virtual double getRtoMin() const;
    virtual void setRtoMin(double rtoMin);
    virtual double getRtoMax() const;
    virtual void setRtoMax(double rtoMax);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SCTPRtoInfo& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SCTPRtoInfo& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/transportlayer/contract/sctp/SCTPCommand.msg:158</tt> by nedtool.
 * <pre>
 * //
 * // Control info to be used with the DATA command.
 * //
 * // \@see ~SctpCommandCode, ~SCTP
 * //
 * message SCTPRcvInfo extends SCTPCommand
 * {
 *     uint32 ppid;
 *     uint32 tsn;
 *     uint32 cumTsn;
 * }
 * </pre>
 */
class SCTPRcvInfo : public ::inet::SCTPCommand
{
  protected:
    uint32_t ppid;
    uint32_t tsn;
    uint32_t cumTsn;

  private:
    void copy(const SCTPRcvInfo& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPRcvInfo&);

  public:
    SCTPRcvInfo(const char *name=nullptr, short kind=0);
    SCTPRcvInfo(const SCTPRcvInfo& other);
    virtual ~SCTPRcvInfo();
    SCTPRcvInfo& operator=(const SCTPRcvInfo& other);
    virtual SCTPRcvInfo *dup() const override {return new SCTPRcvInfo(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual uint32_t getPpid() const;
    virtual void setPpid(uint32_t ppid);
    virtual uint32_t getTsn() const;
    virtual void setTsn(uint32_t tsn);
    virtual uint32_t getCumTsn() const;
    virtual void setCumTsn(uint32_t cumTsn);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SCTPRcvInfo& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SCTPRcvInfo& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/transportlayer/contract/sctp/SCTPCommand.msg:172</tt> by nedtool.
 * <pre>
 * //
 * // Sent with message kind SCTP_I_ESTABLISHED, to let the app know
 * // about the local and remote IP address and port.
 * //
 * // \@see ~SctpCommandCode, ~SCTP
 * //
 * message SCTPConnectInfo extends SCTPCommand
 * {
 *     AddressVector remoteAddresses;
 *     int status;
 *     int inboundStreams;
 *     int outboundStreams;
 * }
 * </pre>
 */
class SCTPConnectInfo : public ::inet::SCTPCommand
{
  protected:
    AddressVector remoteAddresses;
    int status;
    int inboundStreams;
    int outboundStreams;

  private:
    void copy(const SCTPConnectInfo& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPConnectInfo&);

  public:
    SCTPConnectInfo(const char *name=nullptr, short kind=0);
    SCTPConnectInfo(const SCTPConnectInfo& other);
    virtual ~SCTPConnectInfo();
    SCTPConnectInfo& operator=(const SCTPConnectInfo& other);
    virtual SCTPConnectInfo *dup() const override {return new SCTPConnectInfo(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual AddressVector& getRemoteAddresses();
    virtual const AddressVector& getRemoteAddresses() const {return const_cast<SCTPConnectInfo*>(this)->getRemoteAddresses();}
    virtual void setRemoteAddresses(const AddressVector& remoteAddresses);
    virtual int getStatus() const;
    virtual void setStatus(int status);
    virtual int getInboundStreams() const;
    virtual void setInboundStreams(int inboundStreams);
    virtual int getOutboundStreams() const;
    virtual void setOutboundStreams(int outboundStreams);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SCTPConnectInfo& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SCTPConnectInfo& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/transportlayer/contract/sctp/SCTPCommand.msg:188</tt> by nedtool.
 * <pre>
 * //
 * // Sent with message kind SCTP_I_STATUS, in response to command SCTP_C_STATUS.
 * // For explanation of variables, see RFC 4960 or SCTPStateVariables in
 * // SCTPAssociation.h.
 * //
 * // \@see ~SctpStatusInd, ~SctpCommandCode, ~SCTP
 * //
 * message SCTPStatusInfo extends SCTPCommand
 * {
 *     int state;
 *     string stateName;
 *     L3Address pathId;
 *     bool active;
 * }
 * </pre>
 */
class SCTPStatusInfo : public ::inet::SCTPCommand
{
  protected:
    int state;
    ::omnetpp::opp_string stateName;
    L3Address pathId;
    bool active;

  private:
    void copy(const SCTPStatusInfo& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPStatusInfo&);

  public:
    SCTPStatusInfo(const char *name=nullptr, short kind=0);
    SCTPStatusInfo(const SCTPStatusInfo& other);
    virtual ~SCTPStatusInfo();
    SCTPStatusInfo& operator=(const SCTPStatusInfo& other);
    virtual SCTPStatusInfo *dup() const override {return new SCTPStatusInfo(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getState() const;
    virtual void setState(int state);
    virtual const char * getStateName() const;
    virtual void setStateName(const char * stateName);
    virtual L3Address& getPathId();
    virtual const L3Address& getPathId() const {return const_cast<SCTPStatusInfo*>(this)->getPathId();}
    virtual void setPathId(const L3Address& pathId);
    virtual bool getActive() const;
    virtual void setActive(bool active);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SCTPStatusInfo& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SCTPStatusInfo& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/transportlayer/contract/sctp/SCTPCommand.msg:196</tt> by nedtool.
 * <pre>
 * message SCTPPathInfo extends SCTPCommand
 * {
 *     L3Address remoteAddress;
 * }
 * </pre>
 */
class SCTPPathInfo : public ::inet::SCTPCommand
{
  protected:
    L3Address remoteAddress;

  private:
    void copy(const SCTPPathInfo& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPPathInfo&);

  public:
    SCTPPathInfo(const char *name=nullptr, short kind=0);
    SCTPPathInfo(const SCTPPathInfo& other);
    virtual ~SCTPPathInfo();
    SCTPPathInfo& operator=(const SCTPPathInfo& other);
    virtual SCTPPathInfo *dup() const override {return new SCTPPathInfo(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual L3Address& getRemoteAddress();
    virtual const L3Address& getRemoteAddress() const {return const_cast<SCTPPathInfo*>(this)->getRemoteAddress();}
    virtual void setRemoteAddress(const L3Address& remoteAddress);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SCTPPathInfo& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SCTPPathInfo& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/transportlayer/contract/sctp/SCTPCommand.msg:201</tt> by nedtool.
 * <pre>
 * message SCTPResetInfo extends SCTPCommand
 * {
 *     unsigned short requestType = 0;
 *     uint16 instreams = 0;
 *     uint16 outstreams = 0;
 *     uint16 streams[];
 * }
 * </pre>
 */
class SCTPResetInfo : public ::inet::SCTPCommand
{
  protected:
    unsigned short requestType;
    uint16_t instreams;
    uint16_t outstreams;
    uint16_t *streams; // array ptr
    unsigned int streams_arraysize;

  private:
    void copy(const SCTPResetInfo& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPResetInfo&);

  public:
    SCTPResetInfo(const char *name=nullptr, short kind=0);
    SCTPResetInfo(const SCTPResetInfo& other);
    virtual ~SCTPResetInfo();
    SCTPResetInfo& operator=(const SCTPResetInfo& other);
    virtual SCTPResetInfo *dup() const override {return new SCTPResetInfo(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual unsigned short getRequestType() const;
    virtual void setRequestType(unsigned short requestType);
    virtual uint16_t getInstreams() const;
    virtual void setInstreams(uint16_t instreams);
    virtual uint16_t getOutstreams() const;
    virtual void setOutstreams(uint16_t outstreams);
    virtual void setStreamsArraySize(unsigned int size);
    virtual unsigned int getStreamsArraySize() const;
    virtual uint16_t getStreams(unsigned int k) const;
    virtual void setStreams(unsigned int k, uint16_t streams);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SCTPResetInfo& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SCTPResetInfo& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/transportlayer/contract/sctp/SCTPCommand.msg:209</tt> by nedtool.
 * <pre>
 * message SCTPInfo extends SCTPCommand
 * {
 *     int text = 0;
 * }
 * </pre>
 */
class SCTPInfo : public ::inet::SCTPCommand
{
  protected:
    int text;

  private:
    void copy(const SCTPInfo& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPInfo&);

  public:
    SCTPInfo(const char *name=nullptr, short kind=0);
    SCTPInfo(const SCTPInfo& other);
    virtual ~SCTPInfo();
    SCTPInfo& operator=(const SCTPInfo& other);
    virtual SCTPInfo *dup() const override {return new SCTPInfo(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getText() const;
    virtual void setText(int text);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SCTPInfo& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SCTPInfo& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/transportlayer/contract/sctp/SCTPCommand.msg:214</tt> by nedtool.
 * <pre>
 * message SCTPSendQueueAbated extends SCTPCommand
 * {
 *     uint64 bytesAvailable;
 *     uint64 bytesQueued;
 *     uint64 bytesLimit;
 *     uint64 queuedForStream[];
 * }
 * </pre>
 */
class SCTPSendQueueAbated : public ::inet::SCTPCommand
{
  protected:
    uint64_t bytesAvailable;
    uint64_t bytesQueued;
    uint64_t bytesLimit;
    uint64_t *queuedForStream; // array ptr
    unsigned int queuedForStream_arraysize;

  private:
    void copy(const SCTPSendQueueAbated& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPSendQueueAbated&);

  public:
    SCTPSendQueueAbated(const char *name=nullptr, short kind=0);
    SCTPSendQueueAbated(const SCTPSendQueueAbated& other);
    virtual ~SCTPSendQueueAbated();
    SCTPSendQueueAbated& operator=(const SCTPSendQueueAbated& other);
    virtual SCTPSendQueueAbated *dup() const override {return new SCTPSendQueueAbated(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual uint64_t getBytesAvailable() const;
    virtual void setBytesAvailable(uint64_t bytesAvailable);
    virtual uint64_t getBytesQueued() const;
    virtual void setBytesQueued(uint64_t bytesQueued);
    virtual uint64_t getBytesLimit() const;
    virtual void setBytesLimit(uint64_t bytesLimit);
    virtual void setQueuedForStreamArraySize(unsigned int size);
    virtual unsigned int getQueuedForStreamArraySize() const;
    virtual uint64_t getQueuedForStream(unsigned int k) const;
    virtual void setQueuedForStream(unsigned int k, uint64_t queuedForStream);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SCTPSendQueueAbated& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SCTPSendQueueAbated& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/transportlayer/contract/sctp/SCTPCommand.msg:222</tt> by nedtool.
 * <pre>
 * packet SCTPSimpleMessage
 * {
 *     uint32 dataLen;     //TODO remove it, use set/getDataArraySize() functions only
 *     char data[];
 *     simtime_t creationTime = 0;
 *     bool encaps = false;
 * }
 * </pre>
 */
class SCTPSimpleMessage : public ::omnetpp::cPacket
{
  protected:
    uint32_t dataLen;
    char *data; // array ptr
    unsigned int data_arraysize;
    ::omnetpp::simtime_t creationTime;
    bool encaps;

  private:
    void copy(const SCTPSimpleMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPSimpleMessage&);

  public:
    SCTPSimpleMessage(const char *name=nullptr, short kind=0);
    SCTPSimpleMessage(const SCTPSimpleMessage& other);
    virtual ~SCTPSimpleMessage();
    SCTPSimpleMessage& operator=(const SCTPSimpleMessage& other);
    virtual SCTPSimpleMessage *dup() const override {return new SCTPSimpleMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual uint32_t getDataLen() const;
    virtual void setDataLen(uint32_t dataLen);
    virtual void setDataArraySize(unsigned int size);
    virtual unsigned int getDataArraySize() const;
    virtual char getData(unsigned int k) const;
    virtual void setData(unsigned int k, char data);
    virtual ::omnetpp::simtime_t getCreationTime() const;
    virtual void setCreationTime(::omnetpp::simtime_t creationTime);
    virtual bool getEncaps() const;
    virtual void setEncaps(bool encaps);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SCTPSimpleMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SCTPSimpleMessage& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_SCTPCOMMAND_M_H


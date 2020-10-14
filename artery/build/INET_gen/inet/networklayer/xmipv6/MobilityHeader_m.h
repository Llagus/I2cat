//
// Generated file, do not edit! Created by nedtool 5.6 from /home/aniol/Documents/I2cat/artery/extern/inet/src/inet/networklayer/xmipv6/MobilityHeader.msg.
//

#ifndef __INET_MOBILITYHEADER_M_H
#define __INET_MOBILITYHEADER_M_H

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
#include "inet/networklayer/contract/ipv6/IPv6Address.h"
#include "inet/networklayer/ipv6/IPv6Datagram.h" // added by CB
#include "inet/networklayer/ipv6/IPv6ExtensionHeaders.h" // 17.10.07 - CB
// }}


namespace inet {

/**
 * Enum generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/networklayer/xmipv6/MobilityHeader.msg:40</tt> by nedtool.
 * <pre>
 * enum MobilityHeaderType
 * {
 *     BINDING_REFRESH_REQUEST = 0;
 *     HOME_TEST_INIT = 1;
 *     CARE_OF_TEST_INIT = 2;
 *     HOME_TEST = 3;
 *     CARE_OF_TEST = 4;
 *     BINDING_UPDATE = 5;
 *     BINDING_ACKNOWLEDGEMENT = 6;
 *     BINDING_ERROR = 7;
 * }
 * </pre>
 */
enum MobilityHeaderType {
    BINDING_REFRESH_REQUEST = 0,
    HOME_TEST_INIT = 1,
    CARE_OF_TEST_INIT = 2,
    HOME_TEST = 3,
    CARE_OF_TEST = 4,
    BINDING_UPDATE = 5,
    BINDING_ACKNOWLEDGEMENT = 6,
    BINDING_ERROR = 7
};

/**
 * Class generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/networklayer/xmipv6/MobilityHeader.msg:53</tt> by nedtool.
 * <pre>
 * packet MobilityHeader // extends IPv6ExtensionHeader // TODO check how to define MobilityHeader as subclass of IPv6ExtensionHeader
 * {
 *     int mobilityHeaderType \@enum(MobilityHeaderType);
 * }
 * </pre>
 */
class MobilityHeader : public ::omnetpp::cPacket
{
  protected:
    int mobilityHeaderType;

  private:
    void copy(const MobilityHeader& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const MobilityHeader&);

  public:
    MobilityHeader(const char *name=nullptr, short kind=0);
    MobilityHeader(const MobilityHeader& other);
    virtual ~MobilityHeader();
    MobilityHeader& operator=(const MobilityHeader& other);
    virtual MobilityHeader *dup() const override {return new MobilityHeader(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getMobilityHeaderType() const;
    virtual void setMobilityHeaderType(int mobilityHeaderType);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const MobilityHeader& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, MobilityHeader& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/networklayer/xmipv6/MobilityHeader.msg:59</tt> by nedtool.
 * <pre>
 * packet BindingUpdate extends MobilityHeader
 * {
 *     unsigned int lifetime;
 *     unsigned int sequence;
 *     bool ackFlag;                //A-Flag (Acknowledge Flag)
 *     bool homeRegistrationFlag;        //H-Flag (Home Registration Flag)
 *     bool linkLocalAddressCompatibilityFlag;    //L-Flag (Link Local Address Compatibility Flag)
 *     bool keyManagementFlag = false;        //K-Flag (Key Management Flag)
 *     //Mobility Options not defined
 *     IPv6Address homeAddressMN;        //As BU is supposed to be sent with Home Address Option, therefore i make this part of BU Msg.
 * 
 *     // for CN communication; value different from 0 shows that it is used
 *     int bindingAuthorizationData = 0; // 28.08.07 - CB
 * }
 * 
 * 
 * //Defining the status fields for the Binding Acknowledgement Message
 * </pre>
 */
class BindingUpdate : public ::inet::MobilityHeader
{
  protected:
    unsigned int lifetime;
    unsigned int sequence;
    bool ackFlag;
    bool homeRegistrationFlag;
    bool linkLocalAddressCompatibilityFlag;
    bool keyManagementFlag;
    IPv6Address homeAddressMN;
    int bindingAuthorizationData;

  private:
    void copy(const BindingUpdate& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const BindingUpdate&);

  public:
    BindingUpdate(const char *name=nullptr, short kind=0);
    BindingUpdate(const BindingUpdate& other);
    virtual ~BindingUpdate();
    BindingUpdate& operator=(const BindingUpdate& other);
    virtual BindingUpdate *dup() const override {return new BindingUpdate(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual unsigned int getLifetime() const;
    virtual void setLifetime(unsigned int lifetime);
    virtual unsigned int getSequence() const;
    virtual void setSequence(unsigned int sequence);
    virtual bool getAckFlag() const;
    virtual void setAckFlag(bool ackFlag);
    virtual bool getHomeRegistrationFlag() const;
    virtual void setHomeRegistrationFlag(bool homeRegistrationFlag);
    virtual bool getLinkLocalAddressCompatibilityFlag() const;
    virtual void setLinkLocalAddressCompatibilityFlag(bool linkLocalAddressCompatibilityFlag);
    virtual bool getKeyManagementFlag() const;
    virtual void setKeyManagementFlag(bool keyManagementFlag);
    virtual IPv6Address& getHomeAddressMN();
    virtual const IPv6Address& getHomeAddressMN() const {return const_cast<BindingUpdate*>(this)->getHomeAddressMN();}
    virtual void setHomeAddressMN(const IPv6Address& homeAddressMN);
    virtual int getBindingAuthorizationData() const;
    virtual void setBindingAuthorizationData(int bindingAuthorizationData);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BindingUpdate& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BindingUpdate& obj) {obj.parsimUnpack(b);}

/**
 * Enum generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/networklayer/xmipv6/MobilityHeader.msg:77</tt> by nedtool.
 * <pre>
 * enum BAStatus
 * {
 *     BINDING_UPDATE_ACCEPTED = 0;
 *     BU_ACCEPT_BUT_DISCOVER_PREFIX = 1;
 *     REASON_UNSPECIFIED = 128;
 *     ADMINISTRATIVELY_PROHIBITED = 129;
 *     INSUFFICIENT_RESOURCES = 130;
 *     HOME_REGISTRATION_NOT_SUPPORTED = 131;
 *     NOT_HOME_SUBNET = 132;
 *     NOT_HA_FOR_THIS_MN = 133;
 *     DAD_FAILED = 134;
 *     SEQUENCE_NUMBER_OUT_OF_WINDOW = 135;
 *     EXPIRED_HOME_NONCE_INDEX = 136;
 *     EXPIRED_CARE_OF_NONCE_INDEX = 137;
 *     EXPIRED_NONCES = 138;
 *     REGISTRATION_TYPE_CHANGE_DISALLOWED = 139;
 * }
 * 
 * //==================Defining Binding Acknowledgement Message===================
 * </pre>
 */
enum BAStatus {
    BINDING_UPDATE_ACCEPTED = 0,
    BU_ACCEPT_BUT_DISCOVER_PREFIX = 1,
    REASON_UNSPECIFIED = 128,
    ADMINISTRATIVELY_PROHIBITED = 129,
    INSUFFICIENT_RESOURCES = 130,
    HOME_REGISTRATION_NOT_SUPPORTED = 131,
    NOT_HOME_SUBNET = 132,
    NOT_HA_FOR_THIS_MN = 133,
    DAD_FAILED = 134,
    SEQUENCE_NUMBER_OUT_OF_WINDOW = 135,
    EXPIRED_HOME_NONCE_INDEX = 136,
    EXPIRED_CARE_OF_NONCE_INDEX = 137,
    EXPIRED_NONCES = 138,
    REGISTRATION_TYPE_CHANGE_DISALLOWED = 139
};

/**
 * Class generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/networklayer/xmipv6/MobilityHeader.msg:98</tt> by nedtool.
 * <pre>
 * packet BindingAcknowledgement extends MobilityHeader
 * {
 *     int status \@enum(BAStatus);
 *     unsigned int sequenceNumber;
 *     unsigned int lifetime;
 *     bool keyManagementFlag = false;//K-Flag (Key Management Flag)
 *     //Mobility Options not defined
 * 
 *     // for CN communication; value different from 0 shows that it is used
 *     int bindingAuthorizationData = 0; // 28.08.07 - CB
 * }
 * 
 * //==================Defining Binding Error Status====================
 * </pre>
 */
class BindingAcknowledgement : public ::inet::MobilityHeader
{
  protected:
    int status;
    unsigned int sequenceNumber;
    unsigned int lifetime;
    bool keyManagementFlag;
    int bindingAuthorizationData;

  private:
    void copy(const BindingAcknowledgement& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const BindingAcknowledgement&);

  public:
    BindingAcknowledgement(const char *name=nullptr, short kind=0);
    BindingAcknowledgement(const BindingAcknowledgement& other);
    virtual ~BindingAcknowledgement();
    BindingAcknowledgement& operator=(const BindingAcknowledgement& other);
    virtual BindingAcknowledgement *dup() const override {return new BindingAcknowledgement(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getStatus() const;
    virtual void setStatus(int status);
    virtual unsigned int getSequenceNumber() const;
    virtual void setSequenceNumber(unsigned int sequenceNumber);
    virtual unsigned int getLifetime() const;
    virtual void setLifetime(unsigned int lifetime);
    virtual bool getKeyManagementFlag() const;
    virtual void setKeyManagementFlag(bool keyManagementFlag);
    virtual int getBindingAuthorizationData() const;
    virtual void setBindingAuthorizationData(int bindingAuthorizationData);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BindingAcknowledgement& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BindingAcknowledgement& obj) {obj.parsimUnpack(b);}

/**
 * Enum generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/networklayer/xmipv6/MobilityHeader.msg:112</tt> by nedtool.
 * <pre>
 * enum BEStatus
 * {
 *     UNKNOWN_BINDING_FOR_HOME_ADDRESS_DEST_OPTION = 1;
 *     UNKNOWN_MH_TYPE = 2; //Unrecognised MH Type
 * }
 * 
 * //==================Defining Binding Error Message===================
 * </pre>
 */
enum BEStatus {
    UNKNOWN_BINDING_FOR_HOME_ADDRESS_DEST_OPTION = 1,
    UNKNOWN_MH_TYPE = 2
};

/**
 * Class generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/networklayer/xmipv6/MobilityHeader.msg:121</tt> by nedtool.
 * <pre>
 * packet BindingError extends MobilityHeader
 * {
 *     int status \@enum(BEStatus);
 *     IPv6Address homeAddress;
 *     //Mobility Options not defined
 * 
 * }
 * 
 * //=============Message definition of Home Test Init Message ==========
 * </pre>
 */
class BindingError : public ::inet::MobilityHeader
{
  protected:
    int status;
    IPv6Address homeAddress;

  private:
    void copy(const BindingError& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const BindingError&);

  public:
    BindingError(const char *name=nullptr, short kind=0);
    BindingError(const BindingError& other);
    virtual ~BindingError();
    BindingError& operator=(const BindingError& other);
    virtual BindingError *dup() const override {return new BindingError(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getStatus() const;
    virtual void setStatus(int status);
    virtual IPv6Address& getHomeAddress();
    virtual const IPv6Address& getHomeAddress() const {return const_cast<BindingError*>(this)->getHomeAddress();}
    virtual void setHomeAddress(const IPv6Address& homeAddress);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BindingError& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BindingError& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/networklayer/xmipv6/MobilityHeader.msg:131</tt> by nedtool.
 * <pre>
 * packet HomeTestInit extends MobilityHeader
 * {
 *     unsigned int homeInitCookie;
 * }
 * 
 * //=============Message definition of Home Test Message ==========
 * </pre>
 */
class HomeTestInit : public ::inet::MobilityHeader
{
  protected:
    unsigned int homeInitCookie;

  private:
    void copy(const HomeTestInit& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const HomeTestInit&);

  public:
    HomeTestInit(const char *name=nullptr, short kind=0);
    HomeTestInit(const HomeTestInit& other);
    virtual ~HomeTestInit();
    HomeTestInit& operator=(const HomeTestInit& other);
    virtual HomeTestInit *dup() const override {return new HomeTestInit(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual unsigned int getHomeInitCookie() const;
    virtual void setHomeInitCookie(unsigned int homeInitCookie);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const HomeTestInit& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, HomeTestInit& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/networklayer/xmipv6/MobilityHeader.msg:138</tt> by nedtool.
 * <pre>
 * packet HomeTest extends MobilityHeader
 * {
 *     unsigned int homeInitCookie;
 *     unsigned int homeKeyGenToken;
 *     // home nonce index not modelled
 * }
 * 
 * //=============Message definition of Care-of Test Init Message ==========
 * </pre>
 */
class HomeTest : public ::inet::MobilityHeader
{
  protected:
    unsigned int homeInitCookie;
    unsigned int homeKeyGenToken;

  private:
    void copy(const HomeTest& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const HomeTest&);

  public:
    HomeTest(const char *name=nullptr, short kind=0);
    HomeTest(const HomeTest& other);
    virtual ~HomeTest();
    HomeTest& operator=(const HomeTest& other);
    virtual HomeTest *dup() const override {return new HomeTest(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual unsigned int getHomeInitCookie() const;
    virtual void setHomeInitCookie(unsigned int homeInitCookie);
    virtual unsigned int getHomeKeyGenToken() const;
    virtual void setHomeKeyGenToken(unsigned int homeKeyGenToken);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const HomeTest& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, HomeTest& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/networklayer/xmipv6/MobilityHeader.msg:147</tt> by nedtool.
 * <pre>
 * packet CareOfTestInit extends MobilityHeader
 * {
 *     unsigned int careOfInitCookie;
 * }
 * 
 * //=============Message definition of Care-of Test Message ==========
 * </pre>
 */
class CareOfTestInit : public ::inet::MobilityHeader
{
  protected:
    unsigned int careOfInitCookie;

  private:
    void copy(const CareOfTestInit& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const CareOfTestInit&);

  public:
    CareOfTestInit(const char *name=nullptr, short kind=0);
    CareOfTestInit(const CareOfTestInit& other);
    virtual ~CareOfTestInit();
    CareOfTestInit& operator=(const CareOfTestInit& other);
    virtual CareOfTestInit *dup() const override {return new CareOfTestInit(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual unsigned int getCareOfInitCookie() const;
    virtual void setCareOfInitCookie(unsigned int careOfInitCookie);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const CareOfTestInit& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, CareOfTestInit& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/networklayer/xmipv6/MobilityHeader.msg:154</tt> by nedtool.
 * <pre>
 * packet CareOfTest extends MobilityHeader
 * {
 *     unsigned int careOfInitCookie;
 *     unsigned int careOfKeyGenToken;
 *     // care-of nonce index not modelled
 * }
 * </pre>
 */
class CareOfTest : public ::inet::MobilityHeader
{
  protected:
    unsigned int careOfInitCookie;
    unsigned int careOfKeyGenToken;

  private:
    void copy(const CareOfTest& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const CareOfTest&);

  public:
    CareOfTest(const char *name=nullptr, short kind=0);
    CareOfTest(const CareOfTest& other);
    virtual ~CareOfTest();
    CareOfTest& operator=(const CareOfTest& other);
    virtual CareOfTest *dup() const override {return new CareOfTest(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual unsigned int getCareOfInitCookie() const;
    virtual void setCareOfInitCookie(unsigned int careOfInitCookie);
    virtual unsigned int getCareOfKeyGenToken() const;
    virtual void setCareOfKeyGenToken(unsigned int careOfKeyGenToken);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const CareOfTest& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, CareOfTest& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/networklayer/xmipv6/MobilityHeader.msg:165</tt> by nedtool.
 * <pre>
 * ///////////////////////////////////////////
 * // 18.09.07 - CB
 * ///////////////////////////////////////////
 * packet BindingRefreshRequest extends MobilityHeader
 * {
 * }
 * </pre>
 */
class BindingRefreshRequest : public ::inet::MobilityHeader
{
  protected:

  private:
    void copy(const BindingRefreshRequest& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const BindingRefreshRequest&);

  public:
    BindingRefreshRequest(const char *name=nullptr, short kind=0);
    BindingRefreshRequest(const BindingRefreshRequest& other);
    virtual ~BindingRefreshRequest();
    BindingRefreshRequest& operator=(const BindingRefreshRequest& other);
    virtual BindingRefreshRequest *dup() const override {return new BindingRefreshRequest(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BindingRefreshRequest& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BindingRefreshRequest& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>/home/aniol/Documents/I2cat/artery/extern/inet/src/inet/networklayer/xmipv6/MobilityHeader.msg:173</tt> by nedtool.
 * <pre>
 * ///////////////////////////////////////////
 * // 17.10.07 - CB
 * ///////////////////////////////////////////
 * packet HomeAddressOption extends IPv6DestinationOptionsHeader
 * {
 *     \@customize(true);
 *     IPv6Address homeAddress;
 * }
 * </pre>
 *
 * HomeAddressOption_Base is only useful if it gets subclassed, and HomeAddressOption is derived from it.
 * The minimum code to be written for HomeAddressOption is the following:
 *
 * <pre>
 * class HomeAddressOption : public HomeAddressOption_Base
 * {
 *   private:
 *     void copy(const HomeAddressOption& other) { ... }

 *   public:
 *     HomeAddressOption() : HomeAddressOption_Base() {}
 *     HomeAddressOption(const HomeAddressOption& other) : HomeAddressOption_Base(other) {copy(other);}
 *     HomeAddressOption& operator=(const HomeAddressOption& other) {if (this==&other) return *this; HomeAddressOption_Base::operator=(other); copy(other); return *this;}
 *     // ADD CODE HERE to redefine and implement pure virtual functions from HomeAddressOption_Base
 * };
 * </pre>
 */
class HomeAddressOption_Base : public ::inet::IPv6DestinationOptionsHeader
{
  protected:
    IPv6Address homeAddress;

  private:
    void copy(const HomeAddressOption_Base& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const HomeAddressOption_Base&);
    // make constructors protected to avoid instantiation
    HomeAddressOption_Base();
    HomeAddressOption_Base(const HomeAddressOption_Base& other);
    // make assignment operator protected to force the user override it
    HomeAddressOption_Base& operator=(const HomeAddressOption_Base& other);

  public:
    virtual ~HomeAddressOption_Base();
    virtual HomeAddressOption_Base *dup() const override {throw omnetpp::cRuntimeError("You forgot to manually add a dup() function to class HomeAddressOption");}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual IPv6Address& getHomeAddress();
    virtual const IPv6Address& getHomeAddress() const {return const_cast<HomeAddressOption_Base*>(this)->getHomeAddress();}
    virtual void setHomeAddress(const IPv6Address& homeAddress);
};

} // namespace inet

#endif // ifndef __INET_MOBILITYHEADER_M_H


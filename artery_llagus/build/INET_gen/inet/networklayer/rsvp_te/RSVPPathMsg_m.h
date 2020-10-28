//
// Generated file, do not edit! Created by nedtool 5.6 from /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/inet/src/inet/networklayer/rsvp_te/RSVPPathMsg.msg.
//

#ifndef __INET_RSVPPATHMSG_M_H
#define __INET_RSVPPATHMSG_M_H

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
#include "inet/networklayer/rsvp_te/IntServ.h"
#include "inet/networklayer/rsvp_te/RSVPPacket.h"
// }}


namespace inet {

/**
 * Class generated from <tt>/home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/inet/src/inet/networklayer/rsvp_te/RSVPPathMsg.msg:44</tt> by nedtool.
 * <pre>
 * //
 * // FIXME missing documentation
 * //
 * packet RSVPPathMsg extends RSVPPacket
 * {
 *     \@customize(true);
 *     RsvpHopObj_t hop;
 *     LabelRequestObj_t label_request;
 *     SenderDescriptor_t sender_descriptor;
 *     EroVector ERO;
 *     int color;
 * 
 *     rsvpKind = PATH_MESSAGE;
 * }
 * </pre>
 *
 * RSVPPathMsg_Base is only useful if it gets subclassed, and RSVPPathMsg is derived from it.
 * The minimum code to be written for RSVPPathMsg is the following:
 *
 * <pre>
 * class RSVPPathMsg : public RSVPPathMsg_Base
 * {
 *   private:
 *     void copy(const RSVPPathMsg& other) { ... }

 *   public:
 *     RSVPPathMsg(const char *name=nullptr, short kind=0) : RSVPPathMsg_Base(name,kind) {}
 *     RSVPPathMsg(const RSVPPathMsg& other) : RSVPPathMsg_Base(other) {copy(other);}
 *     RSVPPathMsg& operator=(const RSVPPathMsg& other) {if (this==&other) return *this; RSVPPathMsg_Base::operator=(other); copy(other); return *this;}
 *     virtual RSVPPathMsg *dup() const override {return new RSVPPathMsg(*this);}
 *     // ADD CODE HERE to redefine and implement pure virtual functions from RSVPPathMsg_Base
 * };
 * </pre>
 *
 * The following should go into a .cc (.cpp) file:
 *
 * <pre>
 * Register_Class(RSVPPathMsg)
 * </pre>
 */
class RSVPPathMsg_Base : public ::inet::RSVPPacket
{
  protected:
    RsvpHopObj_t hop;
    LabelRequestObj_t label_request;
    SenderDescriptor_t sender_descriptor;
    EroVector ERO;
    int color;

  private:
    void copy(const RSVPPathMsg_Base& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const RSVPPathMsg_Base&);
    // make constructors protected to avoid instantiation
    RSVPPathMsg_Base(const char *name=nullptr, short kind=0);
    RSVPPathMsg_Base(const RSVPPathMsg_Base& other);
    // make assignment operator protected to force the user override it
    RSVPPathMsg_Base& operator=(const RSVPPathMsg_Base& other);

  public:
    virtual ~RSVPPathMsg_Base();
    virtual RSVPPathMsg_Base *dup() const override {throw omnetpp::cRuntimeError("You forgot to manually add a dup() function to class RSVPPathMsg");}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual RsvpHopObj_t& getHop();
    virtual const RsvpHopObj_t& getHop() const {return const_cast<RSVPPathMsg_Base*>(this)->getHop();}
    virtual void setHop(const RsvpHopObj_t& hop);
    virtual LabelRequestObj_t& getLabel_request();
    virtual const LabelRequestObj_t& getLabel_request() const {return const_cast<RSVPPathMsg_Base*>(this)->getLabel_request();}
    virtual void setLabel_request(const LabelRequestObj_t& label_request);
    virtual SenderDescriptor_t& getSender_descriptor();
    virtual const SenderDescriptor_t& getSender_descriptor() const {return const_cast<RSVPPathMsg_Base*>(this)->getSender_descriptor();}
    virtual void setSender_descriptor(const SenderDescriptor_t& sender_descriptor);
    virtual EroVector& getERO();
    virtual const EroVector& getERO() const {return const_cast<RSVPPathMsg_Base*>(this)->getERO();}
    virtual void setERO(const EroVector& ERO);
    virtual int getColor() const;
    virtual void setColor(int color);
};

/**
 * Class generated from <tt>/home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/inet/src/inet/networklayer/rsvp_te/RSVPPathMsg.msg:59</tt> by nedtool.
 * <pre>
 * //
 * // FIXME missing documentation
 * //
 * packet RSVPPathTear extends RSVPPacket
 * {
 *     \@customize(true);
 *     RsvpHopObj_t hop;
 *     SenderTemplateObj_t senderTemplate;
 *     bool force;
 *     rsvpKind = PTEAR_MESSAGE;
 * }
 * </pre>
 *
 * RSVPPathTear_Base is only useful if it gets subclassed, and RSVPPathTear is derived from it.
 * The minimum code to be written for RSVPPathTear is the following:
 *
 * <pre>
 * class RSVPPathTear : public RSVPPathTear_Base
 * {
 *   private:
 *     void copy(const RSVPPathTear& other) { ... }

 *   public:
 *     RSVPPathTear(const char *name=nullptr, short kind=0) : RSVPPathTear_Base(name,kind) {}
 *     RSVPPathTear(const RSVPPathTear& other) : RSVPPathTear_Base(other) {copy(other);}
 *     RSVPPathTear& operator=(const RSVPPathTear& other) {if (this==&other) return *this; RSVPPathTear_Base::operator=(other); copy(other); return *this;}
 *     virtual RSVPPathTear *dup() const override {return new RSVPPathTear(*this);}
 *     // ADD CODE HERE to redefine and implement pure virtual functions from RSVPPathTear_Base
 * };
 * </pre>
 *
 * The following should go into a .cc (.cpp) file:
 *
 * <pre>
 * Register_Class(RSVPPathTear)
 * </pre>
 */
class RSVPPathTear_Base : public ::inet::RSVPPacket
{
  protected:
    RsvpHopObj_t hop;
    SenderTemplateObj_t senderTemplate;
    bool force;

  private:
    void copy(const RSVPPathTear_Base& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const RSVPPathTear_Base&);
    // make constructors protected to avoid instantiation
    RSVPPathTear_Base(const char *name=nullptr, short kind=0);
    RSVPPathTear_Base(const RSVPPathTear_Base& other);
    // make assignment operator protected to force the user override it
    RSVPPathTear_Base& operator=(const RSVPPathTear_Base& other);

  public:
    virtual ~RSVPPathTear_Base();
    virtual RSVPPathTear_Base *dup() const override {throw omnetpp::cRuntimeError("You forgot to manually add a dup() function to class RSVPPathTear");}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual RsvpHopObj_t& getHop();
    virtual const RsvpHopObj_t& getHop() const {return const_cast<RSVPPathTear_Base*>(this)->getHop();}
    virtual void setHop(const RsvpHopObj_t& hop);
    virtual SenderTemplateObj_t& getSenderTemplate();
    virtual const SenderTemplateObj_t& getSenderTemplate() const {return const_cast<RSVPPathTear_Base*>(this)->getSenderTemplate();}
    virtual void setSenderTemplate(const SenderTemplateObj_t& senderTemplate);
    virtual bool getForce() const;
    virtual void setForce(bool force);
};

/**
 * Class generated from <tt>/home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/inet/src/inet/networklayer/rsvp_te/RSVPPathMsg.msg:72</tt> by nedtool.
 * <pre>
 * //
 * // FIXME missing documentation
 * //
 * packet RSVPPathError extends RSVPPacket
 * {
 *     \@customize(true);
 *     IPv4Address errorNode;
 *     int errorCode;
 *     SenderDescriptor_t sender_descriptor;
 * 
 *     rsvpKind = PERROR_MESSAGE;
 * }
 * </pre>
 *
 * RSVPPathError_Base is only useful if it gets subclassed, and RSVPPathError is derived from it.
 * The minimum code to be written for RSVPPathError is the following:
 *
 * <pre>
 * class RSVPPathError : public RSVPPathError_Base
 * {
 *   private:
 *     void copy(const RSVPPathError& other) { ... }

 *   public:
 *     RSVPPathError(const char *name=nullptr, short kind=0) : RSVPPathError_Base(name,kind) {}
 *     RSVPPathError(const RSVPPathError& other) : RSVPPathError_Base(other) {copy(other);}
 *     RSVPPathError& operator=(const RSVPPathError& other) {if (this==&other) return *this; RSVPPathError_Base::operator=(other); copy(other); return *this;}
 *     virtual RSVPPathError *dup() const override {return new RSVPPathError(*this);}
 *     // ADD CODE HERE to redefine and implement pure virtual functions from RSVPPathError_Base
 * };
 * </pre>
 *
 * The following should go into a .cc (.cpp) file:
 *
 * <pre>
 * Register_Class(RSVPPathError)
 * </pre>
 */
class RSVPPathError_Base : public ::inet::RSVPPacket
{
  protected:
    IPv4Address errorNode;
    int errorCode;
    SenderDescriptor_t sender_descriptor;

  private:
    void copy(const RSVPPathError_Base& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const RSVPPathError_Base&);
    // make constructors protected to avoid instantiation
    RSVPPathError_Base(const char *name=nullptr, short kind=0);
    RSVPPathError_Base(const RSVPPathError_Base& other);
    // make assignment operator protected to force the user override it
    RSVPPathError_Base& operator=(const RSVPPathError_Base& other);

  public:
    virtual ~RSVPPathError_Base();
    virtual RSVPPathError_Base *dup() const override {throw omnetpp::cRuntimeError("You forgot to manually add a dup() function to class RSVPPathError");}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual IPv4Address& getErrorNode();
    virtual const IPv4Address& getErrorNode() const {return const_cast<RSVPPathError_Base*>(this)->getErrorNode();}
    virtual void setErrorNode(const IPv4Address& errorNode);
    virtual int getErrorCode() const;
    virtual void setErrorCode(int errorCode);
    virtual SenderDescriptor_t& getSender_descriptor();
    virtual const SenderDescriptor_t& getSender_descriptor() const {return const_cast<RSVPPathError_Base*>(this)->getSender_descriptor();}
    virtual void setSender_descriptor(const SenderDescriptor_t& sender_descriptor);
};

} // namespace inet

#endif // ifndef __INET_RSVPPATHMSG_M_H


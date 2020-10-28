//
// Generated file, do not edit! Created by nedtool 5.6 from /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/inet/src/inet/common/ByteArray.msg.
//

#ifndef __INET_BYTEARRAY_M_H
#define __INET_BYTEARRAY_M_H

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

/**
 * Class generated from <tt>/home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/inet/src/inet/common/ByteArray.msg:27</tt> by nedtool.
 * <pre>
 * //
 * // Class that carries raw bytes.
 * // For example, used by ~RawPacket and some TCP queues.
 * //
 * class ByteArray
 * {
 *     \@customize(true);
 *     char data[];
 * }
 * </pre>
 *
 * ByteArray_Base is only useful if it gets subclassed, and ByteArray is derived from it.
 * The minimum code to be written for ByteArray is the following:
 *
 * <pre>
 * class ByteArray : public ByteArray_Base
 * {
 *   private:
 *     void copy(const ByteArray& other) { ... }

 *   public:
 *     ByteArray() : ByteArray_Base() {}
 *     ByteArray(const ByteArray& other) : ByteArray_Base(other) {copy(other);}
 *     ByteArray& operator=(const ByteArray& other) {if (this==&other) return *this; ByteArray_Base::operator=(other); copy(other); return *this;}
 *     virtual ByteArray *dup() const override {return new ByteArray(*this);}
 *     // ADD CODE HERE to redefine and implement pure virtual functions from ByteArray_Base
 * };
 * </pre>
 *
 * The following should go into a .cc (.cpp) file:
 *
 * <pre>
 * Register_Class(ByteArray)
 * </pre>
 */
class ByteArray_Base : public ::omnetpp::cObject
{
  protected:
    char *data; // array ptr
    unsigned int data_arraysize;

  private:
    void copy(const ByteArray_Base& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const ByteArray_Base&);
    // make constructors protected to avoid instantiation
    ByteArray_Base();
    ByteArray_Base(const ByteArray_Base& other);
    // make assignment operator protected to force the user override it
    ByteArray_Base& operator=(const ByteArray_Base& other);

  public:
    virtual ~ByteArray_Base();
    virtual ByteArray_Base *dup() const override {throw omnetpp::cRuntimeError("You forgot to manually add a dup() function to class ByteArray");}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual void setDataArraySize(unsigned int size);
    virtual unsigned int getDataArraySize() const;
    virtual char getData(unsigned int k) const;
    virtual void setData(unsigned int k, char data);
};

} // namespace inet

#endif // ifndef __INET_BYTEARRAY_M_H


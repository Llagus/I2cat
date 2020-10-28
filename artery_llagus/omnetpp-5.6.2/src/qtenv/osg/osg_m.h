//
// Generated file, do not edit! Created by nedtool 5.6 from osg.msg.
//

#ifndef __OMNETPP_OSG_M_H
#define __OMNETPP_OSG_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0506
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif


namespace omnetpp {

} // namespace omnetpp


namespace osg {

} // namespace osg

// cplusplus {{
namespace omnetpp {
Register_Enum(cOsgCanvas::ViewerStyle, (cOsgCanvas::STYLE_GENERIC, cOsgCanvas::STYLE_EARTH));
Register_Enum(cOsgCanvas::CameraManipulatorType, (cOsgCanvas::CAM_AUTO, cOsgCanvas::CAM_TRACKBALL, cOsgCanvas::CAM_EARTH));
} // namespace omnetpp

#include "omnetpp/osgutil.h"
#include <osg/Node>
#include <osg/Group>

namespace osg {
    inline std::ostream& operator<<(std::ostream& os, Node *node) {
        return os << "(" << node->className() << ")";
    }
} // namespace

inline int osgNode_getNumChildren(osg::Node *node)
{
    osg::Group *group = node->asGroup();
    return group ? group->getNumChildren() : 0;
}

inline osg::Node *osgNode_getChild(osg::Node *node, unsigned int i)
{
    return node->asGroup()->getChild(i);
}

inline int osgNode_getNumDescriptions(osg::Node *node)
{
    return node->getNumDescriptions();
}

inline std::string osgNode_getDescription(osg::Node *node, unsigned int i)
{
#if defined(__clang__)
    return "";  // FIXME clang 3.7 (3.6 is ok) has issues because of a binary ABI incompatibility the compiler cannot link with node->getDescription() - remove this hack once clang is fixed
#else
    return node->getDescription(i);
#endif
}
// }}


namespace omnetpp {

} // namespace omnetpp


namespace osg {

} // namespace osg

#endif // ifndef __OMNETPP_OSG_M_H


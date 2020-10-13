#include "artery/traci/VehicleController.h"
#include <boost/units/systems/angle/degrees.hpp>
#include <boost/units/systems/si/acceleration.hpp>
#include <boost/units/systems/si/plane_angle.hpp>
#include <boost/units/systems/si/velocity.hpp>

//~ 
#include <boost/units/systems/si/time.hpp>

namespace si = boost::units::si;

namespace traci
{

VehicleController::VehicleController(const std::string& id, traci::LiteAPI& api) :
    m_id(id), m_api(api), m_boundary(api.simulation().getNetBoundary()), m_type(getTypeId(), api)
{
}

const std::string& VehicleController::getVehicleId() const
{
    return m_id;
}

std::string VehicleController::getTypeId() const
{
    return m_api.vehicle().getTypeID(m_id);
}

const VehicleType& VehicleController::getVehicleType() const
{
    return m_type;
}

Position VehicleController::getPosition() const
{
    return traci::position_cast(m_boundary, m_api.vehicle().getPosition(m_id));
}

auto VehicleController::getGeoPosition() const -> GeoPosition
{
    TraCIPosition pos = m_api.vehicle().getPosition(m_id);
    TraCIGeoPosition geo = m_api.convertGeo(pos);
    return GeoPosition {
        geo.longitude * boost::units::degree::degree,
        geo.latitude * boost::units::degree::degree
    };
}

auto VehicleController::getHeading() const -> Angle
{
    using namespace traci;
    return angle_cast(TraCIAngle { m_api.vehicle().getAngle(m_id) });
}

auto VehicleController::getSpeed() const -> Velocity
{
    return m_api.vehicle().getSpeed(m_id) * si::meter_per_second;
}

auto VehicleController::getMaxSpeed() const -> Velocity
{
    return m_api.vehicle().getMaxSpeed(m_id) * si::meter_per_second;
}

void VehicleController::setMaxSpeed(Velocity v)
{
    m_api.vehicle().setMaxSpeed(m_id, v / si::meter_per_second);
}

void VehicleController::setSpeed(Velocity v)
{
    m_api.vehicle().setSpeed(m_id, v / si::meter_per_second);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~ some custom commands for V2X-ARCH, named "my_*"
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void VehicleController::my_setSpeedFactor(std::string vtype, int factor)
{
    m_api.vehicletype().setSpeedFactor(vtype, factor);    
}



void VehicleController::my_changeLane(char lane)
{
    // the following is defined in TraCIAPI.cpp / .h
    m_api.vehicle().my_changeLane(m_id, lane, 5000);
}

double VehicleController::my_getSpeed()
{
    return m_api.vehicle().my_getSpeed(m_id);
}

void VehicleController::my_setSpeed(int value)
{
    return m_api.vehicle().my_setSpeed(m_id, value);
}

void VehicleController::my_slowdown()
{
     m_api.vehicle().my_slowDown(m_id, 5000);
}

std::string VehicleController::my_getLaneID()
{
    return m_api.vehicle().my_getLaneID(m_id);
}

int VehicleController::my_getLaneIndex()
{
    return m_api.vehicle().my_getLaneIndex(m_id);
}


std::string VehicleController::my_getRoadID()
{
    return m_api.vehicle().getRoadID(m_id);
}

void VehicleController::my_changeColor()
{
     m_api.vehicle().my_changeColor(m_id);
}


auto VehicleController::getLength() const -> Length
{
    return m_type.getLength();
}

auto VehicleController::getWidth() const -> Length
{
    return m_type.getWidth();
}

void VehicleController::changeTarget(const std::string& edge)
{
    m_api.vehicle().changeTarget(m_id, edge);
}

} // namespace traci

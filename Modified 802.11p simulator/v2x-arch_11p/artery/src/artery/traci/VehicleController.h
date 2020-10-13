#ifndef VEHICLECONTROLLER_H_AXBS5NQM
#define VEHICLECONTROLLER_H_AXBS5NQM

#include "artery/traci/VehicleType.h"
#include "artery/utility/Geometry.h"
#include "traci/LiteAPI.h"
#include <vanetza/units/acceleration.hpp>
#include <vanetza/units/angle.hpp>
#include <vanetza/units/length.hpp>
#include <vanetza/units/velocity.hpp>
#include <string>

namespace traci
{

class VehicleController
{
public:
    using Acceleration = vanetza::units::Acceleration;
    using Length = vanetza::units::Length;
    using Velocity = vanetza::units::Velocity;

    VehicleController(const std::string& id, traci::LiteAPI&);

    const std::string& getVehicleId() const;
    std::string getTypeId() const;
    const VehicleType& getVehicleType() const;

    Position getPosition() const;
    GeoPosition getGeoPosition() const;
    Angle getHeading() const;
    Velocity getSpeed() const;
    Velocity getMaxSpeed() const;
    void setMaxSpeed(Velocity);
    void setSpeed(Velocity);


    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //~ custom V2X-ARCH functions 
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~
    void my_setSpeedFactor(std::string, int);
    void my_changeLane(char);
    void my_slowdown();
    std::string my_getLaneID();
    int my_getLaneIndex();
    double my_getSpeed();
    void my_setSpeed(int);
    void my_changeColor();
    std::string my_getRoadID();

    Length getLength() const;
    Length getWidth() const;

    void changeTarget(const std::string& edge);

    traci::LiteAPI& getLiteAPI() { return m_api; }

private:
    std::string m_id;
    traci::LiteAPI& m_api;
    traci::TraCIBoundary m_boundary;
    VehicleType m_type;
};

} // namespace traci

#endif /* VEHICLECONTROLLER_H_AXBS5NQM */


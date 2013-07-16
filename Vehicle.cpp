/* 
 * File:   Vehicle.cpp
 * Author: maarten
 * 
 * Created on July 8, 2013, 2:03 PM
 */

#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"

Vehicle* Vehicle::createVehicle(int id, VehicleType type, int initialSpeed, int initialPosition)
{
    switch (type)
    {
        case VehicleType::CAR:
        {
            return new Car(id,initialSpeed);
            break;
        }
        case VehicleType::TRUCK:
        {
            return new Truck(id, initialSpeed);
        }
    }
}

Vehicle::Vehicle()
  :m_id(0), m_position(0,0,0), m_maxSpeed(0),m_time(0)
{
    
}
Vehicle::Vehicle(int id, int initialSpeed)
  :m_id(id), m_position(0,0,initialSpeed), m_maxSpeed(0),m_time(0)
{
   
}

Vehicle::~Vehicle()
{
    
}

int Vehicle::getSpeed() const
{
    return m_position.m_speed;
}
int Vehicle::getHorizontalPosition() const
{
    return m_position.m_x;
}
int Vehicle::getLanePosition() const
{
    return m_position.m_y;
}
int Vehicle::getTime() const
{
    return m_time;
}

int Vehicle::getId() const
{
    return m_id;
}


void Vehicle::setSpeed(int newSpeed)
{
    if (m_position.m_speed + newSpeed > m_maxSpeed)
    {
        m_position.m_speed = m_maxSpeed;
    }
    else
    {
        m_position.m_speed = newSpeed;
    }
}
void Vehicle::update(int time)
{
    m_time = time;
    PVData newPos = calculateNewPosition();
    PositionStatus status = isPositionAvailable(m_position);
    
    if (status == PositionStatus::OK)
    {
        m_position = newPos;
    }
    else
    {
        onPositionNotAvailable(newPos,status);
    }
    
    
    
}

std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle)
{
    os << "Id: " << vehicle.m_id << std::endl << "Position: " << vehicle.m_position << std::endl << "Speed: " << vehicle.m_position.m_speed << std::endl;
    return os;
}

PVData Vehicle::calculateNewPosition() const
{
    int newX = m_position.m_x + m_position.m_speed;
    return PVData(newX, m_position.m_y, m_position.m_speed);
}
void Vehicle::onPositionNotAvailable(const PVData& position, const PositionStatus& status)
{
    
}

PositionStatus Vehicle::isPositionAvailable(const PVData& position) const
{
    return PositionStatus::OK;
}

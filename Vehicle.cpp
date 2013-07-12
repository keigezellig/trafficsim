/* 
 * File:   Vehicle.cpp
 * Author: maarten
 * 
 * Created on July 8, 2013, 2:03 PM
 */

#include "Vehicle.h"
#include "Lane.h"
#include "Car.h"
#include "Truck.h"

Vehicle* Vehicle::createVehicle(int id, VehicleType type, int initialSpeed, int initialPosition)
{
    switch (type)
    {
        case VehicleType::CAR:
        {
            return new Car(id,initialSpeed,initialPosition);
            break;
        }
        case VehicleType::TRUCK:
        {
            return new Truck(id, initialSpeed, initialPosition);
        }
    }
}

Vehicle::Vehicle()
  :m_id(0), m_position(), m_speed(0), m_maxSpeed(0)
{
    
}
Vehicle::Vehicle(int id, int initialSpeed)
  :m_id(id), m_position(), m_speed(initialSpeed), m_maxSpeed(0)
{
   
}

virtual Vehicle::~Vehicle()
{
    
}

int Vehicle::getSpeed() const
{
    return m_speed;
}
Position Vehicle::getPosition() const
{
    return m_position;
}
int Vehicle::getId() const
{
    return m_id;
}
void Vehicle::increaseSpeed(int delta)
{
    int newSpeed = m_speed + delta;
    
    if (newSpeed <= m_maxSpeed)
    {
        m_speed = newSpeed;
    }
    else
    {
        m_speed = m_maxSpeed;
    }
        
        
}
void Vehicle::decreaseSpeed(int delta)
{
    int newSpeed = m_speed - delta;
    
    if (newSpeed >= 0)
    {
        m_speed = newSpeed;
    }
    else
    {
        m_speed = 0;
    }
}

void Vehicle::update()
{
    Position newPos = calculateNewPosition();
    PositionStatus status = isPositionAvailable(m_position);
    
    if ( status == PositionStatus.OK)
    {
        m_position = newPos;
    }
    else
    {
        onPositionNotAvailable(newPos,reason);
    }
    
    
    
}

std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle)
{
    os << "Id: " << vehicle.m_id << std::endl << "Position: " << vehicle.m_position << std::endl << "Speed: " << vehicle.m_speed << std::endl;
    return os;
}

Position Vehicle::calculateNewPosition()
{
    return Position(m_position.m_x += m_speed, m_position.m_y);
}
void Vehicle::onPositionNotAvailable(const Position& position, const PositionStatus& status)
{
    
}

PositionStatus Vehicle::isPositionAvailable(const Position& position)
{
    return PositionStatus.OK;
}

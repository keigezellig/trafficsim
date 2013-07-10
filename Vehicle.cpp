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
    
Vehicle::Vehicle(int id, int initialSpeed, int initialPosition)
     :m_id(id), m_position(initialPosition),m_speed(initialSpeed)
{
    
    std::cout << "Ctor Vehicle" << std::endl;
}

Vehicle::Vehicle(const Vehicle& vehicle)
      :m_id(vehicle.m_id), m_position(vehicle.m_position), m_speed(vehicle.m_speed)
{
    std::cout << "Copy ctor Vehicle" << std::endl;
    
}
    int Vehicle::getSpeed() const
    {
        return m_speed;
    }
    int Vehicle::getPosition() const
    {
        return m_position;
    }
    
    
   
    int Vehicle::getId() const
    {
        return m_id;
    }
    
    void Vehicle::setSpeed(int newSpeed)
    {
        if (newSpeed > getMaxSpeed())
        {
            m_speed = getMaxSpeed();
        }
        else
        {
            m_speed = newSpeed;
        }
    }
    void Vehicle::increaseSpeed(int delta)
    {
        int newSpeed = m_speed + delta;
        setSpeed(newSpeed);
        
        
        
        std::cout << "Increasing speed  to: " << m_speed << std::endl;
    }
    
    void Vehicle::decreaseSpeed(int delta)
    {
        int newSpeed = m_speed - delta;
        
        if (newSpeed < 0)
        {
            m_speed = 0;
        }
        else
        {
            m_speed = newSpeed;
        }
        
        std::cout << "Decreasing speed to: " << m_speed << std::endl;
    }
    
    void Vehicle::resetPosition()
    {
        m_position = 0;
    }
    
    void Vehicle::setLane(Lane* lane)
    {
        m_lane = lane;
    }
    
   
    void Vehicle::update()
    {
        std::cout << "Updating vehicle " << m_id << std::endl;
        m_position += m_speed;
    }
    
    


Vehicle::~Vehicle() 
{
    std::cout << "Deleting vehicle " << m_id << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle)
{
    os << "Id: " << vehicle.m_id << std::endl << "Type: " << vehicle.getTypeDescription() << std::endl <<"Position: " << vehicle.m_position << std::endl << "Speed: " << vehicle.m_speed << std::endl << "Max speed: " << vehicle.getMaxSpeed() << std::endl;
    return os;
}


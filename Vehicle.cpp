/* 
 * File:   Vehicle.cpp
 * Author: maarten
 * 
 * Created on July 8, 2013, 2:03 PM
 */

#include "Vehicle.h"
#include "Lane.h"

Vehicle::Vehicle(int id, int initialSpeed)
     :m_id(id), m_position(0), m_speed(initialSpeed)
{
    
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
    void Vehicle::increaseSpeed(int delta)
    {
        int newSpeed = m_speed + delta;
        
        
        if (newSpeed > getMaxSpeed())
        {
            m_speed = getMaxSpeed();
        }
        else
        {
            m_speed = newSpeed;
        }
        
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
        std::cout << "Updating vehicle.." << std::endl;
        m_position += m_speed;
        if (m_lane->isEndOfLane(m_position))
        {
            m_lane->laneEndReached(this);
        }
        
    }
    
    


Vehicle::~Vehicle() 
{
    std::cout << "Deleting vehicle..." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle)
{
    os << "Id: " << vehicle.m_id << std::endl << "Type: " << vehicle.getTypeDescription() << std::endl <<"Position: " << vehicle.m_position << std::endl << "Speed: " << vehicle.m_speed << std::endl << "Max speed: " << vehicle.getMaxSpeed() << std::endl;
    return os;
}


/* 
 * File:   Lane.cpp
 * Author: maarten
 * 
 * Created on July 8, 2013, 4:30 PM
 */

#include "Lane.h"
#include <algorithm>
#include <iostream>

Lane::Lane(int length)
  :m_maxSpeed(0), m_length(length)
{
    
}
void Lane::addVehicle(Vehicle* vehicle)
{
    m_vehicles.push_back(vehicle);
}
void Lane::removeVehicle(Vehicle* vehicle)
{
     
     m_vehicles.erase(std::remove(m_vehicles.begin(), m_vehicles.end(), vehicle), m_vehicles.end());
}

 Vehicle* Lane::getVehicle(int id) const
    {
        for (Vehicle* vehicle : m_vehicles)
        {
            if (vehicle->getId() == id)
            {
                return vehicle;
            }
        }
    }
void Lane::update()
{
    
    for (Vehicle* vehicle:m_vehicles)
    {
        if (vehicle != nullptr)
        {
          vehicle->update();
        }
    }
}
bool Lane::isEndOfLane(int position) const
{
    return position >= m_length;
}
void Lane::laneEndReached(Vehicle* vehicle)
{
    std::cout << "Lane end: " << vehicle->getId() << std::endl;
    removeVehicle(vehicle);
    
}
Lane::~Lane()
{
    for (Vehicle* vehicle:m_vehicles)
    {
        delete vehicle;
    }
}

std::ostream& operator<<(std::ostream& os, const Lane& lane)
{
    for (Vehicle* vehicle:lane.m_vehicles)
    {
        os << *vehicle;
    }
    
    return os;
    
}


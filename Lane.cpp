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
    std::cout << "Ctor Lane" << std::endl;
}

Lane::Lane(const Lane& orig)
  :m_maxSpeed(orig.m_maxSpeed), m_length(orig.m_length)
{
    std::cout << "Copy Ctor Lane" << std::endl;
    for(Vehicle* orig_vehicle: orig.m_vehicles)
    {
        Vehicle* newVehicle = orig_vehicle->clone();
        addVehicle(newVehicle);
    }
}

Lane::Lane()
  :m_maxSpeed(0), m_length(0)
{
    
}
void Lane::addVehicle(Vehicle* vehicle)
{
    vehicle->setLane(this);
    m_vehicles.push_back(vehicle);
    
}


void Lane::removeVehicle(Vehicle* vehicle)
{
    delete vehicle;
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
     for (std::list<Vehicle*>::iterator it = m_vehicles.begin(); it != m_vehicles.end();)
     {
         (*it)->update();
         
         if (isEndOfLane((*it)->getPosition()))
          {
              std::cout << "Lane end: " << (*it)->getId() << std::endl;
              delete *it;
              it = m_vehicles.erase(it);
          }
         else
         {
             ++it;
         }
         
     }
   
    
}
bool Lane::isEndOfLane(int position) const
{
    return position >= m_length;
}

Lane::~Lane()
{
    std::cout << "Deleting lane..."<< std::endl;
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


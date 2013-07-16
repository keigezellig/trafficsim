/* 
 * File:   RoadPart.cpp
 * Author: maarten
 * 
 * Created on July 10, 2013, 11:38 AM
 */

#include "RoadPart.h"
#include <functional>
#include <boost/signals2/slot.hpp>



RoadPart::RoadPart(int numberOfLanes, int laneLength)
     :m_numberOfLanes(numberOfLanes)
{
    
}
/*RoadPart::RoadPart(const RoadPart& orig)
        :m_numberOfLanes(orig.m_numberOfLanes)
{
   
}*/

void RoadPart::addVehicle(std::unique_ptr<Vehicle> vehicle)
{
    Vehicle* veh = vehicle.get();
    veh->addCheckPositionSignal(std::bind(&RoadPart::checkPositionSlot, this, std::placeholders::_1));
    m_vehicles.push_back(std::move(vehicle));
}

void RoadPart::update(int time)
{
    for (std::unique_ptr<Vehicle>& vp : m_vehicles)
    {
        vp.get()->update(time);
    }
}


RoadPart::~RoadPart()
{
   
}

std::ostream& operator<<(std::ostream& os, const RoadPart& part)
{
    for (int i = 0; i < part.m_numberOfLanes; i++)
    {
        //os << "Lane " << i << std::endl << *(part.m_lanes[i]);
    }
    
    return os;
    
}

void RoadPart::checkPositionSlot(const PVData& data)
{
    std::cout << "Checking position " << data;
}


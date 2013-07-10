/* 
 * File:   RoadPart.cpp
 * Author: maarten
 * 
 * Created on July 10, 2013, 11:38 AM
 */

#include "RoadPart.h"



RoadPart::RoadPart(int numberOfLanes, int laneLength)
     :m_numberOfLanes(numberOfLanes)
{
    for (int i=0; i < numberOfLanes; i++)
    {
        m_lanes.push_back(new Lane(laneLength));
    }
}
RoadPart::RoadPart(const RoadPart& orig)
        :RoadPart::RoadPart(orig.m_numberOfLanes, orig.m_lanes.size())
{
    for(Lane* orig_lane: orig.m_lanes)
    {
        Lane* newLane = new Lane(*orig_lane);
        m_lanes.push_back(newLane);
    }
}
int RoadPart::getNumberOfLanes() const
{
    return m_numberOfLanes;
}
void RoadPart::addVehicle(Vehicle* vehicle, int laneIndex)
{
    if (laneIndex >= 0 && laneIndex < m_numberOfLanes )
    {   
        Lane* lane = m_lanes[laneIndex];
        lane->addVehicle(vehicle);
    }
    
}
void RoadPart::update()
{
    for(Lane* lane: m_lanes)
    {
        lane->update();
    }
}

RoadPart::~RoadPart()
{
   std::cout << "Deleting roadpart"<< std::endl;
    for(Lane* lane: m_lanes)
    {
        
       delete lane;
    }

}

std::ostream& operator<<(std::ostream& os, const RoadPart& part)
{
    for (int i = 0; i < part.m_numberOfLanes; i++)
    {
        os << "Lane " << i << std::endl << *(part.m_lanes[i]);
    }
    
    return os;
    
}


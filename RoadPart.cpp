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
    
}
RoadPart::RoadPart(const RoadPart& orig)
        :m_numberOfLanes(orig.m_numberOfLanes)
{
   
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


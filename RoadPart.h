/* 
 * File:   RoadPart.h
 * Author: maarten
 *
 * Created on July 10, 2013, 11:38 AM
 */

#ifndef ROADPART_H
#define	ROADPART_H

#include <vector>
#include <iostream>
#include "Vehicle.h"
#include "Lane.h"

class RoadPart {
public:
    explicit RoadPart(int numberOfLanes, int laneLength);
    RoadPart(const RoadPart& orig);
    int getNumberOfLanes() const;
    void addVehicle(Vehicle* vehicle, int laneIndex);
    void update();
    
    virtual ~RoadPart();
    
    friend std::ostream& operator<<(std::ostream& os, const RoadPart& part);
private:
    std::vector<Lane*> m_lanes;
    int m_numberOfLanes;

};

#endif	/* ROADPART_H */


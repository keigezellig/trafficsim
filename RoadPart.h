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
#include <memory>
#include "Vehicle.h"


class RoadPart {
public:
    explicit RoadPart(int numberOfLanes, int laneLength);
   // RoadPart(const RoadPart& orig);
    void addVehicle(std::unique_ptr<Vehicle> vehicle);
    void update(int time);
    virtual ~RoadPart();
    
    friend std::ostream& operator<<(std::ostream& os, const RoadPart& part);
private:
    int m_numberOfLanes;
    std::vector<std::unique_ptr<Vehicle>> m_vehicles;
    void checkPositionSlot(const PVData& data);
};

#endif	/* ROADPART_H */


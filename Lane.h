/* 
 * File:   Lane.h
 * Author: maarten
 *
 * Created on July 8, 2013, 4:30 PM
 */

#ifndef LANE_H
#define	LANE_H

#include <vector>
#include "Vehicle.h"
class Lane {
public:
    explicit Lane(int length);
    Lane();
    Lane(const Lane& orig);
    void addVehicle(Vehicle* vehicle);
    void removeVehicle(Vehicle* vehicle);
    Vehicle* getVehicle(int id) const;
    void update();
    bool isEndOfLane(int position) const;
    void laneEndReached(Vehicle* vehicle);
    virtual ~Lane();
    friend std::ostream& operator<<(std::ostream& os, const Lane& lane);
private:
    std::vector<Vehicle*> m_vehicles;
    int m_maxSpeed;
    int m_length;
    

};

#endif	/* LANE_H */


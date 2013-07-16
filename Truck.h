/* 
 * File:   Car.h
 * Author: maarten
 *
 * Created on July 8, 2013, 3:44 PM
 */

#ifndef TRUCK_H
#define	TRUCK_H

#include "Vehicle.h"
class Truck  : public Vehicle {
public:
    Truck();
    Truck(int id, int initialSpeed);
    
    virtual ~Truck();
protected:
    virtual PVData calculateNewPosition() const;
    virtual void onPositionNotAvailable(const PVData& position, const PositionStatus& status);
    

};

#endif	/* CAR_H */


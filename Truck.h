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
    Truck(int id, int initialSpeed, int initialPosition = 0);
    virtual int getMaxSpeed() const;
    virtual std::string getTypeDescription() const;
    virtual Truck* clone() const;
    virtual ~Truck();
protected:
    
    Truck(const Truck& truck);

};

#endif	/* CAR_H */


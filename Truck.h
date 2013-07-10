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
    explicit Truck(int id, int initialSpeed);
    Truck(const Truck& truck);
    virtual int getMaxSpeed() const;
    virtual std::string getTypeDescription() const;
    virtual Truck* clone() const;
    virtual ~Truck();
private:

};

#endif	/* CAR_H */


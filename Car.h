/* 
 * File:   Car.h
 * Author: maarten
 *
 * Created on July 8, 2013, 3:44 PM
 */

#ifndef CAR_H
#define	CAR_H

#include "Vehicle.h"
class Car  : public Vehicle {
public:
    Car(int id, int initialSpeed);
    Car(const Car& car);
    Car* clone() const;
    virtual int getMaxSpeed() const;
    virtual std::string getTypeDescription() const;
    virtual ~Car();
private:

};

#endif	/* CAR_H */


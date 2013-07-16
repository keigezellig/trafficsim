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
    Car();
    Car(int id, int initialSpeed);
    virtual ~Car();

};

#endif	/* CAR_H */


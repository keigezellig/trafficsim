/* 
 * File:   Car.cpp
 * Author: maarten
 * 
 * Created on July 8, 2013, 3:44 PM
 */

#include "Car.h"



    Car::Car(int id, int initialSpeed,  Lane* lane)
      :Vehicle(id, initialSpeed, lane)
    {
        
    }
    int Car::getMaxSpeed() const
    {
        return 130000;
    }
    
    std::string Car::getTypeDescription() const
    {
        return "Car";
    }
    Car::~Car()
    {
        
    }


/* 
 * File:   Truck.cpp
 * Author: maarten
 *
 * Created on July 8, 2013, 3:59 PM
 */

#include "Truck.h"

    Truck::Truck(int id, int initialSpeed)
      :Vehicle(id, initialSpeed)
    {
        
    }
    
    int Truck::getMaxSpeed() const
    {
        return 80000;
    }
    
    std::string Truck::getTypeDescription() const
    {
        return "Truck";
    }
    Truck::~Truck()
    {
        
    }


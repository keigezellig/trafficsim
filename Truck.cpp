/* 
 * File:   Truck.cpp
 * Author: maarten
 *
 * Created on July 8, 2013, 3:59 PM
 */

#include "Truck.h"
#include <iostream>

    Truck::Truck(int id, int initialSpeed)
      :Vehicle(id, initialSpeed)
    {
        std::cout << "Ctor Truck" << std::endl;
    }
    Truck::Truck(const Truck& truck)
      :Vehicle(truck)
   {
        std::cout << "Copy ctor Truck" << std::endl;
   }
   
    Truck* Truck::clone() const
    {
        std::cout << "Cloning Truck" << std::endl;
        return new Truck(*this);
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


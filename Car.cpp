/* 
 * File:   Car.cpp
 * Author: maarten
 * 
 * Created on July 8, 2013, 3:44 PM
 */

#include "Car.h"



    Car::Car(int id, int initialSpeed)
      :Vehicle(id, initialSpeed)
    {
        std::cout << "Ctor Car" << std::endl;
    }
    
   Car::Car(const Car& car)
      :Vehicle(car)
   {
       std::cout << "Copy Ctor Car" << std::endl;
   }
    
    Car* Car::clone() const
    {
        std::cout << "Cloning Car" << std::endl;
        return new Car(*this);
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


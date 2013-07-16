/* 
 * File:   Car.cpp
 * Author: maarten
 * 
 * Created on July 8, 2013, 3:44 PM
 */

#include "Car.h"



    Car::Car()
      :Vehicle()
    {
        m_maxSpeed = 130000;
    }
    Car::Car(int id, int initialSpeed)
      :Vehicle(id,initialSpeed)
    {
     
        m_maxSpeed = 130000;
    }
    Car::~Car()
    {
        
    }



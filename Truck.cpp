/* 
 * File:   Truck.cpp
 * Author: maarten
 *
 * Created on July 8, 2013, 3:59 PM
 */

#include "Truck.h"
#include <iostream>
#include <algorithm>

    Truck::Truck()
      :Vehicle()
    {
        m_maxSpeed = 80000;
    }
    Truck::Truck(int id, int initialSpeed)
      :Vehicle(id,initialSpeed)
    {
        m_maxSpeed = 80000;
    }
    Truck::~Truck()
    {
        
    }
    
    PVData Truck::calculateNewPosition() const
    {
        int a = 1000; 
        int newSpeed = std::min(m_position.m_speed + a, m_maxSpeed);
        int newX = m_position.m_x + newSpeed;  
        return PVData(newX, m_position.m_y, newSpeed);
    }
    void Truck::onPositionNotAvailable(const PVData& position, const PositionStatus& status)
    {
        
    }


/* 
 * File:   Vehicle.h
 * Author: maarten
 *
 * Created on July 8, 2013, 2:03 PM
 */

#ifndef VEHICLE_H
#define	VEHICLE_H
#include <iostream>
#include <string>

class Lane;

class Vehicle {
public:
    explicit Vehicle(int id, int initialSpeed, Lane* lane);
    int getSpeed() const;
    int getPosition() const;
    
    void increaseSpeed(int delta);
    void resetPosition();
    void update();
    virtual int getMaxSpeed() const = 0;
    int getId() const;
    virtual std::string getTypeDescription() const = 0;
    
    virtual ~Vehicle();
    friend std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle); 
private:
    int m_id;
    int m_speed;
    int m_position;
    Lane* m_lane;
    

};

#endif	/* VEHICLE_H */


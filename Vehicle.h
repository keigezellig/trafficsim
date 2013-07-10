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

enum class VehicleType {CAR, TRUCK};

class Lane;


class Vehicle {
public:
    
    static Vehicle* createVehicle(int id, VehicleType type, int initialSpeed, int initialPosition = 0);
    
   
    
    int getSpeed() const;
    int getPosition() const;
    

    void increaseSpeed(int delta);
    void decreaseSpeed(int delta);
    void resetPosition();
    void setLane(Lane* lane);
    void setSpeed(int newSpeed);
    void update();
    virtual int getMaxSpeed() const = 0;
    int getId() const;
    virtual std::string getTypeDescription() const = 0;
 
    virtual Vehicle* clone() const = 0;
    virtual ~Vehicle();
    friend std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle); 
protected:
    Vehicle(int id, int initialSpeed, int initialPosition = 0);
    Vehicle(const Vehicle& vehicle);
private:
   
    int m_id;
    int m_speed;
    int m_position;
    const Lane* m_lane;
    
    

};

#endif	/* VEHICLE_H */


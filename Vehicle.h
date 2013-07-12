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
enum class PositionStatus {OK, ROAD_END, POSITION_OCCUPIED};


struct Position
{
    int m_x;       //Horizontal position in meters
    int m_y;       //Lane number 
    
    Position(int x, int y)
    {
        m_x = x;
        m_y = y;
    }
    
   std::ostream& operator<<(std::ostream& os, const Position& pos)
{
    os << "(" << pos.m_x << "," << pos.m_y << ")" << std::endl;
    return os;
}
    
};

class Vehicle {
public:
    
    static Vehicle* createVehicle(int id, VehicleType type, int initialSpeed, int initialPosition = 0);
    
    int getSpeed() const;
    int getPosition() const;
    int getId() const;
    void increaseSpeed(int delta);
    void decreaseSpeed(int delta);
    void update();
    virtual ~Vehicle();
    friend std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle);
    
protected:
    Vehicle();
    Vehicle(int id, int initialSpeed);
    virtual Position calculateNewPosition() const;
    virtual void onPositionNotAvailable(const Position& position, const PositionStatus& status);
    
private:
    int m_id;
    int m_speed;
    int m_maxSpeed;
    Position m_position;
    PositionStatus isPositionAvailable(const Position& position) const;
    
    
    

};

#endif	/* VEHICLE_H */


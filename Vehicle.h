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
enum class PositionStatus {OK, ROAD_END, LANE_OCCUPIED, HORIZONTAL_POS_OCCUPIED };


struct PVData
{
    int m_x;       //Horizontal position in meters
    int m_y;       //Lane number 
    int m_speed;     //Speed in meters/time unit
    
    PVData(int x, int y, int speed)
    {
        m_x = x;
        m_y = y;
        m_speed = speed;
    }
    
 friend std::ostream& operator<<(std::ostream& os, const PVData& pos)
{
    os << "(" << pos.m_x << "," << pos.m_y << ")" << std::endl;
    return os;
}
    
};

class Vehicle {
public:
    
    static Vehicle* createVehicle(int id, VehicleType type, int initialSpeed, int initialPosition = 0);
    
    int getSpeed() const;
    int getHorizontalPosition() const;
    int getLanePosition() const;
    int getTime() const;
    int getId() const;
    void update(int time);
    virtual ~Vehicle();
    friend std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle);
    
protected:
    Vehicle();
    Vehicle(int id, int initialSpeed);
    virtual PVData calculateNewPosition() const;
    virtual void onPositionNotAvailable(const PVData& position, const PositionStatus& status);
    void setSpeed(int newSpeed);
    int m_id;
    int m_time;
    int m_maxSpeed;
    PVData m_position; 
    
private:
    
    PositionStatus isPositionAvailable(const PVData& position) const;
    
    
    

};

#endif	/* VEHICLE_H */


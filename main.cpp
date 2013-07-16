/* 
 * File:   main.cpp
 * Author: maarten
 *
 * Created on July 8, 2013, 2:02 PM
 */

#include <cstdlib>

#include "Vehicle.h"
#include "RoadPart.h"




using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    
    RoadPart* r = new RoadPart(4,100000);
    r->addVehicle(std::unique_ptr<Vehicle>(Vehicle::createVehicle(1,VehicleType::CAR,50000)));
    r->addVehicle(std::unique_ptr<Vehicle>(Vehicle::createVehicle(2,VehicleType::TRUCK,50000)));
    r->addVehicle(std::unique_ptr<Vehicle>(Vehicle::createVehicle(4,VehicleType::CAR,50000)));
    
    
    
    
    
    
    int time = 0;
  
    
    while (true)
    {
        //cout << v1 << v2 << v3 << v4;
        char key = getchar();
        

            if (key == 'n')
            {
                break;
            }
        r->update(time);
        
       
        
        
        
        //cout << v1 << v2 << v3 << v4;
        
        

            
    }
    
    delete r;
    return 0;
}


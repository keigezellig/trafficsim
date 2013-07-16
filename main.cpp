/* 
 * File:   main.cpp
 * Author: maarten
 *
 * Created on July 8, 2013, 2:02 PM
 */

#include <cstdlib>

#include "Car.h"
#include "RoadPart.h"
#include "Truck.h"



using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    
    RoadPart* r = new RoadPart(4,100000);
    r->addVehicle(std::unique_ptr<Vehicle> (new Car(1,50000)));
    r->addVehicle(std::unique_ptr<Vehicle> (new Car(2,45000)));
    r->addVehicle(std::unique_ptr<Vehicle> (new Truck(3,20000)));
    r->addVehicle(std::unique_ptr<Vehicle> (new Truck(4,50000)));
    
    
    
    
    
    
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


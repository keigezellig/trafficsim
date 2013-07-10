/* 
 * File:   main.cpp
 * Author: maarten
 *
 * Created on July 8, 2013, 2:02 PM
 */

#include <cstdlib>
#include "Lane.h"
#include "Car.h"
#include "Truck.h"
#include "RoadPart.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    
    int time = 0;
    std::cout << "Constructing part1" << std::endl;
    RoadPart* part1 = new RoadPart(4,1000000);
    part1->addVehicle(new Car(1,50000),0);
    part1->addVehicle(new Truck(2, 30000),0);
    part1->addVehicle(new Car(3, 80000),0);
     part1->addVehicle(new Truck(4,50000),1);
    part1->addVehicle(new Truck(5, 90000),1);
    part1->addVehicle(new Car(6, 130000),1);
    
     std::cout << "*********************************" << std::endl;
      std::cout << "Constructing part2" << std::endl;
    RoadPart* part2 = new RoadPart(*part1);
    
    
    
    
    
    //std::cout << "Time = " << time << std::endl << part1;
    
    while (true)
    {
       
        char key = getchar();
        

            if (key == 'n')
            {
                break;
            }
           

            part1->update();
            part2->update();
            time++; 
            
             std::cout << "Time = " << time << std::endl << "********************" << std::endl  << *part2 << std::endl << "*********************" << std::endl;

    }
    
    delete part1;
    delete part2;
    return 0;
}


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


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    
    int time = 0;
    Lane* lane1 = new Lane(1000000);
    lane1->addVehicle(new Car(1, 50000,lane1));
    lane1->addVehicle(new Truck(2, 30000,lane1));
    lane1->addVehicle(new Car(3, 50000,lane1));
    
    std::cout << "Time = " << time << std::endl << *lane1;
    
    while (true)
    {
       
        char key = getchar();
        if (key != '\n')
        {

            if (key == 'n')
            {
                break;
            }
            else if (key == '+')
            {
                lane1->getVehicle(1)->setSpeed(80000);
            }

            lane1->update();
            time++; 
            
             std::cout << "Time = " << time << std::endl << "********************" << std::endl << *lane1 << std::endl << "*********************" << std::endl;

        }
    }
    
    delete lane1;
    return 0;
}


/* 
 * File:   main.cpp
 * Author: maarten
 *
 * Created on July 8, 2013, 2:02 PM
 */

#include <cstdlib>

#include "Car.h"

#include "Truck.h"



using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    
    Car v1(1,50000);
    Car v2(2,45000);
    Truck v3(3,20000);
    Truck v4(4,0);
    
    int time = 0;
  
    
    while (true)
    {
        cout << v1 << v2 << v3 << v4;
        char key = getchar();
        

            if (key == 'n')
            {
                break;
            }
       
        v1.update(time);
        v2.update(time);
        v3.update(time);
        v4.update(time);
        
        cout << v1 << v2 << v3 << v4;
        
        

            
    }
    
   
    return 0;
}


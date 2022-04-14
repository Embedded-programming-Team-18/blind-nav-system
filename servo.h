#ifndef SERVO_H
#define SERVO_H

#include <stdio.h>
#include <stdint.h>
#include <pigpio.h>
#include <iostream>
#include <mutex>


/**
* 
* @section DESCRIPTION
* This class represent the servo motor class. 
*/ 
/**
* @brief The servo class is tighly coupled with the lidar to perform a full scan of 90 packets (90 degrees field of view)
*
* This class   
*/
class Servo{
    private:
        int step;
        int startAngle;
        int angle;
        int flag;
        int endAngle;

    public:
        Servo(){
            step=1000/90;
            angle=0;
            //flag=1000;
            startAngle=0;
            endAngle=90;
        }
        int move();
};

#endif
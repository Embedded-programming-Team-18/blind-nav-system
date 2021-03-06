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
* This class manages the servo motor by moving it in the right direction when asked to move.
* It has one class method move which gets called.  
*/
class Servo{
    private:
        int step;
        int startAngle;
        int angle;
        int flag;
        int endAngle;

    public:
    /**
        * This method has different variables to help us set the step size, start and end angles and flags to develop our code.
        *
    **/
        Servo()
        {
            step=1000/90;
            angle=0;
            startAngle=0;
            endAngle=89;
        }
        int move();
};

#endif
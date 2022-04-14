#ifndef SERVO_H
#define SERVO_H

#include <stdio.h>
#include <stdint.h>
//#include <unistd.h>
#include <pigpio.h>
#include <iostream>
#include <mutex>

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
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
        static int steps;
        static int step;
        static int startAngle;
        static int angle;
        static int flag;
        static int endAngle;

    public:
        static void start();
        static int move();
};

#endif
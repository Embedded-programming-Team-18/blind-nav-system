#ifndef SERVO_H
#define SERVO_H

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <pigpio.h>

class Servo{
    private:
        static int steps=0;
        static int step=1000/90;
        static int startDirection;
        static int angle=1;
        static int flag=1000;
        static int endDirection;

    public:
        static void start();
        static int move();
}

#endif
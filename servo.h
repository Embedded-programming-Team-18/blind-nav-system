#ifndef SERVO_H
#define SERVO_H

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <pigpio.h>

struct ServoInit{
        int startAngle;
        int endAngle;
    };

class Servo{
    private:
        static int steps;
        static int step;
        static int startDirection;
        static int angle;
        static int flag;
        static int endDirection;

    public:
        Servo();
        static void start(ServoInit init);
        static int move();
};

#endif
#ifndef LIDAR_H
#define LIDAR_H

#include <stdio.h>
#include <unistd.h>  //Used for UART
#include <fcntl.h>   //Used for UART
#include <termios.h> //Used for UART
#include <iostream>
#include <cstring>
#include <pigpio.h>
#include <thread>
#include <mutex>
#include "servo.h"

class Lidar{
    public:
        // This is the number of distances to obtain from the lidar. 
        //It represents a complete scan
        static const unsigned nDistance = 90;
        
        // This stores all the data received in a complete scan
        int LidarData[nDistance];

        Lidar(bool _doInit = true) {
		    doInit = _doInit;
	    }

        // This is a function to initialize variables/settings needed by the library.
        // It has a serial port argument which is "/dev/ttyS0" by default
        void start(const char *serial_port = "/dev/ttyS0");
        
        // Stops the thread
        void stop();
        
        ~Lidar() {
            stop();
		    gpioTerminate();
	    }

        /**
        * Callback interface which needs to be implemented by the user.
        **/
        struct DataInterface {
            virtual void newScanAvail(int (&)[Lidar::nDistance]) = 0;
        };

        /**
        * Register the callback interface here to receive data.
        **/
        void registerInterface(DataInterface* di) {
            dataInterface = di;
        }

    private:
        int tty_fd= -1;
        DataInterface* dataInterface = nullptr;
        bool running = true;
        std::thread* worker = nullptr;
        static void run(Lidar* Lidar);
        bool doInit = true;
        std::mutex readoutMtx;
        int angle = 0;
};

#endif
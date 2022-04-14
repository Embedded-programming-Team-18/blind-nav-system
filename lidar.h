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
#include <chrono>
#include "servo.h"


/**
* 
* @section DESCRIPTION
* This class represents the LiDAR sensor. 
*/ 
/**
* @brief The LiDAR class is a low-level driver for obtaining distance values needed for the functioning of the blind navigation system.
*
* This class manages TFMini LiDAR sensor and couples the microcontroller such that the executable only needs.
* to implement the data interface  callback method. It runs a thread and uses UART for serial communication.
*   
*/
class Lidar{
    public:
        /* This is the number of distances to obtain from the lidar. 
        *  It represents a complete scan (the obstacle scan + 90 scan degree field of view)
        */
        static const unsigned nDistance = 91;
        
        // This stores all the data received in a complete scan
        int LidarData[nDistance];

        /**
        * Constructor that sets the object to commence.
        * 
        * @param _doInit bool has default value: true
        */ 
        Lidar(bool _doInit = true) {
		    doInit = _doInit;
	    }

        /**
        * This is a method to initialize variables and other settings needed by the library.
        * @param serial_port const char* default  "/dev/ttyS0".
        *
        * @return void
        */
        void start(const char *serial_port = "/dev/ttyS0");
        
        /**
        * This is a method join the Lidar thread, close serial port, and terminate gpio.
        *
        * @return void
        */
        void stop();
        
        /**
        * Destructor to call stop() method and terminate gpio
        *
        */
        ~Lidar() {
            stop();
		    gpioTerminate();
	    }

        /**
        * Callback interface which needs to be implemented by the user.
        *
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
        Servo lidarServo;
};

#endif
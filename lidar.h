#ifndef LIDAR_H
#define LIDAR_H

#include <stdio.h>
#include <unistd.h>  //Used for UART
#include <fcntl.h>   //Used for UART
#include <termios.h> //Used for UART
#include <iostream>
#include <cstring>
#include <pigpio.h>

class Lidar{
    
    private:
        int tty_fd= -1;
        DataInterface* dataInterface = nullptr;
        bool running = true;
        int LidarData[nDistance];
        int angle=0;
        std::thread* worker = nullptr;
        void run(Lidar* Lidar);
        bool doInit = true;

    public:

        static const unsigned nDistance = 90;

        Lidar(bool _doInit = true) {
		    doInit = _doInit;
	    }
        void start(const char *serial_port = "/dev/ttyS0");
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

}

#endif
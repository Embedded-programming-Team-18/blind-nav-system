#ifndef LIDAR_H
#define LIDAR_H

#include <stdio.h>
#include <unistd.h>  //Used for UART
#include <fcntl.h>   //Used for UART
#include <termios.h> //Used for UART
#include <iostream>
#include <cstring>

class Lidar{
    
    private:
    int tty_fd= -1;
	bool running = true;
    int LidarData[90];
    int angle=0;
    std::thread* worker = nullptr;

    public:
        Lidar();
        void start(const char *serial_port = "/dev/ttyS0");
        void stop();
        void run();
        
        ~Lidar() {
		
	    }

}

#endif
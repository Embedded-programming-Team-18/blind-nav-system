#include "lidar.h"
//#include <unistd.h>


void Lidar::start(const char *serial_port) {
    if (nullptr != worker) return;

    // pgpio is initialized here
    if (doInit) {
        if (gpioInitialise() < 0) {
            throw "gpioInitialise failed";
        }
    }

    tty_fd = open(serial_port, O_RDWR); // Open in non blocking read/write mode
    if (tty_fd < 0)
    {
    // ERROR - CAN'T OPEN SERIAL PORT
    std::cout <<"Error - Unable to open serial port.\n";
    }

    // CONFIGURE THE UART
    struct termios tty_opt;
    memset(&tty_opt, 0, sizeof(tty_opt));
    tty_opt.c_cflag = CS8 | CLOCAL | CREAD;
    // CS8: 8n1, CLOCAL: local connection, no modem contol, CREAD: enable receiving characters
    tty_opt.c_iflag = 0;
    tty_opt.c_oflag = 0;
    tty_opt.c_lflag = 0;     // non-canonical mode
    tty_opt.c_cc[VMIN] = 1;  // blocking read until 1 character arrives
    tty_opt.c_cc[VTIME] = 0; // inter-character timer unused
    cfsetospeed(&tty_opt, B115200);
    cfsetispeed(&tty_opt, B115200);
    tcsetattr(tty_fd, TCSANOW, &tty_opt);
    
    // Create the thread which starts running
    worker = new std::thread(Lidar::run,this);
}


void Lidar::run(Lidar* Lidar) {
    // This represent a single read
    unsigned char buf[9];
    // This variable hold the distance value from a single read
    unsigned int dist;
    bool dataAvailable = true;
    int angle=0;
    // start servo
    Servo::start();
    // The thread keeps running
    while (Lidar->running) {
        int f1 = read(Lidar->tty_fd, &buf, 1);
        //std::cout << "Read" << f1 <<"bytes. Received message: " << buf[0];
        // find the header 0xFA 0xA0
        if (1==f1 &&
            0x59==buf[0] &&
            1==read(Lidar->tty_fd, buf+1, 1) &&
            0x59==buf[1]) {
            // read the remaining bytes from the serial port 
            for (int idx=2; idx<9; idx++){
                if (1!=read(Lidar->tty_fd, buf+idx, 1)) break;
                //std::cout << "bytes: "<< idx<<" "<<buf[idx]<<"\n";
            }

            // Calculate the distance
            dist = buf[2]+(buf[3]*256);
            Lidar->LidarData[angle]=dist;
            std::cout << "Distance: "<< Lidar->LidarData[angle]<<" Angle: "<< angle <<"\n"; 
            if (dataAvailable && nullptr!= Lidar->dataInterface){
                Lidar->dataInterface->newScanAvail(Lidar->LidarData);
            }

            Lidar->readoutMtx.lock();
                // Ask servo to move
                angle = Servo::move();
            Lidar->readoutMtx.unlock(); 

        }else{
            std::cout << "Incomplete header: ";
            //usleep(500000);
        }  
        
    }//while loop ends
    close(Lidar->tty_fd);
}


void Lidar::stop(){
    close(tty_fd);
    running = false;
    if (nullptr != worker) {
        worker->join();
        delete worker;
        worker = nullptr;
    }
}
        

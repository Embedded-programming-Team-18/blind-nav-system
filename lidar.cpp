#include "lidar.h"

class Lidar{

    public:
        
        void Lidar::start(const char *serial_port) {
            if (nullptr != worker) return;

            tty_fd = open(serial_port, O_RDWR); // Open in non blocking read/write mode
            if (tty_fd < 0)
            {
            // ERROR - CAN'T OPEN SERIAL PORT
            printf("Error - Unable to open serial port.\n");
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
            
            worker = new std::thread(Lidar::run,this);
        }


    void Lidar::run(Lidar* Lidar) {
        unsigned char buf[9];
        unsigned int dist;
        //start servo
        while (Lidar->running) {
             cout << "In loop\n";
            int f1 = read(Lidar->tty_fd, &buf, 1);
            printf("Read %i bytes. Received message: %d", f1, buf[0]);
            if (1==f1 &&
                0x59==buf[0] &&
                1==read(Lidar->tty_fd, buf+1, 1) &&
                0x59==buf[1]) {
                    cout << "FIrst 2 header read\n";
                // find the header 0xFA 0xA0
                for (int idx=2; idx<9; idx++){
                    if (1!=read(Lidar->tty_fd, buf+idx, 1)) break;
                    //cout << "bytes: "<< idx<<" "<<buf[idx]<<"\n";
                }
                dist = buf[2]+(buf[3]*256);
                Lidar->LidarData[Lidar->angle]=dist;
                cout << "Distance: "<< dist<<"\n";
                
                // Ask servo to the next angle 
            }else{
                cout << "Incomplete header: ";
            }  
            
        }//whil loop ends
	
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
        
}
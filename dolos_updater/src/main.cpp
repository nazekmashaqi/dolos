#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include <vector>
#include <dirent.h>
#include "bsl_commands/BSLCommandManager.h"
#include "bsl_commands/BSLCommand.h"
#include "bsl_commands/BSLConnection.h"
#include "bsl_commands/BSLGetDeviceInfo.h"
#include "bsl_commands/BSLUnlockBootloader.h"
/* #include "../bsl_commands/BSLFlashRangeErase.h"
#include "../bsl_commands/BSLProgramData.h"
#include "../bsl_commands/BSLStartApplication.h" */
//#include "BSLCommandReceiveException.h"
#include "bsl_commands/bsl_command_response/BSLGetDeviceInfoResponse.h"
#include "bsl_commands/bsl_command_response/BSLCoreMessageResponse.h"
using namespace std;
string selectSerialPort()
{

    const char *devPath = "/dev";

    DIR *dir = opendir(devPath);

    if (!dir)
    {

        cerr << "Error opening directory: " << devPath << endl;

        return "";
    }

    vector<string> ttyUSBDevices;

    struct dirent *entry;

    while ((entry = readdir(dir)) != nullptr)
    {

        if (entry->d_type == DT_CHR)
        {

            string entryName(entry->d_name);

            if (entryName.find("ttyACM") != string::npos || entryName.find("ttyUSB") != string::npos)
            {

                ttyUSBDevices.push_back(entryName);
            }
        }
    }

    closedir(dir);

    cout << "Select one of tty devices:" << endl;

    int numOfDevice = 1;

    for (const string &device : ttyUSBDevices)
    {

        cout << numOfDevice << ": " << device << endl;

        numOfDevice++;
    }

    int selectedDevice = 0;

    while (selectedDevice <= 0 || selectedDevice > ttyUSBDevices.size())
    {

        cout << "Enter the number of the serial port: ";

        cin >> selectedDevice;
    }

    return "/dev/" + ttyUSBDevices[selectedDevice - 1];
}

int openSerialPort(const string &deviceName)
{

    int serialPort = open(deviceName.c_str(), O_RDWR);
    struct termios tty;

    // Read in existing settings, and handle any error
    if (tcgetattr(serialPort, &tty) != 0)
    {
        printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
        return 1;
    }

    tty.c_cflag &= ~PARENB;        // Clear parity bit, disabling parity (most common)
    tty.c_cflag &= ~CSTOPB;        // Clear stop field, only one stop bit used in communication (most common)
    tty.c_cflag &= ~CSIZE;         // Clear all bits that set the data size
    tty.c_cflag |= CS8;            // 8 bits per byte (most common)
    tty.c_cflag &= ~CRTSCTS;       // Disable RTS/CTS hardware flow control (most common)
    tty.c_cflag |= CREAD | CLOCAL; // Turn on READ & ignore ctrl lines (CLOCAL = 1)

    tty.c_lflag &= ~ICANON;
    tty.c_lflag &= ~ECHO;                                                        // Disable echo
    tty.c_lflag &= ~ECHOE;                                                       // Disable erasure
    tty.c_lflag &= ~ECHONL;                                                      // Disable new-line echo
    tty.c_lflag &= ~ISIG;                                                        // Disable interpretation of INTR, QUIT and SUSP
    tty.c_iflag &= ~(IXON | IXOFF | IXANY);                                      // Turn off s/w flow ctrl
    tty.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL); // Disable any special handling of received bytes

    tty.c_oflag &= ~OPOST; // Prevent special interpretation of output bytes (e.g. newline chars)
    tty.c_oflag &= ~ONLCR; // Prevent conversion of newline to carriage return/line feed

    tty.c_cc[VTIME] = 10; // Wait for up to 1s (10 deciseconds), returning as soon as any data is received.
    tty.c_cc[VMIN] = 0;

    cfsetispeed(&tty, B9600);
    cfsetospeed(&tty, B9600);

    if (tcsetattr(serialPort, TCSANOW, &tty) != 0)
    {
        printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
        return 0;
    }

    return serialPort;
}

int main()
{
    string deviceName = selectSerialPort();

    if (deviceName.empty())
    {
        cerr << "Invalid serial port selected or no serial ports found!" << endl;
        return 1;
    }

    int serial_port = openSerialPort(deviceName);

    if (serial_port == -1)
    {
        cerr << "Error opening the serial port!" << endl;
        return 1;
    }
BSLCommandManager bslCommandManager(serial_port);
    // connection command
    BSLConnection bslConnection;
     BSLGetDeviceInfoResponse* response = nullptr;
    try {
        BSLCommandResponse* commandResponse = bslCommandManager.transmit(&bslConnection);
        response = dynamic_cast<BSLGetDeviceInfoResponse*>(commandResponse);
        if (response != nullptr) {
            std::cout << "Application Version: " << std::hex << "0x" << response->getApplicationVersion() << "\n";
        } else {
            std::cerr << "Unexpected response type.\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    
    close(serial_port);
    return 0;
}
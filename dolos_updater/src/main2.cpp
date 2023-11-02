

#include <iostream>
#include <boost/crc.hpp>

#include <cstdint>

#include <fcntl.h>

#include <termios.h>

#include <unistd.h>

#include <string>
#include <cstring>

#include <vector>
#include <dirent.h>
using namespace std;

class BSLCommand
{

protected:
    const uint8_t transferHeader = 0x80;

    const uint8_t transferCommand;

    uint8_t transferPacket[256];

    const bool expectBSLCoreResponse;

public:
    BSLCommand(uint8_t transferCmd, bool expectResponse)

        : transferCommand(transferCmd), expectBSLCoreResponse(expectResponse)
    {
    }

    uint8_t *getTransferPacket()
    {

        return transferPacket;
    }

    bool isExpectBSLCoreResponse()
    {

        return expectBSLCoreResponse;
    }

public:
    void assembleTransferPacket(const uint8_t *data, size_t dataSize)
    {

        uint8_t commandData[] = {this->transferCommand};

        size_t commandDataSize = sizeof(commandData) / sizeof(commandData[0]);

        size_t packetDataSize = commandDataSize + dataSize;

        uint8_t packetData[packetDataSize];

        // Copy the command data

        memcpy(packetData, commandData, commandDataSize);

        // Copy the additional data

        memcpy(packetData + commandDataSize, data, dataSize);

        uint16_t dataLength = packetDataSize;

        uint8_t dataLengthBytes[] = {uint8_t(dataLength & 0xFF), uint8_t((dataLength >> 8) & 0xFF)};

        // Calculate CRC32 using your CRC32Calculator function

        uint8_t crc32ForData[] = {/* Calculate CRC here */};

        size_t transferPacketSize = sizeof(transferPacket) / sizeof(transferPacket[0]);

        size_t index = 0;

        transferPacket[index++] = this->transferHeader;

        // Copy the data length bytes

        memcpy(transferPacket + index, dataLengthBytes, sizeof(dataLengthBytes));

        index += sizeof(dataLengthBytes) / sizeof(dataLengthBytes[0]);

        // Copy the packet data

        memcpy(transferPacket + index, packetData, packetDataSize);

        index += packetDataSize;

        // Copy the CRC32 bytes

        memcpy(transferPacket + index, crc32ForData, sizeof(crc32ForData));
    }
};
string selectSerialPort()
{

    const char *devPath = "/dev"; // Directory path for ttyUSB devices

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

    cout << "Select one of ttyUSB devices:" << endl;

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

    struct termios config;

    tcgetattr(serialPort, &config);

    cfsetispeed(&config, B9600);

    cfsetospeed(&config, B9600);

    config.c_cflag = (config.c_cflag & ~CSIZE) | CS8; // 8-bit data

    config.c_cflag &= ~PARENB; // No parity

    config.c_cflag &= ~CSTOPB; // One stop bit

    config.c_cflag &= ~CRTSCTS; // No hardware flow control

    config.c_cflag |= CREAD | CLOCAL; // Enable reading and ignore control lines

    tcsetattr(serialPort, TCSANOW, &config);

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

    int serialPort = openSerialPort(deviceName);

    if (serialPort == -1)
    {

        cerr << "Error opening the serial port!" << endl;

        return 1;
    }
    BSLCommand bslCommand(0x12, true);

    uint8_t commandData[] = {};

    size_t commandDataSize = sizeof(commandData) / sizeof(commandData[0]);

    bslCommand.assembleTransferPacket(commandData, commandDataSize);

    uint8_t *transferPacket = bslCommand.getTransferPacket();

    size_t transferPacketSize = sizeof(transferPacket) / sizeof(transferPacket[0]);

    cout << "Transfer Packet: ";

    for (size_t i = 0; i < transferPacketSize; ++i)
    {

        cout << hex << static_cast<int>(transferPacket[i]) << " ";
    }

    cout << dec << endl;
    write(serialPort, transferPacket, transferPacketSize);
    char Buffer2[256];
    try
    {
        ssize_t bytesRead = read(serialPort, Buffer2, sizeof(Buffer2));
        if (bytesRead > 0)
        {

            cout << "Received on Port 2 (in hex): ";

            for (ssize_t i = 0; i < bytesRead; i++)
            {
                cout << hex << (static_cast<int>(Buffer2[i]) & 0xff) << " ";
            }
            cout << endl;
        }
        else
        {
            cerr << "No data received on Port 2." << endl;
        }
    }
    catch (exception e)
    {
        cout << e.what();
    }
    // close(serialPort);
    return 0;
}

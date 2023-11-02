#include <iostream>

#include <iostream>

#include <fcntl.h>

#include <termios.h>

#include <unistd.h>

#include <string.h>

#include <dirent.h>
#include <vector>
#include <cstdint>
#include <sstream>
using namespace std;

vector<uint8_t> HexStringToBytes(const string &hex)
{

    vector<uint8_t> bytes;

    for (size_t i = 0; i < hex.length(); i += 2)
    {

        string byteString = hex.substr(i, 2);

        uint8_t byte = static_cast<uint8_t>(stoi(byteString, 0, 16));

        bytes.push_back(byte);
    }

    return bytes;
}

int main()
{
    // Directory path for ttyUSB devices

    const char *devPath = "/dev";

    // Open the directory

    DIR *dir = opendir(devPath);

    if (!dir)
    {

        cerr << "Error opening directory: " << devPath << endl;

        return 1;
    }

    // Vector to store ttyUSB device names

    vector<string> ttyUSBDevices;

    // Read directory entries

    struct dirent *entry;

    while ((entry = readdir(dir)) != nullptr)
    {

        // Check if the entry is a serial port

        if (entry->d_type == DT_CHR)
        {

            string entryName(entry->d_name);

            if (entryName.find("ttyACM") != string::npos || entryName.find("ttyUSB") != string::npos)
            {

                ttyUSBDevices.push_back(entryName);
            }
        }
    }

    // Close the directory

    closedir(dir);

    // Print the list of ttyUSB devices
    cout << "Select one of ttyUSB devices:" << endl;
    int numOfDevice = 1;
    for (const string &device : ttyUSBDevices)
    {

        cout << numOfDevice << ": " << device << endl;
        numOfDevice++;
    }
    string device;
    while (numOfDevice != -1)
    {
        try
        {
            numOfDevice = 0;
            cin >> numOfDevice;
            if (numOfDevice <= ttyUSBDevices.size())
            {
                device = "/dev/" + ttyUSBDevices[numOfDevice - 1];
                numOfDevice = -1;
                cout << device;
            }
            else
                cout << "Invalid choice, Please select the correct number of serial port" << endl;
        }
        catch (const exception &e)
        {
            cerr << e.what() << '\n';
        }
    }
    const char *deviceName = device.c_str();
    int serialPort = open(deviceName, O_RDWR);
    struct termios config;

    tcgetattr(serialPort, &config);
    cfsetispeed(&config, B9600);
    cfsetospeed(&config, B9600);
    config.c_cflag = (config.c_cflag & ~CSIZE) | CS8; // 8-bit data
    config.c_cflag &= ~PARENB;                     // No parity
    config.c_cflag &= ~CSTOPB;                     // One stop bit
    config.c_cflag &= ~CRTSCTS;                    // No hardware flow control
    config.c_cflag |= CREAD | CLOCAL;              // Enable reading and ignore control lines

    tcsetattr(serialPort, TCSANOW, &config);
//DEVICE INFO COMMAND
    uint8_t buffer[] = {0x80, 0x01, 0x00, 0x12, 0x3A, 0x61, 0x44, 0xDE};
    int bufferSize = sizeof(buffer);
write(serialPort,reinterpret_cast<char*>(buffer), bufferSize);  
     for(int i = 0 ;i < 8; i++) {
        printf("0x%02x ", buffer[i]);
    }
    cout << '\n';
    char Buffer2[256];
    try
    {
        ssize_t bytesRead = read(serialPort, Buffer2, sizeof(Buffer2));
        if (bytesRead > 0)
        {

            cout << "Received on Port 2 (in hex): ";

            for (ssize_t i = 0; i < bytesRead; i++)
            {
                cout << hex << (static_cast<int>(Buffer2[i]) & 0xff)<< " ";
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
//UNLOCK COMMAND 
     uint8_t infobuffer[] = {0x80, 0x21, 0x00, 0x21,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
     0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
     0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF, 0x02, 0xAA, 0xF0, 0x3D};
    int bufferSize = sizeof(buffer);
write(serialPort,reinterpret_cast<char*>(infobuffer), bufferSize);  
     for(int i = 0 ;i < 8; i++) {
        printf("0x%02x ", infobuffer[i]);
    }
    cout << '\n';
    char Buffer2[256];
    try
    {
        ssize_t bytesRead = read(serialPort, Buffer2, sizeof(Buffer2));
        if (bytesRead > 0)
        {

            cout << "Received on Port 2 (in hex): ";

            for (ssize_t i = 0; i < bytesRead; i++)
            {
                cout << hex << (static_cast<int>(Buffer2[i]) & 0xff)<< " ";
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

uint8_t unluckobuffer[] = {0x80, 0x01, 0x00, 0x12, 0x3A, 0x61, 0x44, 0xDE};
    int bufferSize = sizeof(unluckobuffer);
write(serialPort,reinterpret_cast<char*>(unluckobuffer), bufferSize);  
     for(int i = 0 ;i < 8; i++) {
        printf("0x%02x ", unluckobuffer[i]);
    }
    cout << '\n';
    char Buffer2[256];
    try
    {
        ssize_t bytesRead = read(serialPort, Buffer2, sizeof(Buffer2));
        if (bytesRead > 0)
        {

            cout << "Received on Port 2 (in hex): ";

            for (ssize_t i = 0; i < bytesRead; i++)
            {
                cout << hex << (static_cast<int>(Buffer2[i]) & 0xff)<< " ";
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


    return 0;
}

// Function to reverse the bits in a byte

uint8_t reverseBits(uint8_t data)
{

    uint8_t reversedData = 0;

    for (int i = 0; i < 8; i++)
    {

        reversedData |= ((data >> i) & 1) << (7 - i);
    }

    return reversedData;
}

int crc32()
{

    // Header (0x80)

    uint8_t header = 0x80;

    // Length of data (2 bytes, little-endian)

    uint16_t dataLength = 0x1234; // Example data length

    uint8_t dataLengthBytes[2];

    dataLengthBytes[0] = dataLength & 0xFF;

    dataLengthBytes[1] = (dataLength >> 8) & 0xFF;

    // Command (0x12)

    uint8_t command = 0x12;

    // Previous data (4 bytes, little-endian)

    vector<uint8_t> previousData = {0x01, 0x02, 0x03, 0x04}; // Example previous data

    // Calculate CRC with seed 0xFFFFFFFF in bit-reversed configuration

    uint32_t crc = 0xFFFFFFFF;

    for (uint8_t dataByte : previousData)
    {

        crc ^= reverseBits(dataByte);

        for (int i = 0; i < 8; i++)
        {

            crc = (crc & 1) ? ((crc >> 1) ^ 0xEDB88320) : (crc >> 1);
        }
    }

    // Convert CRC to bytes (4 bytes, little-endian)

    uint8_t crcBytes[4];

    crcBytes[0] = crc & 0xFF;

    crcBytes[1] = (crc >> 8) & 0xFF;

    crcBytes[2] = (crc >> 16) & 0xFF;

    crcBytes[3] = (crc >> 24) & 0xFF;

    // Combine all components into a byte array

    vector<uint8_t> byteArray;

    byteArray.push_back(header);

    byteArray.push_back(dataLengthBytes[0]);

    byteArray.push_back(dataLengthBytes[1]);

    byteArray.push_back(command);

    byteArray.insert(byteArray.end(), previousData.begin(), previousData.end());

    byteArray.insert(byteArray.end(), crcBytes, crcBytes + 4);

    // Print the resulting byte array

    cout << "Resulting Byte Array: ";

    for (uint8_t byte : byteArray)
    {

        cout << hex << static_cast<int>(byte) << " ";
    }

    cout << dec << endl;

    return 0;
}
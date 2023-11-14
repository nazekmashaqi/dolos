#include <iostream>
#include <vector>
#include <cstdint>
#include <cstring>
#include "../Utils/CRC32Calculator.h"
using namespace std;
class BSLCommand
{
protected:
    uint8_t transferHeader = 0x80;
    uint8_t transferCommand;
    vector<uint8_t> transferPacket;
    bool expectBSLCoreResponse;

public:
    BSLCommand(uint8_t transferCommand, bool expectBSLCoreResponse)
    {
        this->transferCommand = transferCommand;
        this->expectBSLCoreResponse = expectBSLCoreResponse;
    }

    vector<uint8_t> getTransferPacket()
    {
        return transferPacket;
    }

    bool isExpectBSLCoreResponse()
    {
        return expectBSLCoreResponse;
    }

protected:
    void assembleTransferPacket(const vector<uint8_t> &data)
    {
        vector<uint8_t> commandData = {this->transferCommand};
        vector<uint8_t> packetData = commandData;
        packetData.insert(packetData.end(), data.begin(), data.end());

        uint16_t packetLength = static_cast<uint16_t>(packetData.size());
        vector<uint8_t> dataLength = {
            static_cast<uint8_t>(packetLength >> 8),
            static_cast<uint8_t>(packetLength & 0xFF)};

        uint32_t crc32ForData = CRC32Calculator::crc32_jamcrc(packetData.data(), packetData.size());
        vector<uint8_t> crc32Bytes = {
            static_cast<uint8_t>((crc32ForData >> 24) & 0xFF),
            static_cast<uint8_t>((crc32ForData >> 16) & 0xFF),
            static_cast<uint8_t>((crc32ForData >> 8) & 0xFF),
            static_cast<uint8_t>(crc32ForData & 0xFF)};

        transferPacket = {transferHeader};
        transferPacket.insert(transferPacket.end(), dataLength.begin(), dataLength.end());
        transferPacket.insert(transferPacket.end(), packetData.begin(), packetData.end());
        transferPacket.insert(transferPacket.end(), crc32Bytes.begin(), crc32Bytes.end());
    }
};

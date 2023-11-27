#include "BSLCommand.h"
#include "../Utils/CRC32Calculator.h"
#include <iostream>
using namespace std;

BSLCommand::BSLCommand(uint8_t transferCommand, bool expectBSLCoreResponse) {
    this->transferCommand = transferCommand;
    this->expectBSLCoreResponse = expectBSLCoreResponse;
}

std::vector<uint8_t> BSLCommand::getTransferPacket() {
    return transferPacket;
}

bool BSLCommand::isExpectBSLCoreResponse() {
    return expectBSLCoreResponse;
}

void BSLCommand::assembleTransferPacket(const std::vector<uint8_t>& data) {
    std::vector<uint8_t> commandData = {this->transferCommand};
    std::vector<uint8_t> packetData = commandData;
    packetData.insert(packetData.end(), data.begin(), data.end());

    uint16_t packetLength = static_cast<uint16_t>(packetData.size());
    std::vector<uint8_t> dataLength = {
          static_cast<uint8_t>(packetLength & 0xFF),
		static_cast<uint8_t>(packetLength >> 8)};

    uint32_t crc32ForData = CRC32Calculator::crc32_jamcrc(packetData.data(), packetData.size());
    std::vector<uint8_t> crc32Bytes = {
        static_cast<uint8_t>((crc32ForData >> 24) & 0xFF),
        static_cast<uint8_t>((crc32ForData >> 16) & 0xFF),
        static_cast<uint8_t>((crc32ForData >> 8) & 0xFF),
        static_cast<uint8_t>(crc32ForData & 0xFF)};

    transferPacket = {transferHeader};
    transferPacket.insert(transferPacket.end(), dataLength.begin(), dataLength.end());
    transferPacket.insert(transferPacket.end(), packetData.begin(), packetData.end());
    transferPacket.insert(transferPacket.end(), crc32Bytes.begin(), crc32Bytes.end());
    for(int i=0;i<transferPacket.size();i++)
    {
    cout<<transferPacket[i];
    }
}

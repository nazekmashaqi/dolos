#include "BSLProgramData.h"
#include <fstream>
#include <iostream>

BSLProgramData::BSLProgramData(int startAddress, const std::vector<uint8_t>& programData)
    : BSLCommand(BSLCommands::PROGRAM_DATA, true), startAddress(startAddress), programData(programData) {
    std::vector<uint8_t> startAddressData = ByteArrayUtils::intToByteArray(startAddress);
    std::vector<uint8_t> data = ByteArrayUtils::combineArrays(startAddressData, this->programData);
    assembleTransferPacket(data);
}

std::vector<BSLProgramData> BSLProgramData::getBslProgramDataPacketsFromFile(const std::string& filePath, int startAddress) {
    std::vector<BSLProgramData> programDataPackets;
    const int maxBufferSize = 0x2000;  // Adjust as needed

    std::ifstream fileStream(filePath, std::ios::binary);
    if (!fileStream.is_open()) {
        std::cerr << "Error: Could not open file " << filePath << std::endl;
        return programDataPackets;
    }

    int dataLeftToRead = maxBufferSize;
    while (dataLeftToRead > 0) {
        std::vector<uint8_t> currentProgramData(maxBufferSize, 0);
        fileStream.read(reinterpret_cast<char*>(currentProgramData.data()), maxBufferSize);
        int currentDataSize = static_cast<int>(fileStream.gcount());

        if (currentDataSize == 0) {
            break;
        }

        BSLProgramData currentProgramBSLPacket(startAddress, currentProgramData);
        programDataPackets.push_back(currentProgramBSLPacket);

        dataLeftToRead -= currentDataSize;
        startAddress += currentDataSize;
    }

    return programDataPackets;
}

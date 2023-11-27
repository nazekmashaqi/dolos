#ifndef BSL_PROGRAM_DATA_H
#define BSL_PROGRAM_DATA_H

#include "BSLCommand.h"
#include "ByteArrayUtils.h"
#include <vector>

class BSLProgramData : public BSLCommand {
private:
    int startAddress;
    std::vector<uint8_t> programData;

public:
    BSLProgramData(int startAddress, const std::vector<uint8_t>& programData);
    static std::vector<BSLProgramData> getBslProgramDataPacketsFromFile(const std::string& filePath, int startAddress);
};

#endif

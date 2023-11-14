#ifndef BSLCOMMAND_H
#define BSLCOMMAND_H

#include <iostream>
#include <vector>
#include "../Utils/CRC32Calculator.h"
#include "../Constants/BSLCommands.h"
#include "../Constants/Sizes.h"

class BSLCommand
{
protected:
    uint8_t transferHeader = 0x80;
    uint8_t transferCommand;
    std::vector<uint8_t> transferPacket;
    bool expectBSLCoreResponse;

public:
    BSLCommand(uint8_t transferCommand, bool expectBSLCoreResponse);

    std::vector<uint8_t> getTransferPacket();

    bool isExpectBSLCoreResponse();

protected:
    void assembleTransferPacket(const std::vector<uint8_t> &data);

    uint32_t getCRC32ForData(const std::vector<uint8_t> &data);
};

#endif // BSLCOMMAND_H

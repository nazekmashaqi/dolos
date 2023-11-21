#include "BSLFlashRangeErase.h"
#include "../Utils/ByteArrayUtils.h"
#include "BSLCommands.h"

BSLFlashRangeErase::BSLFlashRangeErase(int startAddress, int endAddress)
    : BSLCommand(BSLCommands::FLASH_RANGE_ERASE, true), startAddress(startAddress), endAddress(endAddress) {

    std::vector<uint8_t> startAddressData = ByteArrayUtils::intToByteArray(this->startAddress);
    std::vector<uint8_t> endAddressData = ByteArrayUtils::intToByteArray(this->endAddress);
    std::vector<uint8_t> data = ByteArrayUtils::combineArrays(startAddressData, endAddressData);
    assembleTransferPacket(data);
}

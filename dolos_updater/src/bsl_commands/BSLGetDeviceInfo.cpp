#include "BSLGetDeviceInfo.h"

BSLGetDeviceInfo::BSLGetDeviceInfo() : BSLCommand(BSLCommands::GET_DEVICE_INFO_COMMAND, true)
{
    assembleTransferPacket(std::vector<uint8_t>());
}

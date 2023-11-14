#include "BSLConnection.h"

BSLConnection::BSLConnection() : BSLCommand(BSLCommands::CONNECTION_COMMAND, false)
{
    assembleTransferPacket(std::vector<uint8_t>());
}

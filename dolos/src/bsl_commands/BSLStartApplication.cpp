#include "BSLStartApplication.h"
#include "BSLCommands.h"

BSLStartApplication::BSLStartApplication()
    : BSLCommand(BSLCommands::START_APPLICATION, false) {
    assembleTransferPacket({});
}

#include "BSLMassErase.h"
#include "BSLCommands.h"

BSLMassErase::BSLMassErase()
    : BSLCommand(BSLCommands::MASS_ERASE, true) {
    assembleTransferPacket({});
}

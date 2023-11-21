
#ifndef BSL_UNLOCK_BOOTLOADER_H
#define BSL_UNLOCK_BOOTLOADER_H

#include "BSLCommand.h"

class BSLUnlockBootloader : public BSLCommand
{
private:
    static const std::string defaultPassword;
    std::vector<uint8_t> passwordData;

public:
    BSLUnlockBootloader();
    BSLUnlockBootloader(std::string password);
};

#endif // BSL_UNLOCK_BOOTLOADER_H

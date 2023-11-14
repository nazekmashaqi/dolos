#include "BSLUnlockBootloader.h"
#include "../Utils/ByteArrayUtils.h"

const std::string BSLUnlockBootloader::defaultPassword = "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF";

BSLUnlockBootloader::BSLUnlockBootloader() : BSLCommand(BSLCommands::UNLOCK_BOOTLOADER, true)
{
    passwordData = ByteArrayUtils::hexStringToByteArray(defaultPassword);
    assembleTransferPacket(passwordData);
}

BSLUnlockBootloader::BSLUnlockBootloader(std::string password) : BSLCommand(BSLCommands::UNLOCK_BOOTLOADER, true)
{
    if (password.length() != Sizes::BSL_PASSWORD_DATA * 2)
    {
        passwordData = ByteArrayUtils::hexStringToByteArray(defaultPassword);
    }
    else
    {
        passwordData = ByteArrayUtils::hexStringToByteArray(password);
    }
    assembleTransferPacket(passwordData);
}
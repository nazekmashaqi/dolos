#ifndef BSLMSG_H
#define BSLMSG_H

#include <cstdint>

enum class BSLMsg : uint8_t {
    OPERATION_SUCCESSFUL = 0x00,
    BSL_LOCKED_ERROR = 0x01,
    BSL_PASSWORD_ERROR = 0x02,
    MULTIPLE_BSL_PASSWORD_ERROR = 0x03,
    UNKNOWN_COMMAND = 0x04,
    INVALID_MEMORY_RANGE = 0x05,
    INVALID_COMMAND = 0x06,
    FACTORY_RESET_DISABLED = 0x07,
    FACTORY_RESET_PASSWORD_ERROR = 0x08,
    READ_OUT_ERROR = 0x09,
    INVALID_ADDRESS_OR_LENGTH_ALIGNMENT = 0x0A,
    INVALID_LENGTH_FOR_STANDALONE_VERIFICATION = 0x0B,
    INVALID_VALUE = 0xFF
};

BSLMsg BSLMsg_valueOf(uint8_t value);

#endif // BSLMSG_H

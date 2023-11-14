#include "BSLMsg.h"

BSLMsg BSLMsg_valueOf(uint8_t value) {
    switch (value) {
        case 0x00: return BSLMsg::OPERATION_SUCCESSFUL;
        case 0x01: return BSLMsg::BSL_LOCKED_ERROR;
        case 0x02: return BSLMsg::BSL_PASSWORD_ERROR;
        case 0x03: return BSLMsg::MULTIPLE_BSL_PASSWORD_ERROR;
        case 0x04: return BSLMsg::UNKNOWN_COMMAND;
        case 0x05: return BSLMsg::INVALID_MEMORY_RANGE;
        case 0x06: return BSLMsg::INVALID_COMMAND;
        case 0x07: return BSLMsg::FACTORY_RESET_DISABLED;
        case 0x08: return BSLMsg::FACTORY_RESET_PASSWORD_ERROR;
        case 0x09: return BSLMsg::READ_OUT_ERROR;
        case 0x0A: return BSLMsg::INVALID_ADDRESS_OR_LENGTH_ALIGNMENT;
        case 0x0B: return BSLMsg::INVALID_LENGTH_FOR_STANDALONE_VERIFICATION;
        case 0xFF: return BSLMsg::INVALID_VALUE;
        default: return BSLMsg::INVALID_VALUE;
    }
}

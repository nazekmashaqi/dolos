#ifndef BSLRSP_H
#define BSLRSP_H

#include <cstdint>

enum class BSLRsp : uint8_t {
    MEMORY_READ_BACK = 0x30,
    GET_DEVICE_INFO = 0x31,
    STANDALONE_VERIFICATION = 0x32,
    MESSAGE = 0x3B,
    DETAILED_ERROR = 0x3A,
    INVALID_VALUE = 0xFF
};

BSLRsp BSLRsp_valueOf(uint8_t value);

#endif // BSLRSP_H

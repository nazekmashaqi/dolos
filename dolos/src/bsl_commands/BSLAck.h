#ifndef BSLACK_H
#define BSLACK_H

#include <cstdint>

enum class BSLAck : uint8_t {
    ACK = 0x00,
    ERROR_HEADER_INCORRECT = 0x51,
    ERROR_CHECKSUM_INCORRECT = 0x52,
    ERROR_PACKET_SIZE_ZERO = 0x53,
    ERROR_PACKET_SIZE_TOO_BIG = 0x54,
    ERROR_UNKNOWN_ERROR = 0x55,
    ERROR_UNKNOWN_BAUD_RATE = 0x56,
    INVALID_VALUE = 0xFF
};

BSLAck BSLAck_valueOf(uint8_t value);

#endif // BSLACK_H

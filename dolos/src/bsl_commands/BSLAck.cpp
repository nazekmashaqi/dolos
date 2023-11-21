#include "BSLAck.h"

BSLAck BSLAck_valueOf(uint8_t value) {
    switch (value) {
        case 0x00: return BSLAck::ACK;
        case 0x51: return BSLAck::ERROR_HEADER_INCORRECT;
        case 0x52: return BSLAck::ERROR_CHECKSUM_INCORRECT;
        case 0x53: return BSLAck::ERROR_PACKET_SIZE_ZERO;
        case 0x54: return BSLAck::ERROR_PACKET_SIZE_TOO_BIG;
        case 0x55: return BSLAck::ERROR_UNKNOWN_ERROR;
        case 0x56: return BSLAck::ERROR_UNKNOWN_BAUD_RATE;
        case 0xFF: return BSLAck::INVALID_VALUE;
        default: return BSLAck::INVALID_VALUE;
    }
}

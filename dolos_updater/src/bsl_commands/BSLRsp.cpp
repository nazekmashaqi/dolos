#include "BSLRsp.h"

BSLRsp BSLRsp_valueOf(uint8_t value) {
    switch (value) {
        case 0x30: return BSLRsp::MEMORY_READ_BACK;
        case 0x31: return BSLRsp::GET_DEVICE_INFO;
        case 0x32: return BSLRsp::STANDALONE_VERIFICATION;
        case 0x3B: return BSLRsp::MESSAGE;
        case 0x3A: return BSLRsp::DETAILED_ERROR;
        case 0xFF: return BSLRsp::INVALID_VALUE;
        default: return BSLRsp::INVALID_VALUE;
    }
}

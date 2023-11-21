#ifndef CRC32CALCULATOR_H
#define CRC32CALCULATOR_H

#include <cstdint>

class CRC32Calculator {
public:
    CRC32Calculator();
    static uint32_t crc32_jamcrc(const uint8_t *data, size_t length);
};

#endif

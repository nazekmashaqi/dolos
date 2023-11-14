#ifndef CRC32CALCULATOR_H
#define CRC32CALCULATOR_H
#include <iostream>
#include <cstdint>

class CRC32Calculator {
public:
    static uint32_t crc32_jamcrc(const uint8_t *data, size_t length);
};

#endif // CRC32CALCULATOR_H

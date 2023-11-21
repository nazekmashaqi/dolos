#include <iostream>
#include <cstdint>
#include "CRC32Calculator.h"

CRC32Calculator::CRC32Calculator() {}

uint32_t CRC32Calculator::crc32_jamcrc(const uint8_t *data, size_t length) {
    const uint32_t polynomial = 0xEDB88320;
    uint32_t crc = 0xFFFFFFFF;

    for (size_t i = 0; i < length; ++i) {
        crc ^= data[i];
        for (int j = 0; j < 8; ++j) {
            crc = (crc >> 1) ^ ((crc & 1) ? polynomial : 0);
        }
    }

    return ((crc & 0xFF) << 24) | ((crc & 0xFF00) << 8) | ((crc & 0xFF0000) >> 8) | ((crc >> 24) & 0xFF);
}

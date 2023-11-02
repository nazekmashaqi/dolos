#include <iostream> 

#include <cstdint> 

  

uint32_t calculateCRC(const uint8_t *data, size_t length) { 

    const uint32_t polynomial = 0x04C11DB7; // CRC-32-ISO3309 polynomial 

    uint32_t crc = 0xFFFFFFFF; 

  

    for (size_t i = 0; i < length; ++i) { 

        crc ^= data[i]; 

        for (int j = 0; j < 8; ++j) { 

            if (crc & 1) { 

                crc = (crc >> 1) ^ polynomial; 

            } else { 

                crc >>= 1; 

            } 

        } 

    } 

  

    return crc ^ 0xFFFFFFFF; // Final XOR with 0xFFFFFFFF 

} 

  

int main() { 

    const uint8_t message[] = { 0x12 }; // Data 0x12 

    size_t messageLength = sizeof(message) / sizeof(message[0]); 

  

    uint32_t crcResult = calculateCRC(message, messageLength); 

  

    // Adjust to little-endian representation 

    uint32_t littleEndianCRC = ((crcResult >> 24) & 0xFF) | ((crcResult >> 8) & 0xFF00) | ((crcResult << 8) & 0xFF0000) | ((crcResult << 24) & 0xFF000000); 

  

    std::cout << "CRC32 (CRC-32-ISO3309 polynomial, Little-endian): " << std::hex << littleEndianCRC << std::endl; 

  

    return 0; 

} 

 
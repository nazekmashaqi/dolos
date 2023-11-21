#ifndef BYTEARRAYUTILS_H
#define BYTEARRAYUTILS_H

#include <iostream>
#include <vector>
#include <string>

class ByteArrayUtils {
public:
    static std::vector<uint8_t> cloneByteArray(const std::vector<uint8_t>& byteArray);
    static std::vector<uint8_t> extractByteArrayRange(const std::vector<uint8_t>& byteArray, int lower, int upper);
    static std::vector<uint8_t> combineArrays(const std::vector<uint8_t>& array1, const std::vector<uint8_t>& array2);
    static std::vector<uint8_t> combineArrays(const std::vector<uint8_t>& array1, const std::vector<uint8_t>& array2, const std::vector<uint8_t>& array3);
    static std::vector<uint8_t> combineArrays(const std::vector<uint8_t>& array1, const std::vector<uint8_t>& array2, const std::vector<uint8_t>& array3, const std::vector<uint8_t>& array4);
    static std::vector<uint8_t> intToByteArray(int value);
    static std::vector<uint8_t> shortToByteArray(short value);
    static std::vector<uint8_t> hexStringToByteArray(const std::string& hexString);
    static int byteArrayToInt(const std::vector<uint8_t>& byteArray);
    static short byteArrayToShort(const std::vector<uint8_t>& byteArray);
};

#endif // BYTEARRAYUTILS_H

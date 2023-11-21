#include <iostream>
#include <vector>
#include <string>
#include "ByteArrayUtils.h"

      std::vector<uint8_t>  ByteArrayUtils::cloneByteArray(const std::vector<uint8_t>& byteArray) {
        return byteArray;
    }

      std::vector<uint8_t>  ByteArrayUtils::extractByteArrayRange(const std::vector<uint8_t>& byteArray, int lower, int upper) {
        std::vector<uint8_t> extractedBytes(byteArray.begin() + lower, byteArray.begin() + upper);
        return extractedBytes;
    }

    std::vector<uint8_t>  ByteArrayUtils::combineArrays(const std::vector<uint8_t>& array1, const std::vector<uint8_t>& array2) {
    std::vector<uint8_t> combinedArray;
    combinedArray.insert(combinedArray.end(), array1.begin(), array1.end());
    combinedArray.insert(combinedArray.end(), array2.begin(), array2.end());
    return combinedArray;
}

std::vector<uint8_t>  ByteArrayUtils::combineArrays(const std::vector<uint8_t>& array1, const std::vector<uint8_t>& array2, const std::vector<uint8_t>& array3) {
    std::vector<uint8_t> combinedArray = combineArrays(array1, array2);
    combinedArray.insert(combinedArray.end(), array3.begin(), array3.end());
    return combinedArray;
}

std::vector<uint8_t>  ByteArrayUtils::combineArrays(const std::vector<uint8_t>& array1, const std::vector<uint8_t>& array2, const std::vector<uint8_t>& array3, const std::vector<uint8_t>& array4) {
    std::vector<uint8_t> combinedArray = combineArrays(array1, array2, array3);
    combinedArray.insert(combinedArray.end(), array4.begin(), array4.end());
    return combinedArray;
}

      std::vector<uint8_t>  ByteArrayUtils::intToByteArray(int value) {
        std::vector<uint8_t> byteArray(sizeof(int));
        for (size_t i = 0; i < sizeof(int); ++i) {
            byteArray[i] = (value >> (i * 8)) & 0xFF;
        }
        return byteArray;
    }

      std::vector<uint8_t>  ByteArrayUtils::shortToByteArray(short value) {
        std::vector<uint8_t> byteArray(sizeof(short));
        for (size_t i = 0; i < sizeof(short); ++i) {
            byteArray[i] = (value >> (i * 8)) & 0xFF;
        }
        return byteArray;
    }

      std::vector<uint8_t>  ByteArrayUtils::hexStringToByteArray(const std::string& hexString) {
        std::vector<uint8_t> byteArray;
        for (size_t i = 0; i < hexString.size(); i += 2) {
            uint8_t byte = std::stoi(hexString.substr(i, 2), nullptr, 16);
            byteArray.push_back(byte);
        }
        return byteArray;
    }

      int  ByteArrayUtils::byteArrayToInt(const std::vector<uint8_t>& byteArray) {
        int value = 0;
        for (size_t i = 0; i < byteArray.size(); ++i) {
            value |= (byteArray[i] << (i * 8));
        }
        return value;
    }
   


  short  ByteArrayUtils::byteArrayToShort(const std::vector<uint8_t>& byteArray) {
        short value = 0;
        for (size_t i = 0; i < byteArray.size(); ++i) {
            value |= (byteArray[i] << (i * 8));
        }
        return value;
    }





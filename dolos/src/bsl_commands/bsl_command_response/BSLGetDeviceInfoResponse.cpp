/* #include "../bsl_command_response/BSLGetDeviceInfoResponse.h"
#include "../Utils/ByteArrayUtils.h"
#include "../Utils/Range.h"

BSLGetDeviceInfoResponse::BSLGetDeviceInfoResponse(BSLAck bslAck, uint8_t receiveHeader, int receiveLength, BSLRsp bslRsp, uint8_t* receiveData, int receiveCRC32)
    : BSLCommandResponse(bslAck, receiveHeader, receiveLength, bslRsp, receiveData, receiveCRC32) {}

int BSLGetDeviceInfoResponse::getCommandInterpreterVersion() {
    return commandInterpreterVersion;
}

int BSLGetDeviceInfoResponse::getBuildId() {
    return buildId;
}

int BSLGetDeviceInfoResponse::getApplicationVersion() {
    return applicationVersion;
}

int BSLGetDeviceInfoResponse::getActivePlugInInterfaceVersion() {
    return activePlugInInterfaceVersion;
}

int BSLGetDeviceInfoResponse::getBslMaxBufferSize() {
    return bslMaxBufferSize;
}

int BSLGetDeviceInfoResponse::getBslBufferStartAddress() {
    return bslBufferStartAddress;
}

int BSLGetDeviceInfoResponse::getBcrConfigurationId() {
    return bcrConfigurationId;
}

int BSLGetDeviceInfoResponse::getBslConfigurationId() {
    return bslConfigurationId;
}

void BSLGetDeviceInfoResponse::deassembleReceiveData() {
    Range dataRanges[8] = {
        Range(0, 2),
        Range(2, 4),
        Range(4, 8),
        Range(8, 10),
        Range(10, 12),
        Range(12, 16),
        Range(16, 20),
        Range(20, 23)
    };

    // Create a vector to hold the bisected data
    std::vector<uint8_t> bisectedVector;
    for (const auto& range : dataRanges) {
        bisectedVector.insert(bisectedVector.end(), receiveData + range.getLower(), receiveData + range.getUpper());
    }

    // Use the existing function to convert vector to int
    commandInterpreterVersion = ByteArrayUtils::byteArrayToInt(bisectedVector);
    buildId = ByteArrayUtils::byteArrayToInt(bisectedVector);
    applicationVersion = ByteArrayUtils::byteArrayToInt(bisectedVector);
    activePlugInInterfaceVersion = ByteArrayUtils::byteArrayToInt(bisectedVector);
    bslMaxBufferSize = ByteArrayUtils::byteArrayToInt(bisectedVector);
    bslBufferStartAddress = ByteArrayUtils::byteArrayToInt(bisectedVector);
    bcrConfigurationId = ByteArrayUtils::byteArrayToInt(bisectedVector);
    bslConfigurationId = ByteArrayUtils::byteArrayToInt(bisectedVector);
}
 */


#include "BSLGetDeviceInfoResponse.h"
#include "../../Utils/ByteArrayUtils.h"
#include "../../Utils/Range.h"

BSLGetDeviceInfoResponse::BSLGetDeviceInfoResponse(BSLAck bslAck, uint8_t receiveHeader, int receiveLength, BSLRsp bslRsp, uint8_t* receiveData, int receiveCRC32)
    : BSLCommandResponse(bslAck, receiveHeader, receiveLength, bslRsp, nullptr, receiveCRC32) {

    // Assuming receiveLength is the actual length of receiveData
    // Convert uint8_t* to std::vector<uint8_t>
    receiveDataVector.assign(receiveData, receiveData + receiveLength);

    // Call the existing deassembleReceiveData function
    deassembleReceiveData();
}

int BSLGetDeviceInfoResponse::getCommandInterpreterVersion() {
    return commandInterpreterVersion;
}

int BSLGetDeviceInfoResponse::getBuildId() {
    return buildId;
}

int BSLGetDeviceInfoResponse::getApplicationVersion() {
    return applicationVersion;
}

int BSLGetDeviceInfoResponse::getActivePlugInInterfaceVersion() {
    return activePlugInInterfaceVersion;
}

int BSLGetDeviceInfoResponse::getBslMaxBufferSize() {
    return bslMaxBufferSize;
}

int BSLGetDeviceInfoResponse::getBslBufferStartAddress() {
    return bslBufferStartAddress;
}

int BSLGetDeviceInfoResponse::getBcrConfigurationId() {
    return bcrConfigurationId;
}

int BSLGetDeviceInfoResponse::getBslConfigurationId() {
    return bslConfigurationId;
}


void BSLGetDeviceInfoResponse::deassembleReceiveData() {
    Range dataRanges[8] = {
        Range(0, 2),
        Range(2, 4),
        Range(4, 8),
        Range(8, 10),
        Range(10, 12),
        Range(12, 16),
        Range(16, 20),
        Range(20, 23)
    };

    // Use the existing function to convert vector to int for each data range
    commandInterpreterVersion = ByteArrayUtils::byteArrayToInt(std::vector<uint8_t>(receiveDataVector.begin() + dataRanges[0].getLower(), receiveDataVector.begin() + dataRanges[0].getUpper()));
    buildId = ByteArrayUtils::byteArrayToInt(std::vector<uint8_t>(receiveDataVector.begin() + dataRanges[1].getLower(), receiveDataVector.begin() + dataRanges[1].getUpper()));
    applicationVersion = ByteArrayUtils::byteArrayToInt(std::vector<uint8_t>(receiveDataVector.begin() + dataRanges[2].getLower(), receiveDataVector.begin() + dataRanges[2].getUpper()));
    activePlugInInterfaceVersion = ByteArrayUtils::byteArrayToInt(std::vector<uint8_t>(receiveDataVector.begin() + dataRanges[3].getLower(), receiveDataVector.begin() + dataRanges[3].getUpper()));
    bslMaxBufferSize = ByteArrayUtils::byteArrayToInt(std::vector<uint8_t>(receiveDataVector.begin() + dataRanges[4].getLower(), receiveDataVector.begin() + dataRanges[4].getUpper()));
    bslBufferStartAddress = ByteArrayUtils::byteArrayToInt(std::vector<uint8_t>(receiveDataVector.begin() + dataRanges[5].getLower(), receiveDataVector.begin() + dataRanges[5].getUpper()));
    bcrConfigurationId = ByteArrayUtils::byteArrayToInt(std::vector<uint8_t>(receiveDataVector.begin() + dataRanges[6].getLower(), receiveDataVector.begin() + dataRanges[6].getUpper()));
    bslConfigurationId = ByteArrayUtils::byteArrayToInt(std::vector<uint8_t>(receiveDataVector.begin() + dataRanges[7].getLower(), receiveDataVector.begin() + dataRanges[7].getUpper()));
}

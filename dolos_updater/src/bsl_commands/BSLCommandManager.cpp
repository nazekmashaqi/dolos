#include "BSLCommandManager.h"
#include "../Utils/ByteArrayUtils.h"


BSLCommandManager::BSLCommandManager(int serialPort) : serialPort(serialPort), currentCommand(nullptr) {}


BSLAck BSLCommandManager::receiveBSLAckResponse() {
    std::vector<uint8_t> bslAckData = receiveDataResponse(Sizes::ACK_DATA);
    return BSLAck_valueOf(bslAckData[0]); 
}

BSLRsp BSLCommandManager::receiveBSLRspResponse() {
    std::vector<uint8_t> bslRspData = receiveDataResponse(Sizes::RSP_DATA);
    return BSLRsp_valueOf(bslRspData[0]); 
}

uint8_t BSLCommandManager::receiveHeaderResponse() {
    std::vector<uint8_t> headerData = receiveDataResponse(Sizes::HEADER_DATA);
    return headerData[0];
}

std::vector<uint8_t> BSLCommandManager::receiveDataResponse(int length) {
    std::vector<uint8_t> data(length);
    ssize_t readBytesLength = read(serialPort, data.data(), length);

    if (readBytesLength != length) {
        throw std::runtime_error("receive response");
    }

    return data;
}

short BSLCommandManager::receiveLengthResponse() {
    std::vector<uint8_t> lengthData = receiveDataResponse(Sizes::LENGTH_DATA);
    return ByteArrayUtils::byteArrayToShort(lengthData);
}

int BSLCommandManager::receiveCRC32Response() {
    std::vector<uint8_t> crc32Data = receiveDataResponse(Sizes::CRC32_DATA);
    return ByteArrayUtils::byteArrayToInt(crc32Data);
}



BSLCommandResponse* BSLCommandManager::receiveCommandResponse() {
    BSLAck bslAck = receiveBSLAckResponse();

    if (bslAck != BSLAck::ACK) {
        throw std::runtime_error("error2");
    }

    if (!this->currentCommand->isExpectBSLCoreResponse()) {
        return nullptr;
    }

    uint8_t receiveHeader = receiveHeaderResponse();
    short receiveLength = receiveLengthResponse();
    BSLRsp bslRsp = receiveBSLRspResponse();
    std::vector<uint8_t> receiveDataVector = receiveDataResponse(receiveLength - Sizes::RSP_DATA);
    uint8_t* receiveData = receiveDataVector.data();

    int receiveCRC32 = receiveCRC32Response();

    return factory(bslRsp, bslAck, receiveHeader, receiveLength, bslRsp, receiveData, receiveCRC32);
}

void BSLCommandManager::transferCommand() {
    std::vector<uint8_t> transferPacket = this->currentCommand->getTransferPacket();
    write(serialPort, transferPacket.data(), transferPacket.size()); // Use 'write' and 'data()' instead of 'serialPort.writeBytes'
}

BSLCommandResponse* BSLCommandManager::transmit(BSLCommand* bslBasicCommand) {
    this->currentCommand = bslBasicCommand;
    transferCommand();
    BSLCommandResponse* bslCommandResponse = receiveCommandResponse();
    this->currentCommand = nullptr;
    return bslCommandResponse;
}

BSLCommandResponse* BSLCommandManager::factory(BSLRsp rsp, BSLAck bslAck, uint8_t receiveHeader, int receiveLength, BSLRsp bslRsp, uint8_t* receiveData, int receiveCRC32) {
    if (rsp == BSLRsp::INVALID_VALUE) {
        return nullptr;
    }
    else if (rsp == BSLRsp::MEMORY_READ_BACK) {
        return nullptr; //TODO: not supported
    }
    else if (rsp == BSLRsp::GET_DEVICE_INFO) {
        return new BSLGetDeviceInfoResponse(bslAck, receiveHeader, receiveLength, bslRsp, receiveData, receiveCRC32);
    }
    else if (rsp == BSLRsp::STANDALONE_VERIFICATION) {
        return nullptr; //TODO: not supported
    }
    else if (rsp == BSLRsp::MESSAGE) {
        return new BSLCoreMessageResponse(bslAck, receiveHeader, receiveLength, bslRsp, receiveData, receiveCRC32);
    }
    else if (rsp == BSLRsp::DETAILED_ERROR) {
        return nullptr; //TODO: not supported
    }
    return nullptr;
}

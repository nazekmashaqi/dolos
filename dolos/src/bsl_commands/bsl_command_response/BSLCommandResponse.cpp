#include "BSLCommandResponse.h"

BSLCommandResponse::BSLCommandResponse(BSLAck bslAck,  uint8_t receiveHeader, int receiveLength, BSLRsp bslRsp,  uint8_t* receiveData, int receiveCRC32)
    : bslAck(bslAck), receiveHeader(receiveHeader), receiveLength(receiveLength), bslRsp(bslRsp), receiveData(receiveData), receiveCRC32(receiveCRC32) {
	//BSLCommandResponse::deassembleReceiveData();
}

BSLRsp BSLCommandResponse::getBslRsp() {
    return bslRsp;
}

BSLCommandResponse::~BSLCommandResponse() {
    if (receiveData != nullptr) {
        delete[] receiveData;
    }
}

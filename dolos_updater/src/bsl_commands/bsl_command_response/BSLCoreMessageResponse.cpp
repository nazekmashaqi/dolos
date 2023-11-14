#include "BSLCoreMessageResponse.h"
#include "BSLMsg.h"

BSLCoreMessageResponse::BSLCoreMessageResponse(BSLAck bslAck, uint8_t receiveHeader, int receiveLength, BSLRsp bslRsp, uint8_t* receiveData, int receiveCRC32)
    : BSLCommandResponse(bslAck, receiveHeader, receiveLength, bslRsp, receiveData, receiveCRC32) {}

BSLMsg BSLCoreMessageResponse::getBslMsg() {
    return bslMsg;
}

void BSLCoreMessageResponse::deassembleReceiveData() {
    // Assuming receiveData is an array of characters (bytes)
    // Convert the first byte to BSLMsg enum value
    bslMsg = static_cast<BSLMsg>(receiveData[0]);
}

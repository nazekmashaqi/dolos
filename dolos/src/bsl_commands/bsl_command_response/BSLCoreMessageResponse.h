#ifndef BSL_CORE_MESSAGE_RESPONSE_H
#define BSL_CORE_MESSAGE_RESPONSE_H

#include "BSLCommandResponse.h"
#include "../BSLAck.h"
#include "../BSLRsp.h"
#include "../BSLMsg.h"

class BSLCoreMessageResponse : public BSLCommandResponse {
private:
    BSLMsg bslMsg;

public:
    BSLCoreMessageResponse(BSLAck bslAck, uint8_t receiveHeader, int receiveLength, BSLRsp bslRsp, uint8_t* receiveData, int receiveCRC32);
    BSLMsg getBslMsg();
    void deassembleReceiveData() override;
};

#endif // BSL_CORE_MESSAGE_RESPONSE_H

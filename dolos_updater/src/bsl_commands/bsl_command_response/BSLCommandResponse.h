#ifndef BSLCOMMANDRESPONSE_H
#define BSLCOMMANDRESPONSE_H

#include "../BSLAck.h"
#include "../BSLRsp.h"

class BSLCommandResponse {
protected:
    BSLAck bslAck;
    uint8_t receiveHeader;
    int receiveLength;
    BSLRsp bslRsp;
     uint8_t* receiveData;
    int receiveCRC32;

public:
    BSLRsp getBslRsp();
    BSLCommandResponse(BSLAck bslAck,  uint8_t receiveHeader, int receiveLength, BSLRsp bslRsp,  uint8_t* receiveData, int receiveCRC32);
    virtual ~BSLCommandResponse();
    virtual void deassembleReceiveData() = 0;
};

#endif // BSLCOMMANDRESPONSE_H

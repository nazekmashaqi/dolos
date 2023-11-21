#ifndef BSLCOMMANDMANAGER_H
#define BSLCOMMANDMANAGER_H

#include "BSLCommand.h"
#include "BSLAck.h"
#include "BSLRsp.h"
#include <vector>
#include <stdexcept> // Include for std::runtime_error
#include <unistd.h>
#include "bsl_command_response/BSLCommandResponse.h"
#include "bsl_command_response/BSLGetDeviceInfoResponse.h"
#include "bsl_command_response/BSLCoreMessageResponse.h"

class BSLCommandManager {
private:
    int serialPort;
    BSLCommand* currentCommand;

std::vector<uint8_t> receiveDataResponse(int length);
    BSLAck receiveBSLAckResponse();
    BSLRsp receiveBSLRspResponse();
     uint8_t receiveHeaderResponse();
    short receiveLengthResponse();
    int receiveCRC32Response();
    BSLCommandResponse* receiveCommandResponse();
    void transferCommand();
    BSLCommandResponse* factory(BSLRsp rsp, BSLAck bslAck,  uint8_t receiveHeader, int receiveLength, BSLRsp bslRsp,  uint8_t* receiveData, int receiveCRC32);

public:
    BSLCommandManager(int serialPort);
    BSLCommandResponse* transmit(BSLCommand* bslBasicCommand);
};

#endif // BSLCOMMANDMANAGER_H

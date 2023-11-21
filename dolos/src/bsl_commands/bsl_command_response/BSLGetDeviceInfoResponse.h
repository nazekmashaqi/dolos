#ifndef BSLGETDEVICEINFORESPONSE_H
#define BSLGETDEVICEINFORESPONSE_H

#include "BSLCommandResponse.h"
#include <vector> // Add this include for std::vector

class BSLGetDeviceInfoResponse : public BSLCommandResponse {
private:
    int commandInterpreterVersion;
    int buildId;
    int applicationVersion;
    int activePlugInInterfaceVersion;
    int bslMaxBufferSize;
    int bslBufferStartAddress;
    int bcrConfigurationId;
    int bslConfigurationId;

    std::vector<uint8_t> receiveDataVector; // Add this line

public:
    BSLGetDeviceInfoResponse(BSLAck bslAck, uint8_t receiveHeader, int receiveLength, BSLRsp bslRsp, uint8_t* receiveData, int receiveCRC32);
    int getCommandInterpreterVersion();
    int getBuildId();
    int getApplicationVersion();
    int getActivePlugInInterfaceVersion();
    int getBslMaxBufferSize();
    int getBslBufferStartAddress();
    int getBcrConfigurationId();
    int getBslConfigurationId();

private:
    void deassembleReceiveData();
};

#endif // BSLGETDEVICEINFORESPONSE_H

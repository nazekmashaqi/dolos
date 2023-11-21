#ifndef BSL_FLASH_RANGE_ERASE_H
#define BSL_FLASH_RANGE_ERASE_H

#include "BSLCommand.h"

class BSLFlashRangeErase : public BSLCommand {
private:
    int startAddress;
    int endAddress;

public:
    BSLFlashRangeErase(int startAddress, int endAddress);
};

#endif 

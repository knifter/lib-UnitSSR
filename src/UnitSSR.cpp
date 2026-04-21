#include "UnitSSR.h"

enum : uint8_t
{
    REG_RELAY = 0x00,
};

bool UnitSSR::begin(uint8_t addr)
{
    TwoWireDevice::begin(addr);

    time_t timeout = millis() + 5000;
    while(timeout > millis())
    {
        if(ping())
            return true;
    };
    return false;
};

void UnitSSR::setRelay(bool on)
{
    writereg8(REG_RELAY, on ? 0x01 : 0x00);
};

bool UnitSSR::getRelay()
{
    return readreg8(REG_RELAY) && 0x01;
};

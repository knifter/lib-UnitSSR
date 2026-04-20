#ifndef __UNITSSR_H
#define __UNITSSR_H

#include <TwoWireDevice.h>

#define UNITSSR_ADDRESS_DEFAULT     0x25

class UnitSSR : public TwoWireDevice
{
    public:
        UnitSSR(TwoWire& wire, uint8_t addr = UNITSSR_ADDRESS_DEFAULT) : TwoWireDevice(wire, addr) {};
        UnitSSR(uint8_t addr = UNITSSR_ADDRESS_DEFAULT) : TwoWireDevice(addr) {};

        bool begin(uint8_t addr = 0);
        uint32_t max_clock() { return 100000; }; 

        void setRelay(bool on);
        bool getRelay();
};

#endif // __UNITSSR_H

#ifndef __M5UNITSSR_H
#define __M5UNITSSR_H

#include <TwoWireDevice.h>

#define M5UNITSSR_ADDRESS_DEFAULT   0x50    // Unit ACSSR / Unit DCSSR

class M5UnitSSR : public TwoWireDevice
{
    public:
        M5UnitSSR(TwoWire& wire, uint8_t addr = M5UNITSSR_ADDRESS_DEFAULT) : TwoWireDevice(wire, addr) {};
        M5UnitSSR(uint8_t addr = M5UNITSSR_ADDRESS_DEFAULT) : TwoWireDevice(addr) {};

        bool begin(uint8_t addr = 0);
        uint32_t max_clock() { return 100000; };

        void setRelay(bool on);
        bool getRelay();

        void setLEDColor(uint8_t r, uint8_t g, uint8_t b);
        void setLEDColor(uint32_t rgb);     // 0x00RRGGBB
        uint32_t getLEDColor();             // returns 0x00RRGGBB

        uint8_t getVersion();
        void setDeviceAddr(uint8_t addr);
};

#endif // __M5UNITSSR_H

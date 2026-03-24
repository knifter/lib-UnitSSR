#ifndef __UNITACSSR_H
#define __UNITACSSR_H

#include "UnitSSR.h"

#define UNITACSSR_ADDRESS_DEFAULT   0x50

class UnitACSSR : public UnitSSR
{
    public:
        UnitACSSR(TwoWire& wire, uint8_t addr = UNITACSSR_ADDRESS_DEFAULT) : UnitSSR(wire, addr) {};
        UnitACSSR(uint8_t addr = UNITACSSR_ADDRESS_DEFAULT) : UnitSSR(addr) {};

        void setLEDColor(uint8_t r, uint8_t g, uint8_t b);
        void setLEDColor(uint32_t rgb);     // set as  0x00RRGGBB
        uint32_t getLEDColor();             // returns 0x00RRGGBB

        uint8_t getVersion();
        void setDeviceAddr(uint8_t addr);
};

using UnitDCSSR = UnitACSSR;

#endif // __UNITACSSR_H

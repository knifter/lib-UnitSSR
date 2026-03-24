#include "UnitACSSR.h"

enum : uint8_t
{
    REG_RELAY = 0x00,
    REG_LED   = 0x10,
    REG_ADDR  = 0x20,
    REG_VER   = 0xFE,
};

void UnitACSSR::setLEDColor(uint32_t rgb)
{
    writereg(REG_LED, (uint8_t*) &rgb, 3);
};

void UnitACSSR::setLEDColor(uint8_t r, uint8_t g, uint8_t b)
{
    uint8_t buf[3] = {r, g, b};
    writereg(REG_LED, buf, 3);
};

uint32_t UnitACSSR::getLEDColor()
{
    uint8_t buf[3] = {0};
    readreg(REG_LED, buf, 3);
    return ((uint32_t)buf[0] << 16) | ((uint32_t)buf[1] << 8) | buf[2];
};

uint8_t UnitACSSR::getVersion()
{
    return readreg8(REG_VER);
};

void UnitACSSR::setDeviceAddr(uint8_t addr)
{
    writereg8(REG_ADDR, addr);
};

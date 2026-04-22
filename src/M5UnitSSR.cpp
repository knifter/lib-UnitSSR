#include "M5UnitSSR.h"

enum : uint8_t
{
    REG_RELAY = 0x00,
    REG_LED   = 0x10,
    REG_ADDR  = 0x20,
    REG_VER   = 0xFE,
};

bool M5UnitSSR::begin(uint8_t addr)
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

void M5UnitSSR::setRelay(bool on)
{
    writereg8(REG_RELAY, on ? 0x01 : 0x00);
};

bool M5UnitSSR::getRelay()
{
    return readreg8(REG_RELAY) && 0x01;
};

void M5UnitSSR::setLEDColor(uint32_t rgb)
{
    writereg(REG_LED, (uint8_t*) &rgb, 3);
};

void M5UnitSSR::setLEDColor(uint8_t r, uint8_t g, uint8_t b)
{
    uint8_t buf[3] = {r, g, b};
    writereg(REG_LED, buf, 3);
};

uint32_t M5UnitSSR::getLEDColor()
{
    uint8_t buf[3] = {0};
    readreg(REG_LED, buf, 3);
    return ((uint32_t)buf[0] << 16) | ((uint32_t)buf[1] << 8) | buf[2];
};

uint8_t M5UnitSSR::getVersion()
{
    return readreg8(REG_VER);
};

void M5UnitSSR::setDeviceAddr(uint8_t addr)
{
    writereg8(REG_ADDR, addr);
};

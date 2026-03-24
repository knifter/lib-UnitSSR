# lib-UnitSSR

Arduino library for M5Stack SSR (Solid State Relay) units. Covers two product families:

## UnitSSR — Unit SSR (C3 model)

The newer M5Stack Unit SSR with I2C control via an ESP32-C3.

- I2C address: `0x25` (default, configurable via solder pads)
- Connector: Grove (SDA/SCL)

```cpp
UnitSSR ssr;

bool ok = ssr.begin();
ssr.setRelay(true);
ssr.setRelay(false);
bool on = ssr.getRelay();
```

## UnitACSSR — Unit ACSSR / Unit DCSSR

M5Stack Unit ACSSR (AC load) and Unit DCSSR (DC load). Same firmware and protocol;
`UnitDCSSR` is provided as a type alias for `UnitACSSR`.

Additional features: programmable RGB LED, firmware version read, I2C address change.

- I2C address: `0x50` (default, configurable)
- Connector: Grove (SDA/SCL)

```cpp
UnitACSSR ssr;               // or: UnitDCSSR ssr;
UnitACSSR ssr(Wire, 0x50);   // explicit wire and address

bool ok = ssr.begin();

ssr.setRelay(true);
ssr.setRelay(false);
bool on = ssr.getRelay();

ssr.setLEDColor(255, 0, 0);  // red
uint32_t rgb = ssr.getLEDColor();  // 0x00RRGGBB

uint8_t ver = ssr.getVersion();
ssr.setDeviceAddr(0x51);     // change I2C address (persists in firmware)
```

## Dependencies

- [TwoWireDevice](https://github.com/knifter/TwoWireDevice)

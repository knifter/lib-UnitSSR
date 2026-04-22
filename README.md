# lib-M5Unit-SSR

Arduino library for the M5Stack **Unit ACSSR** and **Unit DCSSR** solid-state relay modules. Both share the same ESP32-C3-based firmware and I2C protocol; one `M5UnitSSR` class covers both.

| Product     | Default I2C addr | Notes                                 |
|-------------|:----------------:|---------------------------------------|
| Unit ACSSR  | `0x50`           | AC load switch + addressable RGB LED  |
| Unit DCSSR  | `0x50`           | DC load switch + addressable RGB LED  |

> The older M5Stack **Unit SSR** (BT136S, SKU U122) is **not** supported — it is GPIO-controlled, not I2C, and has no I2C address.

## Usage

```cpp
#include <M5UnitSSR.h>

M5UnitSSR ssr;                 // default address 0x50
M5UnitSSR ssr(Wire, 0x51);     // explicit wire and address

bool ok = ssr.begin();

ssr.setRelay(true);
ssr.setRelay(false);
bool on = ssr.getRelay();

ssr.setLEDColor(255, 0, 0);    // red
ssr.setLEDColor(0x00FF8000);   // orange, 0x00RRGGBB
uint32_t rgb = ssr.getLEDColor();

uint8_t ver = ssr.getVersion();
ssr.setDeviceAddr(0x51);       // change I2C address (persists in firmware)
```

## Dependencies

- [TwoWireDevice](https://github.com/knifter/TwoWireDevice)

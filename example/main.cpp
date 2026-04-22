#include <Arduino.h>
#include <Wire.h>
#include <M5UnitSSR.h>

M5UnitSSR ssr;

void setup()
{
    Serial.begin(115200);
    Wire.begin();

    if(!ssr.begin())
    {
        Serial.println("M5Unit-SSR not found!");
        while(true);
    };
    Serial.println("M5Unit-SSR ready.");
}

void loop()
{
    ssr.setRelay(true);
    Serial.println("ON");
    delay(1000);

    ssr.setRelay(false);
    Serial.println("OFF");
    delay(1000);
}

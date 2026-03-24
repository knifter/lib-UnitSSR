#include <Arduino.h>
#include <Wire.h>
#include <UnitSSR.h>

UnitSSR ssr;

void setup()
{
    Serial.begin(115200);
    Wire.begin();

    if(!ssr.begin())
    {
        Serial.println("Unit SSR not found!");
        while(true);
    };
    Serial.println("Unit SSR ready.");
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

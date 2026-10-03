

#include "Arduino.h"

const uint8_t lightSensorPin = 33;
unsigned long lastSampleTime = 0;

void setup()
{
    Serial.begin(115200);
    pinMode(lightSensorPin, INPUT);
}

void loop()
{
    const unsigned long currentTime = millis();
    if (currentTime - lastSampleTime < 1000) {
        return;
    }
    lastSampleTime = currentTime;

    int minimum = 4095;
    int maximum = 0;
    long total = 0;

    for (uint8_t sampleIndex = 0; sampleIndex < 10; ++sampleIndex) {
        const int reading = analogRead(lightSensorPin);
        if (reading < minimum) {
            minimum = reading;
        }
        if (reading > maximum) {
            maximum = reading;
        }
        total += reading;
    }

    Serial.print("min=");
    Serial.print(minimum);
    Serial.print(" max=");
    Serial.print(maximum);
    Serial.print(" avg=");
    Serial.println(total / 10);
}

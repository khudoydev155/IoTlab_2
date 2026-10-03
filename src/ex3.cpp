

#include "Arduino.h"

const uint8_t lightSensorPin = 33;
const unsigned long sampleInterval = 300;
unsigned long lastSampleTime = 0;
bool alertActive = false;

void setup()
{
    Serial.begin(115200);
    pinMode(lightSensorPin, INPUT);
}

void loop()
{
    const unsigned long currentTime = millis();
    if (currentTime - lastSampleTime < sampleInterval) {
        return;
    }
    lastSampleTime = currentTime;

    const int reading = analogRead(lightSensorPin);

    if (!alertActive && reading > 3000) {
        alertActive = true;
        Serial.println("ALERT=1");
    } else if (alertActive && reading < 2500) {
        alertActive = false;
        Serial.println("ALERT=0");
    }
}

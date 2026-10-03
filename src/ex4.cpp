

#include "Arduino.h"

const uint8_t buttonPin = 25;
const uint8_t ledPins[] = {26, 27, 12, 14};
const uint8_t ledCount = sizeof(ledPins) / sizeof(ledPins[0]);
bool previousButtonState = false;
uint8_t pressCount = 0;

void updateLeds()
{
    for (uint8_t ledIndex = 0; ledIndex < ledCount; ++ledIndex) {
        digitalWrite(ledPins[ledIndex], ledIndex < pressCount ? HIGH : LOW);
    }
}

void setup()
{
    Serial.begin(115200);
    pinMode(buttonPin, INPUT);

    for (uint8_t ledIndex = 0; ledIndex < ledCount; ++ledIndex) {
        pinMode(ledPins[ledIndex], OUTPUT);
    }
    updateLeds();
}

void loop()
{
    const bool buttonState = digitalRead(buttonPin) == HIGH;

    if (buttonState && !previousButtonState) {
        ++pressCount;
        if (pressCount > ledCount) {
            pressCount = 0;
        }

        updateLeds();
        Serial.print("count=");
        Serial.println(pressCount);
    }

    previousButtonState = buttonState;
}

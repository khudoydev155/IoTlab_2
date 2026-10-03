

#include "Arduino.h"

const uint8_t ledPins[] = {26, 27, 12, 14, 12, 27};
const char *const ledNames[] = {"RED", "GREEN", "YELLOW", "BLUE", "YELLOW", "GREEN"};
const uint8_t ledCount = sizeof(ledPins) / sizeof(ledPins[0]);
uint8_t stepIndex = 0;

void setup()
{
    Serial.begin(115200);

    pinMode(26, OUTPUT);
    pinMode(27, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(14, OUTPUT);
}

void loop()
{
    digitalWrite(26, LOW);
    digitalWrite(27, LOW);
    digitalWrite(12, LOW);
    digitalWrite(14, LOW);

    digitalWrite(ledPins[stepIndex], HIGH);
    Serial.print("chase=");
    Serial.println(ledNames[stepIndex]);

    stepIndex = (stepIndex + 1) % ledCount;
    delay(150);
}

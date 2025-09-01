#include "LEDManager.h"
#include <Arduino.h>

void LEDManager::init() {
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
    setColor(0, 0, 0);
}

void LEDManager::updateLED(SystemStatus status) {
    switch (status) {
    case STATUS_GOOD:
        setColor(0, 255, 0);
        break;
    case STATUS_WARNING:
        setColor(255, 255, 0);
        break;
    case STATUS_CRITICAL:
        setColor(255, 0, 0);
        break;
    }
}

void LEDManager::setColor(int red, int green, int blue) {
    analogWrite(RED_PIN, red);
    analogWrite(GREEN_PIN, green);
    analogWrite(BLUE_PIN, blue);
}
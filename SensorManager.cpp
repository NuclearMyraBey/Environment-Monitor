#include "SensorManager.h"

void SensorManager::init() {
    dht.begin();
    pinMode(LDR_PIN, INPUT);
    pinMode(POT_PIN, INPUT);
}

SensorData SensorManager::readData() {
    SensorData data;

    data.temperature = readTemperature();
    data.humidity = readHumidity();
    data.lightLevel = readLightLevel();
    data.potValue = readPotentiometer();

    return data;
}

float SensorManager::readTemperature() {
    float temp = dht.readTemperature();
    if (isnan(temp)) {
        Serial.println("Error reading temperature!");
        return -999;
    }
    return temp;
}

float SensorManager::readHumidity() {
    float humidity = dht.readHumidity();
    if (isnan(humidity)) {
        Serial.println("Error reading humidity!");
        return -999;
    }
    return humidity;
}

int SensorManager::readLightLevel() {
    int rawValue = analogRead(LDR_PIN);
    return map(rawValue, 0, 1023, 0, 1000);
}

int SensorManager::readPotentiometer() {
    return analogRead(POT_PIN);
}
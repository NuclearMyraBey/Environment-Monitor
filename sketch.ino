#include "DisplayManager.h"
#include "SensorManager.h"
#include "LEDManager.h"

DisplayManager displayManager;
SensorManager sensorManager;
LEDManager ledManager;

void setup() {
	Serial.begin(9600);

	displayManager.init();
	sensorManager.init();
	ledManager.init();

	displayManager.showSplashScreen();
	delay(2000);
	displayManager.clearScreen();
}

void loop() {
	SensorData data = sensorManager.readData();
	SystemStatus status = determineSystemStatus(data);
	displayManager.updateDisplay(data, status);
	ledManager.updateLED(status);

	delay(2000);
}

SystemStatus determineSystemStatus(const SensorData& data) {
	int issues = 0;

	if (data.temperature < 18 || data.temperature > 26) issues++;
	if (data.humidity < 30 || data.humidity > 60) issues++;
	if (data.lightLevel < 100 || data.lightLevel > 800) issues++;

	if (issues == 0) return STATUS_GOOD;
	if (issues == 1) return STATUS_WARNING;
	return STATUS_CRITICAL;
}
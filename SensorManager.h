#include "DHT.h"
#include "DataTypes.h"  

#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

class SensorManager {
public:
	void init();
	SensorData readData();

private:
	static const int DHT_PIN = 2;
	static const int LDR_PIN = A0;
	static const int POT_PIN = A1;

	DHT dht = DHT(DHT_PIN, DHT22);

	float readTemperature();
	float readHumidity();
	int readLightLevel();
	int readPotentiometer();
};

#endif
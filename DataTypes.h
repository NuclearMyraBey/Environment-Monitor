#ifndef DATA_TYPES_H
#define DATA_TYPES_H

enum SystemStatus {
	STATUS_GOOD,
	STATUS_WARNING,
	STATUS_CRITICAL
};

struct SensorData {
	float temperature;
	float humidity;
	int lightLevel;
	int potValue;
};

#endif
#include "DataTypes.h"  

#ifndef LED_MANAGER_H
#define LED_MANAGER_H

class LEDManager {
public:
	void init();
	void updateLED(SystemStatus status);
	void setColor(int red, int green, int blue);

private:
	static const int RED_PIN = 3;
	static const int GREEN_PIN = 5;
	static const int BLUE_PIN = 6;
};

#endif
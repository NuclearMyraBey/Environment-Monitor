#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <SPI.h>
#include "DataTypes.h"

#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#define BACKGROUND_COLOR ILI9341_BLACK
#define TEXT_COLOR ILI9341_WHITE
#define GOOD_COLOR ILI9341_GREEN
#define WARNING_COLOR ILI9341_YELLOW
#define CRITICAL_COLOR ILI9341_RED

class DisplayManager {
public:
	void init();
	void updateDisplay(const SensorData& data, SystemStatus status);
	void clearScreen();
	void showSplashScreen();

private:
	Adafruit_ILI9341 tft = Adafruit_ILI9341(10, 9, 8); // CS, DC, RST

	void drawHeader(SystemStatus status);
	void drawSensorData(const SensorData& data);
	void drawRecommendations(SystemStatus status, const SensorData& data);
	String getRecommendationText(SystemStatus status, const SensorData& data);
};

#endif
#include "DisplayManager.h"

void DisplayManager::init() {
    tft.begin();
    tft.setRotation(3);
    clearScreen();
}

void DisplayManager::updateDisplay(const SensorData& data, SystemStatus status) {
    clearScreen();
    drawHeader(status);
    drawSensorData(data);
    drawRecommendations(status, data);
}

void DisplayManager::drawHeader(SystemStatus status) {
    tft.setTextSize(2);
    tft.setTextColor(TEXT_COLOR);

    tft.setCursor(10, 10);
    tft.print("Status: ");

    switch (status) {
    case STATUS_GOOD:
        tft.setTextColor(GOOD_COLOR);
        tft.print("GOOD");
        break;
    case STATUS_WARNING:
        tft.setTextColor(WARNING_COLOR);
        tft.print("WARNING");
        break;
    case STATUS_CRITICAL:
        tft.setTextColor(CRITICAL_COLOR);
        tft.print("CRITICAL");
        break;
    }

    tft.drawLine(0, 35, 320, 35, TEXT_COLOR);
}

void DisplayManager::drawSensorData(const SensorData& data) {
    tft.setTextSize(2);
    tft.setTextColor(TEXT_COLOR);

    tft.setCursor(10, 50);
    tft.print("Temp: ");
    tft.print(data.temperature, 1);
    tft.print(" C");

    tft.setCursor(10, 80);
    tft.print("Humidity: ");
    tft.print(data.humidity, 1);
    tft.print(" %");

    tft.setCursor(10, 110);
    tft.print("Light: ");
    tft.print(data.lightLevel);
    tft.print(" lx");

    tft.drawLine(0, 140, 320, 140, TEXT_COLOR);
}

void DisplayManager::drawRecommendations(SystemStatus status, const SensorData& data) {
    tft.setTextSize(1);
    tft.setTextColor(TEXT_COLOR);

    tft.setCursor(10, 150);
    tft.print("Recommendations:");

    String recommendations = getRecommendationText(status, data);
    tft.setCursor(10, 170);
    tft.setTextSize(1);

    int currentY = 170;
    int lineHeight = 15;

    String currentLine = "";
    for (int i = 0; i < recommendations.length(); i++) {
        char c = recommendations[i];
        if (c == '\n' || currentLine.length() > 35) {
            tft.setCursor(10, currentY);
            tft.print(currentLine);
            currentLine = "";
            currentY += lineHeight;
            if (c == '\n') continue;
        }
        currentLine += c;
    }

    if (currentLine.length() > 0) {
        tft.setCursor(10, currentY);
        tft.print(currentLine);
    }
}

String DisplayManager::getRecommendationText(SystemStatus status, const SensorData& data) {
    if (status == STATUS_GOOD) {
        return "All parameters optimal! Maintain current conditions.";
    }

    String recommendations = "";

    if (data.temperature < 18) {
        recommendations += "! Increase temperature (heater)\n";
    }
    else if (data.temperature > 26) {
        recommendations += "! Decrease temperature (AC/ventilation)\n";
    }

    if (data.humidity < 30) {
        recommendations += "! Increase humidity (humidifier)\n";
    }
    else if (data.humidity > 60) {
        recommendations += "! Decrease humidity (dehumidifier)\n";
    }

    if (data.lightLevel < 100) {
        recommendations += "! Increase lighting (more light)\n";
    }
    else if (data.lightLevel > 800) {
        recommendations += "! Decrease lighting (curtains/shades)\n";
    }

    return recommendations;
}

void DisplayManager::clearScreen() {
    tft.fillScreen(BACKGROUND_COLOR);
}

void DisplayManager::showSplashScreen() {
    clearScreen();
    tft.setTextSize(2);
    tft.setTextColor(ILI9341_CYAN);
    tft.setCursor(50, 100);
    tft.print("Environment Monitor by NMRB_CPP");
    tft.setTextColor(ILI9341_WHITE);
    tft.setCursor(80, 130);
    tft.print("Starting");

    for (int i = 0; i < 3; i++) {
        tft.setCursor(180 + i * 12, 130);
        tft.print(".");
        delay(500);
    }
}
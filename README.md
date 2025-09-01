# Environment-Monitor system by NuclearMyraBey!
--------
[Wokwi link](https://wokwi.com/projects/440837431738006529) | Welcome to my project based on **Arduino Uno**!

> Smart Arduino based environmental monitoring system with color indication and recommendations.
> The project will help you track the level of humidity, temperature, light and give useful tips to the gardener.

# Components
---------
* Arduino Uno or Mega (ur wish, but Uno more comfortable) — system controller;
* DHT22 — temperature and humidity sensor;
* LDR Photoresistor — light sensor;
* RGB LED — LED status indication;
* ILI9341 2.8" TFT-LCD — display for displaying data;

# Additional
----------
* Resistors: 220Ω (3 pcs), 10kΩ (1 pc)
* Breadboard and wires (female/male and male/male)
* Power supply 5V

# Libraries
----------
All libraries you can download in Arduino IDE
* Adafruit GFX Library;
* Adafruit ILI9341;
* DHT sensor library;

# Files
----------
File name | File contents
---------------------|----------------------
Sketch.ino | Main program file (Arduino sketch)
DataTypes.h | General definitions of data structures and enumerations
DisplayManager.h | Header file for controlling the TFT display
DisplayManager.cpp | Implementation of methods for working with the display
SensorManager.h | Header file for working with sensors
SensorManager.cpp | Implementation of methods for reading data from sensors
LEDManager.h | Header file for controlling RGB LED
LEDManager.cpp | Implementation of light indication methods
README.md | Project documentation and assembly instructions
Images/  | Wires, project work and etc.

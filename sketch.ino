// Cesar Giacomini Penteado
// cesargiacomini@gmail.com
// Matrix WS2812 16x16 FastLed.h ESP32 WROOM
// Modified version of Juan Cruz Dillon
// Original version https://wokwi.com/projects/408318183648978945

//#include "Emoji.h"               // Librería creada
#include <TM1637Display.h>
#define CLK  27 // The ESP32 pin GPIO22 connected to CLK
#define DIO  14 // The ESP32 pin GPIO23 connected to DIO
TM1637Display display = TM1637Display(CLK, DIO);

#define CLK2  25 // The ESP32 pin GPIO22 connected to CLK
#define DIO2  26 // The ESP32 pin GPIO23 connected to DIO
TM1637Display display2 = TM1637Display(CLK2, DIO2);


// include library to read and write from flash memory
#include <EEPROM.h>
// define the number of bytes you want to access
#define EEPROM_SIZE 10
//#include "DFRobotDFPlayerMini.h" // Include the DFRobot DFPlayer Mini library

//#define PASSO_MENOR
#define DISPLAY_MENOR 0; //0 - 16x16 1 - 32x32
#define CARACTER_MENOR 0; //0 - 16x16 1 - 32x32

#ifdef ESP32
  #define FPSerial Serial1  // For ESP32, use hardware serial port 1
#else
  #include <SoftwareSerial.h> // Include SoftwareSerial library for non-ESP32 boards
  SoftwareSerial FPSerial(16, 17); // Define SoftwareSerial on pins 16 (RX) and 17 (TX)
#endif

//DFRobotDFPlayerMini myDFPlayer; // Create an instance of the DFRobotDFPlayerMini class


#include <FastLED.h>
#define NUM_LEDS 1024
#define DATA_PIN 13
CRGB leds[NUM_LEDS];

CRGB IMAGES[4][16 * 16] = {
	// 56.png
	{
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 223, 131},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 223, 131},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 223, 131},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 255, 255, 255},
		{ 255, 255, 255},
		{ 255, 255, 255},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 223, 131},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 255, 255, 255},
		{ 255, 255, 255},
		{ 255, 255, 255},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 223, 131},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 255, 255, 255},
		{ 255, 255, 255},
		{ 255, 255, 255},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 223, 131},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 251, 59, 76},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 223, 131},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 251, 59, 76},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 223, 131},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 255, 255, 255},
		{ 255, 255, 255},
		{ 255, 255, 255},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 223, 131},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 255, 255, 255},
		{ 255, 255, 255},
		{ 255, 255, 255},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 255, 255},
		{ 255, 255, 255},
		{ 255, 255, 255},
		{ 247, 204, 80},
		{ 255, 255, 255},
		{ 255, 255, 255},
		{ 255, 255, 255},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 223, 131},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 255, 255},
		{ 255, 255, 255},
		{ 255, 255, 255},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0}
	},
	// 59.png
	{
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 223, 131},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 223, 131},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 223, 131},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 255, 255, 255},
		{ 255, 255, 255},
		{ 255, 255, 255},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 223, 131},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 0, 0, 0},
		{ 255, 255, 255},
		{ 255, 255, 255},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 223, 131},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 255, 255, 255},
		{ 255, 255, 255},
		{ 255, 255, 255},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 0, 0, 0},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 223, 131},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 0, 0, 0},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 223, 131},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 0, 0, 0},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 223, 131},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 255, 255, 255},
		{ 255, 255, 255},
		{ 255, 255, 255},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 0, 0, 0},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 223, 131},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 0, 0, 0},
		{ 255, 255, 255},
		{ 255, 255, 255},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 223, 131},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 255, 255, 255},
		{ 255, 255, 255},
		{ 255, 255, 255},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 223, 131},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 223, 131},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0}
	},
	// 62.png
	{
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 223, 131},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 223, 131},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 0, 0, 0},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 223, 131},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 0, 0, 0},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 0, 0, 0},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 223, 131},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 0, 0, 0},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 0, 0, 0},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 223, 131},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 0, 0, 0},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 0, 0, 0},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 223, 131},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 0, 0, 0},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 242, 15, 36},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 242, 15, 36},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 0, 0, 0},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 242, 15, 36},
		{ 247, 204, 80},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 247, 204, 80},
		{ 0, 0, 0},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 0, 0, 0},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 247, 204, 80},
		{ 242, 15, 36},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 0, 0, 0},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 0, 0, 0},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 242, 15, 36},
		{ 255, 223, 131},
		{ 247, 204, 80},
		{ 242, 15, 36},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 0, 0, 0},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 0, 0, 0},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 223, 131},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 0, 0, 0},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 223, 131},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 215, 159, 54},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 247, 204, 80},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0}
	},
	// 99.png
	{
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 76, 92},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 215, 13, 32},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 76, 92},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 164, 10, 25},
		{ 164, 10, 25},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 215, 13, 32},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 76, 92},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 0, 0, 0},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 164, 10, 25},
		{ 164, 10, 25},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 215, 13, 32},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 76, 92},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 0, 0, 0},
		{ 242, 15, 36},
		{ 215, 13, 32},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 76, 92},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 0, 0, 0},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 215, 13, 32},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 76, 92},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 0, 0, 0},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 215, 13, 32},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 76, 92},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 0, 0, 0},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 215, 13, 32},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 76, 92},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 0, 0, 0},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 215, 13, 32},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 76, 92},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 0, 0, 0},
		{ 242, 15, 36},
		{ 215, 13, 32},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 76, 92},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 0, 0, 0},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 164, 10, 25},
		{ 164, 10, 25},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 215, 13, 32},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 76, 92},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 164, 10, 25},
		{ 164, 10, 25},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 215, 13, 32},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 255, 76, 92},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 215, 13, 32},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 242, 15, 36},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0},
		{ 0, 0, 0}
	}
};




// Tamaño del campo de juego
#ifdef DISPLAY_MENOR
  #define GRID_W              (16)
  #define GRID_H              (32)     // El campo de juego es de 8x24 LEDs
#else
  #define GRID_W              (32)
  #define GRID_H              (32)     // El campo de juego es de 32x32 LEDs
#endif
#define STRAND_LENGTH       (GRID_W*GRID_H)
#define LED_DATA_PIN        (8)     // Pin digital al que va conectado
#define BACKWARDS           (0)    // Conexión tipo Z 
#ifdef CARACTER_MENOR
  #define PIECE_W             (4)   // Cada figura del tetris ocupará 4 LEDs
  #define PIECE_H             (4)
#else
  #define PIECE_W             (8)   // Cada figura del tetris ocupará 8 LEDs
  #define PIECE_H             (8)
#endif
#define NUM_PIECE_TYPES     (7)  // Cantidad de figuras del Tetris
// Parámetros del Joystick
#define JOYSTICK_DEAD_ZONE  (30)
#define JOYSTICK_PIN        (2)   
// Parámetros para la caída de figuras
#define DROP_MINIMUM        (25)  // velocidad máxima que la gravedad puede alcanzar
#define DROP_ACCELERATION   (20)  // qué tan rápido aumenta la gravedad
#define INITIAL_MOVE_DELAY  (70) // retraso inicial
#define INITIAL_DROP_DELAY  (500)
#define INITIAL_DRAW_DELAY  (30)

//int button_pause = 7;     // Pin digital al que va conectado
int button_start = 12;   // Pin digital al que va conectado
int buzzer = 33;        // Pin digital al que va conectado
int joystick_x = 5;   // Pin digital// Pin analógico al que va conectado
int joystick_y = 18;  // Pin digital// Pin analógico al que va conectado
int joystick_r = 19;  // Pin digital// Pin analógico al que va conectado
int joystick_d = 21;  // Pin digital// Pin analógico al que va conectado

//boolean fundo_branco = true;
int i = 0;
int b = 0;
int g_ov = 0;
float top_score = 0;     // Valor inicial del puntaje máximo
float score = 0;        // Valor inicial del puntaje

unsigned long previousMillis = 0; 
unsigned long currentMillis = 0;


#ifdef CARACTER_MENOR 
        
        // Colores por figura
        // Cada pieza tiene un máximo de 4 de ancho, 4 de alto y 4 rotaciones
        const char piece_I[] = {
          0,0,0,0,
          1,1,1,1,
          0,0,0,0,
          0,0,0,0,
        
          0,0,1,0,
          0,0,1,0,
          0,0,1,0,
          0,0,1,0,
          
          0,0,0,0,
          0,0,0,0,
          1,1,1,1,
          0,0,0,0,
        
          0,1,0,0,
          0,1,0,0,
          0,1,0,0,
          0,1,0,0,
        };
        
        const char piece_L[] = {
          0,0,0,0,
          1,1,1,0,
          1,0,0,0,
          0,0,0,0,
          
          1,1,0,0,
          0,1,0,0,
          0,1,0,0,
          0,0,0,0,

          0,0,1,0,
          1,1,1,0,
          0,0,0,0,
          0,0,0,0,
          
          0,1,0,0,
          0,1,0,0,
          0,1,1,0,
          0,0,0,0,
        
        };
        
        const char piece_J[] = {
          0,0,0,0,
          1,1,1,0,
          0,0,1,0,
          0,0,0,0,
          
          0,1,0,0,
          0,1,0,0,
          1,1,0,0,
          0,0,0,0,

          1,0,0,0,
          1,1,1,0,
          0,0,0,0,
          0,0,0,0,
          
          0,1,1,0,
          0,1,0,0,
          0,1,0,0,
          0,0,0,0,
        
        
        };
        
        const char piece_T[] = {
          0,0,0,0,
          1,1,1,0,
          0,1,0,0,
          0,0,0,0,
        
          0,1,0,0,
          1,1,0,0,
          0,1,0,0,
          0,0,0,0,
        
          0,1,0,0,
          1,1,1,0,
          0,0,0,0,
          0,0,0,0,
        
          0,1,0,0,
          0,1,1,0,
          0,1,0,0,
          0,0,0,0,
          
        };
        
        const char piece_S[] = {
          0,1,1,0,
          1,1,0,0,
          0,0,0,0,
          0,0,0,0,
        
          0,1,0,0,
          0,1,1,0,
          0,0,1,0,
          0,0,0,0,
        
          0,0,0,0,
          0,1,1,0,
          1,1,0,0,
          0,0,0,0,
        
          1,0,0,0,
          1,1,0,0,
          0,1,0,0,
          0,0,0,0,
        };
        
        const char piece_Z[] = {
          1,1,0,0,
          0,1,1,0,
          0,0,0,0,
          0,0,0,0,
          
          0,0,1,0,
          0,1,1,0,
          0,1,0,0,
          0,0,0,0,
        
          0,0,0,0,
          1,1,0,0,
          0,1,1,0,
          0,0,0,0,
          
          0,1,0,0,
          1,1,0,0,
          1,0,0,0,
          0,0,0,0,
        };
        
        const char piece_O[] = {
          1,1,0,0,
          1,1,0,0,
          0,0,0,0,
          0,0,0,0,
          
          1,1,0,0,
          1,1,0,0,
          0,0,0,0,
          0,0,0,0,
          
          1,1,0,0,
          1,1,0,0,
          0,0,0,0,
          0,0,0,0,
          
          1,1,0,0,
          1,1,0,0,
          0,0,0,0,
          0,0,0,0,
        };
        
        

  #else 
  
      // Colores por figura
      // Cada pieza tiene un máximo de 8 de ancho, 8 de alto y 8 rotaciones
      const char piece_I[] = {
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
      
        0,0,0,1,1,0,0,0,
        0,0,0,1,1,0,0,0,
        0,0,0,1,1,0,0,0,  
        0,0,0,1,1,0,0,0,  
        0,0,0,1,1,0,0,0,  
        0,0,0,1,1,0,0,0,  
        0,0,0,1,1,0,0,0,  
        0,0,0,1,1,0,0,0,  
      
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        
        0,0,0,1,1,0,0,0,
        0,0,0,1,1,0,0,0,
        0,0,0,1,1,0,0,0,  
        0,0,0,1,1,0,0,0,  
        0,0,0,1,1,0,0,0,  
        0,0,0,1,1,0,0,0,  
        0,0,0,1,1,0,0,0,  
        0,0,0,1,1,0,0,0,  

      };
      
 const char piece_L[] = {
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,1,1,1,1,1,1,0,
        0,1,1,1,1,1,1,0,
        0,1,1,0,0,0,0,0,
        0,1,1,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
      
        0,0,0,0,0,0,0,0,
        0,0,1,1,1,1,0,0,
        0,0,1,1,1,1,0,0,
        0,0,0,0,1,1,0,0,
        0,0,0,0,1,1,0,0,
        0,0,0,0,1,1,0,0,
        0,0,0,0,1,1,0,0,
        0,0,0,0,0,0,0,0,
      
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,1,1,0,
        0,0,0,0,0,1,1,0,
        0,1,1,1,1,1,1,0,
        0,1,1,1,1,1,1,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
      
        0,0,0,0,0,0,0,0,
        0,0,1,1,0,0,0,0,
        0,0,1,1,0,0,0,0,
        0,0,1,1,0,0,0,0,
        0,0,1,1,0,0,0,0,
        0,0,1,1,1,1,0,0,
        0,0,1,1,1,1,0,0,
        0,0,0,0,0,0,0,0,
      
      };
            
       const char piece_J[] = {
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,1,1,1,1,1,1,0,
        0,1,1,1,1,1,1,0,
        0,0,0,0,0,1,1,0,
        0,0,0,0,0,1,1,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,

        0,0,0,0,0,0,0,0,
        0,0,0,0,1,1,0,0,
        0,0,0,0,1,1,0,0,
        0,0,0,0,1,1,0,0,
        0,0,0,0,1,1,0,0,
        0,0,1,1,1,1,0,0,
        0,0,1,1,1,1,0,0,
        0,0,0,0,0,0,0,0,

        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,1,1,0,0,0,0,0,
        0,1,1,0,0,0,0,0,
        0,1,1,1,1,1,1,0,
        0,1,1,1,1,1,1,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,

        0,0,0,0,0,0,0,0,
        0,0,1,1,1,1,0,0,
        0,0,1,1,1,1,0,0,
        0,0,1,1,0,0,0,0,
        0,0,1,1,0,0,0,0,
        0,0,1,1,0,0,0,0,
        0,0,1,1,0,0,0,0,
        0,0,0,0,0,0,0,0,
      

      };      
      
      const char piece_T[] = {
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,1,1,1,1,1,1,0,
        0,1,1,1,1,1,1,0,
        0,0,0,1,1,0,0,0,
        0,0,0,1,1,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
      
        0,0,0,0,0,0,0,0,
        0,0,0,0,1,1,0,0,
        0,0,0,0,1,1,0,0,
        0,0,1,1,1,1,0,0,
        0,0,1,1,1,1,0,0,
        0,0,0,0,1,1,0,0,
        0,0,0,0,1,1,0,0,
        0,0,0,0,0,0,0,0,
      
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,1,1,0,0,0,
        0,0,0,1,1,0,0,0,
        0,1,1,1,1,1,1,0,
        0,1,1,1,1,1,1,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
      
        0,0,0,0,0,0,0,0,
        0,0,1,1,0,0,0,0,
        0,0,1,1,0,0,0,0,
        0,0,1,1,1,1,0,0,
        0,0,1,1,1,1,0,0,
        0,0,1,1,0,0,0,0,
        0,0,1,1,0,0,0,0,
        0,0,0,0,0,0,0,0,
      
      };
      
      const char piece_S[] = {
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,1,1,1,1,0,
        0,0,0,1,1,1,1,0,
        0,1,1,1,1,0,0,0,
        0,1,1,1,1,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
      
        0,0,0,0,0,0,0,0,
        0,0,1,1,0,0,0,0,
        0,0,1,1,0,0,0,0,
        0,0,1,1,1,1,0,0,
        0,0,1,1,1,1,0,0,
        0,0,0,0,1,1,0,0,
        0,0,0,0,1,1,0,0,
        0,0,0,0,0,0,0,0,
      
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,1,1,1,1,0,
        0,0,0,1,1,1,1,0,
        0,1,1,1,1,0,0,0,
        0,1,1,1,1,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
      
        0,0,0,0,0,0,0,0,
        0,0,1,1,0,0,0,0,
        0,0,1,1,0,0,0,0,
        0,0,1,1,1,1,0,0,
        0,0,1,1,1,1,0,0,
        0,0,0,0,1,1,0,0,
        0,0,0,0,1,1,0,0,
        0,0,0,0,0,0,0,0,
      
      };
      
      const char piece_Z[] = {
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,1,1,1,1,0,0,0,
        0,1,1,1,1,0,0,0,
        0,0,0,1,1,1,1,0,
        0,0,0,1,1,1,1,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
      
        0,0,0,0,0,0,0,0,
        0,0,0,0,1,1,0,0,
        0,0,0,0,1,1,0,0,
        0,0,1,1,1,1,0,0,
        0,0,1,1,1,1,0,0,
        0,0,1,1,0,0,0,0,
        0,0,1,1,0,0,0,0,
        0,0,0,0,0,0,0,0,
      
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,1,1,1,1,0,0,0,
        0,1,1,1,1,0,0,0,
        0,0,0,1,1,1,1,0,
        0,0,0,1,1,1,1,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        
        0,0,0,0,0,0,0,0,
        0,0,0,0,1,1,0,0,
        0,0,0,0,1,1,0,0,
        0,0,1,1,1,1,0,0,
        0,0,1,1,1,1,0,0,
        0,0,1,1,0,0,0,0,
        0,0,1,1,0,0,0,0,
        0,0,0,0,0,0,0,0,
      
      };
      
      const char piece_O[] = {
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,1,1,1,1,0,0,
        0,0,1,1,1,1,0,0,
        0,0,1,1,1,1,0,0,
        0,0,1,1,1,1,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
          
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,1,1,1,1,0,0,
        0,0,1,1,1,1,0,0,
        0,0,1,1,1,1,0,0,
        0,0,1,1,1,1,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
      
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,1,1,1,1,0,0,
        0,0,1,1,1,1,0,0,
        0,0,1,1,1,1,0,0,
        0,0,1,1,1,1,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
      
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,1,1,1,1,0,0,
        0,0,1,1,1,1,0,0,
        0,0,1,1,1,1,0,0,
        0,0,1,1,1,1,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
      
      };
 #endif;


// Figuras
const char *pieces[NUM_PIECE_TYPES] = {
  piece_S,
  piece_Z,
  piece_L,
  piece_J,
  piece_O,
  piece_T,
  piece_I,
};

// Color para cada figura
const long piece_colors[NUM_PIECE_TYPES] = {
  0x009900, // verde S
  0xFF0000, // rojo Z
  0xFF8000, // naranja L
  0x000044, // azul J
  0xFFFF00, // amarillo O
  0xFF00FF, // morado T
  0x00FFFF,  // turquesa I
};

//Se define la matriz con la que se esta trabajando y se le da un nombre
//Adafruit_NeoPixel strip = Adafruit_NeoPixel(STRAND_LENGTH, LED_DATA_PIN, NEO_RGB);


// Ayuda a saber el estado anterior del botón
int old_button=0;
// Arduino puede detectar cuando hay nuevos movimientos
int old_px = 0;
// arduino pueda saber cuándo el usuario intenta girar
int old_i_want_to_turn=0;

// Arduino puede recordar la anterior figura que cae
int piece_id;
int piece_rotation;
int piece_x;
int piece_y;

//Secuencia de figuras al azar
char piece_sequence[NUM_PIECE_TYPES];
char sequence_i=NUM_PIECE_TYPES;

// velocidad en la que se puede mover el jugador
long last_move;
long move_delay=INITIAL_MOVE_DELAY;  // 100ms = 5 times a second

// Controla la caída automática de las figuras
long last_drop;
long drop_delay = INITIAL_DROP_DELAY;;  // 500ms = 2 times a second

long last_draw;
long draw_delay;  // 60 fps

int cont_linhas, estado, comemorou = 0;


// Arduino mantiene un historial de donde se encuentran las figuras que ya cayeron
long grid[GRID_W*GRID_H];


//MÉTODOS

void desenha_emoji(unsigned int x, uint8_t snake){//CRGB* datain){
for (unsigned int z=0; z<256; z++){
     leds[rotatedlinearToSnake(z, snake)] = CRGB(IMAGES[x][z]);
  }
}

// convert x/y cordinates to LED index on zig-zag grid
uint16_t getIndex(uint16_t x, uint16_t y, uint8_t zigzag) {
  uint16_t index;

  if (zigzag == 0) {
    // Mapeamento linear normal: todas as linhas são mapeadas da esquerda para a direita.
    index = y * GRID_W + x;
  } else {
    // Mapeamento em zig-zag: linhas pares da esquerda para a direita e linhas ímpares da direita para a esquerda.
    if (y % 2 == 0) {
      index = y * GRID_W + x;
    } else {
      index = y * GRID_W + (GRID_W - 1 - x);
    }
  }
  
  return index;
}

// I want to turn on point P(x,y), which is X from the left and Y from the top.
// I might also want to hold it on for us microseconds.
void p(int x,int y,long color) {
  int a = (GRID_H-1-y)*GRID_W;
  if( ( y % 2 ) == BACKWARDS ) {  // % is modulus.
    // y%2 is false when y is an even number - rows 0,2,4,6.
    a += x;
  } else {
    // y%2 is true when y is an odd number - rows 1,3,5,7.
    a += GRID_W - 1 - x;
  }
  a%=STRAND_LENGTH;
  //FastLED.setBrightness(50);
  leds[getIndex(x, y, 1)] = color;
}


// la cuadrícula contiene la memoria de arduino del tablero de juego, incluida la pieza que está cayendo
void draw_grid() {
  int x, y;
  for(y=0;y<GRID_H;++y) {
    for(x=0;x<GRID_W;++x) {
      if( grid[y*GRID_W+x] != 0 ) {
        p(x,y,grid[y*GRID_W+x]);
      } else {

        //if (fundo_branco) 
        //  leds[getIndex(x, y, 0)].setRGB(16,16,16); // 128 half brightness white
        //else
          p(x,y,0);
      }
    }
  }
  //strip.show();
  //FastLED.setBrightness(50);
  FastLED.show();
}

// elige una nueva pieza de la secuencia de orden aleatorio
void choose_new_piece() {
  if( sequence_i >= NUM_PIECE_TYPES ) {
    // list exhausted
    int i,j, k;
    for(i=0;i<NUM_PIECE_TYPES;++i) {
      do {
        // pick a random piece
        j = rand() % NUM_PIECE_TYPES;
        // make sure it isn't already in the sequence.
        for(k=0;k<i;++k) {
          if(piece_sequence[k]==j) break;  // already in sequence
        }
      } while(k<i);
      // not in sequence.  Add it.
      piece_sequence[i] = j;
    }
    // rewind sequence counter
    sequence_i=0;
  }
  
// Escoge la siguiente figura
  piece_id = piece_sequence[sequence_i++];
  // always start the piece top center.
    
    #ifdef CARACTER_MENOR 
        piece_y=-4;  // -4 squares off the top of the screen.
        piece_x=7;
    #else
        piece_y=-8;  // -8 squares off the top of the screen.
        piece_x=12;
    #endif
    
// Siempre inicia en la misma orientación 
  piece_rotation=0;

}


void erase_piece_from_grid() {
  int x, y;
  
  const char *piece = pieces[piece_id] + (piece_rotation * PIECE_H * PIECE_W);
  
  for(y=0;y<PIECE_H;++y) {
    for(x=0;x<PIECE_W;++x) {
      int nx=piece_x+x;
      int ny=piece_y+y;
      if(ny<0 || ny>GRID_H) continue;
      if(nx<0 || nx>GRID_W) continue;
      if(piece[y*PIECE_W+x]==1) {
        grid[ny*GRID_W+nx]=0;  // zero erases the grid location.
      }
    }
  }
}


void add_piece_to_grid() {
  int x, y;
  
  const char *piece = pieces[piece_id] + (piece_rotation * PIECE_H * PIECE_W);
  
  for(y=0;y<PIECE_H;++y) {
    for(x=0;x<PIECE_W;++x) {
      int nx=piece_x+x;
      int ny=piece_y+y;
      if(ny<0 || ny>GRID_H) continue;
      if(nx<0 || nx>GRID_W) continue;
      if(piece[y*PIECE_W+x]==1) {
        grid[ny*GRID_W+nx]=piece_colors[piece_id];  // zero erases the grid location.
      }
    }
  }
}


void gravarFloat(uint32_t address, float value) {
  union {
    float f;
    uint8_t bytes[4];
  } data;
  data.f = value;
  for (int i = 0; i < 4; i++){
    EEPROM.write((int)address + i,data.bytes[i]); 
  }
  EEPROM.commit();
}

float lerFloat(uint32_t address) {
 union {
    float f;
    uint8_t bytes[4];
  } data;
  for (int i = 0; i < 4; i++){
    data.bytes[i] = EEPROM.read((int)address + i);
  }
  return data.f;  
}

void comemorar_top_score(){
  for (int i=0; i<2; i++){
                      desenha_emoji(0, 0);
                      FastLED.show();
                      display2.showNumberDec(top_score,true);
                      for (int j=0; j<3; j++){
                          digitalWrite(buzzer,HIGH);  // Suena el buzzer
                          delay(50);
                          digitalWrite(buzzer,LOW);
                          delay(50);
                      }    
                      display2.clear();
                      delay(50);
                      for(int j=0;j<STRAND_LENGTH;j++){
                          leds[j]=CRGB::Black;
                          delay(1); // Delay for a period of time (in milliseconds).
                      }
                      FastLED.show();


  }                    

}

// Borrar fila cada vez que se completa 
void delete_row(int y) {
  digitalWrite(buzzer,HIGH);  // Suena el buzzer
  delay(350);
  digitalWrite(buzzer,LOW);
  

  #ifdef CARACTER_MENOR
     score = score + 15;       // Cada fila
  #else
     score = score + 7.5;       // Cada fila
  #endif
    
  if(score > top_score) {
    gravarFloat(2,score);
    top_score = lerFloat(2);
    if (comemorou == 0)
       comemorar_top_score();
    comemorou = 1;
  }


  display.showNumberDec(score,true); 
  display2.showNumberDec(top_score,true); 
  int x;
  for(;y>0;--y) {
    for(x=0;x<GRID_W;++x) {
      grid[y*GRID_W+x] = grid[(y-1)*GRID_W+x];
    }
  }
// todo se movió hacia abajo 1, por lo que la fila superior debe estar vacía o el juego terminaría.
  for(x=0;x<GRID_W;++x) {
    grid[x]=0;
  }
}

//Caída rápida de figuras
void fall_faster() { 
  //if(drop_delay > DROP_MINIMUM) drop_delay -= DROP_ACCELERATION;

                   if ((estado == 0) and (cont_linhas == 4)) {
                      drop_delay = 350;
                      move_delay = 50;
                      estado = 1;
                      cont_linhas = -1;
                      digitalWrite(buzzer,HIGH);  // Suena el buzzer
                      desenha_emoji(1, 0);
                      FastLED.show();
                      delay(3000);
                      digitalWrite(buzzer,LOW);
                   }   
                   if ((estado == 1) and (cont_linhas == 3)) {
                      drop_delay = 250;
                      move_delay=30;
                      estado = 2;
                      cont_linhas = -1;
                      digitalWrite(buzzer,HIGH);  // Suena el buzzer
                      desenha_emoji(0, 0);
                      FastLED.show();
                      delay(3000);
                      digitalWrite(buzzer,LOW);
                   }   
                   if ((estado == 2) and (cont_linhas == 2)) {
                      drop_delay = 200;
                      move_delay= 5;
                      estado = 3;
                      cont_linhas = -1;
                      digitalWrite(buzzer,HIGH);  // Suena el buzzer
                      desenha_emoji(3, 0);
                      FastLED.show();
                      delay(3000);
                      digitalWrite(buzzer,LOW);
                   }   
                   if ((estado == 3) and (cont_linhas == 1)) {
                      drop_delay = 500;
                      move_delay=70;
                      estado = 0;
                      cont_linhas = -1;
                      digitalWrite(buzzer,HIGH);  // Suena el buzzer
                      desenha_emoji(2, 0);
                      FastLED.show();
                      delay(3000);
                      digitalWrite(buzzer,LOW);
                   }   
                //}      
                cont_linhas++;

}

//Remover filas completas 
void remove_full_rows() {
  int x, y, c;
  char row_removed=0;
  
  for(y=0;y<GRID_H;++y) {
    //cuenta los espacios vacios de la fila
    c = 0;
    for(x=0;x<GRID_W;++x) {
      if( grid[y*GRID_W+x] > 0 ) c++;
    }
    if(c==GRID_W) {
      // row full!
      delete_row(y);
      fall_faster();
    }
  }  
}


// Instrucciones para cada angulo del joystick
void try_to_move_piece_sideways() {
  int new_px = 0;
  // click the button?
    if((digitalRead(joystick_y) == LOW) and (digitalRead(button_start) == HIGH) and (digitalRead(joystick_x) == HIGH) and (digitalRead(joystick_d) == HIGH) and (digitalRead(joystick_r) == HIGH) ){ 
      //try_to_move_fast_left();
      new_px=-1;
    }            
      
 
     if((digitalRead(joystick_x) == LOW) and (digitalRead(button_start) == HIGH) and (digitalRead(joystick_d) == HIGH) and (digitalRead(joystick_y) == HIGH) and (digitalRead(joystick_r) == HIGH) ){ 
       //try_to_move_fast_right();    
       new_px=1;
     } 

  
  #ifdef PASSO_MENOR
    if(new_px!=old_px && piece_can_fit(piece_x+new_px,piece_y,piece_rotation)==1) {
      piece_x+=new_px;
    }
  #else
    if(piece_can_fit(piece_x+new_px,piece_y,piece_rotation)==1) {
      piece_x+=new_px;
    }
  #endif
 

  old_px = new_px;
}


void try_to_rotate_piece() {
  int i_want_to_turn=0;
    
  // Rotaciones con el joystick
  int dy = 0;
  if((digitalRead(joystick_r) == LOW) and (digitalRead(button_start) == HIGH) and (digitalRead(joystick_x) == HIGH) and (digitalRead(joystick_y) == HIGH) and (digitalRead(joystick_d) == HIGH) ){ 
     i_want_to_turn=1;
  }
  
  if(i_want_to_turn==1 && i_want_to_turn != old_i_want_to_turn) {
    // figure out what it will look like at that new angle
    int new_pr = ( piece_rotation + 1 ) % 4; 

    // if it can fit at that new angle (doesn't bump anything)
    if(piece_can_fit(piece_x,piece_y,new_pr)) {
      // then make the turn.
      piece_rotation = new_pr;
    } else {
      // wall kick
      if(piece_can_fit(piece_x-1,piece_y,new_pr)) {
        piece_x = piece_x-1;
        piece_rotation = new_pr;
      } else if(piece_can_fit(piece_x+1,piece_y,new_pr)) {
        piece_x = piece_x+1;
        piece_rotation = new_pr;
      } 
    }
  }
  old_i_want_to_turn = i_want_to_turn;
}


//Encajar figuras entre si
int piece_can_fit(int px,int py,int pr) {
  if( piece_off_edge(px,py,pr) ) return 0;
  if( piece_hits_rubble(px,py,pr) ) return 0;
  return 1;
}

// Cuando las figurs sobrepasen el borde
int piece_off_edge(int px,int py,int pr) {
  int x,y;
  const char *piece = pieces[piece_id] + (pr * PIECE_H * PIECE_W);
  
  for(y=0;y<PIECE_H;++y) {
    for(x=0;x<PIECE_W;++x) {
      int nx=px+x;
      int ny=py+y;
      if(ny<0) continue;  // off top, don't care
      if(piece[y*PIECE_W+x]>0) {
        if(nx<0) return 1;  // Fuera del lado izquierdo
        if(nx>=GRID_W ) return 1;  // Fuera del lado derecho
      }
    }
  }
  
  return 0;  // dentro de los lìmites
}

//Saber cuando borrar o no una fila
int piece_hits_rubble(int px,int py,int pr) {
  int x,y;
  const char *piece = pieces[piece_id] + (pr * PIECE_H * PIECE_W);
  
  for(y=0;y<PIECE_H;++y) {    
    int ny=py+y;
    if(ny<0) continue;
    for(x=0;x<PIECE_W;++x) {
      int nx=px+x;
      if(piece[y*PIECE_W+x]>0) {
        if(ny>=GRID_H ) return 1;  // Enviar un 1 si revasa los lìmites de la matriz    
        if(grid[ny*GRID_W+nx]!=0 ) return 1;  // Enviar un 0 si la red esta completa aún
      }
    }
  }
  
  return 0;   
}


//Reinicio
void draw_restart(){
  for(int i=0;i<STRAND_LENGTH;i++)   {
    leds[0]=CRGB::Black;
   }
   FastLED.show();
}


void all_white()
{
  for(int i=0;i<STRAND_LENGTH;i++){
    leds[i]=CRGB::Black;
    delay(3); // Delay for a period of time (in milliseconds).
  }
   FastLED.show();

   #ifdef DISPLAY_MENOR
     leds[15]=CRGB::Yellow;
     leds[14]=CRGB::Yellow;
     leds[13]=CRGB::Yellow;
     leds[17]=CRGB::Yellow;
     leds[46]=CRGB::Yellow;
     leds[49]=CRGB::Yellow;
     leds[78]=CRGB::Yellow;
     leds[81]=CRGB::Yellow;
     leds[110]=CRGB::Yellow;

     leds[11]=CRGB::Green;
     leds[10]=CRGB::Green;
     leds[20]=CRGB::Green;
     leds[43]=CRGB::Green;
     leds[52]=CRGB::Green;
     leds[53]=CRGB::Green;
     leds[75]=CRGB::Green;
     leds[84]=CRGB::Green;
     leds[107]=CRGB::Green;
     leds[106]=CRGB::Green;

     leds[144]=CRGB::Blue;
     leds[145]=CRGB::Blue;
     leds[146]=CRGB::Blue;
     leds[174]=CRGB::Blue;
     leds[177]=CRGB::Blue;
     leds[206]=CRGB::Blue;
     leds[209]=CRGB::Blue;
     leds[238]=CRGB::Blue;
     leds[241]=CRGB::Blue;
     
     leds[148]=CRGB::Red;
     leds[171]=CRGB::Red;
     leds[180]=CRGB::Red;
     leds[203]=CRGB::Red;
     leds[212]=CRGB::Red;
     leds[235]=CRGB::Red;
     leds[244]=CRGB::Red;
     leds[149]=CRGB::Red;
     leds[202]=CRGB::Red;
     leds[213]=CRGB::Red;
     leds[150]=CRGB::Red;
     leds[169]=CRGB::Red;
     leds[182]=CRGB::Red;
     leds[201]=CRGB::Red;
     leds[233]=CRGB::Red;
     leds[247]=CRGB::Red;

     leds[153]=CRGB::Orange;
     leds[166]=CRGB::Orange;
     leds[185]=CRGB::Orange;
     leds[198]=CRGB::Orange;
     leds[217]=CRGB::Orange;
     leds[230]=CRGB::Orange;
     leds[249]=CRGB::Orange;

     leds[155]=CRGB::Cyan;
     leds[164]=CRGB::Cyan;
     leds[187]=CRGB::Cyan;
     leds[196]=CRGB::Cyan;
     leds[251]=CRGB::Cyan;
     leds[156]=CRGB::Cyan;
     leds[195]=CRGB::Cyan;
     leds[252]=CRGB::Cyan;
     leds[157]=CRGB::Cyan;
     leds[194]=CRGB::Cyan;
     leds[221]=CRGB::Cyan;
     leds[226]=CRGB::Cyan;
     leds[253]=CRGB::Cyan;

     leds[8]=CRGB::Magenta;
     leds[23]=CRGB::Magenta;
     leds[40]=CRGB::Magenta;
     leds[55]=CRGB::Magenta;
     leds[72]=CRGB::Magenta;
     leds[39]=CRGB::Magenta;
     leds[71]=CRGB::Magenta;
     leds[38]=CRGB::Magenta;
     leds[57]=CRGB::Magenta;
     leds[70]=CRGB::Magenta;

     leds[4]=CRGB::Magenta;
     leds[27]=CRGB::Magenta;
     leds[36]=CRGB::Magenta;
     leds[59]=CRGB::Magenta;
     leds[68]=CRGB::Magenta;
     leds[3]=CRGB::Magenta;
     leds[67]=CRGB::Magenta;

     leds[1]=CRGB::Magenta;
     leds[30]=CRGB::Magenta;
     leds[33]=CRGB::Magenta;
     leds[62]=CRGB::Magenta;
     leds[65]=CRGB::Magenta;
     leds[0]=CRGB::Magenta;
     leds[64]=CRGB::Magenta;


  #endif
   
   FastLED.show();
   
   delay(4000);
}



void game_over() {
  if (g_ov == 0){
    EEPROM.write(0, piece_id);
    EEPROM.commit();
    //myDFPlayer.playFolder(2, 1);
    g_ov = 1;
    delay(7000);
  } 
  score = 0;
  game_over_loop_leds();
  delay(1000);
  int x,y;

  long over_time = millis();
  draw_restart();
  currentMillis = millis();
  previousMillis = currentMillis;
  int led_number = 1;
  while(millis() - over_time < 8000) {
    currentMillis = millis();
    if(currentMillis - previousMillis >= 1000){
      previousMillis += 1000;
      #ifdef DISPLAY_MENOR
        leds[42]=CRGB(0,0,255);
        leds[53]=CRGB::Blue;
        leds[74]=CRGB::Blue;
        leds[85]=CRGB::Blue;
        leds[106]=CRGB::Blue;
        leds[117]=CRGB::Blue;
        leds[138]=CRGB::Blue;
        leds[149]=CRGB::Blue;
        leds[170]=CRGB::Blue;
        leds[181]=CRGB::Blue;
        leds[202]=CRGB::Blue;
        leds[213]=CRGB::Blue;
        leds[214]=CRGB::Blue;
        leds[215]=CRGB::Blue;
        leds[216]=CRGB::Blue;
        leds[217]=CRGB::Blue;
        leds[218]=CRGB::Blue;
        leds[197]=CRGB::Blue;
        leds[186]=CRGB::Blue;
        leds[165]=CRGB::Blue;
        leds[154]=CRGB::Blue;
        leds[133]=CRGB::Blue;
        leds[122]=CRGB::Blue;
        leds[101]=CRGB::Blue;
        leds[90]=CRGB::Blue;
        leds[69]=CRGB::Blue;
        leds[58]=CRGB::Blue;
        leds[37]=CRGB::Blue;
        
        
        leds[41]=CRGB::Blue;
        leds[54]=CRGB::Blue;
        leds[73]=CRGB::Blue;
        leds[86]=CRGB::Blue;
        leds[105]=CRGB::Blue;
        leds[118]=CRGB::Blue;
        leds[137]=CRGB::Blue;
        leds[150]=CRGB::Blue;
        leds[169]=CRGB::Blue;
        leds[182]=CRGB::Blue;
        leds[201]=CRGB::Blue;
        leds[200]=CRGB::Blue;
        leds[199]=CRGB::Blue;
        leds[198]=CRGB::Blue;
        leds[185]=CRGB::Blue;
        leds[166]=CRGB::Blue;
        leds[153]=CRGB::Blue;
        leds[134]=CRGB::Blue;
        leds[121]=CRGB::Blue;
        leds[102]=CRGB::Blue;
        leds[89]=CRGB::Blue;
        leds[70]=CRGB::Blue;
        leds[57]=CRGB::Blue;
        leds[38]=CRGB::Blue;

        leds[32]=CRGB::White;
        leds[34]=CRGB::White;
        leds[36]=CRGB::White;
        leds[62]=CRGB::White;
        leds[60]=CRGB::White;
        leds[66]=CRGB::White;
        leds[68]=CRGB::White;
        //leds[70]=CRGB::White;
        leds[92]=CRGB::White;
        leds[88]=CRGB::White;
        leds[100]=CRGB::White;
        //leds[102]=CRGB::White;
        leds[104]=CRGB::White;
        leds[120]=CRGB::White;
        //leds[118]=CRGB::White;
        //leds[134]=CRGB::White;
        leds[136]=CRGB::White;
        leds[152]=CRGB::White;
        //leds[150]=CRGB::White;
        leds[148]=CRGB::White;
        leds[168]=CRGB::White;
        leds[172]=CRGB::White;
        //leds[182]=CRGB::White;
        leds[180]=CRGB::White;
        leds[178]=CRGB::White;
        leds[204]=CRGB::White;
        leds[206]=CRGB::White;
        leds[212]=CRGB::White;
        leds[210]=CRGB::White;
        leds[208]=CRGB::White;

     #endif   
        FastLED.show();
      //led_number += 1; 
    }    
    if (comemorou == 1) {
        
                    
                      delay(50);
                      for(int j=0;j<STRAND_LENGTH;j++){
                          leds[j]=CRGB::Black;
                          delay(1); // Delay for a period of time (in milliseconds).
                      }
                      FastLED.show();

                      desenha_emoji(0, 1);
                      FastLED.show();
                      delay(500); // Delay for a period of time (in milliseconds).

    }
    
    // click the button?
      if((digitalRead(button_start) == LOW) and (digitalRead(joystick_d) == HIGH) and (digitalRead(joystick_x) == HIGH) and (digitalRead(joystick_y) == HIGH) and (digitalRead(joystick_r) == HIGH) ){ 
                comemorou = 0;
                //fundo_branco = !fundo_branco;
                all_white();
                delay(500);
                setup();
                break;
    }
  }
  return;
}


void game_over_loop_leds()
{
  for(int i=0;i<STRAND_LENGTH;i++){
    leds[i]=CRGB::Black;
    delay(1); // Delay for a period of time (in milliseconds).
  } 
  FastLED.show();
}


//Girar una figura 
void try_to_drop_piece() {
  erase_piece_from_grid();  
  if(piece_can_fit(piece_x,piece_y+1,piece_rotation)) {
    piece_y++;  // move piece down
    add_piece_to_grid();
  } else {
    // hit something!
    // put it back
    add_piece_to_grid();
    remove_full_rows();
    if(game_is_over()==1) {
      game_over();
    }
    // game isn't over, choose a new piece
    choose_new_piece();
  }
}

// Cuando el joystick se encuentra hacia abajo, aumentar velocidad de caída
void try_to_drop_faster() {
  if((digitalRead(joystick_d) == LOW) and (digitalRead(button_start) == HIGH) and (digitalRead(joystick_x) == HIGH) and (digitalRead(joystick_y) == HIGH) and (digitalRead(joystick_r) == HIGH) ){ 
            // player is holding joystick down, drop a little faster.
            try_to_drop_piece();
  }
}

void react_to_player() {
  erase_piece_from_grid();

  if (piece_y >= 0) {
      try_to_move_piece_sideways();
  }

  
  
  
  try_to_rotate_piece();
  add_piece_to_grid();
  try_to_drop_faster();
}

// ¿Puede la pieza caber en esta nueva ubicación?
int game_is_over() {
  int x,y;
  const char *piece = pieces[piece_id] + (piece_rotation * PIECE_H * PIECE_W);
  
  for(y=0;y<PIECE_H;++y) {
    for(x=0;x<PIECE_W;++x) {      
      int ny=piece_y+y;
      int nx=piece_x+x;
      if(piece[y*PIECE_W+x]>0) {
        if(ny<0) return 1;  // yes: off the top!
      }
    }
  }
  
  return 0;  // not over yet...
}



uint8_t rotatedlinearToSnake(uint8_t index, uint8_t snake) {
    // Obtém as coordenadas originais
    uint8_t row = index / GRID_W;  // Linha: 0 a 15
    uint8_t col = index % GRID_W;  // Coluna: 0 a 15

    // Rotaciona 90° no sentido horário:
    // new_row = col, new_col = MATRIX_SIZE - 1 - row
    uint8_t new_row = col;
    uint8_t new_col = GRID_W - 1 - row;
    
    // Se solicitado, aplica o padrão snake
    if (snake == 1) {
        // Se a nova linha for ímpar, inverte a coluna
        if (new_row % 2 == 1) {
            new_col = (GRID_W - 1) - new_col;
        }
    }
    
    // Reconstrói o índice linear na matriz rotacionada (16x16)
    return new_row * GRID_W + new_col;
}


/*uint8_t linearToSnake(uint8_t index) {
    uint8_t row = index / 16;
    uint8_t col = index % 16;
    
    // Se a linha for ímpar, inverte a ordem da coluna.
    if (row % 2 == 1) {
        col = (16 - 1) - col;
    }
    
    return row * 16 + col;
}*/

// called once when arduino reboots
void setup() {
  display.clear();
  display.setBrightness(7); // set the brightness to 7 (0:dimmest, 7:brightest)
  display2.clear();
  display2.setBrightness(7); // set the brightness to 7 (0:dimmest, 7:brightest)
 if (b == 0) {
      b = 1;
      #ifdef ESP32
        FPSerial.begin(9600, SERIAL_8N1, 16, 17); // Start serial communication for ESP32 with 9600 baud rate, 8 data bits, no parity, and 1 stop bit
      #else
        FPSerial.begin(9600); // Start serial communication for other boards with 9600 baud rate
      #endif

      Serial.begin(115200); // Start the Serial monitor communication with 115200 baud rate

      //Serial.println(F("DFRobot DFPlayer Mini Demo")); // Print a demo start message
      //Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)")); // Print initialization message
      
      //if (!myDFPlayer.begin(FPSerial)) { // Initialize the DFPlayer Mini with the defined serial interface
      //  Serial.println(F("Unable to begin:")); // If initialization fails, print an error message
      //  Serial.println(F("1.Please recheck the connection!")); // Suggest rechecking the connection
      //  Serial.println(F("2.Please insert the SD card!")); // Suggest checking for an inserted SD card
      //  while(true); // Stay in an infinite loop if initialization fails
      //}
      //Serial.println(F("DFPlayer Mini online.")); // Print a success message if initialization succeeds
      
      //myDFPlayer.volume(6);  // Set the DFPlayer Mini volume to 30 (max is 30)
      // initialize EEPROM with predefined size
      EEPROM.begin(EEPROM_SIZE);
}

  //myDFPlayer.playFolder(1, 1);
  //myDFPlayer.loopFolder(1);
  g_ov = 0;
  FastLED.setBrightness(100);
  delay(1000);

  //pinMode(button_pause,INPUT_PULLUP);
  pinMode(button_start,INPUT);
  pinMode(button_start,INPUT_PULLUP);
  pinMode(joystick_x,INPUT);
  pinMode(joystick_x,INPUT_PULLUP);
  pinMode(joystick_y,INPUT);
  pinMode(joystick_y,INPUT_PULLUP);
  pinMode(joystick_r,INPUT);
  pinMode(joystick_r,INPUT_PULLUP);
  pinMode(joystick_d,INPUT);
  pinMode(joystick_d,INPUT_PULLUP);
  pinMode(buzzer,OUTPUT);
  delay(1);

  int i;
  // setup the LEDs
  FastLED.addLeds<WS2812,DATA_PIN,GRB>(leds,NUM_LEDS);
  FastLED.setBrightness(100);

   desenha_emoji(0, 1);
   FastLED.show();
   delay(1000);

   desenha_emoji(1, 1);
   FastLED.show();
   delay(1000);

   desenha_emoji(2, 1);
   FastLED.show();
   delay(1000);



  //for (unsigned int z=0; z<256; z++){
     //leds[i].setRGB( 50, 100, 150);
     //leds[rotatedlinearToSnake(z)] = CRGB(IMAGES[0][z]);
  //desenha_emoji(1);
  //}
  //FastLED.show();
  //delay(5000);

  
  // make sure arduino knows the grid is empty.
  for(i=0;i<GRID_W*GRID_H;++i) {
    grid[i]=0;
  }
  
  // make the game a bit more random - the last piece as seed
  randomSeed(EEPROM.read(0));
  
  // get ready to start the game.
  choose_new_piece();
  
  //move_delay=INITIAL_MOVE_DELAY;
  //drop_delay=INITIAL_DROP_DELAY;
  draw_delay=INITIAL_DRAW_DELAY;

  // start the game clock after everything else is ready.
  last_draw = last_drop = last_move = millis();
}



// called over and over after setup()
void loop() {
if (EEPROM.read(2) == 255){
    if (EEPROM.read(3) == 255) {
        if (EEPROM.read(4) == 255) {
           if (EEPROM.read(5) == 255){
             EEPROM.write(2, 0);
             //EEPROM.commit();
             EEPROM.write(3, 0);
             //EEPROM.commit();
             EEPROM.write(4, 0);
             //EEPROM.commit();
             EEPROM.write(5, 0);
             EEPROM.commit();
           }
        }
     }
  }

/*if (EEPROM.read(2) == 255){
   EEPROM.write(2, 0);
   EEPROM.commit();
   }
*/   
  top_score = lerFloat(2);
  display.showNumberDec((int)score, true); 
  display2.showNumberDec((int)top_score,true);


  long t = millis();

    
    // the game plays at one speed,
    if(t - last_move > move_delay ) {
      last_move = t;
      react_to_player();
    }
    
    // ...and drops the falling block at a different speed.
    if(t - last_drop > drop_delay ) {
      last_drop = t;
      try_to_drop_piece();
    }
    
    // when it isn't doing those two things, it's redrawing the grid.
    if(t - last_draw > draw_delay ) {
      last_draw = t;
      draw_grid();
    }
    delay(1);
}

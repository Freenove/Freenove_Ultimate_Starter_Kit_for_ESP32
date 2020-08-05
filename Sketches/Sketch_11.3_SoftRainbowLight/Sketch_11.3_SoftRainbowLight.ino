/**********************************************************************
  Filename    : SoftRainbowLight
  Description : Make the strip light up in rainbow colors.
  Auther      : www.freenove.com
  Modification: 2020/07/11
**********************************************************************/
#include "Freenove_WS2812_Lib_for_ESP32.h"

#define PIN_POT     13 // Define analog input pins
#define LEDS_COUNT  8  // The number of led
#define LEDS_PIN    2  // define the pin connected to the Freenove 8 led strip
#define CHANNEL     0  // RMT module channel
#define BRIGHTNESS  100   // breghtness, the value range is 0-255.
Freenove_ESP32_WS2812 strip = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN, CHANNEL, TYPE_GRB);

void setup() {
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
}

void loop() {
  int colorPos = map(analogRead(PIN_POT), 0, 4095, 0, 255);
  for (int i = 0; i < LEDS_COUNT; i++) {
    strip.setLedColorData(i,strip.Wheel(colorPos + i * 255 / 8)); // Set color data.
  }
  strip.show(); // Send color data to LED, and display.
  delay(10);
}

/**********************************************************************
  Filename    : RainbowLight
  Description : Make the strip light up in rainbow colors.
  Auther      : www.freenove.com
  Modification: 2020/07/11
**********************************************************************/
#include "Freenove_WS2812_Lib_for_ESP32.h"

#define LEDS_COUNT  8
#define LEDS_PIN	2
#define CHANNEL		0

Freenove_ESP32_WS2812 strip = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN, CHANNEL, TYPE_GRB);

void setup() {
  strip.begin();
}

void loop() {
  for (int j = 0; j < 255; j += 2) {
    for (int i = 0; i < LEDS_COUNT; i++) {
      strip.setLedColorData(i, strip.Wheel((i * 256 / LEDS_COUNT + j) & 255));
    }
    strip.show();
    delay(5);
  }  
}

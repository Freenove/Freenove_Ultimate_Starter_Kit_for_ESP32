/**********************************************************************
  Filename    : SoftRainbowLight
  Description : Make the strip light up in rainbow colors.
  Auther      : www.freenove.com
  Modification: 2020/07/11
**********************************************************************/
#include <Adafruit_NeoPixel.h>

#define PIN_POT   13
#define PIN_LED   2     // define the pin conenected to the Freenove 8 led strip
#define NUM_LEDS  8     // The number of led
#define BRIGHTNESS  100   // breghtness, the value range is 0-255.

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN_LED);

void setup() {
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
}

void loop() {
  int colorPos = map(analogRead(PIN_POT), 0, 4095, 0, 255);
  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, wheel(colorPos + i * 255 / 8)); // Set color data.
  }
  strip.show(); // Send color data to LED, and display.
  delay(10);
}

long wheel(int pos) {   //colorwheel
  long WheelPos = pos % 0xff;
  if (WheelPos < 85) {
    return ((255 - WheelPos * 3) << 16) | ((WheelPos * 3) << 8);
  } else if (WheelPos < 170) {
    WheelPos -= 85;
    return (((255 - WheelPos * 3) << 8) | (WheelPos * 3));
  } else {
    WheelPos -= 170;
    return ((WheelPos * 3) << 16 | (255 - WheelPos * 3));
  }
}

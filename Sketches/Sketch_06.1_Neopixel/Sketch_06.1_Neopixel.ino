/**********************************************************************
  Filename    : NeoPixel
  Description : Basic usage of neopixel, 
                Make the strip light up in different colors gradually.
  Auther      : www.freenove.com
  Modification: 2020/07/11
**********************************************************************/
#include <Adafruit_NeoPixel.h>

#define PIN_LED 2     // define the pin conenected to the Freenove 8 led strip
#define NUM_LEDS  8   // The number of led
#define BRIGHTNESS  100   // breghtness, the value range is 0-255.

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN_LED);
//Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN_LED, NEO_GRBW + NEO_KHZ800);

uint32_t colors[] = {0xFF0000, 0x00FF00, 0x0000FF, 0xFFFFFF, 0x000000};
int delayval = 50;

void setup() {
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
}

void loop() {
  for (int j = 0; j < sizeof(colors) / 4; j++) {
    for (int i = 0; i < NUM_LEDS; i++) {
      strip.setPixelColor(i, colors[j]); // Set color data.
      strip.show(); // Send color data to LED, and display.
      delay(delayval); // Interval time of each LED.
    }
    delay(500); // Interval time of each group of colors.
  }
  delay(500);   // Interval time of each loop.
}

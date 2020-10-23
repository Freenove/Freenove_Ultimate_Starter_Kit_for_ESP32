/**********************************************************************
  Filename    : SoftColorfulLight
  Description : Controlling the color of RGBLED by potentiometer.
  Auther      : www.freenove.com
  Modification: 2020/07/11
**********************************************************************/
const byte ledPins[] = {15, 2, 4};      //define led pins
const byte pwmChns[] = {0, 1, 2};       //define the pwm channels
const byte adcChns[] = {13, 12, 14};    // define the adc channels
int colors[] = {0, 0, 0};               // red, green ,blue values of color.
void setup() {
  for (int i = 0; i < 3; i++) {   //setup the pwm channels
    ledcSetup(pwmChns[i], 1000, 8);   //1KHz, 8bit(0-255).
    ledcAttachPin(ledPins[i], pwmChns[i]);
  }
}

void loop() {
  for (int i = 0; i < 3; i++) {
    colors[i] = map(analogRead(adcChns[i]), 0, 4096, 0, 255); //calculate color value.
    ledcWrite(pwmChns[i], 256 - colors[i]);   //set color
  }
  delay(10);
}

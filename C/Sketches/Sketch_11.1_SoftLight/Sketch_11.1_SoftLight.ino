/**********************************************************************
  Filename    : SoftLight
  Description : Controlling the brightness of LED by potentiometer.
  Auther      : www.freenove.com
  Modification: 2020/07/11
**********************************************************************/
#define PIN_ANALOG_IN   4
#define PIN_LED         25
#define CHAN            0
void setup() {
  ledcSetup(CHAN, 1000, 12);
  ledcAttachPin(PIN_LED, CHAN);
}

void loop() {
  int adcVal = analogRead(PIN_ANALOG_IN); //read adc
  int pwmVal = adcVal;        // adcVal re-map to pwmVal
  ledcWrite(CHAN, pwmVal);    // set the pulse width.
  delay(10);
}

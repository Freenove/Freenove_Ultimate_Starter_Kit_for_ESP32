/**********************************************************************
  Filename    : BreathingLight
  Description : Make led light fade in and out, just like breathing.
  Auther      : www.freenove.com
  Modification: 2024/06/18
**********************************************************************/
#define PIN_LED   2     //define the led pin
#define CHN       0     //define the pwm channel
#define FRQ       1000  //define the pwm frequency
#define PWM_BIT   8     //define the pwm precision
void setup() {
  ledcAttachChannel(PIN_LED, FRQ, PWM_BIT, CHN);  //attach the led pin to pwm channel
}

void loop() {
  for (int i = 0; i < 255; i++) { //make light fade in
    ledcWrite(PIN_LED, i);
    delay(10);
  }
  for (int i = 255; i > -1; i--) {  //make light fade out
    ledcWrite(PIN_LED, i);
    delay(10);
  }
}

/**********************************************************************
  Filename    : Alertor
  Description : Control passive buzzer by button.
  Auther      : www.freenove.com
  Modification: 2020/07/11
**********************************************************************/
#define PIN_BUZZER 13
#define PIN_BUTTON 4
#define CHN        0   //define the pwm channel

void setup() {
  Serial.begin(115200);
  pinMode(PIN_BUTTON, INPUT);
  pinMode(PIN_BUZZER, OUTPUT);
  Serial.printf("setup: %f \n", ledcSetup(CHN, 1, 10));          //setup pwm channel
  Serial.printf("write: %f \n", ledcWriteTone(CHN, 0));
  ledcAttachPin(PIN_BUZZER, CHN);  //attach the led pin to pwm channel
  ledcWriteTone(CHN, 2000);        //Sound at 2KHz for 0.3 seconds
  delay(300);
}

void loop() {
  if (digitalRead(PIN_BUTTON) == LOW) {
    alert();
  } else {
    ledcWriteTone(CHN, 0);
  }
}

void alert() {
  float sinVal;         // Define a variable to save sine value
  int toneVal;          // Define a variable to save sound frequency
  for (int x = 0; x < 360; x += 10) {     // X from 0 degree->360 degree
    sinVal = sin(x * (PI / 180));       // Calculate the sine of x
    toneVal = 2000 + sinVal * 500;      // Calculate sound frequency according to the sine of x
    ledcWriteTone(CHN, toneVal);
    delay(10);
  }
}

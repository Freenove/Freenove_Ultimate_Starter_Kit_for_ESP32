/**********************************************************************
  Filename    : TouchLamp
  Description : Control led by touch button.
  Auther      : www.freenove.com
  Modification: 2024/06/18
**********************************************************************/
#define PIN_LED   2
#define PRESS_VAL 14	  //Set a threshold to judge touch
#define RELEASE_VAL 25	//Set a threshold to judge release

bool isProcessed = false;
void setup() {
  Serial.begin(115200);
  pinMode(PIN_LED, OUTPUT);
}
void loop() {
  if (touchRead(T0) < PRESS_VAL) {
    if (!isProcessed) {
      isProcessed = true;
      Serial.println("Touch detected! ");
      reverseGPIO(PIN_LED);
    }
  }

  if (touchRead(T0) > RELEASE_VAL) {
    if (isProcessed) {
      isProcessed = false;
      Serial.println("Released! ");
    }
  }
}

void reverseGPIO(int pin) {
  digitalWrite(pin, !digitalRead(pin));
}

/**********************************************************************
  Filename    : Alertor
  Description : Using software pwm to control passive buzzer by button.
  Auther      : www.freenove.com
  Modification: 2020/07/11
**********************************************************************/
#define BUZZER_PIN     13
#define PIN_BUTTON     4
hw_timer_t * timer = NULL;

bool isAlerting = false;

void IRAM_ATTR onTimer() {
  digitalWrite(BUZZER_PIN, !digitalRead(BUZZER_PIN));
}

void setup() {
  pinMode(PIN_BUTTON, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  // Use 1st timer of 4 (counted from zero).
  // Set 80 divider for prescaler (see ESP32 Technical Reference Manual for more info).
  timer = timerBegin(0, 80, true);
  // Attach onTimer function to our timer.
  timerAttachInterrupt(timer, &onTimer, true);
}
void loop() {
  if (digitalRead(PIN_BUTTON) == LOW) {
    if (!isAlerting) {
      isAlerting = true;
      // Set alarm, 1ms, repeat
      timerAlarmWrite(timer, 1000, true);
      // Start an alarm
      timerAlarmEnable(timer);
    }
    alert();
  } else {
    if (isAlerting) {
      isAlerting = false;
      timerAlarmDisable(timer);
      digitalWrite(BUZZER_PIN, LOW);
    }
  }
}

void alert() {
  float sinVal;
  int toneVal;
  for (int x = 0; x < 360; x += 1) {
    sinVal = sin(x * (PI / 180));
    toneVal = 2000 + sinVal * 500;
    timerAlarmWrite(timer, 500000 / toneVal, true);
    delay(1);
  }
}

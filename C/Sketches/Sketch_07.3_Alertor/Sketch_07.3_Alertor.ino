/**********************************************************************
  Filename    : Alertor
  Description : Using software pwm to control passive buzzer by button.
  Auther      : www.freenove.com
  Modification: 2024/06/18
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
  // Set the timer frequency to 1MHz.(see ESP32 Technical Reference Manual for more info).
  timer = timerBegin(1000000);
  // Attach onTimer function to our timer.
  timerAttachInterrupt(timer, &onTimer);
}
void loop() {
  if (digitalRead(PIN_BUTTON) == LOW) {
    if (!isAlerting) {
      isAlerting = true;
      // Set alarm, 1ms, repeat, auto-reload value.
      timerAlarm(timer, 1000, true, 0);
      // Start an alarm
      timerStart(timer);
    }
    alert();
  } else {
    if (isAlerting) {
      isAlerting = false;
      timerStop(timer);
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
    timerAlarm(timer, 500000 / toneVal, true, 0);
    delay(1);
  }
}

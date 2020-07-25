/**********************************************************************
  Filename    : Alertor
  Description : Using IDF-SDK function to generate PWM control buzzer.
  Auther      : www.freenove.com
  Modification: 2020/07/11
**********************************************************************/

#include "driver/ledc.h"

#define BUZZER_PIN     13
#define PIN_BUTTON     4

#define LEDC_HS_TIMER          LEDC_TIMER_0
#define LEDC_LS_TIMER          LEDC_TIMER_1

#define LEDC_HS_MODE           LEDC_HIGH_SPEED_MODE
#define LEDC_LS_MODE           LEDC_LOW_SPEED_MODE

#define LEDC_HS_CH0_GPIO       (BUZZER_PIN)
#define LEDC_HS_CH0_CHANNEL    LEDC_CHANNEL_0

bool isAlerting = false;

void setup() {
    pinMode(PIN_BUTTON, INPUT);
    ledc_channel_config_t ledc_channel = {
        LEDC_HS_CH0_GPIO,
        LEDC_HIGH_SPEED_MODE,
        LEDC_CHANNEL_0,
        LEDC_INTR_DISABLE,
        LEDC_HS_TIMER,
        0,
        0
    };
    ledc_timer_config_t ledc_timer = {
        LEDC_HIGH_SPEED_MODE,
        LEDC_TIMER_10_BIT,
        LEDC_HS_TIMER,
        5000
    };
    // Set configuration of timer0 for high speed channels
    ledc_timer_config(&ledc_timer);
    // Set LED Controller with previously prepared configuration
    ledc_channel_config(&ledc_channel);	
    ledc_fade_func_install(0);
}
void loop() {
    if (digitalRead(PIN_BUTTON) == LOW) {
        if (!isAlerting) {
            isAlerting = true;			
            ledc_set_duty_and_update(LEDC_HS_MODE, LEDC_CHANNEL_0, 0, 0);
        }
        alert();
    }
    else {
        if (isAlerting) {
            isAlerting = false;
            ledc_set_duty_and_update(LEDC_HS_MODE, LEDC_CHANNEL_0, 0, 0);
        }
    }
}

void alert() {
    float sinVal;
    int toneVal;
    for (int x = 0; x < 360; x += 1) {
        sinVal = sin(x * (PI / 180));
        toneVal = 2000 + sinVal * 500;
        ledc_set_freq(LEDC_HS_MODE, LEDC_TIMER_0, toneVal);
        ledc_set_duty_and_update(LEDC_HS_MODE, LEDC_CHANNEL_0, 512, 0);
        delay(1);
    }
}

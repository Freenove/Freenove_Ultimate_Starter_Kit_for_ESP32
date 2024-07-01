/**********************************************************************
  Filename    : Control LED through Infrared Remote
  Description : Remote control the LED with the infrared remote control.
  Auther      : www.freenove.com
  Modification: 2024/06/28
**********************************************************************/
#include "Freenove_IR_Lib_for_ESP32.h"

const uint16_t recvPin = 15;              // Infrared receiving pin
Freenove_ESP32_IR_Recv ir_recv(recvPin);  // Create a class object used to receive class

int ledPin = 14;              // the number of the LED pin
int buzzerPin = 13;           // the number of the buzzer pin

void setup(){
  ledcAttachChannel(ledPin, 1000, 8, 0);// set the frequency,solution_bits,channel to GPIO pin
  pinMode(buzzerPin, OUTPUT);           // set buzzer pin into output mode
}

void loop() {
  ir_recv.task();                   // Get IR receice data.
  if(ir_recv.nec_available()){      // The data of the NEC protocol is checked
    handleControl(ir_recv.data());  // Handle the commands from remote control
  }
}

void handleControl(unsigned long value) {
  // Make a sound when it rereives commands
  digitalWrite(buzzerPin, HIGH);
  delay(100);
  digitalWrite(buzzerPin, LOW);
  switch (value) {
    case 0xff6897:              // Receive the number '0'
      ledcWrite(ledPin, 0);     // Turn off LED
      break;
    case 0xff30cf:              // Receive the number '1'
      ledcWrite(ledPin, 7);     // Dimmest brightness
      break;
    case 0xff18e7:              // Receive the number '2'
      ledcWrite(ledPin, 63);    // Medium brightness
      break;
    case 0xff7a85:              // Receive the number '3'
      ledcWrite(ledPin, 255);   // Strongest brightnss
      break;
  }
}

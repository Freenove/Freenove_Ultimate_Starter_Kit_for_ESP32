/**********************************************************************
  Filename    : Infrared Remote Control
  Description : Decode the infrared remote control and print it out through the serial port.
  Auther      : www.freenove.com
  Modification: 2024/06/28
**********************************************************************/
#include "Freenove_IR_Lib_for_ESP32.h"

const uint16_t recvPin = 15;              // Infrared receiving pin
Freenove_ESP32_IR_Recv ir_recv(recvPin);  // Create a class object used to receive class

void setup() {
  Serial.begin(115200);       // Initialize the serial port and set the baud rate to 115200
  Serial.print("IRrecvDemo is now running and waiting for IR message on Pin ");
  Serial.println(recvPin);   //print the infrared receiving pin
}

void loop() {
  ir_recv.task();                  //Get IR receice data.
  if(ir_recv.nec_available()){     //The data of the NEC protocol is checked
    //Print IR data.
    Serial.printf("IR Code:  %#x\r\n", ir_recv.data());
  }
}

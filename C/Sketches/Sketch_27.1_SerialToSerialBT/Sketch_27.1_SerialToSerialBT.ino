/**********************************************************************
  Filename    : SerialToSerialBT
  Description : ESP32 communicates with the phone by bluetooth and print phone's data via a serial port
  Auther      : www.freenove.com
  Modification: 2024/06/19
**********************************************************************/
#include "BluetoothSerial.h"

BluetoothSerial SerialBT;
String buffer;
void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("\nThe device started, now you can pair it with bluetooth!");
}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  delay(20);
}

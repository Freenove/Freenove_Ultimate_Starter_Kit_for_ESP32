/**********************************************************************
  Filename    : SerialPrinter
  Description : Use UART send some data to PC, and show them on serial monitor.
  Auther      : www.freenove.com
  Modification: 2020/07/11
**********************************************************************/

void setup() {
  Serial.begin(115200);
  Serial.println("ESP32 initialization completed!");
}

void loop() {
  Serial.printf("Running time : %.1f s\n", millis() / 1000.0f);
  delay(1000);
}

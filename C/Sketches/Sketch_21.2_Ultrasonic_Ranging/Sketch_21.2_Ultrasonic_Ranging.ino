/**********************************************************************
  Filename    : Ultrasonic Ranging
  Description : Use the ultrasonic module to measure the distance.
  Auther      : www.freenove.com
  Modification: 2020/07/11
**********************************************************************/
#include <UltrasonicSensor.h>

UltrasonicSensor ultrasonic(13, 14);

void setup() {
  Serial.begin(115200);
  
  int temperature = 22;
  ultrasonic.setTemperature(temperature);
}

void loop() {
  int distance = ultrasonic.distanceInCentimeters();
  Serial.printf("Distance: %dcm\n",distance);
  delay(300);
}

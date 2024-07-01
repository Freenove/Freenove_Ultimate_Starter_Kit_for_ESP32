/**********************************************************************
  Filename    : TouchRead
  Description : Read touch sensor value.
  Auther      : www.freenove.com
  Modification: 2024/06/18
**********************************************************************/

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  Serial.printf("Touch value: %d \n",touchRead(T0));  // get value using T0（GPIO4）
  delay(1000);
}

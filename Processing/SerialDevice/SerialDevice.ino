/*
  Sketch    SerialDevice
  Author    Zhentao Lin @ Freenove (http://www.freenove.com)
  Date      2020/07/11
  Brief     This sketch is used to communicate to Processing sketch running
            on PC. The Processing sketch will automatically detect and
            connect to this board which use the same trans format.
  Copyright Copyright © Freenove (http://www.freenove.com)
  License   Creative Commons Attribution ShareAlike 3.0
            (http://creativecommons.org/licenses/by-sa/3.0/legalcode)
*/
#include "SerialCommand.h"

int analogPins[] = {A0, A3, A6, A7, A4, A5};
int keys[] = {4, 5, 18, 19};
int ledPin = 2;
int keyValue = 0;
int keyValueBuffer=0;

void keyscan() {
  if (digitalRead(keys[0]) == 0) {
    keyValue = 1;
  }
  else if (digitalRead(keys[1]) == 0) {
    keyValue = 2;
  }
  else if (digitalRead(keys[2]) == 0) {
    keyValue = 3;
  }
  else if (digitalRead(keys[3]) == 0) {
    keyValue = 4;
  }
  else keyValue = 0;
}

void setup() {
  int i = 0;
  for (i = 0; i < 4; i++)
    pinMode(keys[i], INPUT_PULLUP);
    
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  analogSetWidth(10);
  analogReadResolution(10);
}

void loop() {
  static byte inData[64];
  static byte inDataNum = 0;
  while (Serial.available() > 0)
  {
    byte inByte = Serial.read();//读取串口数据
    if (inByte == SerialCommand.transStart)//接收开始标志
      inDataNum = 0;
    inData[inDataNum++] = inByte;//接收数据
    if (inByte == SerialCommand.transEnd)//接收结束标志
      if (inData[0] == SerialCommand.transStart)
        break;
  }
  unsigned long msNow = millis();
  if (msNow % 2000 < 1000)
    digitalWrite(ledPin, HIGH);
  else
    digitalWrite(ledPin, LOW);
  keyscan();
  if (inData[0] == SerialCommand.transStart && inData[inDataNum - 1] == SerialCommand.transEnd)//校验开始和结束标志
  {
    Serial.write(SerialCommand.transStart);
    if (inData[1] == SerialCommand.requestEcho)
    {
      Serial.write(SerialCommand.echo);
    }
    else if (inData[1] == SerialCommand.requestAnalog)//请求一个模拟值
    {
      int analog = analogRead(keys[0]);
      Serial.write(SerialCommand.Analog);
      Serial.write(analog / 128);
      Serial.write(analog % 128);
    }
    else if (inData[1] == SerialCommand.requestDigital)//请求一个数字值
    {
      Serial.write(SerialCommand.Digital);
      Serial.write(keyValue);
    }
    else if (inData[1] == SerialCommand.requestAnalogs)//请求多个模拟值
    {
      int analogs[inData[2]];
      for (int i = 0; i < inData[2]; i++)
        analogs[i] = analogRead(analogPins[i]);
      Serial.write(SerialCommand.Analogs);
      for (int i = 0; i < inData[2]; i++)
      {
        Serial.write(analogs[i] / 128);
        Serial.write(analogs[i] % 128);
      }
    }
    Serial.write(SerialCommand.transEnd);
    for (int i = 0; i < inDataNum; i++)
      inData[i] = 0;
  }
}

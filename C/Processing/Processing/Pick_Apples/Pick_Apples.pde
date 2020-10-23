/*
 ******************************************************************************
 * Sketch  Pick Apples
 * Author  Zhentao Lin @ Freenove (http://www.freenove.com)
 * Date    2020/7/11
 ******************************************************************************
 * Brief
 *   This sketch is used to control a 2D ellipse through communicate to an 
 *   ESP32 board or other micro controller.
 *   It will automatically detect and connect to a device (serial port) which 
 *   use the same trans format.
 ******************************************************************************
 * Copyright
 *   Copyright © Freenove (http://www.freenove.com)
 * License
 *   Creative Commons Attribution ShareAlike 3.0 
 *   (http://creativecommons.org/licenses/by-sa/3.0/legalcode)
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

SerialDevice serialDevice = new SerialDevice(this);
int serial_flag=0;

void setup() {
  size(650,650);
  background(102);
  textAlign(CENTER, CENTER);
  textSize(64);
  text("Starting...", width / 2, (height - 40) / 2);
  textSize(16);
  text("www.freenove.com", width / 2, height - 20);
  
  gameUiInit();
}

void draw() {
  if(serial_flag<1){
    if (!serialDevice.active())
    {
      if (!serialDevice.start())
      {
        delay(50);
        serial_flag++;
      }
      if(serialDevice.start())serial_flag=0;
    }
  }
  int[] analogs = new int[2];
  analogs = serialDevice.requestAnalogs(2);
  if (analogs != null)
  {
    dealData(analogs[0], analogs[1]);
  }
  RunGame();
}
void dealData(int analogs1,int analogs2){
    if(analogs1 < 300 && x != 0) {
      x -= 10;
    }
    if(analogs1 >= 700 && x != 600) {
      x += 10;
    }
    if(analogs2 < 300 && y != 0) {
      y -= 10;
    }
    if(analogs2 >= 700 && y != 600) {
      y += 10;
    }
}
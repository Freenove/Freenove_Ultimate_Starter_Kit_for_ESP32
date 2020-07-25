/* //<>//
 ******************************************************************************
 * Sketch  Two Dimensional Ellipse
 * Author  Zhentao Lin @ Freenove (http://www.freenove.com)
 * Date    2020/7/11
 ******************************************************************************
 * Brief
 *   This sketch is used to control a 2D ellipse through communicate to an 
 *   Arduino board or other micro controller.
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

void setup()
{
  size(360, 360);
  background(102);
  textAlign(CENTER, CENTER);
  textSize(64);
  text("Starting...", width / 2, (height - 40) / 2);
  textSize(16);
  text("www.freenove.com", width / 2, height - 20);
  frameRate(1000 / 40);
}

void draw()
{
  if (!serialDevice.active())
  {
    if (!serialDevice.start())
    {
      delay(1000);
      return;
    }
  }

  int[] analogs = new int[2];
  analogs = serialDevice.requestAnalogs(2);
  if (analogs != null)
  {
    background(102);
    drawEllipse(analogs[0], analogs[1]);
  }
}

void drawEllipse(int x, int y)
{
  int maxDiameter = 280;

  fill(255, 255, 255);
  textAlign(CENTER, CENTER);
  textSize(16);
  text("Press Enter to visit www.freenove.com", width / 2, height - 20);
  text("X: " + x, width / 2 - 30, 20);
  text("Y: " + y, width / 2 + 30, 20);
  x = x * maxDiameter / 1023;
  y = y * maxDiameter / 1023;
  fill(227, 118, 12);
  ellipse(width / 2, height / 2, x, y);
}

void keyPressed() 
{
  if (key == '\n' || key == '\r')
  {
    link("http://www.freenove.com");
  }
}
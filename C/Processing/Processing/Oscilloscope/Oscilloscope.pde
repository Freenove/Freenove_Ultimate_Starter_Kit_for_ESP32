/* //<>//
 ******************************************************************************
 * Sketch  Oscilloscope
 * Author  Zhentao Lin @ Freenove (http://www.freenove.com)
 * Date    2020/7/11
 ******************************************************************************
 * Brief
 *   This sketch is used to make an oscilloscope through communicate to an 
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
int[] analogs;          // Analog data send from serial device
int analogsCount;       // Length of analogs[] array
int voltage = 0;        // Voltage 
int hMult = 1;          // Horizontal zoom ratio, relative to 1 second
boolean pause = false;  // Storage is suspended display

void setup()
{
  size(530, 290);
  background(102);
  textAlign(CENTER, CENTER);
  textSize(64);
  text("Starting...", width / 2, (height - 40) / 2);
  textSize(16);
  text("www.freenove.com", width / 2, height - 20);
  textAlign(LEFT, CENTER);

  analogsCount = width / 2;
  analogs = new int[analogsCount];
  for (int i = 0; i < analogsCount; i++)
    analogs[i] = -1;

  int drawCycle = 20 * width / analogsCount;
  frameRate(1000 / drawCycle);
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

  int analog = serialDevice.requestAnalog();
  if (analog != -1)
  {
    // GUI
    background(102);
    textSize(12);
    text("↑: Zoom up", 120, 6);
    text("↓: Zoom down", 120, 20);
    text("Enter: Visit Freenove website", 220, 6);
    text("Space: Pause", 220, 20);
    textSize(16);
    // Voltage scale text
    for (int i = 5; i >= 0; i--)
    {
      text(i, 5, 280 - i * 50 - 2);
      if (i == 5)
        text("V", 15, 280 - i * 50 - 2);
    }
    // Horizontal line
    stroke(64, 64, 64);
    for (int i = 0; i < 6; i++)
      line(30, 30 + i * 50, width, 30 + i * 50);
    // Vertical line time text
    text(1000 / hMult + "ms", 40, 15 - 2);
    // Vertical line
    for (int i = 0; i < (width - 30) / 50 + 1; i++)
      line(30 + i * 50, 30, 30 + i * 50, height - 10);

    if (!pause)
    {
      // Prepare wave data
      for (int i = 0; i < analogsCount - 1; i++)
        analogs[i] = analogs[i + 1];
      analogs[analogsCount - 1] = height - 10 - analog * (height - 10 - 30) / 1023;
      // Voltage text
      voltage = analog * 500 / 1023;
    }
    String sVoltage = voltage / 100 + "." + voltage / 10 % 10 + voltage % 10;
    text(sVoltage + "V", width - 48, 15 - 2);
    // Wave line
    stroke(0, 255, 0);
    for (int i = width; i > 30; i -= hMult * width / analogsCount)
    {
      int a = i / hMult + width * (hMult - 1) / hMult;
      a = a * analogsCount / width - 1;
      if (analogs[a] >= 0 && analogs[a - 1] >= 0)
        line(i, analogs[a], i - hMult * width / analogsCount, analogs[a - 1]);
    }
  }
}

void keyPressed() 
{
  if (key == CODED) 
  {
    if (keyCode == UP) 
    {
      if (hMult == 1)
        hMult = 2;
      else if (hMult == 2)
        hMult = 5;
      else if (hMult == 5)
        hMult = 10;
    } 
    else if (keyCode == DOWN) 
    {
      if (hMult == 10)
        hMult = 5;
      else if (hMult == 5)
        hMult = 2;
      else if (hMult == 2)
        hMult = 1;
    }
  } 
  else 
  {
    if (key == ' ') 
    {
      pause = !pause;
      if (!pause)
      {
        for (int i = 0; i < analogsCount; i++)
          analogs[i] = -1;
      }
    } 
    else if (key == '\n' || key == '\r')
    {
      link("http://www.freenove.com");
    }
  }
}
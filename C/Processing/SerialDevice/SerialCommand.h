/*
  Class     SerialCommand
  Author    Ethan Pan @ Freenove (http://www.freenove.com)
  Date      2016/8/8
  Brief     This class is used to save serial command.
  Copyright Copyright © Freenove (http://www.freenove.com)
  License   Creative Commons Attribution ShareAlike 3.0
            (http://creativecommons.org/licenses/by-sa/3.0/legalcode)
*/

class serialCommand
{
  public:
    // Trans control command, range 128 ~ 255
    const byte transStart = 128;
    const byte transEnd = 129;

    // General command , range 0 ~ 127
    // The odd command is sent by the requesting party
    // The even command is sent by the responding party
    // Request echo, to confirm the device
    const byte requestEcho = 0;      // Comm
    // Respond echo, to tell this is the device
    const byte echo = 1;             // Comm
    // Request 1 analog value
    const byte requestAnalog = 10;   // Comm
    // Respond 1 analog value
    const byte Analog = 11;          // Comm A/100 A%100
    // Request n analog values
    const byte requestAnalogs = 12;  // Comm n
    // Respond n analog values
    const byte Analogs = 13;         // Comm A1/100 A1%100 ... An/100 An%100
    // Request 1 digital value
    const byte requestDigital = 14;  // Comm 
    // Respond n digital values
    const byte Digital = 15;         // Comm 
    
} SerialCommand;

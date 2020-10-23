/**********************************************************************
  Filename    : 4 Digital 7 Segment Display
  Description : Use 74HC595 to drive the digital display
  Auther      : www.freenove.com
  Modification: 2020/07/11
**********************************************************************/
int latchPin = 2;          // Pin connected to ST_CP of 74HC595（Pin12）
int clockPin = 4;          // Pin connected to SH_CP of 74HC595（Pin11）
int dataPin = 15;          // Pin connected to DS of 74HC595（Pin14）
int comPin[] = {25,26,27,14};// Common pin (anode) of 4 digit 7-segment display

// Define the encoding of characters 0-F of the common-anode 7-Segment Display
byte num[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8,
              0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e};
              
void setup() {
  // set pins to output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  for (int i = 0; i < 4; i++) {
    pinMode(comPin[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 4; i++) {
    // Select a single 7-segment display
    electDigitalDisplay (i);
    // Send data to 74HC595
    writeData(num[i]);
    delay(5);
    // Clear the display content
    writeData(0xff);
  }
}

void electDigitalDisplay(byte com) {
  // Close all single 7-segment display
  for (int i = 0; i < 4; i++) {
    digitalWrite(comPin[i], LOW);
  }
  // Open the selected single 7-segment display
  digitalWrite(comPin[com], HIGH);
}

void writeData(int value) {
  // Make latchPin output low level
  digitalWrite(latchPin, LOW);
  // Send serial data to 74HC595
  shiftOut(dataPin, clockPin, LSBFIRST, value);  // Make latchPin output high level
// Make latchPin output high level, then 74HC595 will update data to parallel output
  digitalWrite(latchPin, HIGH);
}

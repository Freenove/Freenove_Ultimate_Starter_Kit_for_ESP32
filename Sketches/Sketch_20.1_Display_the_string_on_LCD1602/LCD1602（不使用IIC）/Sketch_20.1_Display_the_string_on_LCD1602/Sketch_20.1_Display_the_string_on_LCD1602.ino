/**********************************************************************
  Filename    : Display the string on LCD1602
  Description : Use LiquidCrystal to drive lcd1602 to print strings and stopwatch
  Auther      : www.freenove.com
  Modification: 2020/07/11
**********************************************************************/
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(14,27,26,25,18,19);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD
  lcd.print("hello, world!");
}

void loop() {
   //set the cursor to column 0, line 1
   //(note:parameter "0" is the first columns, parameter "1" is the second row, since counting begins with 0)
  lcd.setCursor(0, 1);//0 stand for column, 1 stand for row
  // print the number of seconds since reset:
  lcd.print("Counter:");
  lcd.print(millis() / 1000);
}

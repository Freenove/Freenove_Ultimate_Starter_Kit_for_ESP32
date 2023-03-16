/**********************************************************************
  Filename    : Temperature_and_Humidity_Sensor
  Description : Get the temperature value and humidity value of DHT11, which are displayed in LCD1602
  Auther      : www.freenove.com
  Modification: 2020/07/11
**********************************************************************/
#include <LiquidCrystal.h>
#include "DHTesp.h"

DHTesp dht;          // create dht object
int dhtPin = 13;     // the number of the DHT11 sensor pin

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(25,26,27,14,18,19);

void setup() {
  lcd.begin(16, 2);                 // set up the LCD's number of columns and rows
  dht.setup(dhtPin, DHTesp::DHT11); //attach the dht pin and initialize it
}

void loop() {
  // read DHT11 data and save it 
  flag:TempAndHumidity DHT = dht.getTempAndHumidity();
  if (dht.getStatus() != 0) {       
    goto flag;
  }  
  lcd.setCursor(0, 0);              //set the cursor to column 0, line 1
  lcd.print("Temperature:");        //display the Humidity on the LCD1602
  lcd.print(DHT.temperature);   
  lcd.setCursor(0, 1);              //set the cursor to column 0, line 0 
  lcd.print("Humidity   :");        //display the Humidity on the LCD1602
  lcd.print(DHT.humidity);  
  delay(2000);
}

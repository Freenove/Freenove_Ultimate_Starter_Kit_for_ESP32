/**********************************************************************
  Filename    : Temperature and Humidity Sensor
  Description : Use DHT11 to measure temperature and humidity.Print the result to the LCD1602.
  Auther      : www.freenove.com
  Modification: 2020/07/11
**********************************************************************/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHTesp.h"

#define SDA 13                    //Define SDA pins
#define SCL 14                    //Define SCL pins

DHTesp dht;                       // create dht object
LiquidCrystal_I2C lcd(0x27,16,2); //initialize the LCD
int dhtPin = 18;                  // the number of the DHT11 sensor pin

void setup() {
  Wire.begin(SDA, SCL);           // attach the IIC pin
  lcd.init();                     // LCD driver initialization
  lcd.backlight();                // Open the backlight
  dht.setup(dhtPin, DHTesp::DHT11); //attach the dht pin and initialize it
}

void loop() {
  // read DHT11 data and save it 
  flag:TempAndHumidity DHT = dht.getTempAndHumidity();
  if (dht.getStatus() != 0) {       //Determine if the read is successful, and if it fails, go back to flag and re-read the data
    goto flag;
  }  
  lcd.setCursor(0, 0);              //set the cursor to column 0, line 1
  lcd.print("Temperature:");        //display the Humidity on the LCD1602
  lcd.print(DHT.temperature);   
  lcd.setCursor(0, 1);              //set the cursor to column 0, line 0 
  lcd.print("Humidity   :");        //display the Humidity on the LCD1602
  lcd.print(DHT.humidity);  
}

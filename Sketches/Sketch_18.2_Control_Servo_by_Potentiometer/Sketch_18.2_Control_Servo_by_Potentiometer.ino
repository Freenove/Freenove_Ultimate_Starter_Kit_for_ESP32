/**********************************************************************
  Filename    : Control Servo by Potentiometer
  Description : Use potentiometer to control the rotation of servo motor.
  Auther      : www.freenove.com
  Modification: 2020/07/11
**********************************************************************/
#include <ESP32Servo.h> 
#define ADC_Max 4095    // This is the default ADC max value on the ESP32 (12 bit ADC width); 

Servo myservo;  // create servo object to control a servo

int servoPin = 15;      // GPIO pin used to connect the servo control (digital out)
int potPin = 34;        // GPIO pin used to connect the potentiometer (analog in)
int potVal;             //variable to read the value from the analog pin

void setup()
{
  myservo.setPeriodHertz(50);// Standard 50hz servo   
  // attaches the servo on servoPin to the servo object
  myservo.attach(servoPin, 500, 2500);   
  Serial.begin(115200);
}

void loop() {
  // read the value of the potentiometer (value between 0 and 4095)
  potVal = analogRead(potPin);             
  Serial.printf("potVal_1: %d\t",potVal);
  // scale it to use it with the servo (value between 0 and 180)
  potVal = map(potVal, 0, ADC_Max, 0, 180); 
  // set the servo position according to the scaled value
  myservo.write(potVal);                  
  Serial.printf("potVal_2: %d\n",potVal);
  delay(15);// wait for the servo to get there
}

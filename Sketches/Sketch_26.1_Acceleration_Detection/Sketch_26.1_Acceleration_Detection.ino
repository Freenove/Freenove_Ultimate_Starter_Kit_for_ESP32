/**********************************************************************
  Filename    : Acceleration detection
  Description : Read the MPU6050 data and print it out through the serial port
  Auther      : www.freenove.com
  Modification: 2020/07/11
**********************************************************************/
#include <MPU6050_tockn.h>
#include <Wire.h>

#define SDA 13
#define SCL 14

MPU6050 mpu6050(Wire);//Attach the IIC
int16_t ax,ay,az;//define acceleration values of 3 axes
int16_t gx,gy,gz;//define variables to save the values in 3 axes of gyroscope

long timer = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA, SCL);          //attach the IIC pin
  mpu6050.begin();               //initialize the MPU6050
  mpu6050.calcGyroOffsets(true); //get the offsets value
}

void loop() {
  if(millis() - timer > 1000){   //each second printf the data
    mpu6050.update();            //update the MPU6050
    getMotion6();                //gain the values of Acceleration and Gyroscope value
    Serial.print("\na/g:\t");
    Serial.print(ax); Serial.print("\t");
    Serial.print(ay); Serial.print("\t");
    Serial.print(az); Serial.print("\t");
    Serial.print(gx); Serial.print("\t\t");
    Serial.print(gy); Serial.print("\t\t");
    Serial.println(gz);
    Serial.print("a/g:\t");
    Serial.print((float)ax / 16384); Serial.print("g\t");
    Serial.print((float)ay / 16384); Serial.print("g\t");
    Serial.print((float)az / 16384); Serial.print("g\t");
    Serial.print((float)gx / 131); Serial.print("d/s \t");
    Serial.print((float)gy / 131); Serial.print("d/s \t");
    Serial.print((float)gz / 131); Serial.print("d/s \n");
    timer = millis();
  }
}
void getMotion6(void){
  ax=mpu6050.getRawAccX();//gain the values of X axis acceleration raw data
  ay=mpu6050.getRawAccY();//gain the values of Y axis acceleration raw data
  az=mpu6050.getRawAccZ();//gain the values of Z axis acceleration raw data
  gx=mpu6050.getRawGyroX();//gain the values of X axis Gyroscope raw data
  gy=mpu6050.getRawGyroX();//gain the values of Y axis Gyroscope raw data
  gz=mpu6050.getRawGyroX();//gain the values of Z axis Gyroscope raw data
}

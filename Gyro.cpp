#include "Gyro.h"
#include "ports.c"

void Gyro::begin() {
  
    Wire.begin();
    Wire.beginTransmission(GyroAddr);
    Wire.write(0x6B); 
    Wire.write(0);    
    Wire.endTransmission(true);
};

void Gyro::getData(int *x, int *y){
  Wire.beginTransmission(GyroAddr);
  Wire.write(0x3B);  
  Wire.endTransmission(false);

  Wire.requestFrom(GyroAddr,12,true);
  
  *x=  Wire.read()<<8|Wire.read();
  *y=Wire.read()<<8|Wire.read();
};

#ifndef Gyro_h
#define Gyro_h
#include "Arduino.h" 

#include <Wire.h>


class Gyro{
  public:
    void begin();
    void getData(int *x, int *y);
  };
#endif

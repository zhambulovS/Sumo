#ifndef Lidar_h
#define Lidar_h
#include <Wire.h>
#include <Adafruit_VL53L0X.h>
#include "Arduino.h" 

class Lidar{
  public:
    Lidar();
    void getData(int *r);
    void begin();
  };
#endif

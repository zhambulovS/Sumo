#ifndef Motor_h
#define Motor_h
#include "Arduino.h" 

class Motor{
  public:
    Motor();
    void Shake(int s);
    void ForWard(int s);
    void BackWard(int s);
    void FPovorot(int LSpeed, int RSpeed);
    void BPovorot(int LSpeed, int RSpeed);
    void Search(int LSpeed, int RSpeed);
  private:
    unsigned long timing;
  };
#endif

#include "ports.c"
#include "Motor.h"

Motor::Motor() {
    pinMode(PinA1, OUTPUT);
    pinMode(PinA2, OUTPUT);
    pinMode(PinB1, OUTPUT);
    pinMode(PinB2, OUTPUT);
  }
  void Motor::ForWard(int s){
    analogWrite(PinA1, s);
    analogWrite(PinA2, 0);
    analogWrite(PinB1, s);
    analogWrite(PinB2, 0);
  }
  void Motor::FPovorot(int LSpeed, int RSpeed){
    analogWrite(PinA1, LSpeed);
    analogWrite(PinA2, 0);
    analogWrite(PinB1, RSpeed);
    analogWrite(PinB2, 0);
  }
  void Motor::Shake(int s){
    if (millis() - timing > 150){  
      timing = millis(); 
      FPovorot(s, s-200);
     }else
      FPovorot(s-200, s);
  }
  void Motor::BackWard(int s){
    analogWrite(PinA1, 0);
    analogWrite(PinA2, s);
    analogWrite(PinB1, 0);
    analogWrite(PinB2, s);
  }
  void Motor::BPovorot(int LSpeed, int RSpeed){
    analogWrite(PinA1, 0);
    analogWrite(PinA2, LSpeed);
    analogWrite(PinB1, 0);
    analogWrite(PinB2, RSpeed);
  }
   void Motor::Search(int LSpeed, int RSpeed){
    analogWrite(PinA1, LSpeed);
    analogWrite(PinA2, 0);
    analogWrite(PinB1, 0);
    analogWrite(PinB2, RSpeed);
  }

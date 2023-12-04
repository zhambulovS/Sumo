#include "Motor.h"
#include "Lidar.h"
#include "Gyro.h"
  Motor motor;
  Gyro myGyro;
  Lidar lidar;
  
//PART SETUP
void setup(){
 DDRB &= ~(1<<0);
 DDRB &= ~(1<<3);
 myGyro.begin();
  Serial.begin(9600);
  lidar.begin();
  while (!btn()){};
  delay(5000);
}

//PART FUNCTIONS
bool btn(){ //Кнопка басылғаны
  if ((1 << PB3) & PINB){
      return true;
    }else {
       return false;
    }
}
bool line(){ //Если датчик дигитал болса
  if ((1 << PB0) & PINB){
      return true;
    }else {
       return false;
    }
}

//void trick1(){
//   if (r<=100){
//    motor.Shake(255);
//   }else{
//     motor.Search(50,-50);
//   }
//  }
//
// void trick2(){
//  if (r<=50){
//    motor.Shake(255);
//   }
//   else if (r>50 && r<=150){
//    motor.ForWard(255);
//    }
//   else{
//     motor.Search(50,-50);
//   }
//  }
 
//PART LOOP
void loop(){
  int x, y, r;
  myGyro.getData(&x, &y); // Получаем данные с гироскопа
  lidar.getData(&r);//Датчик растояний
  Serial.println(r);
//  if (line()){  
    if (r<=100){
      motor.ForWard(255);
   }
    else if (r<=300){
      motor.ForWard(175);
    }else{
      motor.Search(30, 30);
   }

//   delay(10);
  }
  
//  else{
//      motor.BackWard(50);
//      motor.Search(50,-50);
//   }
//}
 

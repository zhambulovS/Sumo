#include "ports.c"
#include "Lidar.h"

//Adafruit_VL53L0X lox1 = Adafruit_VL53L0X();
Adafruit_VL53L0X lox2 = Adafruit_VL53L0X();

// this holds the measurement
//VL53L0X_RangingMeasurementData_t measure1;
VL53L0X_RangingMeasurementData_t measure2;
Lidar::Lidar() { //i2C
//  DDRD |=1<<2; //pinMode(SHT_LOX1, OUTPUT);
  DDRD |=1<<3;//pinMode(SHT_LOX2, OUTPUT);
//  PORTD &=~(1<<2);//digitalWrite(SHT_LOX1, LOW);
  PORTD &=~(1<<3);//digitalWrite(SHT_LOX2, LOW);
  };

void Lidar::begin() {
  // all reset
//  PORTD &=~(1<<2);//digitalWrite(SHT_LOX1, LOW);
//  PORTD &=~(1<<3);//digitalWrite(SHT_LOX2, LOW);
//  _delay_ms(10);
//  
  // all unreset
//  PORTD |= 1<<2;//digitalWrite(SHT_LOX1, HIGH);
//  PORTD |= 1<<3;//digitalWrite(SHT_LOX2, HIGH);
//  _delay_ms(10);
  // activating LOX1 and resetting LOX2
//  PORTD |= 1<<2;//digitalWrite(SHT_LOX1, HIGH);
//  PORTD &=~(1<<3);//digitalWrite(SHT_LOX2, LOW);
//  lox1.begin(LOX1_ADDRESS);
//  _delay_ms(10);

  // activating LOX2
  PORTD |= 1<<3;//digitalWrite(SHT_LOX2, HIGH);
  _delay_ms(10);
  lox2.begin(LOX2_ADDRESS);

//  lox1.setMeasurementTimingBudgetMicroSeconds(20000);
  lox2.setMeasurementTimingBudgetMicroSeconds(20000);

};

void Lidar::getData(int *r) {
//  lox1.rangingTest(&measure1, false); // pass in 'true' to get debug data printout!
  lox2.rangingTest(&measure2, false); // pass in 'true' to get debug data printout!
//  *l=measure1.RangeMilliMeter;
  *r=measure2.RangeMilliMeter;
};

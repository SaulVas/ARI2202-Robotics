#include <avr/wdt.h>
#include "DeviceDriverSet_Motor.h"
#include "ApplicationFunctionSet_1.cpp"
#include "DeviceDriverSet_USS.h"


DeviceDriverSet_Motor AppMotor;
DeviceDriverSet_Uss AppUss;
Application app;

DeviceDriverSet_Uss;

void setup() {
  AppMotor.Motor_Init();
  AppUss.Uss_Init();
  delay(1000);
}

void loop() {
  long distance;
  
  AppUss.Uss_Send_Pulse();
  distance = AppUss.Uss_Get_Distance();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");


  delay(500);
  
}

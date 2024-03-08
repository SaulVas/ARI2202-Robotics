#include <avr/wdt.h>
#include "DeviceDriverSet_1.h"
#include "ApplicationFunctionSet_1.cpp"

DeviceDriverSet_Motor AppMotor;
Application app;

bool executed = false;

void setup() {
  AppMotor.Motor_Init();
  delay(1000);
}

void loop() {
  // Only executes the desired functionality once
  while (!executed) {
    // Loops through the enum value contained in the app variable twice, starting with a value of forwards and ending with a value of backwards
    for (int edge = 0 ; edge < 4 ; ++edge) {
      ApplicationFunctionSet_SmartRobotCarMotionControl(Forward, 100);
      delay(2000);
      
      ApplicationFunctionSet_NinetyDegreeTurn(Right);
    }

    // Stops the car
    ApplicationFunctionSet_SmartRobotCarMotionControl(stop_it /*direction*/, 100 /*speed*/);
    executed = true;
  }
}

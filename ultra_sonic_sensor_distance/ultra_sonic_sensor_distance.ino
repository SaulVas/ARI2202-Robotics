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
    for (app.Motion_Control = 0 ; app.Motion_Control < 2; app.Motion_Control = app.Motion_Control + 1) {
      ApplicationFunctionSet_SmartRobotCarMotionControl(app.Motion_Control, 100);
      delay(5000);
    }

    // Stops the car
    ApplicationFunctionSet_SmartRobotCarMotionControl(stop_it /*direction*/, 100 /*speed*/);
    
    executed = true;
  }
}

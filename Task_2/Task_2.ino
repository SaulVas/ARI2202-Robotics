#include <avr/wdt.h>
#include "DeviceDriverSet_Motor.h"
#include "ApplicationFunctionSet_1.cpp"
#include "DeviceDriverSet_USS.h"

DeviceDriverSet_Motor motor;
DeviceDriverSet_Uss ultrasonic;
Application app;

bool executing = true;
unsigned long startTime;

void setup() {
  // Initialize Motor and Ultrasonic Sensor
  motor.Motor_Init();
  ultrasonic.Uss_Init();

  // Set direction to forward
  app.Motion_Control = 0;

  // Record start time
  startTime = millis(); 

  // Start moving forward immediately
  ApplicationFunctionSet_SmartRobotCarMotionControl(app.Motion_Control, 100);
}

void loop() {
  // Condition to check if 10 seconds have passed
  if ((millis() - startTime < 10000) && (executing == true)) { 
    ultrasonic.Uss_Send_Pulse(); 
    long distance = ultrasonic.Uss_Get_Distance();
    
    // Check if obstacle is within 20 cm
    if (distance <= 20) {
      // Stop the robot and end the program
      app.Motion_Control = 8;
      ApplicationFunctionSet_SmartRobotCarMotionControl(app.Motion_Control, 0);
      executing = false;
    }
  } else {
    app.Motion_Control = 8;
    ApplicationFunctionSet_SmartRobotCarMotionControl(app.Motion_Control, 0);
    executing = false;
  }
  
}

#include <avr/wdt.h>
#include "DeviceDriverSet_Motor.h"
#include "ApplicationFunctionSet_1.cpp"
#include "DeviceDriverSet_USS.h"

#define SPEED 50

DeviceDriverSet_Motor motor;
DeviceDriverSet_Uss ultrasonic;
Application app;

void setup() {
  // Initialize Motor and Ultrasonic Sensor
  motor.Motor_Init();
  ultrasonic.Uss_Init();
}

void loop() {
  // Check for obstacle
  ultrasonic.Uss_Send_Pulse();
  long distance = ultrasonic.Uss_GetDistance();
  
  if (distance < 20) {
    // Obstacle detected, perform obstacle avoidance
    
    // Turn 90 degrees left
    ApplicationFunctionSet_NinetyDegreeTurn(LEFT);
    
    // Check for obstacle again
    ultrasonic.Uss_Send_Pulse();
    distance = ultrasonic.Uss_GetDistance();
    
    if (distance < 20) {
      // Obstacle still detected, turn 180 degrees right
      ApplicationFunctionSet_NinetyDegreeTurn(RIGHT);
      ApplicationFunctionSet_NinetyDegreeTurn(RIGHT);
      
      // Check for obstacle again
      ultrasonic.Uss_Send_Pulse();
      distance = ultrasonic.Uss_GetDistance();
      
      if (distance < 20) {
        // Obstacle still detected, turn another 90 degrees right
        ApplicationFunctionSet_NinetyDegreeTurn(RIGHT);
      }
    }
  } else {
    // No obstacle detected, move forward
    ApplicationFunctionSet_SmartRobotCarMotionControl(FORWARD, SPEED);
  }
}

void loop() {
  
  
}

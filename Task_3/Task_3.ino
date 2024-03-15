#include <avr/wdt.h>
#include "Motor.h"
#include "UltraSonicSensor.h"

#define SPEED 50

Motor motor;
UltraSonicSensor ultrasonic;

void setup() {
  Serial.begin(9600);
  // Initialize Motor and Ultrasonic Sensor
  motor.init();
  ultrasonic.init();
}

void loop() {
  // Check for obstacle
  ultrasonic.send_pulse();
  long distance = ultrasonic.get_distance();
  
  if (distance < 20) {
    // Obstacle detected, perform obstacle avoidance
    
    // Turn 90 degrees left
    motor.turn(LEFT, 90);
    
    // Check for obstacle again
    ultrasonic.send_pulse();
    distance = ultrasonic.get_distance();
    
    if (distance < 20) {
      // Obstacle still detected, turn 180 degrees right
      motor.turn(RIGHT, 180);
      
      // Check for obstacle again
      ultrasonic.send_pulse();
      distance = ultrasonic.get_distance();
      
      if (distance < 20) {
        // Obstacle still detected, turn another 90 degrees right
        motor.turn(RIGHT, 90);
      }
    }
  } else {
    // No obstacle detected, move forward
    motor.move(FORWARD, SPEED);
  }
}

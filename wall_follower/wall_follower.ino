#include <avr/wdt.h>
#include "Motor.h"
#include "UltraSonicSensor.h"
#include "ServoRotate.h"
#include "InfraRedSensor.h"

Motor motor;
UltraSonicSensor ultrasonic;
ServoRotate servo;
InfraRedSensor irs;
unsigned long start_time;
const int targetDistance = 12; // Target distance from the wall in cm
const float proportionalGain = 5.5; // Proportional gain for correction
int baseSpeed = 100;
bool rightWall = true;
bool foundEnd = false;
int frontDistance;


void setup() {
  motor.init();
  ultrasonic.init();
  servo.init();
  irs.init();
  servo.rotateTo(0);
  delay(500); //time to start
  start_time = millis();
}

// Constant and Variables for Wall Following



void loop() {
  unsigned long current_time = millis();
  int left = irs.get_left();
  int right = irs.get_right();
  int middle = irs.get_middle();

  if (!foundEnd) {
    if ((left > BLACK_LOWER && left < BLACK_UPPER) && (middle > BLACK_LOWER && middle < BLACK_UPPER) && (right > BLACK_LOWER && right < BLACK_UPPER)){
      foundEnd = true;
      motor.move(FORWARD, 100);
      delay(400); //time moving forward
      motor.move(STOP, 0);
      delay(1000); //found end pause
      motor.move(LEFT, 200);
      delay(500); //time moving left
      motor.move(STOP, 0);
      delay(50); //time stopped
    }
  }
  else if (foundEnd && rightWall) {
    if ((left > GRAY_LOWER && left < GRAY_UPPER) && (middle > GRAY_LOWER && middle < GRAY_UPPER) && (right > GRAY_LOWER && right < GRAY_UPPER)){
        rightWall = false;
        motor.move(FORWARD, baseSpeed);
        delay(400); //adjust!!!!
        motor.move(STOP, 0);
        delay(25);
        motor.move(LEFT, 200);
        delay(500); //time turning left
        motor.move(STOP, 0);
        delay(600); //time stopped to reset
        servo.rotateTo(180);
        delay(400); //time for servo to rotate
  }
}
  
  if (rightWall) {  
    if (current_time - start_time > 400) {
      motor.move(STOP, 0);
      servo.rotateTo(90);
      delay(250); //time for servo to rotate
      ultrasonic.send_pulse();
      int frontDistance = ultrasonic.get_distance();
      
      if (frontDistance < 10) {
          motor.move(LEFT, 200);
          delay(270); //time turning left
      }

      motor.move(STOP, 0);
      delay(75); //time stopped
      // redundant?
      // motor.move(STOP, 0);
      // delay(50); //time stopped
      ultrasonic.send_pulse();
      frontDistance = ultrasonic.get_distance();
      if (frontDistance < 12) {
          motor.move(LEFT, 200);
          delay(225); //time turning left
          motor.move(STOP, 0);
          delay(50); //time sotpped
      }

      servo.rotateTo(0);
      delay(175); //time for servo to rotate
      start_time = millis();
    }
    ultrasonic.send_pulse();
    int currentDistance = ultrasonic.get_distance();

    // Calculate error with saturation
    int error;
    if (currentDistance > 25) {
      error = 25 - targetDistance; // Cap the error to the value at 25 cm
    } else {
      error = currentDistance - targetDistance;
    }

    // Calculate speed adjustment
    int speedAdjustment = proportionalGain * error;

    // Set motor speeds
    int rightMotorSpeed = baseSpeed - speedAdjustment;
    int leftMotorSpeed = baseSpeed + speedAdjustment;

    // Ensure speeds remain within 0-255
    rightMotorSpeed = constrain(rightMotorSpeed, 0, 150);
    leftMotorSpeed = constrain(leftMotorSpeed, 0, 150);

    // Move robot
    motor.motor_control(DIRECTION_FRONT, rightMotorSpeed, DIRECTION_FRONT, leftMotorSpeed, CONTROL_ENABLE);
  }
  else if (!rightWall) {
    if (!rightWall){
      if ((left > BLACK_LOWER && left < BLACK_UPPER) && (middle > BLACK_LOWER && middle < BLACK_UPPER) && (right > BLACK_LOWER && right < BLACK_UPPER)){
        motor.move(STOP, 0);
        delay(300000); //end
      }
    }
    if (current_time - start_time > 400) {
      motor.move(STOP, 0);
      servo.rotateTo(90);
      delay(250); //time for servo to rotate
      ultrasonic.send_pulse();
      int frontDistance = ultrasonic.get_distance();
      
      if (frontDistance < 10) {
        motor.move(RIGHT, 200);
        delay(270); //time turning right
      }

      motor.move(STOP, 0);
      delay(75); //time stopped
      ultrasonic.send_pulse();
      frontDistance = ultrasonic.get_distance();
      if (frontDistance < 12) {
        motor.move(RIGHT, 200);
        delay(225); //time moving right
        motor.move(STOP, 0);
        delay(50); //time stopped
      }

      servo.rotateTo(180);
      delay(175); //time for servo to rotate
      start_time = millis();
    }
    ultrasonic.send_pulse();
    int currentDistance = ultrasonic.get_distance();

    // Calculate error with saturation
    int error;
    if (currentDistance > 25) {
      error = 25 - targetDistance; // Cap the error to the value at 25 cm
    } else {
      error = currentDistance - targetDistance;
    }

    // Calculate speed adjustment
    int speedAdjustment = proportionalGain * error;

    // Set motor speeds
    int rightMotorSpeed = baseSpeed + speedAdjustment;
    int leftMotorSpeed = baseSpeed - speedAdjustment;

    // Ensure speeds remain within 0-255
    rightMotorSpeed = constrain(rightMotorSpeed, 0, 150);
    leftMotorSpeed = constrain(leftMotorSpeed, 0, 150);

    // Move robot
    motor.motor_control(DIRECTION_FRONT, rightMotorSpeed, DIRECTION_FRONT, leftMotorSpeed, CONTROL_ENABLE);
  }
  // Delay to allow for movement
  delay(75);
   
}
  
/*
psuedo:

1. explore node we are in
2. Follow right wall for 1100ms
    follow:
    maybe just forwards
    - if distance to wall < 13 -> Turn LEFT FORWARD
    - if distance inbwteen 13 and 15 -> Go FORWARD
    - if distance inbetween 15 and 18 -> Turn RIGHT FORWARD

3. when 1.1s passes (travels 30cm - one square)
4. check 3 sides
5. turn as needed
6. repeat 2-6
*/ 
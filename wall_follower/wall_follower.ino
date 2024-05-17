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


void setup() {
  motor.init();
  ultrasonic.init();
  servo.init();
  irs.init();
  servo.rotateTo(0);
  delay(1000);
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
      delay(350);
      motor.move(STOP, 0);
      delay(1000);
      servo.rotateTo(90);
      delay(350);
      ultrasonic.send_pulse();
      int frontDistance = ultrasonic.get_distance();

      if (frontDistance < 20) {
        servo.rotateTo(180);
        delay(350);
        ultrasonic.send_pulse();
        int leftDistance = ultrasonic.get_distance();
        if (leftDistance < 20) {
          motor.move(LEFT, 200);
          delay(500);
          motor.move(STOP, 0);
          delay(50);
        }
        else {
          motor.move(LEFT, 200);
          delay(250);
          motor.move(STOP, 0);
          delay(50);
        }
      }
    }
  }
  else if (foundEnd) {
    if ((left > GRAY_LOWER && left < GRAY_UPPER) && (middle > GRAY_LOWER && middle < GRAY_UPPER) && (right > GRAY_LOWER && right < GRAY_UPPER)){
        motor.move(FORWARD, baseSpeed);
        delay(400);
        rightWall = false;
        motor.move(STOP, 0);
        delay(1000);
        motor.move(LEFT, 200);
        delay(500);
        motor.move(STOP, 0);
        delay(50);
  }
}
  
  if (rightWall) {  
    if (current_time - start_time > 400) {
      motor.move(STOP, 0);
      servo.rotateTo(90);
      delay(350);
      ultrasonic.send_pulse();
      int frontDistance = ultrasonic.get_distance();
      
      if (frontDistance < 10) {
          motor.move(LEFT, 200);
          delay(270);
          motor.move(STOP, 0);
          delay(50);
      }

      motor.move(STOP, 0);
      delay(50);
      ultrasonic.send_pulse();
      frontDistance = ultrasonic.get_distance();
      if (frontDistance < 12) {
          motor.move(LEFT, 200);
          delay(270);
          motor.move(STOP, 0);
          delay(50);
      }

      servo.rotateTo(0);
      delay(350);
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
        delay(300000);
      }
    }
    if (current_time - start_time > 400) {
      motor.move(STOP, 0);
      servo.rotateTo(90);
      delay(350);
      ultrasonic.send_pulse();
      int frontDistance = ultrasonic.get_distance();
      
      if (frontDistance < 10) {
        motor.move(RIGHT, 200);
        delay(270);
        motor.move(STOP, 0);
        delay(50);
      }

      ultrasonic.send_pulse();
      frontDistance = ultrasonic.get_distance();
      if (frontDistance < 12) {
        motor.move(RIGHT, 200);
        delay(225);
        motor.move(STOP, 0);
        delay(50);
      }

      servo.rotateTo(180);
      delay(350);
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
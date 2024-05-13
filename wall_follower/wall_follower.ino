#include <avr/wdt.h>
#include "Motor.h"
#include "UltraSonicSensor.h"
#include "ServoRotate.h"

#define SPEED 50

Motor motor;
UltraSonicSensor ultrasonic;
ServoRotate servo;


void setup() {
  motor.init();
  ultrasonic.init();
  servo.init();
  Serial.begin(9600);
  delay(1000);
}

void loop() {

  servo.rotateTo(90);
  delay(350);
  ultrasonic.send_pulse();
  long frontDistance = ultrasonic.get_distance();

  servo.rotateTo(0);
  delay(350);
  ultrasonic.send_pulse();
  long rightDistance = ultrasonic.get_distance();

  
  // motor.move(FORWARD, SPEED);
    if (rightDistance < 10) {
    motor.move(LEFT_FORWARD, SPEED);
  }
  else {
    if (rightDistance > 22.5) {
      motor.move(FORWARD, SPEED);
      delay(750);
      motor.turn(RIGHT, 70);
      motor.move(FORWARD, SPEED);
      delay(400);
    }
    else if (frontDistance < 10) {
      motor.turn(LEFT, 90);
    } 
    else if (rightDistance > 13) {
      motor.move(RIGHT_FORWARD, SPEED);
    }
    else {
      motor.move(FORWARD, SPEED);
    }

  }  
   
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
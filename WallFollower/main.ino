#include <avr/wdt.h>
#include "Motor.h"
#include "UltraSonicSensor.h"
#include "WallFollower.h"
#include "ServoRotate.h"

#define SPEED 100

Motor motor;
UltraSonicSensor ultrasonic;

void setup() {
  // Initialize Motor and Ultrasonic Sensor
  motor.init();
  ultrasonic.init();

  delay(1000);
}

void loop() {
  // code to make motor rotate
  /*Serial.println("Rotating to 0 degrees");
  servo.rotateTo(0);
  delay(1000);

  Serial.println("Rotating to 90 degrees");
  servo.rotateTo(90);
  delay(1000);

  Serial.println("Rotating to 180 degrees");
  servo.rotateTo(180);
  delay(1000);*/
   
}
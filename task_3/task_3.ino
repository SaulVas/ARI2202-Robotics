#include <avr/wdt.h>
#include "Motor.h"
#include "InfraRedSensor.h"
#define SPEED 75

Motor motor;
InfraRedSensor infrared;

void setup() {
  motor.init();
  infrared.init();
  delay(1000);
}

void loop() {

  int left = infrared.get_left();
  int middle = infrared.get_middle();
  int right = infrared.get_right();

    if (right < THRESHOLD && left < THRESHOLD && middle < THRESHOLD) {
        motor.move(STOP, SPEED);
    } else if (right < THRESHOLD && left < THRESHOLD && middle >= THRESHOLD) {
        motor.move(FORWARD, SPEED);
    } else if (left >= THRESHOLD && right < THRESHOLD && middle < THRESHOLD) {
        motor.move(LEFT, SPEED);
    } else if (right >= THRESHOLD && left < THRESHOLD && middle < THRESHOLD) {
        motor.move(RIGHT, SPEED);
    } else if (right >= THRESHOLD && middle >= THRESHOLD && left < THRESHOLD) {
        motor.move(RIGHT, SPEED);
    } else if (left >= THRESHOLD && middle >= THRESHOLD && right < THRESHOLD) {
        motor.move(LEFT, SPEED);
    } else {
        motor.move(STOP, SPEED);
        delay(250);
        // Check if line continues
        motor.move(FORWARD, SPEED);
        delay(50);

        int left = infrared.get_left();
        int middle = infrared.get_middle();
        int right = infrared.get_right();

        if (right < THRESHOLD && LEFT < THRESHOLD && middle < THRESHOLD) {
            motor.move(STOP, SPEED);
            delay(0);
        }
    }
}

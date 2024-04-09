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

  if (middle >= THRESHOLD && (left >= THRESHOLD || right >= THRESHOLD)){
      motor.move(FORWARD, SPEED); // Call motor.move function to move forward
  }
  else if (middle >= THRESHOLD) {
      motor.move(FORWARD, SPEED); // Call motor.move function to move forward
  }
  else if (left >= THRESHOLD){
      motor.move(LEFT,SPEED); // Call motor.move function to turn left
  }
  else if (right >= THRESHOLD){
      motor.move(RIGHT, SPEED);// Call motor.move function to turn right
  }
  else {
      motor.move(STOP, SPEED); // Call motor.move function to stop
  }

}

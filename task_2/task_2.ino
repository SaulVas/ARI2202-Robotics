#include <avr/wdt.h>
#include "Motor.h"
#include "UltraSonicSensor.h"
#include "InfraRedSensor.h"

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

  if (middle >= THRESHOLD){
      motor.move(FORWARD); // Call motor.move function to move forward
  }
  else if (left >= THRESHOLD){
      motor.move(LEFT_FORWARD); // Call motor.move function to turn left
  }
  else if (right >= THRESHOLD){
      motor.move(RIGHT_FORWARD)// Call motor.move function to turn right
  }
  else {
      motor.move(STOP); // Call motor.move function to stop
  }

}

#include <avr/wdt.h>
#include "Motor.h"
#include "UltraSonicSensor.h"

Motor motor;
UltraSonicSensor ultrasonic;

void setup() {
  Serial.begin(9600);
  motor.init();
  ultrasonic.init();
  delay(1000);
}

void loop() {
  long distance;
  
  ultrasonic.send_pulse();
  distance = ultrasonic.get_distance();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");

  delay(500);
}

#include <avr/wdt.h>
#include "Motor.h"
#include "UltraSonicSensor.h"
#include "InfraRedSensor.h"

Motor motor;
UltraSonicSensor ultrasonic;
InfraRedSensor infrared;

void setup() {
  Serial.begin(9600);
  motor.init();
  ultrasonic.init();
  infrared.init();
  delay(1000);
}

void loop() {
  infrared.analogue_values();
  delay(500);
}

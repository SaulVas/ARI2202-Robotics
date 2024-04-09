#include <avr/wdt.h>


#include "InfraRedSensor.h"



InfraRedSensor infrared;

void setup() {
  Serial.begin(9600);
  infrared.init();
  delay(1000);
}

void loop() {
  infrared.analogue_values();
  delay(500);
}

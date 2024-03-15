#include "UltraSonicSensor.h"

/*Ultra Sonic Sensor control*/
void UltraSonicSensor::init(void) {
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
}

void UltraSonicSensor::send_pulse(void) {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
}

// Returns distance in cm
long UltraSonicSensor::get_distance(void) {
  long duration, distance;
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;

  return distance;
}
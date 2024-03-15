#include "DeviceDriverSet_USS.h"

/*Ultra Sonic Sensor control*/
void DeviceDriverSet_Uss::Uss_Init(void) {
  Serial.begin(9600);

  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
}

void DeviceDriverSet_Uss::Uss_Send_Pulse(void) {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
}

// Returns distance in cm
long DeviceDriverSet_Uss::Uss_Get_Distance(void) {
  long duration, distance;
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;

  return distance;
}
#include <avr/wdt.h>


#include "InfraRedSensor.h"

InfraRedSensor infrared;

void setup() {
  Serial.begin(9600);
  infrared.init();
  delay(1000);
}

void loop() {
  int left = infrared.get_left();
  int middle = infrared.get_middle();
  int right = infrared.get_right();



    Serial.print("Left: ");
    Serial.print(left);
    Serial.print(", Middle: ");
    Serial.print(middle);
    Serial.print(", Right: ");
    Serial.println(right);

  // if (left >= LOWER_GRAY && left <= UPPER_GRAY) {
  //   Serial.print("Left on gray, ");
  // } else if (left >= LOWER_BLACK && left <= UPPER_BLACK) {
  //   Serial.print("Left on black, ");
  // } else if (left > UPPER_BLACK) {
  //   Serial.print("Left off ground, ");
  // } else {
  //   Serial.print("Left on Background, ");
  // }

  // if (middle >= LOWER_GRAY && middle <= UPPER_GRAY) {
  //   Serial.print("Middle on gray, ");
  // } else if (middle >= LOWER_BLACK && middle <= UPPER_BLACK) {
  //   Serial.print("Middle on black, ");
  // } else if (middle > UPPER_BLACK) {
  //   Serial.print("Middle off ground, ");
  // } else {
  //   Serial.print("Middle on Background, ");
  // }

  // if (right >= LOWER_GRAY && right <= UPPER_GRAY) {
  //   Serial.print("Right on gray, ");
  // } else if (right >= LOWER_BLACK && right <= UPPER_BLACK) {
  //   Serial.print("Right on black, ");
  // } else if (right > UPPER_BLACK) {
  //   Serial.print("Right off ground, ");
  // } else {
  //   Serial.print("Right on Background, ");
  // }
  
  Serial.println("");
  delay(500);
}

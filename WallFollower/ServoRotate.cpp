// servorotate.cpp
#include "servorotate.h"

ServoRotate::ServoRotate(int pin) : servoPin(pin) {}

void ServoRotate::initialize() {
    myservo.attach(servoPin);  // Attaches the servo on the specified pin to the servo object
}

void ServoRotate::rotateTo(int degrees) {
    myservo.write(degrees);  // Rotate the servo to the specified angle
}

// servorotate.cpp
#include "servorotate.h"

void ServoRotate::init(void) {
    myservo.attach(SERVO_PIN);  // Attaches the servo on the specified pin to the servo object
}

void ServoRotate::rotateTo(int degrees) {
    myservo.write(degrees);  // Rotate the servo to the specified angle
}

// servorotate.h
#ifndef SERVO_ROTATE_H
#define SERVO_ROTATE_H

#include <Servo.h>

class ServoRotate {
public:
    ServoRotate(int pin);  // Constructor to attach a servo on a specified pin
    void rotateTo(int degrees);  // Method to rotate the servo to a specific angle
    void initialize();  // Initializes the servo

private:
    Servo myservo;  // Servo object
    int servoPin;  // Pin to which the servo is attached
};

#endif // SERVO_ROTATE_H

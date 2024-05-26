// servorotate.h
#ifndef SERVO_ROTATE_H
#define SERVO_ROTATE_H

#include <Servo.h>

class ServoRotate {
private:
    #define SERVO_PIN 10
    Servo myservo;

public:
    void init(void);  // Initializes the servo

    void rotateTo(int degrees);  // Method to rotate the servo to a specific angle

};

#endif // SERVO_ROTATE_H

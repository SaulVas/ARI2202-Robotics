#ifndef WALLFOLLOWER_H
#define WALLFOLLOWER_H

#include <Arduino.h>
#include "Motor.h"
#include "UltraSonicSensor.h"

class WallFollower {
public:
    WallFollower(int triggerPin, int echoPin, Motor& motor); // Constructor with sensor pins and motor reference
    void followWall(); // Main method to control the robot based on sensor data

private:
    UltraSonicSensor ultrasonic; // Ultrasonic sensor object
    Motor& motor; // Reference to motor control object
    const int IDEAL_DISTANCE = 50; // Ideal distance from the wall in centimeters
    const int TURN_THRESHOLD = 10; // Distance threshold for turning
    const float CORRECTION_FACTOR = 0.5; // Factor to adjust turning sharpness
};

#endif // WALLFOLLOWER_H

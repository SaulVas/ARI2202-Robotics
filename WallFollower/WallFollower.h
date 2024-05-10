#ifndef WALLFOLLOWER_H
#define WALLFOLLOWER_H

#include <Arduino.h>

class WallFollower {
public:
    WallFollower(int triggerPin, int echoPin); // Constructor with pins for the ultrasonic sensor
    void followWall(); // Method to initiate wall following behavior

private:
    int triggerPin, echoPin;
    const int IDEAL_DISTANCE = 50; // Ideal distance from the wall in centimeters
    const int TURN_THRESHOLD = 10; // Distance threshold for turning
    const float CORRECTION_FACTOR = 0.5; // Factor to adjust turning sharpness

    long get_distance(void);
};

#endif // WALLFOLLOWER_H
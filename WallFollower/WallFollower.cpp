#include "WallFollower.h"
#include "UltraSonicSensor.h"

// Constructor
WallFollower::WallFollower(int triggerPin, int echoPin) : triggerPin(triggerPin), echoPin(echoPin) {
    pinMode(triggerPin, OUTPUT); // Set the trigger pin as an output
    pinMode(echoPin, INPUT); // Set the echo pin as an input
    Serial.begin(9600); // Start serial communication
    Serial.println("WallFollower initialised.");
}
// Method to measure distance using ultrasonic sensor
long UltraSonicSensor::get_distance(void) {
  long duration, distance;
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;

  return distance;
}

// Main method to control the robot based on sensor data
void WallFollower::followWall() {
    long distance = measureDistance();
    Serial.print("Measured Distance: ");
    Serial.println(distance);

    //implement wall following logic here
}
//hi
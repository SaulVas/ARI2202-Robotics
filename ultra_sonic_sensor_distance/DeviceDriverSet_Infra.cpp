#include "DeviceDriverSet_Infra.h"

DeviceDriverSet_Infra(int leftSensorPin,int middleSensorPin, int rightSensorPin){}

/*Infrared sensors are set to on and are capable of reading the line*/
void DeviceDriverSet_Infra::LineFollower_Init(void){
    pinMode(LEFT_IRS_PIN, INPUT);
    pinMode(MIDDLE_IRS_PIN, INPUT);
    pinMode(RIGHT_IRS_PIN, INPUT);
}


void DeviceDriverSet_Infra::FollowLine(void){
    int left = digitalRead(LEFT_IRS_PIN);
    int middle = digitalRead(MIDDLE_IRS_PIN);
    int right = digitalRead(RIGHT_IRS_PIN);

    if (middle == HIGH){
        //move foward
    }
    else if (left == HIGH){
        //turn left
    }
    else if (right == HIGH){
        //turn right
    }
    else {
        //stop
    }
}
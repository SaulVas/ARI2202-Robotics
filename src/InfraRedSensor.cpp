#include "InfraRedSensor.h"

/*Infrared sensors are set to on and are capable of reading the line*/
void InfraRedSensor::init(void){
    pinMode(LEFT_IRS_PIN, INPUT);
    pinMode(MIDDLE_IRS_PIN, INPUT);
    pinMode(RIGHT_IRS_PIN, INPUT);
}


void InfraRedSensor::FollowLine(void){
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
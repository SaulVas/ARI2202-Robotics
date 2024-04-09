#include "InfraRedSensor.h"

/*Infrared sensors are set to on and are capable of reading the line*/
void InfraRedSensor::init(void){
    pinMode(LEFT_IRS_PIN, INPUT);
    pinMode(MIDDLE_IRS_PIN, INPUT);
    pinMode(RIGHT_IRS_PIN, INPUT);
}

void InfraRedSensor::analogue_values(void){
    int left = analogRead(LEFT_IRS_PIN);
    int middle = analogRead(MIDDLE_IRS_PIN);
    int right = analogRead(RIGHT_IRS_PIN);

    Serial.print("Left: ");
    Serial.print(left);
    Serial.print(" Middle: ");
    Serial.print(middle);
    Serial.print(" Right: ");
    Serial.println(right);
}
#include "InfraRedSensor.h"

int InfraRedSensor::get_analogue_value(int pin){
    int value = analogRead(pin);
    return value;
}

/*Infrared sensors are set to on and are capable of reading the line*/
void InfraRedSensor::init(void){
    pinMode(LEFT_IRS_PIN, INPUT);
    pinMode(MIDDLE_IRS_PIN, INPUT);
    pinMode(RIGHT_IRS_PIN, INPUT);
}

int InfraRedSensor::get_left(void){
    return get_analogue_value(LEFT_IRS_PIN);
}

int InfraRedSensor::get_middle(void){
    return get_analogue_value(MIDDLE_IRS_PIN);
}

int InfraRedSensor::get_right(void){
    return get_analogue_value(RIGHT_IRS_PIN);
}
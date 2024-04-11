#ifndef _InfraRedSensor_H_
#define _InfraRedSensor_H_

#include <arduino.h>

/*Infrared Sensor*/
class InfraRedSensor {
    private:
    #define LEFT_IRS_PIN A2
    #define MIDDLE_IRS_PIN A1
    #define RIGHT_IRS_PIN A0

    int get_analogue_value(int pin);

public: 
    #define LOWER_GRAY 150
    #define UPPER_GRAY 425

    #define LOWER_BLACK 600
    #define UPPER_BLACK 800

    void init(void);
    int get_left(void);
    int get_middle(void);
    int get_right(void);

};

#endif

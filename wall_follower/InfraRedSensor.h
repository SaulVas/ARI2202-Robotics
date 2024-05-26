#ifndef _InfraRedSensor_H_
#define _InfraRedSensor_H_

#include <arduino.h>

/*Infrared Sensor*/
class InfraRedSensor {
    private:
    // Pins for the Infrared Sensors
    #define LEFT_IRS_PIN A2
    #define MIDDLE_IRS_PIN A1
    #define RIGHT_IRS_PIN A0

    int get_analogue_value(int pin);

public: 
    # define THRESHOLD 600
    # define BLACK_LOWER 500
    # define BLACK_UPPER 1000
    # define GRAY_LOWER 200
    # define GRAY_UPPER 500

    void init(void);
    int get_left(void);
    int get_middle(void);
    int get_right(void);
};

#endif

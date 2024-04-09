#ifndef _InfraRedSensor_H_
#define _InfraRedSensor_H_

#include <arduino.h>

/*Infrared Sensor*/
class InfraRedSensor {
    private:
    #define LEFT_IRS_PIN A2
    #define MIDDLE_IRS_PIN A1
    #define RIGHT_IRS_PIN A0

public: 

    void init(void);

    void analogue_values(void);

    void follow_line(void);
};

#endif

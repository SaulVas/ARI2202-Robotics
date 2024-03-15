#ifndef _DeviceDriverSet_1_H_
#define _DeviceDriverSet_1_H_

#include <arduino.h>

/*Infrared Sensor*/
//pin numbers are from notes
class DeviceDriverSet_Infra {
    private:
    #define LEFT_IRS_PIN = A2;
    #define MIDDLE_IRS_PIN = A1;
    #define RIGHT_IRS_PIN = A0;

public: 

void LineFollower_Init(void);

void FollowLine(void);
};

#endif

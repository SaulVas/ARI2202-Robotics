#ifndef _DeviceDriverSet_1_H_
#define _DeviceDriverSet_1_H_

#include <arduino.h>

/*Motor*/
class DeviceDriverSet_Motor {                                                               
private:
  // A -> Right Side 
  // B -> Left Side
  // PWMA and PWMB are used for Pulse Width Modulation (control the speed of motors a and b)
  #define PIN_Motor_PWMA 5
  #define PIN_Motor_PWMB 6

  // AIN and BIN control the direction of motors a and b respectively
  #define PIN_Motor_AIN_1 7
  #define PIN_Motor_BIN_1 8

  // STBY pin is used to enable or disable the motor driver
  #define PIN_Motor_STBY 3


public:

  // Initializes the motor hardware settings, must be called in setup()
  void Motor_Init(void);

  // Controls the motor based on direction of each side, speed and enable/disable control
  void Motor_control(boolean direction_A, uint8_t speed_A,
                                     boolean direction_B, uint8_t speed_B, 
                                     boolean controlED                     
  );         

  #define speed_Max 255
  #define direction_just true
  #define direction_back false
  #define direction_void 3

  #define Duration_enable true
  #define Duration_disable false
  #define control_enable true
  #define control_disable false

};

#endif

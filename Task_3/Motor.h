#ifndef _Motor_H_
#define _Motor_H_

#include <arduino.h>
#include <string.h>

class Motor {                                                               
private:
  // A -> Right Side 
  // B -> Left Side
  // PWMA and PWMB are used for Pulse Width Modulation (control the speed of motors a and b)
  #define PIN_MOTOR_PWMA 5
  #define PIN_MOTOR_PWMB 6

  // AIN and BIN control the direction of motors a and b respectively
  #define PIN_MOTOR_AIN_1 7
  #define PIN_MOTOR_BIN_1 8

  // STBY pin is used to enable or disable the motor driver
  #define PIN_MOTOR_STBY 3

  // Speed and direction settings
  #define SPEED_MAX 255
  #define SPEED_MIN 0
  #define DIRECTION_FRONT true
  #define DIRECTION_BACK false
  #define DIRECTION_VOID 3

  // Control settings
  #define CONTROL_ENABLE true
  #define CONTROL_DISABLE false

  #define TIME_FOR_360_DEGREE 6400

  // Controls the motor based on direction of each side, speed and enable/disable control
  void motor_control(boolean direction_A, uint8_t speed_A,
                                     boolean direction_B, uint8_t speed_B, 
                                     boolean controlED                     
  );         

public:
  // Movement directions 
  #define FORWARD "forward"
  #define BACKWARD "backward"
  #define LEFT "left"
  #define RIGHT "right"
  #define LEFT_FORWARD "left_forward"
  #define LEFT_BACKWARD "left_backward"
  #define RIGHT_FORWARD "right_forward"
  #define RIGHT_BACKWARD "right_backward"
  #define STOP "stop_it"

  // Initializes the motor hardware settings, must be called in setup()
  void init(void);

  // Moves the robot based on direction, speed
  void move(String direction, int speed); 

  void turn(String direction, int degrees);
};

#endif

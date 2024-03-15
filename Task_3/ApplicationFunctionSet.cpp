#include "ApplicationFunctionSet.h"

void ApplicationFunctionSet::move(int direction, int speed) {
  static uint8_t directionRecord = 0;
  uint8_t speed = is_speed;
  switch (direction)
  {
  case FORWARD:
      AppMotor.Motor_control(direction_just, speed,
                                             direction_just, speed, 
                                             control_enable); 
    break;
  
  case BACKWARD:
      AppMotor.Motor_control(direction_back, speed,
                                             direction_back, speed, 
                                             control_enable); 
    break;
  
  case LEFT:
    AppMotor.Motor_control(direction_just, speed,
                                           direction_back, speed, 
                                           control_enable); 
    break;

  case RIGHT:  
    AppMotor.Motor_control(direction_back, speed,
                                           direction_just, speed, 
                                           control_enable); 
    break;

  case LEFT_FORWARD:
    AppMotor.Motor_control(direction_just, speed,
                                           direction_just, speed / 2,  
                                           control_enable); 
    break;

  case LEFT_BACKWARD:
    AppMotor.Motor_control(direction_back, speed,
                                           direction_back, speed / 2, 
                                           control_enable); 
    break;

  case RIGHT_FORWARD:
    AppMotor.Motor_control(direction_just, speed / 2,
                                           direction_just, speed, 
                                           control_enable); 
    break;

  case RIGHT_BACKWARD:
    AppMotor.Motor_control(direction_back, speed / 2,
                                           direction_back, speed, 
                                           control_enable); 
    break;
    
  case STOP_IT:
    AppMotor.Motor_control(direction_void, 0,
                                           direction_void, 0, 
                                           control_enable); 
    break;
    
  default:
    break;
  }
}
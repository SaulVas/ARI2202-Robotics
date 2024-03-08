#include "DeviceDriverSet_1.h"

extern DeviceDriverSet_Motor AppMotor;

/* Motion Direction Control Sequence */
enum SmartRobotCarMotionControl
{
  Forward,       //(1)
  Backward,      //(2)
  Left,          //(3)
  Right,         //(4)
  LeftForward,   //(5)
  LeftBackward,  //(6)
  RightForward,  //(7)
  RightBackward, //(8)
  stop_it        //(9)
};               

struct Application
{
  SmartRobotCarMotionControl Motion_Control;
};

extern Application app;

static void ApplicationFunctionSet_SmartRobotCarMotionControl(SmartRobotCarMotionControl direction, uint8_t is_speed)
{
  static uint8_t directionRecord = 0;
  uint8_t speed = is_speed;
  switch (direction)
  {
  case Forward:
      AppMotor.Motor_control(direction_just, speed,
                                             direction_just, speed, 
                                             control_enable); 
    break;
  
  case Backward:
      AppMotor.Motor_control(direction_back, speed,
                                             direction_back, speed, 
                                             control_enable); 
    break;
  
  case Left:
    AppMotor.Motor_control(direction_just, speed,
                                           direction_back, speed, 
                                           control_enable); 
    break;

  case Right:  
    AppMotor.Motor_control(direction_back, speed,
                                           direction_just, speed, 
                                           control_enable); 
    break;

  case LeftForward:
    AppMotor.Motor_control(direction_just, speed,
                                           direction_just, speed / 2,  
                                           control_enable); 
    break;

  case LeftBackward:
    AppMotor.Motor_control(direction_back, speed,
                                           direction_back, speed / 2, 
                                           control_enable); 
    break;

  case RightForward:
    AppMotor.Motor_control(direction_just, speed / 2,
                                           direction_just, speed, 
                                           control_enable); 
    break;

  case RightBackward:
    AppMotor.Motor_control(direction_back, speed / 2,
                                           direction_back, speed, 
                                           control_enable); 
    break;
    
  case stop_it:
    AppMotor.Motor_control(direction_void, 0,
                                           direction_void, 0, 
                                           control_enable); 
    break;
    
  default:
    break;
  }
}

static void ApplicationFunctionSet_NinetyDegreeTurn(SmartRobotCarMotionControl direction) {
  if (direction == Left || direction == Right) {
    ApplicationFunctionSet_SmartRobotCarMotionControl(direction, 50);
    delay(1650);
  }
}

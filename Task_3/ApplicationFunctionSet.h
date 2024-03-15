#ifndef _ApplicationFunctionSet_H_
#define _ApplicationFunctionSet_H_

#include <arduino.h>
#include "DeviceDriverSet_Motor.h"

/*Motor*/
class ApplicationFunctionSet {                                                               
private:
  #define FORWARD 0
  #define BACKWARD 1
  #define LEFT 2
  #define RIGHT 3
  #define LEFT_FORWARD 4
  #define LEFT_BACKWARD 5
  #define RIGHT_FORWARD 6
  #define RIGHT_BACKWARD 7
  #define STOP_IT 8

  DeviceDriverSet_Motor AppMotor;
  
public:
  void move(int direction, int speed);

  void ninetyDegreeTurn(int direction);

};

#endif

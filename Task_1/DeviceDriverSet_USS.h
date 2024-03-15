#ifndef _DeviceDriverSet_1_H_
#define _DeviceDriverSet_1_H_

#include <arduino.h>

/*Motor*/
class DeviceDriverSet_Uss {                                                               
private:
  #define ECHO_PIN 12
  #define TRIG_PIN 13
  
public:
  void Uss_Init(void);

  void Uss_Send_Pulse(void);

  long Uss_Get_Distance(void);

};

#endif

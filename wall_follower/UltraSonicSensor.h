#ifndef _UltraSonicSensor_H_
#define _UltraSonicSensor_H_

#include <arduino.h>

/*Motor*/
class UltraSonicSensor {                                                               
private:
  #define ECHO_PIN 12
  #define TRIG_PIN 13
  
public:
  void init(void);

  void send_pulse(void);

  long get_distance(void);

};

#endif

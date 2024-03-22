#include <avr/wdt.h>
#include "Motor.h"
#include "UltraSonicSensor.h"

Motor motor;
UltraSonicSensor ultrasonic;

bool executing = true;
unsigned long startTime;


void setup() {
  // Initialize Motor and Ultrasonic Sensor
  motor.init();
  ultrasonic.init();

  delay(1000);

  motor.move(FORWARD, 100);
  // Record start time
  startTime = millis(); 

}

void loop() {
  // Condition to check if 10 seconds have passed
  if ((millis() - startTime < 10000) && (executing == true)) { 
    
    ultrasonic.send_pulse(); 
    long distance = ultrasonic.get_distance();
    
    // Check if obstacle is within 20 cm
    if (distance <= 20) {
      // Stop the robot and end the program
      motor.move(STOP, 0);
      executing = false;
    }
  } else {
    motor.move(STOP, 0);
    executing = false;
  }
  
}

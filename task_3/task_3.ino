#include <avr/wdt.h>
#include "Motor.h"
#include "InfraRedSensor.h"
#include "UltraSonicSensor.h"
#define FORWARD_SPEED 100
#define TURNING_SPEED 50

Motor motor;
InfraRedSensor infrared;
UltraSonicSensor ultrasonic;
bool on_line = true;
String last_turn = LEFT;
bool taken_blind_start_time = false;
bool executing = true;
bool junction_mode = false;
int junction_steps = 0;
unsigned long junction_start_time = millis();

void blind_detection (String direction) {
  static unsigned long start_time;
  static String opposite_direction;
  if (direction == LEFT || direction == RIGHT) {
    if (direction == LEFT) {
        opposite_direction = RIGHT;
    } else {
        opposite_direction = LEFT;
    }

    if (!taken_blind_start_time) {
        start_time = millis();
        motor.move(STOP, 0);
        taken_blind_start_time = true;
    }

    if (millis() - start_time < 2000) {
        motor.move(direction, TURNING_SPEED);
    } else if (millis() - start_time < 3500) {
        motor.move(opposite_direction, TURNING_SPEED*2);
    } else {
        motor.move(STOP, 0);
    }
  }
}

bool junction_handling (long distance) {
    int left = infrared.get_left();
    int middle = infrared.get_middle();
    int right = infrared.get_right();

    if (middle > THRESHOLD && right > THRESHOLD && left > THRESHOLD) {
        if (junction_steps == 0) {
            if (millis() - junction_start_time < 200) {
                motor.move(FORWARD, FORWARD_SPEED);
            }
            else {
                junction_steps += 1;
                motor.move(STOP, 0);
            }
        }
        else if (junction_steps == 1) {
            if (millis() - junction_start_time < 1800) {
                motor.move(LEFT, TURNING_SPEED * 2);
            } else {
                junction_steps += 1;
                motor.move(STOP, 0);
            }
        }
        else if (junction_steps == 2) {
            if (millis() - junction_start_time < 4800) {
                motor.move(RIGHT, TURNING_SPEED * 2);
            } else {
                motor.move(STOP, 0);
                executing = false;
            }
        }
    } 

    else if (middle > THRESHOLD || left > THRESHOLD || RIGHT > THRESHOLD) {
        if (junction_steps == 0) {
            if (distance < 30) {
                junction_steps += 1;
            } else {
                junction_mode = false;
            }
        }
        if (junction_steps == 1) {
            if (middle > THRESHOLD && left > THRESHOLD) {
                if (distance < 30) {
                    motor.move(STOP, 0);
                    junction_steps += 1;
                } else {
                    junction_mode = false;
                }
            } else {
                if (millis() - junction_start_time < 1800) {
                    motor.move(LEFT, TURNING_SPEED * 2);
                } else {
                    junction_steps += 1;
                    motor.move(STOP, 0);
                }
            }
        }
        if (junction_steps == 2) {
            if (middle > THRESHOLD && right > THRESHOLD) {
                if (distance > 30) {
                    junction_mode = false;
                } else {
                    if (millis() - junction_start_time < 4800) {
                        motor.move(RIGHT, TURNING_SPEED * 2);
                    } else {
                        motor.move(STOP, 0);
                        executing = false;
                    }
                }
            } else {
                if (millis() - junction_start_time < 4800) {
                        motor.move(RIGHT, TURNING_SPEED * 2);
                    } else {
                        motor.move(STOP, 0);
                        executing = false;
                    }
            }
        }
    } 
    
    else {
        if (junction_steps == 0) {
            if (millis() - junction_start_time < 200) {
                motor.move(FORWARD, FORWARD_SPEED);
            }
            else {
                junction_steps += 1;
                motor.move(STOP, 0);
            }
        }
        else if (junction_steps == 1) {
            if (millis() - junction_start_time < 1800) {
                motor.move(LEFT, TURNING_SPEED * 2);
            }
            else {
                junction_steps += 1;
                motor.move(STOP, 0);
            }
        }
        else if (junction_steps == 2) {
            if (millis() - junction_start_time < 4800) {
                motor.move(RIGHT, TURNING_SPEED * 2);
            } else {
                motor.move(STOP, 0);
                executing = false;
            }
        }
    }
}

void setup() {
  motor.init();
  infrared.init();
  ultrasonic.init();
  delay(1000);
}

void loop() {
    while (executing) {
        if (junction_mode) {
            ultrasonic.send_pulse();
            long distance = ultrasonic.get_distance();
            junction_handling(distance);
        }
        else {
            int left = infrared.get_left();
            int middle = infrared.get_middle();
            int right = infrared.get_right();

            if (middle > THRESHOLD && right > THRESHOLD && left > THRESHOLD) {
                // Junction Handling
                motor.move(STOP, 0);
                junction_mode = true;
                junction_steps = 0;
                junction_start_time = millis();
                ultrasonic.send_pulse();
                long distance = ultrasonic.get_distance();
                junction_handling(distance);
            } 
            else if (middle > THRESHOLD) {
                motor.move(FORWARD, FORWARD_SPEED);
                taken_blind_start_time = false;
            } 
            else if (left > THRESHOLD) {
                motor.move(LEFT, TURNING_SPEED);
                last_turn = LEFT;
                taken_blind_start_time = false;
            } 
            else if (right > THRESHOLD) {
                motor.move(RIGHT, TURNING_SPEED);
                last_turn = RIGHT;
                taken_blind_start_time = false;
            } else {
                blind_detection(last_turn);
            }
        }
    }
}

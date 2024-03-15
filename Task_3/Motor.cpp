#include "Motor.h"

void Motor::motor_control(boolean direction_A, uint8_t speed_A, 
                                          boolean direction_B, uint8_t speed_B, 
                                          boolean controlED)                                     
{
  if (controlED == CONTROL_ENABLE) // Checks if motor control is enabled
  {
    digitalWrite(PIN_MOTOR_STBY, HIGH); // Activates the motor driver by setting STBY to high
    { //A...Right
      switch (direction_A) 
      {
      case DIRECTION_FRONT:
        digitalWrite(PIN_MOTOR_AIN_1, HIGH);
        analogWrite(PIN_MOTOR_PWMA, speed_A);
        break;

      case DIRECTION_BACK:
        digitalWrite(PIN_MOTOR_AIN_1, LOW);
        analogWrite(PIN_MOTOR_PWMA, speed_A);
        break;

      case DIRECTION_VOID:
        analogWrite(PIN_MOTOR_PWMA, 0);
        digitalWrite(PIN_MOTOR_STBY, LOW);
        break;

      default:
        analogWrite(PIN_MOTOR_PWMA, 0);
        digitalWrite(PIN_MOTOR_STBY, LOW);
        break;

      }
    }

    { //B...Left
      switch (direction_B)
      {
      case DIRECTION_FRONT:
        digitalWrite(PIN_MOTOR_BIN_1, HIGH);
        analogWrite(PIN_MOTOR_PWMB, speed_B);
        break;

      case DIRECTION_BACK:
        digitalWrite(PIN_MOTOR_BIN_1, LOW);
        analogWrite(PIN_MOTOR_PWMB, speed_B);
        break;

      case DIRECTION_VOID:
        analogWrite(PIN_MOTOR_PWMB, 0);
        digitalWrite(PIN_MOTOR_STBY, LOW);
        break;

      default:
        analogWrite(PIN_MOTOR_PWMB, 0);
        digitalWrite(PIN_MOTOR_STBY, LOW);
        break;

      }
    }
  }

  else
  {
    digitalWrite(PIN_MOTOR_STBY, LOW);
    return;
  }
}

void Motor::init(void) {
  pinMode(PIN_MOTOR_PWMA, OUTPUT);
  pinMode(PIN_MOTOR_PWMB, OUTPUT);
  pinMode(PIN_MOTOR_AIN_1, OUTPUT);
  pinMode(PIN_MOTOR_BIN_1, OUTPUT);
  pinMode(PIN_MOTOR_STBY, OUTPUT);
}
                                                          

void Motor::move(String direction, int is_speed) {
  static uint8_t directionRecord = 0;
  uint8_t speed = is_speed;
  if (is_speed > SPEED_MAX)
  {
    speed = SPEED_MAX;
  }
  else if (is_speed < SPEED_MIN)
  {
    speed = SPEED_MIN;
  }
  if (direction == FORWARD) {
    motor_control(DIRECTION_FRONT, speed,
                  DIRECTION_FRONT, speed, 
                  CONTROL_ENABLE); 
  } 
  else if (direction == BACKWARD) {
    motor_control(DIRECTION_BACK, speed,
                  DIRECTION_BACK, speed, 
                  CONTROL_ENABLE); 
  } 
  else if (direction == LEFT) {
    motor_control(DIRECTION_FRONT, speed,
                  DIRECTION_BACK, speed, 
                  CONTROL_ENABLE); 
  } 
  else if (direction == RIGHT) {
    motor_control(DIRECTION_BACK, speed,
                  DIRECTION_FRONT, speed, 
                  CONTROL_ENABLE); 
  } 
  else if (direction == LEFT_FORWARD) {
    motor_control(DIRECTION_FRONT, speed,
                  DIRECTION_FRONT, speed / 2,  
                  CONTROL_ENABLE); 
  } 
  else if (direction == LEFT_BACKWARD) {
    motor_control(DIRECTION_BACK, speed,
                  DIRECTION_BACK, speed / 2, 
                  CONTROL_ENABLE); 
  } 
  else if (direction == RIGHT_FORWARD) {
    motor_control(DIRECTION_FRONT, speed / 2,
                  DIRECTION_FRONT, speed, 
                  CONTROL_ENABLE); 
  } 
  else if (direction == RIGHT_BACKWARD) {
    motor_control(DIRECTION_BACK, speed / 2,
                  DIRECTION_BACK, speed, 
                  CONTROL_ENABLE); 
  } 
  else if (direction == STOP) {
    motor_control(DIRECTION_VOID, 0,
                  DIRECTION_VOID, 0, 
                  CONTROL_ENABLE); 
  } 
  else {
    return;
  }
}


void Motor::turn(String direction, int degrees) {
  if (direction == LEFT || direction == RIGHT) {
    move(direction, 50);
    int time = (degrees / 360.0) * TIME_FOR_360_DEGREE;
    delay(time);
  }
}
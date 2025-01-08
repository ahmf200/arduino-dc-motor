#ifndef DC_MOTOR_CONTROL_HPP
#define DC_MOTOR_CONTROL_HPP
#include "Arduino.h"

#define DIRA 3 // Direction A assigned to pin 3
#define DIRB 4 // Direction B assigned to pin 4
#define ENABLE 5 // Pin for the DC motor assigned to 5

void turnOnMotorAndSetSpeed(int number);
void reverseMotorAndSetSpeed(int number);
void turnOffMotor();

#endif
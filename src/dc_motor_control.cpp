#include "dc_motor_control.hpp"

void turnOnMotorAndSetSpeed(int number) {
  digitalWrite(ENABLE, HIGH); // enable on
  digitalWrite(DIRA, HIGH); // turn on for direction A
  digitalWrite(DIRB, LOW); // turn off for direction B
  analogWrite(ENABLE, number); // higher value means more speed
}

void reverseMotorAndSetSpeed(int number) {
    Serial.println("I pressed 3 - Reverse");
    digitalWrite(ENABLE, HIGH);
    digitalWrite(DIRA,LOW);  // disable direction A
    digitalWrite(DIRB,HIGH); // enable direction B
    analogWrite(ENABLE, number);  // higher value means more speed
}

void turnOffMotor() {
    Serial.println("I pressed 0 - Fan OFF");
    digitalWrite(ENABLE,LOW); // turn off
    digitalWrite(DIRA,LOW);
    digitalWrite(DIRB,LOW);
    analogWrite(ENABLE,0);
}
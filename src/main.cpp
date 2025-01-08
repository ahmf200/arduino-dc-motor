/*************************
Running a DC motor using
the L293D chip with an IR
Receiver
*************************/

#include <IRremote.h>
#include "dc_motor_control.hpp"

const int REMOTE_RECV_PIN = 11;
IRrecv irrecv_remote(REMOTE_RECV_PIN);

const unsigned long eventInterval = 1000;
unsigned long previousTime = 0;

void setup() {
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  Serial.begin(115200);
  irrecv_remote.enableIRIn(); // Start the IR receiver
  Serial.println("Ready to receive IR signals.");
}

void loop() {
  unsigned long currentTime = millis();
  if ( currentTime - previousTime >= eventInterval ) {
    if (irrecv_remote.decode()) {
    switch (irrecv_remote.decodedIRData.command) {
      case 69: // Power button
        turnOffMotor();
        break;

      case 12: // Button 1
        turnOnMotorAndSetSpeed(720);
        break;

      case 24: // Button 2
        Serial.println("I pressed 2 - Fan Half Speed");
        turnOnMotorAndSetSpeed(120);
        break;

      case 94: // Button 3
        reverseMotorAndSetSpeed(80);
        break;
      
      default:
        Serial.println("Unknown command: " + irrecv_remote.decodedIRData.command);
        Serial.println(irrecv_remote.decodedIRData.command);
        break;
    }

    irrecv_remote.resume(); // Prepare for the next signal
    }
  previousTime = currentTime;
  }
}

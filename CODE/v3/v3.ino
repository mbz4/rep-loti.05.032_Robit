#include "variables.h"

void setup() {
  Serial.begin(115200);
  initIMU();
  //initUS();
  //initMotors();
  //initPresAltTemp();
  init2Motorsv1();
  initPID();
  delay(2000);
}

void loop() {
  //reportPresAltTemp();
  //goFwdBck();
  //runOpenIMU();
  //loopUS();
  //delay(100);
  motorPropCtrl(PID(runOpenIMU())); //gets pitch [deg], calculates output, moves robit
  printDEBUG();
}

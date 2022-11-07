#include "variables.h"

void setup()
{
  Serial.begin(115200);
  setupIMUv2();
  init2Motorsv1();
  initPID();
}

void loop() {
  motorPropCtrl(PID(runOpenIMU())); //gets pitch [deg], calculates output, moves robit
  printDEBUG();
}

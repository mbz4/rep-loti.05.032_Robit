
// ========================================================================

void initMotors() {
  pinMode(stepPin_motorA, OUTPUT);
  pinMode(dirPin_motorA, OUTPUT);
  pinMode(stepPin_motorB, OUTPUT);
  pinMode(dirPin_motorB, OUTPUT);
  pinMode(PIN_ENABLE_MOTORS, OUTPUT);
  digitalWrite(PIN_ENABLE_MOTORS, HIGH); //turns off motors
  Serial.println("Motors ready!");
}
// ========================================================================

void motorsStop() {
  //digitalWrite(PIN_ENABLE_MOTORS, LOW); //turns on motors
  delay(100);
  digitalWrite(PIN_ENABLE_MOTORS, HIGH); //turns off motors
}

void motorsOFF() {
  digitalWrite(PIN_ENABLE_MOTORS, HIGH); //turns off motors
}

void motorsON() {
  digitalWrite(PIN_ENABLE_MOTORS, LOW); //turns on motors
}

void oneMotorStep(int stePin, int motorRateDelayControl) {
  digitalWrite(stePin, HIGH);
  delayMicroseconds(motorRateDelayControl); //controls motor speed
  digitalWrite(stePin, LOW);
  delayMicroseconds(motorRateDelayControl);
}

// ========================================================================
void stepLoop(int rotateFrac, int motorRateDelay) {
  for (int x = 0; x < 200 * rotateFrac; x++) { //200 steps per revolution
    oneMotorStep(stepPin_motorA, motorRateDelay);
    oneMotorStep(stepPin_motorB, motorRateDelay);
  }
}
// ========================================================================


void distCheck() {
  if (dist < 15) {
    motorsStop();
    goRight();
  }
}


void jigglejiggle() {
  motorsON();
  digitalWrite(dirPin_motorA, LOW);
  digitalWrite(dirPin_motorB, HIGH);
  stepLoop(0.25, 150);
  delay(100);
  digitalWrite(dirPin_motorA, HIGH);
  digitalWrite(dirPin_motorB, LOW);
  stepLoop(0.25, 100);
  motorsOFF();
}

void goForward() {
  motorsON();
  digitalWrite(dirPin_motorA, LOW); //changes direction of rotation
  digitalWrite(dirPin_motorB, HIGH);
  stepLoop(rotateFraction, motorRateDelay); // rotates; rotateFrac controls fraction of rotation...
  motorsOFF();
}

void goBackward() {
  motorsON();
  digitalWrite(dirPin_motorA, HIGH); //changes direction of rotation
  digitalWrite(dirPin_motorB, LOW);
  stepLoop(rotateFraction, motorRateDelay); // rotates; rotateFrac controls fraction of rotation...
  motorsOFF();
}

void goRight() {
  motorsON();
  digitalWrite(dirPin_motorA, HIGH); //changes direction of rotation
  digitalWrite(dirPin_motorB, HIGH);
  stepLoop(rotateFraction, motorRateDelay); // rotates; rotateFrac controls fraction of rotation...
  motorsOFF();
}

void goLeft() {
  motorsON();
  digitalWrite(dirPin_motorA, LOW); //changes direction of rotation
  digitalWrite(dirPin_motorB, LOW);
  stepLoop(rotateFraction, motorRateDelay); // rotates; rotateFrac controls fraction of rotation... 2 & 180
  motorsOFF();
}
// ========================================================================

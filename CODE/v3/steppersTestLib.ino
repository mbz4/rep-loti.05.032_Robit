

void initMotors() {
  pinMode(stepPin_motorA, OUTPUT);
  pinMode(dirPin_motorA, OUTPUT);
  pinMode(stepPin_motorB, OUTPUT);
  pinMode(dirPin_motorB, OUTPUT);
  Serial.println("Motors ready!");
}

void oneMotorStep(int stePin, int motorRateDelayControl) {
  digitalWrite(stePin, HIGH);
  delayMicroseconds(motorRateDelayControl); //controls motor speed
  digitalWrite(stePin, LOW);
  delayMicroseconds(motorRateDelayControl);
}

void stepLoop(int rotateFrac) {
  for (int x = 0; x < 200 * rotateFrac; x++) { //200 steps per revolution
    oneMotorStep(stepPin_motorA, motorRateDelay);
    oneMotorStep(stepPin_motorB, motorRateDelay);
  }
}

void goFwdBck() {
  digitalWrite(dirPin_motorA, HIGH); //changes direction of rotation
  digitalWrite(dirPin_motorB, LOW);
  stepLoop(rotateFraction); // rotates; rotateFrac controls fraction of rotation...
  delay(1000);
  digitalWrite(dirPin_motorA, LOW);
  digitalWrite(dirPin_motorB, HIGH);
  stepLoop(rotateFraction);
  delay(1000);
}

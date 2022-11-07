
void init2Motorsv1()
{
  stepper1.setMaxSpeed(PID_LIMITS);
  stepper2.setMaxSpeed(PID_LIMITS);
  stepper1.setAcceleration(PID_LIMITS * 2);
  stepper2.setAcceleration(PID_LIMITS * 2);
}

void motorPropCtrl(double output)
{
  currSign = get_sign(output);
  if (currSign == -1) {
    stepcrement -= STEPCREMENT_FACTOR;
  }
  if (currSign == 0) { // do nothing if output = 0
    if (currSign != prevSign) {
      prevSign = currSign;
      stepcrement = 0;
    }
    return;
  }
  if (currSign == 1) {
    stepcrement += STEPCREMENT_FACTOR;
  }
  stepper1.moveTo(stepcrement);
  stepper2.moveTo(stepcrement*(-1));
  stepper1.setSpeed(abs(int(output)));
  stepper2.setSpeed(abs(int(output)));
  stepper1.runSpeedToPosition();
  stepper2.runSpeedToPosition();
}



void initPID()
{
  PIDController.begin(&input, &output, &setpoint, p, i, d);
  //PIDController.reverse();               // Uncomment if controller output is "reversed"
  //PIDController.setSampleTime(10);      // OPTIONAL - will ensure at least 10ms have past between successful compute() calls
  PIDController.setOutputLimits(-PID_LIMITS, PID_LIMITS); //Clip output to values to min and max
  //PIDController.setBias(100.0 / 2.0); //Output will have a constant offset of _bias, usually used in conjunction with setOutputLimits()
  PIDController.setWindUpLimits(-PID_LIMITS, PID_LIMITS); // Gross bounds for the integral term to prevent integral wind-up
  //PIDController.setDeadBand(-10, 10);
  //PIDController.setDirection(FORWARD);
  PIDController.start();
  // PIDController.reset();               // Used for resetting the I and D terms - only use this if you know what you're doing
  // PIDController.stop();                // Turn off the PID controller (compute() will not do anything until start() is called)
  
  //avgPitch.begin();
}

double PID(float pitchDeg)
{
  //input = avgPitch.reading(pitchDeg); // add + 25 for raiseup offset
  input = pitchDeg; // add + 25 for raiseup offset
  PIDController.compute();
  //PIDController.debug();

  if (pitchDeg < 2 && pitchDeg > -2) {
    output -= output * (decay_factor / 10000); // decay factor
    decay_factor++;
    if (decay_factor > DECAY_FACTOR_MAX) {
      decay_factor = DECAY_FACTOR_MAX;
    }
  }
  else {
    decay_factor = 0;
  }
  
if (pitchDeg > CUTOFF_PITCH_ANGLE || pitchDeg < -CUTOFF_PITCH_ANGLE) {
    output = 0;
  }

  return output;
}

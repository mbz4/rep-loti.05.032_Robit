
// ################################################################################
// PIDLib
// ################################################################################


#include "ArduPID.h"   //https://github.com/PowerBroker2/ArduPID
#include <movingAvg.h>                  // https://github.com/JChristensen/movingAvg

ArduPID PIDController;
//movingAvg avgPitch(2);

double input;
double output;
double setpoint = 0; //use 0 if holding calibration, ~-20 otherwise

double p = 1.292;
double i = 4.979;
double d = 1.508;

int PID_LIMITS = 200;
int CUTOFF_PITCH_ANGLE = 75;

// ################################################################################
// Stepper variables
// ################################################################################

//// https://github.com/zjor/balancing-robot << super extra fantastic repo
//// https://create.arduino.cc/projecthub/zjor/self-balancing-robot-with-arduino-nano-and-steppers-9bf019?ref=part&ref_id=11332&offset=4
//// https://github.com/zjor/balancing-robot

#include <AccelStepper.h>

AccelStepper stepper1(AccelStepper::FULL4WIRE, 11, 10, 9, 8); //FULL4WIRE gives max torque
AccelStepper stepper2(AccelStepper::FULL4WIRE, 4, 5, 6, 7); //HALF4WIRE gives 1/3 of max torque

int prevSign = 0;
int currSign = 0;
int stepcrement = 0;
int STEPCREMENT_FACTOR = 1;

// ################################################################################
// UTILITIES
// ################################################################################

float decay_factor = 0.0;
int DECAY_FACTOR_MAX = 3000;

static int8_t get_sign(double val) {
  if (val < 0) return -1;
  if (val == 0) return 0;
  return 1;
}
void printDEBUG() {
  Serial.print(" PITCH [deg] = ");
  Serial.print(input); //pitchInDegrees, moving averaged
  Serial.print(" PID output = ");
  Serial.print(output);
  Serial.print(" stepcrement = ");
  Serial.println(stepcrement);
}

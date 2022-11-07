

//=============CORE SERVER VARS=============
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>

const char *ssid = "MBZ_SERVER";
const char *password = "vrysmort";

const int howManyClients = 1;

//=============RCVD VARS=============

// parser
//char array[] = "1,2.0,3,4";
char *strings[4]; // an array of pointers to hold received strings
char *ptr = NULL; // after strtok()
String s = "1,2.0,3,4";
//char buf[s.length() + 1]; //byte buf[s.length() + 1];
// received vars...


// =========US Lib=========
#include <movingAvg.h>
movingAvg avgDistance(5);
int returnAvgDist = 0;

#define echoPin 5
#define trigPin 18

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int state;
bool debugUS = true;

// ################################################################################
// PIDLib
// ################################################################################


#include "ArduPID.h"   //https://github.com/PowerBroker2/ArduPID

ArduPID PIDController;

double input;
double output;
double setpoint = 0; //use 0 if holding calibration, ~-20 otherwise

double p = 1.292;
double i = 4.979;
double d = 1.508;

int PID_LIMITS = 200;
int CUTOFF_PITCH_ANGLE = 75;

bool debugIMU = true;

// ################################################################################
// Stepper variables
// ################################################################################


#include <AccelStepper.h>

const int motorRateDelay = 500;
const int rotateFraction = 10;

#define stepPin_motorA 14
#define dirPin_motorA 27

#define stepPin_motorB 26
#define dirPin_motorB 25

AccelStepper stepper1(AccelStepper::DRIVER, stepPin_motorA, dirPin_motorA);
AccelStepper stepper2(AccelStepper::DRIVER, stepPin_motorB, dirPin_motorB);

int prevSign = 0;
int currSign = 0;
int stepcrement = 0;
int STEPCREMENT_FACTOR = 100;

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
  Serial.print("\t YAW [deg] =\t");
  Serial.print(input);
  Serial.print("\t PID output =\t");
  Serial.print(output);
  Serial.print("\t stepcrement =\t");
  Serial.println(stepcrement);
}


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

#define PIN_ENABLE_MOTORS 12  

AccelStepper stepper1(AccelStepper::DRIVER, stepPin_motorA, dirPin_motorA);
AccelStepper stepper2(AccelStepper::DRIVER, stepPin_motorB, dirPin_motorB);

int prevSign = 0;
int currSign = 0;
int stepcrement = 0;
int STEPCREMENT_FACTOR = 100;

// ################################################################################
// UltraSonic Sensor variables
// ################################################################################
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

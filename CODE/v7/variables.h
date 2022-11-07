
// ################################################################################
// Runtime variables
// ################################################################################

// Timer variables
unsigned long lastTime = 0;
unsigned long timerDelay = 1000;

enum speedSettings
{
  SLOW = 250,
  NORMAL = 180,
  FAST = 110
};

// Change this to your network SSID
const char *ssid = "RobitMk2";
//const char *ssid = "ut-public";
//const char *password = "";

// ################################################################################
// Stepper variables
// ################################################################################

int motorRateDelay = 200;
int rotateFraction = 2;

#define stepPin_motorA 14
#define dirPin_motorA 27

#define stepPin_motorB 26
#define dirPin_motorB 25

#define PIN_ENABLE_MOTORS 12  


// ################################################################################
// UltraSonic Sensor variables
// ################################################################################
#include <movingAvg.h>
movingAvg avgDistance(3);
int returnAvgDist = 0;
int dist = 0;
#define echoPin 5
#define trigPin 18

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int state;
bool debugUS = false;

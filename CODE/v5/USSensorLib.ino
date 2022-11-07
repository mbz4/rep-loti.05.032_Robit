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

void initUS() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  if (debugUS) {
    Serial.println("Ultrasonic Sensor HC-SR04 Setup complete!"); // print some text in Serial Monitor
  }
  avgDistance.begin();
}

int loopUS() {
  digitalWrite(trigPin, LOW); // Clears the trigPin condition
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // // Calculating the distance: speed of sound wave / 2 (distance was traversed twice!)
  returnAvgDist = avgDistance.reading(distance);
  if (debugUS) {
    Serial.print("Distance: "); // Displays the distance on the Serial Monitor
    Serial.print(returnAvgDist);
    Serial.println(" cm");
  }
  return returnAvgDist;
}

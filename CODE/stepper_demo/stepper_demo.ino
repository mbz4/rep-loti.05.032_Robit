// Include the Arduino Stepper Library
#include <Stepper.h>
String command = "a";
// Number of steps per output rotation
const int stepsPerRevolution = 200;
const int rpm = 100;
int var = 0;
// Create Instance of Stepper library
Stepper myStepper(stepsPerRevolution, 7, 6, 5, 4);

//Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

// Vehicle speed = Wheels RPM × Tire diameter × π × 60 / 63360
const double pi = 3.1415926535897932384626433832795; //pi const
const int diameter = 12.5; //cm
const double vel = rpm*diameter*pi*60/63360; // const

void setup()
{
  // set the speed at 60 rpm:
  myStepper.setSpeed(rpm); //[rpm]
  //myStepper.setAcceleration(50.0); // set acceleration/deceleration
  // initialize the serial port:
  Serial.begin(9600);
  Serial.println("Ready to spin at...");
  Serial.println(vel);
  Serial.println("kph");
}


void loop() {
  
  if(Serial.available()) // if there is data coming
  {
    
    String command = Serial.readStringUntil('\n'); // read string until meet newline character

    if(command == "a")
    {
      Serial.println("Rotating cw"); // rotate counter clockwise
      var = 0;
      while(var < 200)
      {
        myStepper.step(stepsPerRevolution);
        var++;
        delay(250);
        String command = Serial.readStringUntil('\n');
        if(command == "stop")
        {
          break;
        }
      }
      
    }
    
    else
    if(command == "d")
    {
      Serial.println("Rotating ccw"); // rotate clockwise
      while(var < 200)
      {
        myStepper.step(-stepsPerRevolution);
        var++;
        delay(250);
        String command = Serial.readStringUntil('\n');
        if(command == "stop")
        {
          break;
        }
      }

    }
    delay(250);
  
  }
}

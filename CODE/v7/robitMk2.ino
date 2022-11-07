class Car
{
  private:
    // holds the current speed settings, see values for SLOW, NORMAL, FAST
    speedSettings currentSpeedSettings;

  public:
    Car()
    {
      // Set all pins to output
      initMotors();

      // Set initial motor state to OFF
      motorsOFF();

      // initialize default speed to SLOW
      setCurrentSpeed(speedSettings::NORMAL);
    }

    // Turn the car left
    void turnLeft()
    {
      distCheck();
      Serial.println("car is turning left...");
      setMotorSpeed();
      goLeft();
    }

    // Turn the car right
    void turnRight()
    {
      distCheck();
      Serial.println("car is turning right...");
      setMotorSpeed();
      goRight();
    }

    // Move the car forward
    void moveForward()
    {
      distCheck();
      Serial.println("car is moving forward...");
      setMotorSpeed();
      goForward();
    }

    // Move the car backward
    void moveBackward()
    {
      distCheck();
      setMotorSpeed();
      Serial.println("car is moving backward...");
      goBackward();
    }

    // Stop the car
    void stop()
    {
      Serial.println("car is stopping...");
      motorsStop();
    }

    // Set the motor speed
    void setMotorSpeed()
    {
      // change the duty cycle of the speed control pin connected to the motor
      Serial.print("Speed Settings: ");
      Serial.println(currentSpeedSettings);
      motorRateDelay = currentSpeedSettings;
      if (motorRateDelay == SLOW) {
        rotateFraction = 4;
      }
      else if (motorRateDelay == NORMAL) {
        rotateFraction = 8;
      }
      else if (motorRateDelay == FAST) {
        rotateFraction = 20;
      }
    }
    // Set the current speed
    void setCurrentSpeed(speedSettings newSpeedSettings)
    {
      Serial.println("car is changing speed...");
      currentSpeedSettings = newSpeedSettings;
    }
    // Get the current speed
    speedSettings getCurrentSpeed()
    {
      return currentSpeedSettings;
    }
};

// Our car object
Car car;

#include <Wire.h>
#include <LPS.h>

LPS ps;

void initPresAltTemp()
{
  //Serial.begin(9600);
  Wire.begin();

  if (!ps.init())
  {
    Serial.println("Failed to autodetect pressure sensor!");
    while (1);
  }

  ps.enableDefault();
}

float reportPresAltTemp()
{
  //float pressure = ps.readPressureMillibars();
  //float altitude = ps.pressureToAltitudeMeters(pressure);
  float tempC = ps.readTemperatureC();
  return tempC;
}

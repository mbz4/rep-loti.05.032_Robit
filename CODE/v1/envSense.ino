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

void reportPresAltTemp()
{
  float pressure = ps.readPressureMillibars();
  float altitude = ps.pressureToAltitudeMeters(pressure);
  float temperature = ps.readTemperatureC();
  
  Serial.print("p: ");
  Serial.print(pressure);
  Serial.print(" mbar\ta: ");
  Serial.print(altitude);
  Serial.print(" m\tt: ");
  Serial.print(temperature);
  Serial.println(" deg C");

  delay(100);
}

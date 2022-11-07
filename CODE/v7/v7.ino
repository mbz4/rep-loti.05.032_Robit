#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "SPIFFS.h"
#include "variables.h"
#include <Arduino_JSON.h>

// AsyncWebserver runs on port 80 and the asyncwebsocket is initialize at this point also
AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

// Create an Event Source on /events
AsyncEventSource events("/events");

// Json Variable to Hold Sensor Readings
JSONVar readings;

void setup()
{
  // Initialize the serial monitor baud rate
  Serial.begin(115200);
  initWifi();
  initIMU();
  initUS();
  initPresAltTemp();
  initSPIFFS();

  // Add callback function to websocket server
  ws.onEvent(onWsEvent);
  server.addHandler(&ws);
  server.serveStatic("/", SPIFFS, "/");

  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request)
  {
    Serial.println("Requesting index page...");
    request->send(SPIFFS, "/index.html", "text/html", false, indexPageProcessor);
  });


  // Request for the latest sensor readings
  server.on("/readings", HTTP_GET, [](AsyncWebServerRequest * request) {
    String json = getSensorReadings();
    request->send(200, "application/json", json);
    json = String();
  });

  // Route to load entireframework.min.css file
  server.on("/entireframework.min.css", HTTP_GET, [](AsyncWebServerRequest * request)
  {
    request->send(SPIFFS, "/entireframework.min.css", "text/css");
  });

  // Route to load custom.css file
  server.on("/custom.css", HTTP_GET, [](AsyncWebServerRequest * request)
  {
    request->send(SPIFFS, "/custom.css", "text/css");
  });

  // Route to load custom.js file
  server.on("/custom.js", HTTP_GET, [](AsyncWebServerRequest * request)
  {
    request->send(SPIFFS, "/custom.js", "text/javascript");
  });

  // On Not Found
  server.onNotFound(notFound);
  server.addHandler(&events);
  // Start server
  server.begin();
  jigglejiggle();
}


void loop()
{
  //runOpenIMU(); // has code to shut motors off if on the sides...
  dist = loopUS();
  distCheck();
  if ((millis() - lastTime) > timerDelay) {

    /*
    Serial.print("temp: ");
    Serial.print(reportPresAltTemp());
    Serial.print("dist: ");
    Serial.println(loopUS());
    */
    // Send Events to the client with the Sensor Readings Every x seconds
    events.send("ping", NULL, millis());
    events.send(getSensorReadings().c_str(), "new_readings" , millis());
    lastTime = millis();
  }
}

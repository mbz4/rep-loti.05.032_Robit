//// resources for parsing w/ arduino...
//// https://forum.arduino.cc/t/separating-a-comma-delimited-string/682868/2
//// https://www.cplusplus.com/reference/cstdlib/atof/?kw=atof
//// https://m.cplusplus.com/reference/cstring/strtok/
//#include "variables.h"
////IPAddress local_IP(192, 168, 4, 111);
////IPAddress gateway(192, 168, 4, 13);
////IPAddress subnet(255, 255, 255, 0);
//
//WiFiClient clients[howManyClients]; //set to 3 for final task...
//
//WiFiServer server(80);
//
//void setup() {
//  Serial.begin(115200);
//  LCDInit(); //initializes LCD...
//  /* ***SERVER & SOFT AP SETUP *** */
//  dispInitServer();
//  server.begin();
//  Serial.println("Server started");
//  /* ***SERVER CLIENT ACCEPTER HANDLER*** */
//  int i = 0; //waits for all clients to connect then does something...
//  while (i < howManyClients) {
//    WiFiClient client_local = server.available();
//    if (client_local.connected()) {
//      clients[i] = client_local;
//      i++;
//    }
//  }
//  Serial.print(howManyClients);
//  Serial.println(" clients connected...");
//  prompter(howManyClients); // show nm clients connected on 7seg display...
//  initneopx();
//}
//
//
//void loop() {
//  neopx();
//  int i = 0;
//  while (i < howManyClients) { //loop over all clients and serve each sequentially...
//    if (clients[i]) {
//      if (clients[i].available()) {
//        s = clients[i].readStringUntil('\n');
//        dispDebugMSG(i, s);
//        //disp_Dist_LCD(i, s); //display messages on LCD...
//        char buf[s.length() + 1];
//        returnStrings(s, buf); //parses out individual strings...
//        cl_ID = atoi(strings[0]); // convert first string to int (client ID...)
//
//        if (cl_ID == 1) { // Encoder/Pot client: int ID, float pot, int enc, int lamp
//          Serial.print("\tCLIENT_Enc_Pot ");
//          pot_voltage = atof(strings[1]); // atof ==> String to float, ASCII
//          encoder_counter = atoi(strings[2]);  //atoi ==> String to int, ASCII
//          toggle_lamp = atoi(strings[3]);
//          disp_CLIENT_Enc_Pot_VALS(i, s);
//        }
//
//        if (cl_ID == 2) { // US_ToF client: int ID, 0.0, int meas, 0
//          Serial.print("\tUS_ToF client ");
//          distanceMeas = atoi(strings[2]);  //atoi ==> String to int, ASCII
//          disp_CLIENT_US_ToF_VALS(i, s);
//        }
//
//        if (cl_ID == 3) { // PIR client
//          Serial.print("\tPIR client ");
//          PIRstate = atoi(strings[2]);  //atoi ==> String to int, ASCII
//          disp_CLIENT_PIR_VAL(i, s);
//        }
//      }
//    }
//    i++;
//  }
//}

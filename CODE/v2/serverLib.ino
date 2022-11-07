void dispInitServer() {
  Serial.println();
  //Serial.print("Setting soft-AP configuration ... ");
  //Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!");
  Serial.println();
  Serial.println("Configuring access point...");
  WiFi.softAP(ssid, password); // You can remove the password parameter if you want the AP to be open.
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.print(myIP);
  Serial.println(" on port 80...");
}
void dispDebugMSG(int i, String s) {
  Serial.print("\nClient:\t");
  Serial.print(i);
  Serial.print("\t Message:\t");
  Serial.println(s);

}

void returnStrings(String s, char *buf) {
  s.toCharArray(buf, s.length() + 1);
  byte index = 0;
  ptr = strtok(buf, ",");  // delimiter, maybe s instead...
  while (ptr != NULL)
  {
    strings[index] = ptr;
    index++;
    ptr = strtok(NULL, ",");
  }
}

//void disp_CLIENT_Enc_Pot_VALS(int i, String s) {
//  if (millis() - previousMillis >= 1.25 * period) {
//    Serial.print(",");
//    Serial.print(pot_voltage);
//    Serial.print(",");
//    Serial.print(encoder_counter);
//    Serial.print(",");
//    Serial.println(toggle_lamp);
//    previousMillis = millis();
//    delay(50);
//  }
//}
//void disp_CLIENT_US_ToF_VALS(int i, String s) {
//  if (millis() - previousMillis >= 1.15 * period) {
//    Serial.print(",");
//    Serial.println(distanceMeas);
//    previousMillis = millis();
//    delay(50);
//  }
//}
//void disp_CLIENT_PIR_VAL(int i, String s) {
//  if (millis() - previousMillis >= 2.5 * period) {
//    Serial.print(",");
//    Serial.println(PIRstate);
//    previousMillis = millis();
//    delay(50);
//  }
//}

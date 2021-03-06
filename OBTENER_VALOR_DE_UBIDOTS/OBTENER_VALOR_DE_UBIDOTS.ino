
/****************************************
 * Include Libraries
 ****************************************/

#include "Ubidots.h"

/****************************************
 * Define Constants
 ****************************************/

const char* UBIDOTS_TOKEN = "BBFF-rnkdNzhiOWs6jvQ59YU13nYYAX2zCc";                                     // Put here your Ubidots TOKEN
const char* WIFI_SSID = "Josh";                                         // Put here your Wi-Fi SSID
const char* WIFI_PASS = "francisco";                                         // Put here your Wi-Fi password
const char* DEVICE_LABEL_TO_RETRIEVE_VALUES_FROM = "intensidad-de-luminica.";  // Replace with your device label
const char* VARIABLE_LABEL_TO_RETRIEVE_VALUES_FROM = "intensidad";       // Replace with your variable label

Ubidots ubidots(UBIDOTS_TOKEN, UBI_TCP);

/****************************************
 * Auxiliar Functions
 ****************************************/

// Put here your auxiliar functions

/****************************************
 * Main Functions
 ****************************************/

void setup() {
  Serial.begin(115200);
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
  // ubidots.setDebug(true); //Uncomment this line for printing debug messages
}
void loop() {
  /* Obtain last value from a variable as float using TCP */
  float value = ubidots.get(DEVICE_LABEL_TO_RETRIEVE_VALUES_FROM, VARIABLE_LABEL_TO_RETRIEVE_VALUES_FROM);

  // Evaluates the results obtained
  if (value != ERROR_VALUE) {
    Serial.print("Value:");
    Serial.println(value);
  }
  delay(5000);
}

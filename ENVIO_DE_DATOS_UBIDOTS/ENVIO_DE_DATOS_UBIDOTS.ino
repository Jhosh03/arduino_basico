
#include "Ubidots.h"

float v_cantidad;

const char* UBIDOTS_TOKEN = "BBFF-rnkdNzhiOWs6jvQ59YU13nYYAX2zCc";  // TOKEN DE UBIDOTS
const char* WIFI_SSID = "Redmi";      // NOMBRE DEL Wi-Fi SSID
const char* WIFI_PASS = "josh12345";      // CONTRASEÑA Wi-Fi
const char* DEVICE_LABEL_TO_RETRIEVE_VALUES_FROM = "iluminacion";  // NOMBRE DEL DISPOSITIVO EN UBIDOTS
const char* VARIABLE_LABEL_TO_RETRIEVE_VALUES_FROM = "cantidad";       // NOMBRE DE LA VARIABLE DEL DISPOSITIVO
#define out2 D5
#define out3 D6
int i=0;
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
  // ubidots.setDebug(true);  // Uncomment this line for printing debug messages
  pinMode(out2,OUTPUT);
  pinMode(out3, OUTPUT);
}

void loop() {
  v_cantidad= analogRead(0);
  
  ubidots.add("cantidad", v_cantidad);  // Change for your variable name


  bool bufferSent = false;
  bufferSent = ubidots.send("iluminacion");  // Will send data to a device label that matches the device Id
  float value = ubidots.get(DEVICE_LABEL_TO_RETRIEVE_VALUES_FROM, VARIABLE_LABEL_TO_RETRIEVE_VALUES_FROM);
  if (bufferSent) {
    // Do something if values were sent properly
    Serial.println("se han enviado los datos ");
  }
 if (value != ERROR_VALUE) {
    Serial.print("Valor recibido:");
    Serial.println(value);
  }
  if(value>=100){
    act_alarma();
    }
  delay(5000);
    
}

void act_alarma(){
  digitalWrite(out2,HIGH);
  digitalWrite(out3,HIGH);
  delay(1000);
  digitalWrite(out2,LOW);
  digitalWrite(out3,LOW);
  delay(1000);
  }

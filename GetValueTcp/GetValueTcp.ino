#include "Ubidots.h"
#include <LiquidCrystal_I2C.h>
int lcdColumns = 16;
int lcdRows = 2;  
const char* UBIDOTS_TOKEN = "BBFF-rnkdNzhiOWs6jvQ59YU13nYYAX2zCc";                                     // Put here your Ubidots TOKEN
const char* WIFI_SSID = "Redmi";                                         // Put here your Wi-Fi SSID
const char* WIFI_PASS = "jhosh12345";                                         // Put here your Wi-Fi password
const char* DEVICE_LABEL_TO_RETRIEVE_VALUES_FROM = "iluminacion";  // Replace with your device label
const char* VARIABLE_LABEL_TO_RETRIEVE_VALUES_FROM = "cantidad";       // Replace with your variable label

Ubidots ubidots(UBIDOTS_TOKEN, UBI_TCP);
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);
void setup() {
  Serial.begin(115200);
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
  pinMode(14,OUTPUT);
  pinMode(12,OUTPUT);
  lcd.init();                  
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("CANTIDAD: ");
}
void loop() {
  /* Obtain last value from a variable as float using TCP */
  float value = ubidots.get(DEVICE_LABEL_TO_RETRIEVE_VALUES_FROM, VARIABLE_LABEL_TO_RETRIEVE_VALUES_FROM);

  // Evaluates the results obtained
  if (value != ERROR_VALUE) {
    Serial.print("Value:");
    Serial.println(value);
    lcd.setCursor(1,1);
    lcd.print(value);
  }

    if(value<=300){
      digitalWrite(14,HIGH);
      digitalWrite(12,LOW);
      delay(100);
    }else{
      digitalWrite(14,LOW);
      digitalWrite(12,HIGH);
      delay(100);
      }
  delay(3000);
}

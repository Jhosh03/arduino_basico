#include "Ubidots.h"
#include <LiquidCrystal_I2C.h>

int lcdColumns = 16;
int lcdRows = 2;  
const char* UBIDOTS_TOKEN = "BBFF-rnkdNzhiOWs6jvQ59YU13nYYAX2zCc";  // Put here your Ubidots TOKEN
const char* WIFI_SSID = "Redmi";      // Put here your Wi-Fi SSID
const char* WIFI_PASS = "jhosh12345";      // Put here your Wi-Fi password
float v_cant;

Ubidots ubidots(UBIDOTS_TOKEN, UBI_TCP);
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

void setup() {
  Serial.begin(115200);
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
  lcd.init();                  
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("CANTIDAD: ");
}

void loop() {
  v_cant=analogRead(0);
  lcd.setCursor(1,1);
  lcd.print(v_cant);
  ubidots.add("cantidad",v_cant);  
  bool bufferSent = false;
  bufferSent = ubidots.send("iluminacion");  // Will send data to a device label that matches the device Id

  if (bufferSent) {
    Serial.println("Se han enviado los datos"); 
  }
  delay(5000);
}

#include <LiquidCrystal_I2C.h>
int lcdColumns = 16;
int lcdRows = 2;
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

void setup(){
  lcd.init();                  
  lcd.backlight();
}
void loop(){
  lcd.setCursor(1,0);
  lcd.print("Hola Bonita");
  delay(1000);
  lcd.clear(); 
  lcd.setCursor(1,1);
  lcd.print("Hola Bonita");
  delay(1000);
  lcd.clear(); 
}

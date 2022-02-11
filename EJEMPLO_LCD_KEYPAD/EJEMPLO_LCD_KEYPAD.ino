#include <LiquidCrystal.h> // libreria que permite controlar la pantalla LCD
#include <Keypad.h>
const int rs = 13, enable = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8; // Declaracion de los pines
LiquidCrystal lcd(rs, enable, d4, d5, d6, d7); // crea el objeto "lcd" de tipo LyquidCrystal
char pulsacion;       // almacena la tecla pulsada
int  contador = 1;    // cuenta el nivel del menu en el que se esta
const byte ROWS = 4;  //Cuatro Filas
const byte COLS = 4;  //Cuatro Columnas 
char keys[ROWS][COLS] = {
  {'7','8','9','/'},
  {'4','5','6','*'},
  {'1','2','3','-'},
  {'C','0','=','+'}
};
byte rowPins[ROWS] = {7,6,5,4}; //Puntos de conexion del teclado al arduino FILAS
byte colPins[COLS] = {3,2,1,0}; //Puntos de conexion del teclado al arduino COLUMNAS
Keypad Teclado1 = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //Configura el teclado
////////////////////////////////// Void Setup() ///////////
void setup() {
pinMode(A0,OUTPUT);  
pinMode(A1,OUTPUT); 
pinMode(A2,OUTPUT); 
pinMode(A3,OUTPUT); 
lcd.begin(16, 4); // inicializa la pantalla lcd, define el tamaño de la pantalla LCD
                     // en este caso es una pantalla 16x2
lcd.setCursor(0,0);  // los parametros deben ser dados en lcd.begin(columnas, lineas) 
lcd.print("BIENVENIDO");
delay(1000);
lcd.clear();                          
}
////////////////////////// Void loop() ///////////////////////
void loop() {
 pulsacion = Teclado1.getKey() ;  // Lee la tecla pulsada
 if (pulsacion != 0) {      
    lcd.clear();
    delay(100);
 } 
 if(contador == 4){ menu_4();accion_4();}
 if(contador == 3){ menu_3();accion_3();}
 if(contador == 2){ menu_2();accion_2();}
 if(contador == 1){ menu_1();accion_1();}
} ///////// Fin del void loop(), inician las Funciones///////////////

/////////////////////Intro_0 //////////////////////////////
void intro_0(){ 
 lcd.clear();  // Borra el  LCD
 lcd.setCursor(3,0);         // Se posiciona en la Columna 3, Fila 0
 lcd.print("BIENVENIDO ");
 lcd.setCursor(1,1);
 lcd.print("PRUEBA DE MENU");
 delay(4000);                // espera 4 segundos mostrando el intro
 lcd.clear();
}
/////////////////////Menu_1  //////////////////////////////////
void menu_1(){ 
   lcd.setCursor(0,0);
   lcd.print("MENU 1");
   lcd.setCursor(0,1);
   lcd.print("ON    >1  ");
   lcd.setCursor(10,1);
   lcd.print("OFF >2");   
   lcd.setCursor(0,2);
   lcd.print("INTER >3  "); 
   lcd.setCursor(10,2);
   lcd.print("MAS >+");
}
/////////////////////Accion 1 //////////////////////////////
void accion_1(){ 
  if(pulsacion == '1') digitalWrite(A0,HIGH);
  if(pulsacion == '2') digitalWrite(A0,LOW);
  if(pulsacion == '3') intermitente();
  if(pulsacion == '+') contador=2;
}
/////////////////////Menu_2  //////////////////////////////////
void menu_2(){
   lcd.setCursor(0,0);
   lcd.print("MENU 2"); 
   lcd.setCursor(0,1);
   lcd.print("MOTOR  >1   ");
   lcd.setCursor(8,1);
   lcd.print("TIEMPO>2");
   lcd.setCursor(0,2);
   lcd.print("MENU PRIN> C     ");
}
/////////////////////accion_2  //////////////////////////////////
void accion_2(){ 
  if(pulsacion == '1') contador=3;
  if(pulsacion == '2') contador=4;
  if(pulsacion == 'C') contador=1;
}
/////////////////////Menu_3  //////////////////////////////////
void menu_3(){ 
   lcd.setCursor(0,0);
   lcd.print("MENU 3"); 
   lcd.setCursor(0,1);
   lcd.print("Motor :          ");
   lcd.setCursor(5,1);
   lcd.print("Activado");
   digitalWrite(A2,HIGH);
   delay(500);  
   digitalWrite(A2,LOW);
   lcd.setCursor(0,2);
   lcd.print("MENU PRIN>C   <-- 0");
}
/////////////////////accion_3  //////////////////////////////////
void accion_3(){ 
  if(pulsacion == 'C') contador=1;
  if(pulsacion == '0') contador=2;
}
/////////////////////Menu_4 //////////////////////////////////
void menu_4(){ 
   lcd.setCursor(0,0);
   lcd.print("MENU 4"); 
   unsigned long tiempo1 = (millis()/1000);  
   lcd.setCursor(0,1);
   lcd.print("TIEMPO:            ");
   lcd.setCursor(8,1);
   lcd.print(tiempo1);  
   lcd.setCursor(0,2);
   lcd.print("MENU PRIN>C   <-- 0");
}
/////////////////////accion_4  //////////////////////////////////
void accion_4(){ 
  if(pulsacion == 'C') contador=1;
  if(pulsacion == '0') contador=2;
}
/////////////////////intermitente  //////////////////////////////////
void intermitente(){ 
  digitalWrite(A0,HIGH);
  delay(300);
  digitalWrite(A0,LOW);
  delay(300);
  digitalWrite(A0,HIGH);
  delay(300);
  digitalWrite(A0,LOW);
  delay(300);
}

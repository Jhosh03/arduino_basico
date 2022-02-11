/*Utilice la instrucción Do While para muestre una secuencia de números en consola
Mientras la instrucción sea menor o igual a su edad.
*/
int i=0;
void setup() {
Serial.begin(9600);
}

void loop() {
   do{
    i++;    
    Serial.println(i);
     delay(500);
    }while(i<25);
  Serial.println("Fin del ciclo:");
    i=0;
}

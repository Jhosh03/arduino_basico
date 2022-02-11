
/*Utilice la sentencia if para generar un menú que evalúe si una persona es mayor o
menor de edad, Si una persona es menor de edad se mostrara el mensaje en
consola “ejercicio 1: la persona es menor de edad” y por el contrario si es mayor
de edad muestre el mensaje en pantalla “ejercicio 1: la persona es mayor de edad”.
*/
int edad=0;

void setup() {
 Serial.begin(9600);
 Serial.println("Ingrese la edad");
}

void loop() {
  if(Serial.available()>0){ 
    edad=Serial.parseInt();
    Serial.println(edad);
    delay(500);

    if(edad<=17){
      Serial.println("Ejercicio1: la persona es menor de edad");
      }else {
        Serial.println("Ejercicio1: la persona es mayor de edad");
        }
  }
}


/*Utilice una sentencia for para recorrer un Array de tipo string con sus datos
[primer nombre, segundo nombre, primer apellido, segundo apellido], y los muestre
en la consola.
*/

String datos[]={"josue","francisco","bor","siney"};

void setup() {
Serial.begin(9600);
}

void loop() {
  
  for(int i=0; i<4;i++){
   Serial.println(datos[i]);
   delay(500);
  }
}

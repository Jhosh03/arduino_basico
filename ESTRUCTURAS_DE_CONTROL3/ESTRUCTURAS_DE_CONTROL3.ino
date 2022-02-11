/*Utilice una estructura switch case para realizar un menú con 5 opciones que al
seleccionarlas deberán mostrar el mensaje en consola con el siguiente orden:
1. “Electrónica analógica”
2. “Electrónica digital”
3. “Microcontroladores”
4. “Rapsberry Pi”
5. “IoT”
*/
int opciones =0;

void setup() {
 Serial.begin(9600);
 Serial.println("Bienvenido seleccione el curso al que desee asignarse: ");
 Serial.println("1. Electronica analogica");
 Serial.println("2. Electronica digital");
 Serial.println("3. Electronica Microprocesadores");
 Serial.println("4. IoT");
}

void loop() {
  if(Serial.available()>0){
     opciones=Serial.parseInt();
     
     switch(opciones){
      case 1: Serial.println("Bienvenido al curso de electronica analogica");
      break;
      case 2: Serial.println("Bienvenido al curso de electronica digital");
      break;
      case 3: Serial.println("Bienvenido al curso de electronica microprosesadores");
      break;
      case 4: Serial.println("Bienvenido al curso de electronica IoT");
      break;
      default: Serial.println("Opcion invalida utilice un numero de 1-4");
      break;
      }
    }
}

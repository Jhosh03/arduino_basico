//declaracion de variables.
int MOTOR =7;
int VERDE=10;
int AMARILLO=11;
int ROJO= 12;
int sensor=1;
int medicion=0;
int temperatura=0;
// configuracion de los puertos a utilizar
void setup() {
 Serial.begin(9600); 
 pinMode(sensor,INPUT);  
 pinMode(MOTOR,OUTPUT); 
 pinMode(VERDE,OUTPUT); 
 pinMode(AMARILLO,OUTPUT); 
 pinMode(ROJO,OUTPUT); 
 Serial.println("SENSOR DE TEMPERATURA:");
 delay(500);
}
void loop() {
  medicion=analogRead(sensor);   //declaracion de la lectura del sensor
  temperatura = ((medicion / 1023.0) * 5000)/10; // calculo para los grados centigrados
  Serial.print("TEMPERATURA EN GRADOS CENTIGRADOS: ");// se muestra en el monitor serial
  Serial.println(temperatura);
  if(temperatura>=0&&temperatura<=17){verde();delay(100);}// rangos de temperatura
  if(temperatura>=18&&temperatura<=27){amarillo();delay(100);}   
  if(temperatura>=28){rojo();delay(100);}  
}
void verde(){
    digitalWrite(VERDE,HIGH);
    digitalWrite(AMARILLO,LOW);// funcion para mostrar el color verde
    digitalWrite(ROJO,LOW);    // y activar el ventilador.    
    digitalWrite(MOTOR,LOW); 
  }

void amarillo(){
    digitalWrite(VERDE,LOW);
    digitalWrite(AMARILLO,HIGH);  //funcion para el color amarillo.
    digitalWrite(ROJO,LOW);
    digitalWrite(MOTOR,LOW); 
  }
void rojo(){
    digitalWrite(VERDE,LOW);
    digitalWrite(AMARILLO,LOW); // funcion para el color rojo.
    digitalWrite(ROJO,HIGH);
    digitalWrite(MOTOR,HIGH); 
  }    

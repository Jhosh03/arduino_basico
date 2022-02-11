
int pulsador1=5;
int pulsador2=6;
int pulsador3=7;
int pulsador4=8;
int pulsador5=9;
int valor1=0;
int valor2=0;
int valor3=0;
int valor4=0;
int valor5=0;       
void setup() {
Serial.begin(9600);
pinMode(pulsador1,INPUT);  
}

void loop() {
  valor1=digitalRead(pulsador1);
  valor2=digitalRead(pulsador2);
  valor3=digitalRead(pulsador3);
  valor4=digitalRead(pulsador4);
  valor5=digitalRead(pulsador5);
   if(valor1==HIGH){
    Serial.println("Lunes");
    }
 if(valor2==HIGH){
    Serial.println("Martes");
    }
 if(valor3==HIGH){
    Serial.println("Miercoles");
    }
 if(valor4==HIGH){
    Serial.println("Jueves");
    }

 if(valor5==HIGH){
    Serial.println("Viernes");
    }   
  delay(1000);
}

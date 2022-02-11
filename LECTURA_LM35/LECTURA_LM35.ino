int sensorLM35 =A1;
int ledrojo=5;
int ledverde=6;
void setup() {
 Serial.begin(9600);  
 pinMode(sensorLM35,INPUT);
 pinMode(ledrojo,OUTPUT);
 pinMode(ledverde,OUTPUT);
}

void loop() {
  int valor =analogRead(sensorLM35);
  float milivolts =(valor/1023.0)*5000; 
  float centigrados =milivolts/10;
  Serial.println(centigrados);
  delay(500); 
  if(centigrados>40){
     Serial.println("temperatura alta");
     digitalWrite(ledverde,LOW); 
     digitalWrite(ledrojo,HIGH); 
     delay(500);   
    }else{
      Serial.println("temperatura baja");
      digitalWrite(ledrojo,LOW); 
      digitalWrite(ledverde,HIGH); 
      delay(500);
      }
}

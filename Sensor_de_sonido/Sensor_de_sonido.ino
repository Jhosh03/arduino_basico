int MIC=8;
int LED=7;
int valor;
int estado;
void setup()
{
  pinMode(MIC, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  valor=digitalRead(MIC);
  if(valor==HIGH){
    estado=digitalRead(LED);
    digitalWrite(LED, !estado);
    Serial.println("Sonido detectado");
    delay(500); 
  }  
}

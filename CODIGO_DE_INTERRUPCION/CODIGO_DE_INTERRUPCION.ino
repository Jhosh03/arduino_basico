int L1=9;
int L2=10;
int L3=11;
int STOP;
int START;
void setup(){
pinMode(L1,OUTPUT);
pinMode(L2,OUTPUT);
pinMode(L3,OUTPUT);
pinMode(STOP,INPUT);
pinMode(START,INPUT); 
}
void loop(){ 
  START=digitalRead(6);
  STOP=digitalRead(7);
  
  if(START==HIGH){ 
  while(STOP!=HIGH){
  STOP=digitalRead(7);     
  secuencia(); 
  }
  }
    digitalWrite(L1,LOW);
    digitalWrite(L2,LOW);
    digitalWrite(L3,LOW); 
}
void secuencia(){
  digitalWrite(L1,HIGH);
  delay(100);
  digitalWrite(L1,LOW);
  delay(100);
  digitalWrite(L2,HIGH);
  delay(100);
  digitalWrite(L2,LOW);
  delay(100);
  digitalWrite(L3,HIGH);
  delay(100);
  digitalWrite(L3,LOW);
  delay(100);
  }
  

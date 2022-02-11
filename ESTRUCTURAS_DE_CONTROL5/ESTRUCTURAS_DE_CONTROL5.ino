/*Utilice la estructura de control que considere adecuada para diseñar un programa
que al ingresar cuatro notas nos devuelva el promedio de las mismas y muestre el
resultado en la consola.
*/
int notaA=0;
int notaB=0;
int notaC=0;
int notaD=0;
int sumatoria=0;
int promedio= 0;
void setup(){
  Serial.begin(9600);
  }

void loop()
{
  Serial.println("ingrese la nota 1");
  notaA=Serial.parseInt();
  delay(3000);
  Serial.println("ingrese la nota 2");
  notaB=Serial.parseInt();
  delay(3000);
  Serial.println("ingrese la nota 3");
  notaC=Serial.parseInt();
  delay(3000);
  Serial.println("ingrese la nota 4");
  notaD=Serial.parseInt();
  delay(3000);

    sumatoria= (notaA+notaB)+(notaC+notaD);
    promedio= (sumatoria/4);
    Serial.print("El promedio es: ");
    Serial.println(promedio);
    delay(2000);
    notaA=0;
    notaB=0;
    notaC=0;
    notaD=0;
    sumatoria=0;
    promedio=0;
    
}

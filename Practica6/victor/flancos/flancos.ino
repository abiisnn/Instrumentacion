 unsigned long tiempoAnt=0;
 int periodo=1000;
 int pulsos=0;
 int tiempo=0;
void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2),contarPulso,RISING);
}

void loop() {
  // put your main code here, to run repeatedly:

     if(millis()-tiempoAnt>=periodo)
      {
        tiempo++;
        Serial.print("Tiempo:");
        Serial.println(tiempo);
        tiempoAnt=millis();
      }
      if(tiempo==10)
      {
        
        Serial.print("Pulsaciones por minuto:");
        Serial.println(pulsos*6);
        tiempo=pulsos=0;
      }
     
}
void contarPulso()
{
      pulsos++;
}

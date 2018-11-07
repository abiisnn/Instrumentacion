 const int tiempoImpresion=2;
 const int p=1000;
 unsigned long tiempoAnt=0;
 int tiempo=0;
 int iniPeriodo=0;
 int finPeriodo=0;
 float periodo=0;
 float ppm;


void setup() {  
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2),contarPulso,RISING);
}

void loop() {
   if(millis()-tiempoAnt>=p)
      {
        tiempo++;
        tiempoAnt=millis();
      }
      if(tiempo==tiempoImpresion)
      {
        Serial.print("Pulsaciones por minuto:");
        Serial.println((int)ppm);
        tiempo=0;
      }

}
void contarPulso()
{
    finPeriodo=millis();
    periodo=(float)(finPeriodo-iniPeriodo);
    iniPeriodo=millis();
    ppm=60000/periodo;
    
    //Serial.print("Periodo:");
    //Serial.println(periodo);
    //Serial.print("Pulsaciones por minuto:");
    //Serial.println((int)ppm);
}

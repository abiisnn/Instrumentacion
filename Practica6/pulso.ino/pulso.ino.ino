//#include <SoftwareSerial.h>
//SoftwareSerial BTserial(3, 2); // (TX,RX)
// Especifico que  
int in = 13;
float tiempo = 0, numPulso = 0;
void setup() 
{
  // Aqui especifico que pin quiere tener de entrada
  pinMode(in, INPUT);
  //BTserial.begin(9600);
  Serial.begin(9600);
}

void loop() 
{
  tiempo++;
  //BTserial.flush();
  int sensorValue = digitalRead(in);
  // Imprime en la computadora
  Serial.println(sensorValue);
  if(sensorValue == 0)
  {
    numPulso++;
  }
  //Serial.println("Num Pulso:");
  //Serial.println(numPulso);
  float pulsar = (numPulso / tiempo )* 6.0;
  Serial.println("Pulsaciones por minuto:");
  Serial.println(pulsar);
  // Tiempo que se espera para cada lectura
  delay(100);
}

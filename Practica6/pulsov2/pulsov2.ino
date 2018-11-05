#include <SoftwareSerial.h>
// Especifico que  
#define TxD 6
#define RxD 7
#define KEY 4
#define VCC 5
#define in  13
float numPulso = 0;
int tiempo = 0;

SoftwareSerial Bluetooth(TxD, RxD); //(6, 7)

void setup() 
{
  Bluetooth.begin(9600);
  // Aqui especifico que pin quiere tener de entrada
  pinMode(KEY, OUTPUT);
  pinMode(VCC, OUTPUT);
  pinMode(in, INPUT);

  digitalWrite(KEY, HIGH);
  digitalWrite(VCC, LOW);
  digitalWrite(VCC, HIGH);
  
  Serial.begin(9600);
}

void loop() 
{
  int sensorValue = digitalRead(in);
  char comand = Bluetooth.read();

  switch(comando){
    tiempo = (millis()/1000);
    if(sensorValue == 0)
    {
      numPulso++;
    }
  
    if(tiempo % 10 == 0)
    {
      float pulsar = numPulso * 6.0;
      Serial.print("Pulsaciones por minuto: ");
      Serial.println(pulsar);
      Bluetooth.print("Pulsaciones por minuto: ");
      Bluetooth.println(pulsar);
      numPulso = 0;
    }
    delay(1000);
    break;
  }
  
}

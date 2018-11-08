//BT RxD = TX1 Arduino
//BT TxD = RX1 Arduino
//BT GND = GND Arduino
//BT VCC = 5V Arduino
/*VARIABLES PARA LA LECTURA DE PULSOS*/
unsigned long tiempoAnt=0;
int tiempo=0;
int iniPeriodo=0;
int finPeriodo=0;
float periodo=0;
float pulsos;

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600); //Bluetooth
  Serial.begin(9600); //PC
  pinMode(2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2),contar,RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte val = map(digitalRead(2),0,1,50,150);    //Mapeamos segun el alto del canvas de la apk
  Serial1.write(val);                              //Serial1.write envia un byte en cada loop 
  delay(400); 
  
  if(millis()-tiempoAnt>=1000)
  {
    tiempo++;
    tiempoAnt=millis();
  }
  
  if(tiempo == 2)
  {
    if(pulsos<120){
      Serial.print("Pulsaciones por minuto: ");
      Serial.println((int)pulsos);
      Serial1.println((int)pulsos);
    }
    tiempo=0;
  } 
  //delay(400);
}

void contar()
{
  finPeriodo=millis();
  periodo=(float)(finPeriodo-iniPeriodo);
  iniPeriodo=millis();
  //1 minuto
  pulsos=60000/periodo;
}

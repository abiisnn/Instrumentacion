 /*VARIABLES PARA CONEXION BT*/
#include <SoftwareSerial.h>

/*
  Parametros de SoftwareSerial(rxPin,txPin,inverse_logic);
  rxPin donde se recibe el dato
  txPin: Pin donde se transmite el dato
*/
const byte rxPin = 10;
const byte txPin = 11;
const int led=13;
String cadena="";
boolean mensajeCompleto=false;
SoftwareSerial miBT(rxPin,txPin);
 
 /*VARIABLES PARA LA LECTURA DE PULSOS*/
 const int tiempoImpresion=2;
 const int p=1000;
 unsigned long tiempoAnt=0;
 int tiempo=0;
 int iniPeriodo=0;
 int finPeriodo=0;
 float periodo=0;
 float ppm;


void setup() {  
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  Serial.println("Listo:");
  miBT.begin(38400);
  
  attachInterrupt(digitalPinToInterrupt(2),contarPulso,RISING);
}

void loop() {

   miBT.listen();
   
   if(millis()-tiempoAnt>=p)
      {
        tiempo++;
        tiempoAnt=millis();
      }
      if(tiempo==tiempoImpresion)
      {
        Serial.print("Pulsaciones por minuto:");
        Serial.println((int)ppm);
        miBT.print("Pulsaciones por minuto:");
        miBT.println((int)ppm);
        tiempo=0;
      }

      
      
      
      
      
      /*CODIGO PARA LEER DEL BT*/
      while (miBT.available())
      {
         // Obtiene el siguiente byte que se recibió, este es un carácter
         char comando = (char)miBT.read();
         cadena+=comando;
    
          mensajeCompleto=true;
      }

      if(mensajeCompleto)
      {
         Serial.print("Recibido:");
         Serial.println(cadena);
         if(cadena=="ENCENDER")
          digitalWrite(led,HIGH);
          if(cadena=="APAGAR")
          digitalWrite(led,LOW);
         cadena="";
         mensajeCompleto=false;
      }
      // Esperamos un tiempo de 20 milisegundos
      //delay(200);

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

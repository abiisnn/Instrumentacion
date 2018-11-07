float Pulso; 
float Tiempo = 0;
float Frecuencia = 0;
int NumeroPulsos = 0;
void setup () 
{ 
Serial.begin (9600); 
} 

void loop () 
{ 
Pulso = pulseIn (2, HIGH, 15000); 
Tiempo = Pulso / 1000000;
if (Tiempo > 0.001)
{
Serial.print ("Duracion del pulso: "); 
Serial.print (Tiempo); 
Serial.println (" segundos"); 
Serial.println (" "); 
}

Frecuencia = 1 / Tiempo;

NumeroPulsos = Frecuencia * 360;
Serial.print ("Numero de pulsos/minut0: "); 
Serial.println (NumeroPulsos); 
Serial.println (" ");
Serial.println (" ");

delay (1000);
}

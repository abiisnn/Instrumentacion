double grados, bits[8], decimal;
const int a = 22, b = 24, c = 26, d = 28, e = 30, f = 32, g = 34, h = 36, salida = 9;
const double resolucion = 5.00/255.00;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(a, INPUT);
  pinMode(b, INPUT);
  pinMode(c, INPUT);
  pinMode(d, INPUT);
  pinMode(e, INPUT);
  pinMode(f, INPUT);
  pinMode(g, INPUT);
  pinMode(h, INPUT);
  pinMode(salida, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  bits[0] = digitalRead(a);
  bits[1] = digitalRead(b);
  bits[2] = digitalRead(c);
  bits[3] = digitalRead(d);
  bits[4] = digitalRead(e);
  bits[5] = digitalRead(f);
  bits[6] = digitalRead(g);
  bits[7] = digitalRead(h);

  decimal = bits[0] + bits[1]*2 + bits[2]*4 + bits[3]*8 + bits[4]*16 + bits[5]*32 + bits[6]*64 + bits[7]*128;
  
  //Serial.println(decimal);
  
  digitalWrite(salida, HIGH);
  delay(1000);
  digitalWrite(salida, LOW);
  delay(1000);

  
  grados = resolucion*decimal*10;
  Serial.print("Grados: ");
  Serial.print(grados);
  Serial.println("°C");
  delay(100);
}

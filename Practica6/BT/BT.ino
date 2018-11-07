//BT RxD = TX1 Arduino
//BT TxD = RX1 Arduino
//BT GND = GND Arduino
//BT VCC = 5V Arduino
const int in = 13;


void setup() {
  // put your setup code here, to run once:
  Serial1.begin(38400); //Bluetooth
  Serial.begin(9600); //PC
  pinMode(in, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Recibido");
  Serial1.print("Recibido");
  delay(50);
}

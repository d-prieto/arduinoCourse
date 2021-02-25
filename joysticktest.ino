const int pinBoton = 3; 
const int pinEjeY = A1; 
const int pinEjeX = A0; 
 
void setup() {
  pinMode(pinBoton, INPUT);
  digitalWrite(pinBoton, HIGH);
  Serial.begin(9600);
}
 
void loop() {
  Serial.print("Boton:  ");
  Serial.print(digitalRead(pinBoton));
  Serial.print("\n");
  Serial.print("Eje X: ");
  Serial.print(analogRead(pinEjeX));
  Serial.print("\n"); //esto es un salto de linea
  Serial.print("Eje Y: ");
  Serial.println(analogRead(pinEjeY));
  Serial.print("\n\n");
  delay(150);
}

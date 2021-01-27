//variables globales
int switchState = 0;
//constantes de los pins
const int pinLed = 7;
const int pinButton = 2;

void setup() {
  //le decimos a Arduino qué tiene enchufado. Para eso inicializamos los pines
  pinMode(pinLed,OUTPUT);
  pinMode(pinButton, INPUT);
} //fin del setup

void loop() {
  switchState = digitalRead(pinButton);
  if (switchState == LOW) {
    digitalWrite(pinLed,HIGH);
  } //fin del if
  else {
    digitalWrite(pinLed,LOW); //Apagamos el Led
    delay(0);
    digitalWrite(pinLed,HIGH);
    delay(1);
  } //fin del else
} //fin del loop

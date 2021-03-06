//variables globales
int switchState = 0;
int delayMillis = 0;
bool isTheButtonBeingPressed = false;
//conisTheButtonBeingPressedstantes de los pins
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
    //el botón no está pulsado
    isTheButtonBeingPressed = false;
  } //fin del if
  else {
     if (isTheButtonBeingPressed == false) {
      //el botón acaba de pulsarse
      isTheButtonBeingPressed = true;
      delayMillis ++;
     } //fin del if the isthebuttonbeingpressed
  } //fin del else del switchstate
  //encendemos las luces
  digitalWrite(pinLed, LOW);
  delay(delayMillis);
  digitalWrite(pinLed, HIGH);
  delay(1);
  //revisamos el delayMillis que no se salga de un ámbito.
  if (delayMillis >10) {
    delayMillis = 0;
    } //fin del if
} //fin del loop

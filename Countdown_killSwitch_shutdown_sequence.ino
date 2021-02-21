/*

   Nombre: David Prieto
   Fecha: 21/02/2021
   Este programa es una modificación del Reloj digital (proyecto del starter kit)

   Al pulsar el botón comienza a encender los leds. Al volver a pulsarlo, se apagan en el orden inverso de encenderse. 
   Al cambiar de pulsación sigue encendiendo o apagando donde lo dejó. 
   Ignora el tiempo que se esté puldando.




*/

// constante del pin del botón.
const int switchPin = 3;
const int startingOutputPin = 4; // variable para guardar el primer pin a activar.
const int finishingOutputPin = 10;  //constante para guardar el último pin a activar.

unsigned long previousTime = 0; // store the last time an LED was updated
unsigned long currentTime = 0; // store the current time
int switchState = 0; // the current switch state

bool shouldLightPins = false;
bool isTheButtonBeingPressed = false;

int currentPin = startingOutputPin; // en esta variable guardamos el valor del pin que queremos activar

// 600000 = 10 minutes in milliseconds
long interval = 600; // interval at which to light the next LED

void setup() {
  // utilizamos un bucle for para iniciar los leds
  for (int x = startingOutputPin; x <= finishingOutputPin; x++) {
    pinMode(x, OUTPUT);
  }
  // Pin del botón como input
  pinMode(switchPin, INPUT);
  // Iniciamos la comunicación con el ordenador por si necesitamos resolver cualquier error.
  Serial.begin(9600);
}

void loop() {
  checkButton();
  if (shouldLightPins) {
    lightPins();
  }
  else {
    turnOffSequence();
  }

}

void lightPins() {
  // Miramos la hora y la guardamos
  currentTime = millis();

  // Comparamos la hora con la "hora anterior" y revisamos si ha pasado tiempo suficiente (interval)
  if (currentTime - previousTime > interval) {
    // Si ya ha pasado el tiempo de intervalo, decimos que la última vez que se activó esto es ahora
    previousTime = currentTime;
    // encendemos el pin que le toca
    digitalWrite(currentPin, HIGH);
    // aumentamos la variable del pin para que luego le toque al siguiente pin
    currentPin++;
    // En caso de que se exceda el límite de los pines, se queda automáticamente en el número +1 para evitar errores y reinicios extraños
    if (currentPin > finishingOutputPin) {
      currentPin = finishingOutputPin;
    }
  }
}

void checkButton() {
  // leemos el botón y lo guardamos en switchtate
  switchState = digitalRead(switchPin);
  Serial.println(switchState);
  if (switchState == HIGH) {
    if (isTheButtonBeingPressed == false) {
      shouldLightPins = !shouldLightPins;
      isTheButtonBeingPressed = true;
    }
  }
  else {
    isTheButtonBeingPressed = false;
  }
}

void turnOffSequence() {
  // Miramos la hora y la guardamos
  currentTime = millis();
  if (currentTime - previousTime > interval) {
    // Si ya ha pasado el tiempo de intervalo, decimos que la última vez que se activó esto es ahora
    previousTime = currentTime;
    // apagamos el pin que le toca
    digitalWrite(currentPin, LOW);
    // disminuimos la variable del pin para que luego le toque al siguiente pin (disminuyendo)
    currentPin--;
    // En caso de que se exceda el límite de los pines, se queda automáticamente en el mínimo
    if (currentPin < startingOutputPin) {
      currentPin = startingOutputPin;
    }
  }
}

/*
 * 
 * Nombre: David Prieto
 * Fecha: 21/02/2021
 * Este programa es una modificación del blink
 * Sirve

*/

//en este caso los pines de los leds estan del 4 al 10 y se inicializan todos a la vez

void setup() {
  //bucle for para inicializar todos los leds
    for (int x = 4; x < 11; x++) {
    pinMode(x, OUTPUT);
  }
  /*
   * Esto es equivalente a escribir lo siguiente:
   * pinMode(4, OUTPUT);
   * pinMode(5, OUTPUT);
   * pinMode(5, OUTPUT);
   * pinMode(7, OUTPUT);
   * pinMode(8, OUTPUT);
   * pinMode(9, OUTPUT);
   * pinMode(10, OUTPUT);
   * Pero es más fácil de cambiar si en vez del 4 al 10 fuera del 5 al 11 solo hay que cambiar los parámetros del for
   */
}

void loop() {
  //utilizo también un bucle for para encender los leds
  for (int x = 4; x < 11; x++) {
    digitalWrite(x, HIGH);
  }
  delay(1000); //delay del rato que están encendidos los leds
  //y, como no, utilizo un bucle for para apagar los leds
   for (int x = 4; x < 11; x++) {
    digitalWrite(x, LOW);
  }
  delay(1000);  //delay del rato que están apagados los leds
}

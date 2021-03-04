# Variaciones de Joystick

## Introducción

Para ahondar más en el sensor que hemos estado trabajando (el Joystick) vamos a hacer una serie de variaciones. Comenzaremos por las más sencillas y la más compleja que quiero hacer es un pequeño juego donde hay que detectar una posición determinada al azar con el joystick usando sonido. 

## Tareas 

* Hacer estos ejercicios y subir las fotografías y el código. 
* Crear una modificación personal de alguno de estos programas. 

_se pueden utilizar estas variaciones para completar tareas anteriores_

## Programas base 

### Código plantilla 

Este es el código plantilla para todos estos proyectos. Después sólo cambiaré elementos específicos. Está realizado a partir de [plantilla.ino](https://github.com/d-prieto/arduinoCourse/blob/main/plantilla.ino) y también a partir del proyecto de prueba del Joystick para definir las variables. 

```C++
/*
*  Documentación del programa 
*  Autore: 
*  Fecha:
*  Código referencia: (url)
*  Descripción del programa:
*  Hardware necesario:
*/

//Includes

//Definiciones de constantes de pines
const int pinBoton = 3; 
const int pinEjeY = A1; 
const int pinEjeX = A0; 

//Definición de variables globales 

void setup() {
//inicializaciones
  pinMode(pinBoton, INPUT);
  digitalWrite(pinBoton, HIGH);
  Serial.begin(9600);
//código que se ejecuta solo una vez. Calibraciones  
}

void loop() {
 //código que se repite una y otra vez. Recuerda colocar las funciones que hagan falta para que sea más claro.  
}  
```

## Proyecto de LED que se enciende cuando pulsas el botón del joystick 

### Nombre del archivo proyecto 

JoystickVariacion01

### Hardware

Tengo un led conectado en este caso al pin 9. Podeis usar este pin o cualquier otro. 

![](https://raw.githubusercontent.com/d-prieto/arduinoCourse/main/Images/Joystick%20con%201%20led.JPG)

Esta es la variación que me ha pasado Alba 

![](https://raw.githubusercontent.com/d-prieto/arduinoCourse/main/Images/Joystick%20Alba%20con%20led.JPG)

### Software 

Aquí explicaré primero las cosas que voy a añadir y cómo queda el código al final. 

#### Inicio del programa

Primero añadiré a la plantilla mi nombre, la fecha y lo que hace el programa

```C++
/*
*  Documentación del programa 
*  Autore: David Prieto
*  Fecha: 28/02/2021
*  Código referencia: https://github.com/d-prieto/arduinoCourse/edit/main/Variaciones%20de%20Joystick.md
*  Descripción del programa: Este programa cuando se pulsa el botón del joystick se enciende un LED. Si no está pulsado el led está apagado. 
*  Hardware necesario: Joystick. Led. Resistencia de 220 Ohms
*/

```
#### Variables

Después añado en la sección de variables (antes del setup y el loop) las nuevas variables que necesito. Una de un pin y otra del estado del botón. En este caso para la definición de variables, para facilitar la comprensión las escribiré en castellano. Así que en vez de SwitchState estoy utilizando EstadoBoton

```C++
const int pinLed = 9;

 int estadoBoton = 1;
```
#### Setup 

En el Setup sólo tenemos que añadir una línea para inicializar el LED: 

```C++
 pinMode(pinLed, OUTPUT);
```
#### Loop 

Ahora el loop. Este loop lo hemos hecho varias veces. Necesitamos que 
a) Lea el botón
b) Decida si encender el led se enciende o no. 

Para lo primero usamos lo que hemos usado otras veces: 

```C++
 estadoBoton= digitalRead(pinBoton);
```
Recordad que digitalRead puede dar o 1 (HIGH) o 0 (LOW) y sólo esos 2 valores posibles. 

Si tuvieramos algún problema, añadiríamos después un Serial.println(estadoBoton) para ver en el PC qué señal recibe el botón y si está bien conectado (debería leer 0 cuando está pulsado y 1 cuando está sin pulsar). 

Después tenemos el control de flujo (el portero de discoteca que hemos mencionado algunas veces) if. Lo que ocurre es que este botón, a diferencia de los que solemos montar normalmente funciona que "LOW" es cuando está pulsado y no al revés. Esto depende de cómo sea la estructura eléctrica de la conexión del botón. 

En el caso de que sea "LOW" encenderemos el LED usando "digitalWrite" y le indicaremos el pin y HIGH para que lo encienda. En el else haremos lo contrario para que, si el botón no está pulsado, apague el LED

```C++
  if (estadoBoton == LOW){
  digitalWrite(pinLed, HIGH);
 }
 else{
  digitalWrite(pinLed, LOW);
 }
```
#### Código completo 

El código entero está aquí: https://github.com/d-prieto/arduinoCourse/blob/main/JoystickLedButton.ino


## Proyecto de LED que se enciende cuando llevas el joystick cerca del punto máximo en el eje X 

Este proyecto parte del mismo Hardware que tenemos pero vamos a revisar uno de los 2 ejes, el eje X. Después haremos otras acciones en el eje Y. Pero vamos despacio. 

Este proyecto parte del anterior así que iré mencionando las cosas que hay que **añadir** y también las que hay que **quitar**. Seguiremos el mismo orden que en el ejercicio anterior, salvo por la parte de que el código completo no estará disponible. (Se pide que los alumnos seáis capaces de montarlo por vuestra parte a partir de los anteriores ejercicios y subirlo correctamente). 

### Nombre del archivo proyecto 

JoystickVariacion02

### Hardware

Utiliza el mismo Hardware que el ejercicio anterior. 

### Software 

#### Inicio del programa

Primero añadiré a la plantilla mi nombre, la fecha y lo que hace el programa

```C++
/*
*  Documentación del programa 
*  Autore: David Prieto
*  Fecha: 28/02/2021
*  Código referencia: https://github.com/d-prieto/arduinoCourse/blob/main/JoystickLedButton.ino
*  Descripción del programa: Este programa cuando el Joystick llega a determinado rango de valores en el EjeX ilumina el LED. Si no, el led se encuentra apagado. 
*  Hardware necesario: Joystick. Led. Resistencia de 220 Ohms
*/
```

#### Variables

Aquí sí es cierto que tenemos que guardar el pin del led, pero no necesitamos el **estadoBoton** para nada, así que lo borraremos. En su lugar vamos a utilizar una variable que le llamaremos **valorEjeX**

```C++

 int valorEjeX = 0; 
```
#### Setup 

Aquí no necesitamos cambiar el setup

#### Loop 

En este caso vamos a hacer algo similar que con el botón. Leeremos el sensor del ejeX. Pero en vez de usar DigitalRead, usaremos AnalogRead. DigitalRead (lectura digital traduciendo literalmente) nos da valores de 0 o 1. Pero AnalogRead nos da valores entre 0 y 1023. En este caso el valor 0 es el extremo izquierdo y el valor 1023 es el valor moviendo hasta el tope de la derecha el Joystick. 

```C++
 valorEjeX = analogRead(pinEjeX);
```

Después haremos un control de flujo (if) con la condición de que supere una determinada franja. En este caso he puesto el valor 800, pero **podéis probar otros valores para ver qué ocurre**. 

```C++
 
 if (valorEjeX > 800){
  digitalWrite(pinLed, HIGH);
 }
 else{
  digitalWrite(pinLed, LOW);
 }
```

El valor máximo que puede alcanzar el ejeX es 1023, con lo cual hasta entonces podemos ir viendo su sensibilidad. Con 800 el intervalo es bastante sensible. Y he visto que poniendo ==1023 no llego al tope físico del mecanismo sino que lo supero. 

## Proyecto de Joystick que solo ilumina cuando llega a un rango determinado del eje X 

Aquí hemos mirado un umbral (que sea superior a 800) pero vamos a hacer otra variación donde vamos a incluir 2 límites. Un mínimo y un máximo

### Nombre del archivo proyecto 

JoystickVariacion03


### Hardware

Utiliza el mismo Hardware que el ejercicio anterior. 

### Software 

#### Inicio del programa

Primero añadiré a la plantilla mi nombre, la fecha y lo que hace el programa. En este caso "determinado rango de valores" sigue siendo válido. Así que lo podemos dejar. 

```C++
/*
*  Documentación del programa 
*  Autore: David Prieto
*  Fecha: 28/02/2021
*  Código referencia: https://github.com/d-prieto/arduinoCourse/blob/main/JoystickLedButton.ino
*  Descripción del programa: Este programa cuando el Joystick llega a determinado rango de valores en el EjeX ilumina el LED. Si no, el led se encuentra apagado. 
*  Hardware necesario: Joystick. Led. Resistencia de 220 Ohms
*/
```

#### Variables

No tenemos nada nuevo respecto al ejercicio anterior. 

#### Setup 

Aquí no necesitamos cambiar el setup

#### Loop 

Aquí sí vamos a tocar la parte de la condición del if. **El resto quedará igual**. Lo que vamos a hacer es que vaya sólo entre determinados valores. Para ello usaremos el operador Y (&&). Por ejemplo vamos a hacer que sea mayor que 100 y menor que 200 para que encienda el LED de la siguiente forma:


```C++
 
 if (valorEjeX > 100 && valorEjeX < 200){
  digitalWrite(pinLed, HIGH);
 }
 else{
  digitalWrite(pinLed, LOW);
 }
```


## Proyecto de Joystick que cuando llegas a un punto determinado suena una pequeña nota en el altavoz

Este proyecto sigue avanzando a partir del anterior. Vamos a utilizar aquí el eje Y, mientras el eje X sigue encendiendo el led. 

### Hardware

Añado el altavoz al pin 8. En este caso para poner el altavoz basta conectarlo si necesidad de resistencia. Uno de los palos del altavoz se conecta al pin 8 y otro se conecta al Ground.

![](https://raw.githubusercontent.com/d-prieto/arduinoCourse/main/Images/Joystick%20con%20Led%20y%20altavoz.JPG)

En mi caso como el piezo se lo dejé a alguien que se le rompió el suyo, utilizo otro altavoz conectándolo con un cable negro al Ground y con un cable blanco al pin 8. 

Dejo igualmente el Joystick y el led donde estaban dado que siguen funcionando en este sketch. 

### Software

#### Inicio del programa

Aquí sí caben modificaciones en la parte del hardware y en la descripción. 

```C++
/*
*  Documentación del programa 
*  Autore: David Prieto
*  Fecha: 29/02/2021
*  Código referencia: https://github.com/d-prieto/arduinoCourse/blob/main/JoystickLedButton.ino
*  Descripción del programa: Este programa cuando el Joystick llega a determinado rango de valores en el EjeX ilumina el LED. Si no, el led se encuentra apagado. En el ejeY además si llega a determinado umbral, el altavoz hará un breve pitido. 
*  Hardware necesario: Joystick. Led. Resistencia de 220 Ohms
*/
```
#### Variables

Tenemos un pin nuevo así que una nueva constante para ese pin:

```C++

 const int pinAltavoz = 8; 
```


Añadimos la variable para guardar el eje Y. Le llamaremos valorEjeY, como la del ejeX podrá guardar valores entre 0 y 1023

```C++

 int valorEjeY = 0; 
```

También añado un par de variables que son la frecuencia del sonido (440 hertzios, un LA) y una duración del sonido (en milisegundos) para probar. 

```C++

 int frecuenciaNota = 440; 
 int duracionSonido = 250;
 
```

#### Setup 

Aquí no necesitamos cambiar el setup

#### Loop 

Este loop mantiene lo anterior, leer los datos del eje X y hacer algo con ello. De momento lo podemos dejar tal cual y poner después el eje Y. Cuando tengamos ese valor lo comparamos con un valor (por ejemplo que sea menor que 223) y en ese caso, ponemos un tone. Tone es la funcion que necesitamos para crear un sonido y necesita el pin, la frecuencia de la nota y la duración del sonido en milisegundos. Las tres cosas las tenemos guardadas en variables (ver sección de variables) así que las usamos. 

En el caso de que no estemos, voy a poner un "noTone" para silenciar el altavoz. 

```C++

 valorEjeY = analogRead(pinEjeY);
 if (valorEjeY < 223){
  tone(pinAltavoz,frecuenciaNota,duracionSonido);
 }
 else{
  noTone(pinAltavoz);
 }
 
 ```
 
 Probad diferentes valores de frecuencia y límites del valor de ejeY para ver que todo funciona bien y haced variaciones. 
 
 
## El rádar 

![](https://image.freepik.com/vector-gratis/radar-verde-sonar-submarino-armada-objetivos-ilustracion-pantalla-navegacion_53562-8136.jpg)

Este es un pequeño juego. Cada vez que iniciamos se generan unas coordenadas de un "tesoro" y tenemos que encontrar el punto dentro del joystick. Cuando lo encontramos suena una melodía de éxito y vuelve a empezar. 

Este proyecto es GRANDE así que lo vamos a hacer juntos. Esta versión funciona aunque es incompleta. La idea es ir haciéndola juntos poco a poco. 
 
En este aso voy a colocar TODO el código por partes, incluyendo las de ejercicios anteriores. 

### Nombre del proyecto

Radar.ino
 
 
### Hardware

Utiliza el mismo Hardware que el ejercicio anterior. El joystick, un led y el altavoz. Si no estuviera el altavoz igualmente el Led hace el mismo efecto. 

### Software

Aquí hablaremos de las diferentes partes del código. Iremos fragmento por fragmento. Y como utilizaremos otras funciones además de setup y loop las trataremos en apartados diferentes. 

#### Inicio del programa

Aquí sí caben modificaciones en la  descripción
 
 ```C++
 /*
*  Documentación del programa 
*  Autore: David Prieto
*  Fecha: 28/02/2021
*  Código referencia: https://github.com/d-prieto/arduinoCourse/edit/main/Variaciones%20de%20Joystick.md
*  Descripción del programa:
*  Este programa crea un punto al azar. Cuando vas acercando el joystick al punto va acercándose la distancia de los puntos
*  suena con más frecuencia.
*  Llegado un determinado punto toca una melodía de éxito y se reinicia. 
*  
*  
*  Hardware necesario: Joystick. Led. Resistencia de 220 Ohms
*/


 ```
 #### Variables
 
 Comenzamos con las variables de los pines (que, si usáis una plantilla ya deberían estar escritas)
 
  ```C++
  //Includes

//Definiciones de constantes de pines
const int pinBoton = 3; 
const int pinEjeY = A1; 
const int pinEjeX = A0; 

const int pinLed = 9;
const int pinAltavoz = 8;

   ```
   
Después vienen las variables globales, que son unas cuantas y las podemos dividir en categorías 

Estas son las variables para guardar los valores del Joystick de entrada. En esta primera versión no uso estado botón. En versiones posteriores sí la utilizaré. 
```C++
   
int valorEjeX = 0;
int valorEjeY = 0;
int estadoBoton = 0;
```  

Estas son las variables donde guardo la frecuencia del sonido del rádar y cuanto dura. Se pueden modificar a vuestro gusto para que el radar sea más agudo, grave, dure más o dure menos.

```C++
int frecuenciaNota = 440; 
int duracionSonido = 250;
```  

Estas son las coordenadas del "tesoro" que tenemos que encontrar. Comienzan en 0 pero se inician aleatoriamente en la función _iniciarDatosAleatorios()_

```C++
int xObjetivo = 0;
int yObjetivo = 0;
```  

Estas son las variables que tienen que ver con si se ejecuta el sonido o no (si toca silencio o toca que el altavoz suene) y cuanto es el intervalo entre los pitidos del rádar. La idea es que si ejecutarSonido es false no pita y si ejecutarSonido es true. 

```C++
int intervalo = 2000;
bool ejecutarSonido = false;
```  

Estas son las variables del tiempo. Las hemos usado en los proyectos de millis(), las he traducido al castellano y en vez de currentTime tenemos tiempoActual y tiempoAnterior.

```C++
unsigned long tiempoActual = 0;
unsigned long tiempoAnterior = 0;
```  

Por último tenemos las variables de la melodía de la victoria. Estas son del ejercicio de melodía. Igualmente con las otras he traducido los nombre de las variables al castellano. En vez de melody tenemos frecuenciasMelodia[] y en vez de notesDuration tenemos duracionDeNotas[].

Si queréis consultarlo está aquí el ejercicio de la melodía:

https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody

//melodia de victoria
```C++
int frecuenciasMelodia[] = {
  262, 196, 196, 220, 196, 0, 247, 262
};

int duracionDeNotas[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};
```  
Otro cambio que he realizado es, para no hacerlo aún más largo, en vez de utilizar definiciones de notas, he colocado su valor. He sustituido los  NOTE_C4 por 262 y así sucesivamente. 

 
 #### Setup 

Este Setup tiene partes que conocemos: 

```C++
void setup() {
//inicializaciones
  pinMode(pinBoton, INPUT);
  pinMode(pinLed, OUTPUT);
  digitalWrite(pinBoton, HIGH);
  Serial.begin(9600);
```
  Donde inicializamos el botón, el led e iniciamos el Serial y después una parte nueva:
  
  
```C++
  iniciarDatosAleatorios();
} //llave del setup

```
  Esto llamará a una nueva función que vamos a definir ahora. Esta ocurrirá una primera vez con el setup, pero también se le llamará desde el loop cuando toquemos la melodía. 
  
 #### iniciarDatosAleatorios()

Estas funciones ahora van a ir introducidas por una pequeña documentación que explican qué hacen. Esto forma parte de la documentación y es importante para programas complejos como este para llevarlo bien. 

```C++
 /*
 * Esta función crea el punto objetivo del juego
 */
void iniciarDatosAleatorios() {

 // Si no ponemos esta línea siempre empieza con los mismos valores
  randomSeed(analogRead(A2));
  
  xObjetivo = random(1023);
  yObjetivo = random(1023);
  Serial.println("Nuevas coordenadas");
  Serial.print("Eje X: ");
  Serial.println(xObjetivo);
  Serial.print("Eje Y: ");
  Serial.println(yObjetivo);

  
}
```
Esta función asigna a dos variables globales (xObjetivo e Yobjetivo) un punto al azar entre 0 y 1023. Después las enseña en pantalla.

Para tener un número pseudo-al azar tenemos la función random(numero). Esto te devuelve un número al azar entre 0 y el número que le digas. Puede tirar un dado de seis caras, lanzar una moneda, coger una carta de la baraja. Lo que haga falta. Aunque tiene algunos límites. 

Para que el número funcione realmente al azar y no exactamente igual cada vez que se ejecuta, necesito una pequeño truco que es usar una "semilla de azar" que tomo de un pin que no tiene nada conectado. 

Si no la pones la lína de randomSeed cada vez que ejecutas el arduino comienza en el mismo punto ¡y no es cuestión en este caso!. 

NOTA: SI HAS COPIADO HASTA AQUÍ, HAZ UN COMPILADO DE PRUEBA PARA VERIFICAR QUE NO HAYA LLAVES DE MÁS O DE MENOS PORQUE LA COSA A PARTIR DE AQUÍ SE COMPLICA. 




#### Loop 

Como otras veces, cuando tenemos un programa muy complejo, hacemos que haga sólo 3 líneas muy sencillas llamando a otras funciones que iremos desarrollando. 

Leer datos leerá los datos de los sensores (el joystick) y mirará la hora. 

Después procesa los datos y toma decisiones respecto a lo que ha leído. 

Por último decide si ejecutar luces y sonidos o no. 

```C++
void loop() {
  leerDatos();
  procesarDatos();
  ejecutarSonidosYLuces();

}  
```
Luego como es un bucle, vuelve a repetir el proceso. Ahora explicaremos cada una de las funciones

 #### leerDatos()
 
 De todas las funciones esta es la más sencilla. Sólo tiene 4 líneas de instrucciones. No obstante también ayuda que tenga sus líneas de documentación. 

```C++
/*
 * Esta función sólo lee datos y los guarda en variables. 
 */
void leerDatos() {
  valorEjeX = analogRead(pinEjeX);
  valorEjeY = analogRead(pinEjeY);
  estadoBoton = digitalRead(pinBoton);
  tiempoActual = millis();
}
```

Esto lo hemos visto varias veces en clase. Para los valores del potenciómetro necesitamos valores entre 0 y 1023 así que estamos obligados a usar analogRead en los respectivos pines y lo guardamos en variables para poder consultarlo después. 

EstadoBoton, por otro lado está conectado a un pin digital con lo cual no puede ejecutar analogRead (y tampoco tiene sentido que lo haga) así que usa digitalRead que le dará valores de 0 o 1. 

Por úlitmo y como novedad añadimos aquí lo de mirar la hora en "tiempoActual". 


 #### procesarDatos()
 
 La función procesarDatos es la más grande de las funciones e, incluso se podría haber subdividido en 2 funciones (calcularDistancia y decidirIntervalo) pero aquí está todo unido. Tiene al inicio la cabecera. 
 
```C++
/*
 * Esta función procesa los datos leídos y cambia las variables para la ejecución de sonidos. 
 */
void procesarDatos() {
```
Después comenzamos con la distancia entre 2 puntos. Nosotros tenemos en nuestro potenciómetro un punto en el eje X e Y (es bastante sensible al respecto

```C++
  // distancia entre dos puntos de coordenadas X Y 
  
  long distanciaX = valorEjeX - xObjetivo;
  Serial.print("Distancia en el eje X: ");
  Serial.println(distanciaX);
  long distanciaY = valorEjeY - yObjetivo;
  Serial.print("Distancia en el eje Y: ");
  Serial.println(distanciaY);
  //esto es la raiz cuadrada de la suma de los cuadrados de diferencia. 
  long distanciaReal = sqrt(sq(distanciaX)+sq(distanciaY));
  Serial.print("Distancia: ");
  Serial.println(distanciaReal);

  if (distanciaReal >= 1000)
  {
    intervalo = 2000;
  }
  else if (distanciaReal >= 800 && distanciaReal < 1000) {
    intervalo = 1500;
  }
  else if (distanciaReal >= 600 && distanciaReal < 800) {
    intervalo = 1000;
  } 
  else if (distanciaReal >= 400 && distanciaReal < 600) {
    intervalo = 750;
  }
  else if (distanciaReal >= 200 && distanciaReal < 400) {
    intervalo = 500;
  } 
  else if (distanciaReal >= 120 && distanciaReal < 200) {
    intervalo = 750;
  }
  else if (distanciaReal >= 75 && distanciaReal < 120) {
    intervalo = 250;
  } 
  else if (distanciaReal >= 50 && distanciaReal < 75) {
    intervalo = 100;
  } 
  else { // con menos de 50 de distancia considero que ya se ha acertado el punto
    secuenciaFinal();
  }
}
```


#### ejecutarSonidosYLuces()
```C++
/*
 * Esta función en función de las variables anteriores enciende el led y activa el led 
 */
void ejecutarSonidosYLuces() {
  if (tiempoActual - tiempoAnterior >= intervalo) {
     tiempoAnterior = tiempoActual;
     ejecutarSonido = !ejecutarSonido;
     if (ejecutarSonido) {
      tone(pinAltavoz, frecuenciaNota, duracionSonido);
      digitalWrite(pinLed,HIGH);
     }
     else {
      noTone(pinAltavoz);
      digitalWrite(pinLed,LOW);
     }
  }
}
```

#### secuenciaFinal()
```C++
/*
 * Esta función toca una melodía y vuelve a iniciar las coordenadas.  
 */
void secuenciaFinal() {
  
  for (int estaNota = 0; estaNota < 8; estaNota++) {


    int duracionNota = 1000 / duracionDeNotas[estaNota];
    tone(pinAltavoz, frecuenciasMelodia[estaNota], duracionNota);
    digitalWrite(pinLed,LOW);
    int pausaEntreNotas = duracionNota * 1.30;
    delay(pausaEntreNotas);
    digitalWrite(pinLed,HIGH);
    noTone(pinAltavoz);
  }
  iniciarDatosAleatorios();
}

 ```

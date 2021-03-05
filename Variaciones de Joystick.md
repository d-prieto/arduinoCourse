# Variaciones de Joystick

## Índice 

* [Rádar](#el-rádar)
* [Variaciones del rádar](#retoques-al-radar)

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

Si no la pones la lína de randomSeed cada vez que ejecutas el arduino comienza en el mismo punto ¡y no es cuestión en este caso!

Al final vamos a tener un punto en el plano de esta forma:

![](https://raw.githubusercontent.com/d-prieto/arduinoCourse/main/Images/JoystickCoordenadas02.jpg)

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

En este caso lo que hacemos es pintar en un plano cartesiano donde está nuestro Joystick. Aquí podéis ver cómo funciona:

![](https://raw.githubusercontent.com/d-prieto/arduinoCourse/main/Images/JoystickCoordenadas01.jpg)

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
 ##### Cálculo de la distancia

Después comenzamos con la distancia entre 2 puntos. Nosotros tenemos en nuestro potenciómetro un punto en el eje X e Y (es bastante sensible al respecto) y necesitamos saber cómo de lejos está del tesoro (punto objetivo) que también tiene coordenadas x e y y están guardadas en distanciaX y distanciaY respectivamente. 

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
  
  
  ```
 Para saber esa distancia tenemos que usar _matemáticas_ y teorema de Pitágoras. Ahora mismo ya tenemos dos puntos en el plano y queremos averiguar la Distancia Real 
 
 ![](https://raw.githubusercontent.com/d-prieto/arduinoCourse/main/Images/JoystickCoordenadas03.jpg)
 
 Esto se puede asimilar a esta imagen
 
 ![](https://www.superprof.es/apuntes/wp-content/uploads/2019/07/distancia-entre-dos-puntos.gif)
 
 Y aquí hay una clase explicándolo con videos 
 
 http://matematicatuya.com/GRAFICAecuaciones/S1a.html
 
 Al final tenemos esta fórmula de aquí
 
 ![imagen](https://user-images.githubusercontent.com/60569015/109956735-4eb7fb00-7ce4-11eb-9a3f-b6da212f9105.png)

 
 Lo que nos importa aquí ¿Cómo hacemos cuadrados o raices cuadradas en arduino? Pues para ello tenemos 2 funciones y 1 aviso. 
 
 El aviso es que vamos a tener números mayores a 32 000 por lo que necesitamos sí o sí utilizar long en vez de ints (que por eso defino la distanciaX y la distanciaY como long y no como int)
 
 La primera función que tenemos que usar es **sq(numero)** para multiplicar un número por sí mismo. Square significa cuadrado en inglés y el diminutivo es sq así que lo que hace es elevar al cuadrado el número que le lancemos. 
 
 Y la segunda función que tenemos que utilizar es **sqrt(numero)** para obtener la raíz cuadrada de un número. En inglés raíz cuadrada es square root, así que la abreviación es sqrt. 
 
 Al final escribimos:   long distanciaReal = sqrt(sq(distanciaX)+sq(distanciaY)); para hacerlo. Son muchos paréntesis pero ahí está todo. Raíz de suma de cuadrados. 
 
 Ya tenemos la distancia ¡yay! Ahora vamos a hacer los cambios en función de esa distancia. 
 
 ##### Decisiones en función de la distancia
 
 Lo que se viene es un if else muy largo. Hemos hecho uno parecido con el teclado. 

  
```C++
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

Si la distancia es mayor que 1000 el intervalo de los pitidos es de 2000 milisegundos, 2 segundos. Si te acercas se va reduciendo hasta un mínimo de 100 milisegundos. Si consigues acercarte a menos de 50 activiará "secuenciaFinal" que definiremos más tarde. 




#### ejecutarSonidosYLuces()

Después de que decida cual es el intervalo actual, y con la hora ya medida en leerDatos, vamos a revisar ahora si encendemos el led y pitamos o no. Como otras veces, comenzamos con la pequeña documentación de la propia función. 

```C++
/*
 * Esta función en función de las variables anteriores enciende el led y activa el led 
 */
```
_Siempre documentación, nunca indocumentación_

Luego comenzamos con unas líneas muy similares a lo que hemos hecho en el ejercicio de los leds. Si ha pasado el tiempo del intervalo activamos o desactivamos el sonido. Para hacer una vez cada cosa, utilizamos la variable "ejecutarSonido". 

Si ejecutarSonido coincide que es true, pitamos y encendemos el led. Si resulta que no lo es, pues apagamos el led y el altavoz. 

```C++
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

Por último tenemos la secuancia final, en el caso de que nos hayamos acercado lo suficiente al tesoro (a una distancia de 50 o menos). Comenzamos con la documentación. 

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
 
 ## Retoques al radar 
 
 Hoy viernes vamos a hacer retoques al rádar
 
 ### Fáciles:
 
 #### Frecuencia del rádar
 
 Primero voy a retocar del rádar el pitido del radar para que sea constante, pero tenga otro tono. Para ello ubico, en la zona de variables este fragmento de código:
 
 ![imagen](https://user-images.githubusercontent.com/60569015/110084159-e9b9df00-7d8f-11eb-87d2-97ffe610434f.png)

Y ahí cambio la "frecuenciaNota", por un valor más alto o más bajo a 440, bastante agudo sería 880, un valor grave sería 262. 

 #### Hacer que el led se encienda cuando ocurre el silencio y viceversa. 
 
 Esto lo que hace es que si el audio suena el led esté apagado. Y si el audio le toca silencio, el led se encienda. Localizo este fragmento en ejecutarSonidosYLuces()
 
 ![imagen](https://user-images.githubusercontent.com/60569015/110084695-8b413080-7d90-11eb-99ad-10be1569cad3.png)

y done pone digitalWrite(pinLed, HIGH) pongo digitalWrite(pinLed, LOW) y viceversa. 

 #### Modificar la melodía del final
 
 En este caso, tendríamos que retocar 3 cosas. Por un lado las variables frecuenciasMelodia[] y duracionDeNotas[] que están el las variables

![imagen](https://user-images.githubusercontent.com/60569015/110085100-fdb21080-7d90-11eb-97db-006fe7e3f1fa.png)

Por otro lado, si cambiamos el número de notas y en vez de poner 8 ponemos más o menos tendremos que actualizar en el bucle for de secuencia final el número de notas que vayamos a tocar

![imagen](https://user-images.githubusercontent.com/60569015/110085302-38b44400-7d91-11eb-8392-fdd5e15e1712.png)


Donde poner estaNota<8 necesitariamos colocar el número de notas que tuviéramos o deseásemos tocar. 

### Medias 

Estas requieren un poco más de trabajo, o al menos más delicado. 

#### Cambiar la dificultad del juego 

Ahora mismo el juego es bastante difícil. Esto es porque hay que ser muy preciso con el Joystick para hacerlo preciso. Esto se puede hacer de varias aproximaciones. La primera es modificar en "procresarDatos()" los umbrales de los if/else. Estos de aquí:

![imagen](https://user-images.githubusercontent.com/60569015/110086965-55517b80-7d93-11eb-8d2e-4a299039d37d.png)

Ahora mismo los umbrales son:
 ```
1000
800
600
400
200
120
75
y 
50
 ```
Estos son los umbrales a partir de los cuales se cambia el intervalo. Cada uno de estos números está escrito dos veces (en la horquilla inferior de una condición y en la horquilla superior del siguiente). 

En este caso tras darle vueltas he utilizado estos valores y voy a probarlos: 1000,850,700,550,400,225,150,100

![imagen](https://user-images.githubusercontent.com/60569015/110087687-40291c80-7d94-11eb-92db-e35775d3b996.png)

Comprobado y funcionan bastante bien, ahora es más entretenido la verdad con estos ajustes. 

### Añadir un LED para que alterne con el otro

El que haya un led está guay, pero con dos y que se alternen podría estar aún mejor. En este caso sí necesitaríamos añadir un poco más de hardware. 

Incluiríamos un led con su resistencia a otro pin (por ejemplo el 7) y tendríamos que añadir sus respectivas variables (sigue). También se podría utilizar el led integrado del pin 13, pero no tiene tanto flow como un led al lado del otro que tenemos. 

#### Hardware 

Añadimos otro pin, en este caso lo pongo en el pin 10 y lo conecto a Ground utilizando una resistencia. Como otros leds que hemos montado 

![imagen](https://user-images.githubusercontent.com/60569015/110099963-30b0d000-7da2-11eb-9a03-2d41c97535ce.png)


#### Software 

Aquí tenemos que intervenir en 3 partes. Por un lado añadir la constante del pin que utilicemos en las variables 


![imagen](https://user-images.githubusercontent.com/60569015/110100093-50e08f00-7da2-11eb-860c-91aa34959a3f.png)


En el Setup también tenemos que añadir el pinMode, si no lo hacemos el LED va a brillar muy muy flojito. 

![imagen](https://user-images.githubusercontent.com/60569015/110100191-6a81d680-7da2-11eb-8c81-5e6f1c54978d.png)

Por último en ejecutarSonidosYLuces añado las líneas para hacer que se encienda cuando el otro esté apagado y al revés. 

![imagen](https://user-images.githubusercontent.com/60569015/110100353-98671b00-7da2-11eb-82b8-b5c18df9cf0f.png)

Donde pone digitalWrite(pinLed2, HIGH o LOW) son las líneas nuevas (ojo que hay 2)

Como extra se puede añadir en la secuencia final, pero no queda con mucho flow, la verdad. 

![imagen](https://user-images.githubusercontent.com/60569015/110100476-c0567e80-7da2-11eb-9d27-06022ad85085.png)

### Difícil Variación del caminante

Ahora mismo el punto del tesoro es un punto del joystick, pero en cualquier videojuego nosotros nos movemos en un "espacio virtual" y los joysticks nos permiten movernos en ese espacio. Vamos a intentarlo nosotros. 

![imagen](https://user-images.githubusercontent.com/60569015/110101176-8c2f8d80-7da3-11eb-8537-e1b0aac24f09.png)

_imagen de videojuego_

Para ello necesitamos saber "la posición de quien juega" y esa posición se modificará cuando movemos el joystick. Si movemos hacia arriba el joystick se moverá "arriba" en el plano del juego ficticio (que no vemos porque no tenemos una pantalla). Pero si dejamos el Joystick detenido el jugador se mantendrá en esa posición. 

Así que para ello vamos a desdoblar lo de la distancia para añadir las variables de "posicionJugadore" (posición de la persona que juega) que tendrán una X y una Y. Después tendremos que revisar cómo cambia el joystick esa posición. 

El resto del programa se mantendrá tal cual de momento. 

¡A ello!

#### Variables 

Tenemos que añadir posicionJugadoreX y posicionJugadoreY como variables globales. 


```C++
int posicionJugadoreX = 0;
int posicionJugadoreY = 0;
```

#### procesarDatos()

Aquí vamos a cambiar las variables de distanciaX e Y para que las calcule a partir de posicionJugadoreX. Y como calcular la posición es complicado, la voy a sacar en calcularPosicionJugadore() para que funcione aparte y tener todo un poco más ordenado. Me queda esto:

```C++
void procesarDatos() {
  // distancia entre dos puntos de coordenadas X Y 
  calcularPosicionJugadore();
  long distanciaX = posicionJugadoreX - xObjetivo;
  Serial.print("Distancia en el eje X: ");
  Serial.println(distanciaX);
  long distanciaY = posicionJugadoreY - yObjetivo;
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
  else if (distanciaReal >= 850 && distanciaReal < 1000) {
    intervalo = 1500;
  }
  .
  .
  .
```
Sólo he cambiado 3 líneas, cómo calcula la distanciaX, la distanciaY. El resto de _magia matemática_ la dejo tal cual porque como funciona no hace falta tocar nada. 

#### calcularPosicionJugadore()

Esta es una nueva función, así que debemos utilizar una documentación para ver lo que hace. 

![imagen](https://user-images.githubusercontent.com/60569015/110103482-4922e980-7da6-11eb-92ee-f92c9c2ac846.png)


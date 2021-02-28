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

### Proyecto de LED que se enciende cuando pulsas el botón del joystick 

#### Hardware

Tengo un led conectado en este caso al pin 9. Podeis usar este pin o cualquier otro. 

#### Software 

Aquí explicaré primero las cosas que voy a añadir y cómo queda el código al final. 

##### Inicio del programa

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
##### Variables

Después añado en la sección de variables (antes del setup y el loop) las nuevas variables que necesito. Una de un pin y otra del estado del botón. En este caso para la definición de variables, para facilitar la comprensión las escribiré en castellano. Así que en vez de SwitchState estoy utilizando EstadoBoton

```C++
const int pinLed = 9;

 int estadoBoton = 1;
```
##### Setup 

En el Setup sólo tenemos que añadir una línea para inicializar el LED: 

```C++
 pinMode(pinLed, OUTPUT);
```
##### Loop 

Ahora el loop. Este loop lo hemos hecho varias veces. Necesitamos que 
a) Lea el botón
b) Decida si encender el led se enciende o no. 

Para lo primero usamos lo que hemos usado otras veces: 

```C++
 estadoBoton= digitalRead(pinBoton);
```

Si tuvieramos algún problema, añadiríamos después un Serial.println(estadoBoton) para ver en el PC qué señal recibe el botón y si está bien conectado (debería leer 0 cuando está pulsado y 1 cuando está sin pulsar). 

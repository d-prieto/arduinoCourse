# Módulo de Joystick con botón KY-023 Joystick

## Objetivos 

* Utilizar el sensor de joystick para este y otros proyectos. 

* Aprender a conectar sensores al protoboard y al arduino de diferentes formas según nuestras necesidades.

* Utilizar un código de referencia para comprobar que las conexiones son correctas 

* Añadir una funcionalidad extra a través de outputs que ya tenemos (servomotor, motor 9V, leds, ledRGB)

## Módulo de Joystick Qué es y cómo funciona

Este módulo es un pequeño circuito integrado como el resto de los sensores de la caja (es decir, tiene circuitos dentro con más o menos complejidad) y en este caso combina dos potenciómetros y 1 botón. Esta información es remitida a cada uno de los diferentes pines. 

Estamos acostumbrados a los potenciómetros que se giran respecto al eje "vertical" pues estos potenciómeros están "tumbados" 90 grados y cada uno de ellos gira 180 grados en función de cómo se mueva el joystick de un mínimo a un máximo. 

Sí, los mandos de una play funcionan con el mismo principio. 

Este es el esquema:

![](http://cursoarduino.proserquisa.com/wp-content/uploads/2016/10/25-03.jpg)

Si el sensor está en el centro los valores de X y de Y estarán en torno a 500, cuando se mueve el joystick suben o bajan. 

En este caso, además, si se presiona el joystick se pulsa un botón (si os fijáis podéis ver el botón). 

## Conexión

El módulo tiene varias salidas y con su nombre indican hacia donde deberían ir. Os las enumero:

GND. -> Ground, toma tierra, 0V de potencial eléctrico. 

5V -> Voltaje de 5V. Esto hay que conectarlo a los 5 voltios de potencia para que pueda ser leído correctamente. 

VRx -> Este es el Voltaje Regulado en el eje X horizontal. Hay que conectarlo a un pin analógico para que pueda leerse.  

VRy -> Este es el Voltaje Regulado en el eje Y vertical. Hay que conectarlo a un pin de lectura analógica para que pueda leerse. 

SW -> Switch. Este es el botón. Al estar ya integrado se puede conectar directamente a un pin digital sin tener que incluir la resistencia. Sin embargo este es un botón pull

## Referencia 

Para este articulo he utilizado referencias en este artículo anterior http://cursoarduino.proserquisa.com/2016/10/13/tutorial-25-modulo-joystick-ky-023/

# Variantes de contador 

## Origen de este documento

Este documento explica las variantes realizadas a partir del trabajo de [Bangwei](https://github.com/chenbangwei/Arduino). En su proyecto (complejo) consistía que presionando un botón se inciiara una secuencia que iniciase varios leds (incluyendo un led RGB) hasta iniciar el motor. 

He creado esta secuencia de programas, de más sencillo a más complejo para ilustrar el proceso de programación de algo así. 

## Programas

Primero, para revisar si mi hardware estaba bien instalado he colocado un programa de parpadeo (blink) que es [este de aquí.](https://github.com/d-prieto/arduinoCourse/blob/main/Countdown_blink.ino)

Una vez he visto que funcionaba he modificado el programa del digital clock para que funcione con el mismo funcionamiento [aquí.](https://github.com/d-prieto/arduinoCourse/blob/main/Countdown_digitaltimer_only_pressed.ino)

Después lo he refactorizado (en parte) para poder hacer y analizar el código mejor. Cada vez modifico las variables para que tengan sentido en ese programa. Así que puede haber cambios en los nombres de las variables (porque al hacer cosas diferentes, prefiero cambiarles de nombre a uno que tenga sentido en ese programa). 

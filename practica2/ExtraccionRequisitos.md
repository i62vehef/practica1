# Extraccion de Requisitos

## Partes interesadas

Profesor y Alumnos

## Datos a guardar

* DNI

* Nombre

* Apellidos

* Teléfono

* Email corporativo

* Domicilio

* Curso más alto matriculado

* Fecha de nacimiento

* Equipo

* ¿Es líder del equipo?

## Requisitos Funcionales

RF-1 El sistema debe ser capaz de buscar un alumno entre los ya registrados mediante su DNI, sus apellidos o su grupo.

RF-2 Introducción de nuevos alumnos de forma manual. Durante el registro se deberán introducir todos los datos del alumno a excepción del equipo y si es líder o no del mismo.

RF-3 Se podrá cargar desde un fichero o copia de seguridad un conjunto de alumnos.

RF-4 El sistema contará con una opción para generar una nueva copia de seguridad cuando el usuario/cliente lo desee, siempre sin sobreescribir la anterior. También se preguntará, al finalizar la sesión, si se desea crear una nueva copia.

RF-5 Borrar un alumno.

RF-6 Modificar los datos de un alumno.

RF-7 El sistema podrá mostrar un alumno en concreto.

RF-8 El sistema tendrá la opción de mostrar los alumnos de un único grupo en concreto.

RF-9 El sistema contará con la opción de mostrar de forma ordenada ascendente o descendentemente el conjunto de todos los alumnos registrados.

RF-10 Los usuarios podrán acceder al sistema iniciando sesión con su identificador y contraseña únicos.

## Requisitos no funcionales

RNF-1 La interfaz utilizada será la línea de comandos

RNF-2 El lenguaje de programación utilizado para este sistema será C++.

RNF-3 El lenguaje de documentación utilizado en este sistema será Markdown.

RNF-4 Las copias de seguridad serán guardadas en ficheros binarios, tanto los admitidos como entrada como los generados por el sistema.

RNF-5 El número máximo de alumnos que soportará el sistema será de 150 alumnos.

RNF-6 El sistema será operativo en SOs Linux.

RNF-7 A la hora de mostrar un alumno se mostrará tanto mediante la interfaz como a través de una aplicación web facilitada mediante lenguaje html.

## Prioridad de los requisitos

RF-1 -> Prioridad 1

RF-2 -> Prioridad 2

RF-3 -> Prioridad 3

RF-4 -> Prioridad 3

RF-5 -> Prioridad 4

RF-6 -> Prioridad 5

RF-7 -> Prioridad 5

RF-8 -> Prioridad 5

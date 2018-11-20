### **Borrar Alumno**

**ID:** 005

**Breve Descripción:** El sistema borrará un alumno

**Actores principales:** Profesor

**Actores secundarios:** Alumno

**Precondiciones:** 

 1. El alumno debe estar registrado.

 **Flujo principal:**

  1. El sistema necesita borrar un alumno.
  2. Se pide el DNI o los apellidos del alumno.
  3. El sistema busca el alumno.
  4. El sistema comprobará si el alumno a borrar es el líder.
  5. El sistema asignará la condición de líder al compañero en caso de que el alumno a borrar sea el líder.
  6. El sistema preguntará al usuario si está seguro de borrar al alumno.
  7. Se borran los datos del alumno.
  8. El sistema mostrará un mensaje confirmando que el alumno ha sido borrado.
  

**Postcondiciones:**

  1. El sistema borrará todos los datos del alumno.

 **Flujo alternativo:**

  3a. Si no encuentra el alumno, muestra un mensaje de error y vuelve al paso anterior (pedir datos).

  3b. Si, al buscar por apellidos, se encuentran varios alumnos, se mostrarán sus datos (apellidos, nombre y DNI).
      Después se volverá a pedir los datos para que se introduzca el DNI del alumno a borrar.

  7a. Si no se eliminan correctamente los datos, se muestra un mensaje de error y vuelve al menú principal.

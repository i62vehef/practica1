### **Borrar Alumno**

**ID:** 005

**Breve Descripción:** El sistema borrará un alumno

**Actores principales:** Usuario

**Actores secundarios:** Alumno

**Precondiciones:** 

 1. El alumno debe estar registrado.

 **Flujo principal:**

  1. El sistema necesita borrar un alumno.
  2. El sistema debe comprobar que el alumno esta registrado.
  3. El sistema comprobará si el alumno a borrar es el líder.
  4. El sistema asignará la condición de líder al compañero en caso de que el alumno a borrar sea el líder.
  5. El sistema preguntará al usuario si esta seguro de borrar al alumno.
  6. El sistema mostrará un mensaje confirmando que el alumno ha sido borrado.
  

**Postcondiciones:**

  1. El sistema borrará todos los datos del alumno.
 

 **Flujo alternativo:**

  5a. El sistema mostrará un mensaje si el alumno a borrar no se encuentra registrado.

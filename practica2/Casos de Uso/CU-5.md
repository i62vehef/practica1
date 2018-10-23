### **Borrar Alumno**

**ID:** 005

**Breve Descripción:** El sistema borrará un alumno

**Actores principales:** Usuario

**Actores secundarios:** Alumno

**Precondiciones:** 

 1. El alumno debe estar registrado.

 **Flujo principal:**

  1. El sistema debe comprobar que el alumno esta registrado.
  2. Se filtra en la lista de alumnos para encontrarlo. 
  3. El sistema comprobará si el alumno a borrar es el lider.
  4. El sistema asignará la condición de lider al compañero en caso de que el alumno a borrar sea el lider.
  5. El sistema mostrará un mensaje de que el alumno ha sido borrado.
  

**Postcondiciones:**

  1. El sistema borrará todos los datos del alumno.
 

 **Flujo alternativo:**

  1a. El sistema mostrará un mensaje si el alumno no se encuentra registrado.

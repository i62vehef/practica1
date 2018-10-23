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
  3. El sistema al borrar los datos de un alumno se comprueba que este es el lider se le asignará a su compañero.
  4. El sistema mostrará un mensaje de que el alumno ha sido borrado.
  

**Postcondiciones:**

  1. El sistema borrará todos los datos del alumno.
 

 **Flujo alternativo:**

  1a. El sistema mostrará un mensaje si el alumno no se encuentra registrado.

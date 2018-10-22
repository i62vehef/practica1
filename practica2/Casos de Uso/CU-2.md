### **Introducir un nuevo alumno**

**ID:** 002

**Breve descripción**: El sistema debe poder introducir un nuevo alumno

**Actores principales**: Usuario

**Actores secundarios**: Alumno

**Precondiciones:**

 1. El alumno no debe estar registrado

 **Flujo principal:**

  1. El sistema comprobara si el alumno esta registrado
  2. Se necesita un criterio de búsqueda: DNI, apellidos o grupo
  3. Se filtra en la lista de alumnos para comprobar si el alumno esta registrado.
  4. El sistema recoge los datos del alumno a excepción del grupo y su lider.

 **Postcondiciones:**

  1. El sistema guarda los datos del nuevo alumno a excepcion del grupo y su lider.

 **Flujos alternativos:**
 
  3a. Si el alumno se encuentra registrado, se muestra un mensaje de que el alumno ya esta registrado.

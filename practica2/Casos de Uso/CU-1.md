### **Buscar alumno**

**ID:** 001

**Breve descripción:** El sistema debe poder buscar un alumno

**Actores principales:** Profesor

**Actores secundarios:** Alumno

**Precondiciones:**

 1. El alumno debe estar registrado

 **Flujo principal:**

  1. El sistema necesita buscar un alumno
  2. Se necesita un criterio de búsqueda: DNI, apellidos o grupo
  3. Se filtra en la lista de alumnos para encontrarlo.

 **Postcondiciones:**

  1. El sistema recoge los datos del alumno

 **Flujos alternativos:**
 
  3a. Si el alumno no se encuentra, se muestra un mensaje de error.
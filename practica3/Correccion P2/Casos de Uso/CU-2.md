### **Introducir un nuevo alumno**

**ID:** 002

**Breve descripción:** El sistema debe poder introducir un nuevo alumno

**Actores principales:** Profesor

**Actores secundarios:** Alumno

**Precondiciones:**

 1. El alumno no debe estar registrado.

**Flujo principal:**

  1. El sistema necesita introducir un nuevo alumno.
  2. El sistema pide los datos del nuevo alumno.
  3. El sistema recibe los datos del nuevo alumno a excepción del grupo y su lider.
  4. Se comprueba si el alumno no está ya registrado.
  5. Se guardan los datos del alumno.

**Postcondiciones:**

  1. El nuevo alumno queda registrado en el sistema.

**Flujos alternativos:**
 
  3a. Si los datos introducidos no son válidos, se muestra un mensaje de error.

  3b. El sistema permite volver a introducir todos los datos del nuevo alumno.

  4a. Si el alumno ya está registrado se muestra un mensaje de error.

  4b. Se vuelve al menú principal.
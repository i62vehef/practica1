### **Mostrar grupo**

**ID:** 008

**Breve descripción:** El sistema debe poder mostrar los alumnos que forman un grupo de trabajo.

**Actores principales:** Profesor

**Actores secundarios:** Alumno

**Precondiciones:**

 1. El grupo debe estar registrado

 **Flujo principal:**

  1. El sistema necesitar mostrar los alumnos de un grupo.
  2. El sistema pide al usuario el ID del grupo.
  3. El sistema busca los alumnos por la ID de su grupo.
  4. Se recogen los nombres y apellidos de los componentes.

 **Postcondiciones:**

  1. Se muestran los nombres y apellidos de los componentes del grupo.

 **Flujos alternativos:**
 
  2a. Si se introduce un ID que no es válido, se muestra un mensaje de error.

  3a. Si no se encuentra ningún alumno con dicho grupo asignado se muestra un mensaje de error.
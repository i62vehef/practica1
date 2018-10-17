### **Mostrar alumno**

**ID**: 006

**Breve descripción**: El sistema debe poder mostrar los datos de un alumno.

**Actores principales**: Usuario

**Actores secundarios**: Alumno

**Precondiciones:**

 1. El alumno debe estar registrado en el sistema.

 **Flujo principal:**

  1. El sistema necesita mostrar un alumno.
  2. El sistema pide el criterio de búsqueda al usuario, que debe ser DNI o apellidos.
  3. El sistema busca el alumno.
  4. Se recogen los datos del alumno.

 **Postcondiciones:**

  1. Se muestran los datos del alumno.

 **Flujos alternativos:**
 
  2a. En caso de que se introduzca un DNI, si no es correcto, se muestra un mensaje de error.
  3. Si el alumno no existe muestra un mensaje de error.
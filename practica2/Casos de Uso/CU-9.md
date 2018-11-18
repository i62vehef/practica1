### **Modificar Alumno**

**ID**: 00?

**Breve descripción**: El sistema puede modificar los datos de un Alumno.

**Actores principales**: Usuario

**Actores secundarios**: Alumno

**Precondiciones:**

 1. El alumno debe estar registrado

 **Flujo principal:**

  1. El sistema necesita buscar un alumno
  2. Se necesita un criterio de búsqueda: DNI, apellidos o grupo
  3. Se filtra en la lista de alumnos para encontrarlo.
  4. El sistema podra modificar cualquier dato del Alumno.

 **Postcondiciones:**

  1. El sistema recoge los datos modificados del Alumno.

 **Flujos alternativos:**
 
  3a. Si el alumno no se encuentra, se muestra un mensaje de error.


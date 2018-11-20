### **Modificar Alumno**

**ID:** 006

**Breve descripción:** El sistema puede modificar los datos de un alumno.

**Actores principales:** Profesor

**Actores secundarios:** Alumno

**Precondiciones:**

 1. El alumno debe estar registrado

 **Flujo principal:**

  1. El sistema necesita modificar los datos de un alumno.
  2. Se piden los datos del alumno para buscarlo: DNI o apellidos.
  3. Se busca el alumno.
  4. Se muestran los datos del alumno.
  5. El sistema pregunta cuál es el dato a modificar.
  6. Se pide el nuevo valor.
  7. El sistema pide confirmación del cambio.

 **Postcondiciones:**

  1. El sistema modifica los datos del alumno.

 **Flujos alternativos:**
 
  3a. Si el alumno no se encuentra, se muestra un mensaje de error.

  3b. Si, al buscar por apellidos, se encuentran varios alumnos, se mostrarán sus datos (apellidos, nombre y DNI).
      Después se volverá a pedir los datos para que se introduzca el DNI del alumno a modificar.
### **Listar alumnado completo**

**ID:** 009

**Breve descripción:** El sistema debe poder mostrar una lista de todos los alumnos registrados.

**Actores principales:** Profesor

**Actores secundarios:** Alumno

**Precondiciones:**

 1. Debe haber alumnos registrados.

 **Flujo principal:**

  1. El sistema necesita listar los alumnos.
  2. Se pide al usuario si desea listarlo de manera creciente o decreciente.
  3. El sistema pregunta el criterio de ordenación.
  4. Se ordenan los alumnos internamente según el criterio indicado.
  5. El sistema genera un fichero html con la lista de alumnos.

 **Postcondiciones:**

  1. El sistema muestra la lista de todos los alumnos ordenados.

 **Flujos alternativos:**
 
  2a. Solo se admite ordenación creciente o decreciente.
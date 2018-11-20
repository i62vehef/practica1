### **Cargar Datos**

**ID:** 003

**Breve descripción:** El sistema debe poder cargar una lista de alumnos.

**Actores principales:** Usuario

**Actores secundarios:** Alumno


**Precondiciones:**

 1. El sistema debe tener una lista de alumnos en un fichero o copia de seguridad.
  
**Flujo principal:**

  1. El sistema necesita cargar de un fichero datos sobre alumnos.
  2. El sistema pide el nombre del fichero.
  3. Se carga la lista de alumnos en el sistema desde el fichero indicado.
  4. El sistema mostrará un mensaje de que la lista se cargo correctamente.

**Postcondiciones:**

 1. El sistema debe tener guardados todos los datos de la lista de alumnos que hubiese en la copia de seguridad.

 **Flujo alternativo:**
 
 3a. El sistema mostrará un mensaje de "Error" si la lista no se cargo correctamente.

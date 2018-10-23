### **Crear Copia de Seguridad**

**ID:** 004

**Breve descripción:** El sistema debe crear una copia de seguridad

**Actores principales:** Usuario

**Actores secundarios:** Alumno

**Precondiciones**

 1. El sistema debe generar una nueva copia de seguridad.

 **Flujo principal:**

  1. El sistema podrá crear una copia de seguridad en cualquier momento.
  2. El sistema preguntará si se quiere hacer copia de seguridad al salir del programa.
  3. El sistema creara una copia de seguridad sin sobrescribir la anterior.

**Postcondiciones:**

 1. El sistema crea la copia de seguridad.

 **Flujo alternativo:**

 3a. El sistema mostrará un mensaje de "Error" si no se creo la copia de seguridad. 

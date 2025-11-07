# Software Requirements Specification - Programa 04 (Persona)

Lista de requerimientos para el **Programa 04 (Persona)**, basados en las consignas del desarrollo práctico y mis especificaciones.

## Requerimientos Funcionales y No Funcionales

### Requerimientos Funcionales (RF)

  * **RF-01 (Crear):** El sistema debe permitir registrar una nueva persona especificando su nombre y fecha de nacimiento (día, mes, año).
  * **RF-02 (Leer):** El sistema debe permitir consultar la información de las personas existentes.
  * **RF-03 (Actualizar):** El sistema debe permitir modificar el nombre y/o fecha de nacimiento de una persona existente.
  * **RF-04 (Eliminar):** El sistema debe permitir eliminar una persona del sistema.
  * **RF-05 (Persistencia):** El sistema debe guardar los datos de las personas (nombre y fecha de nacimiento) en un archivo para que la información no se pierda al cerrar la aplicación.
  * **RF-06 (Carga):** El sistema debe cargar automáticamente las personas desde el archivo al iniciar la aplicación.
  * **RF-07 (Ingreso Fecha Actual):** El sistema debe permitir al usuario ingresar una "fecha actual" (día, mes, año) para usarla en los cálculos.
  * **RF-08 (Cálculo Edad):** El sistema debe calcular la edad de una persona, basándose en su fecha de nacimiento y la "fecha actual" ingresada por el usuario.
  * **RF-09 (Visualización):** El sistema debe poder mostrar al usuario el nombre y la edad calculada de una persona.

### Requerimientos No Funcionales (RNF)

  * **RNF-01 (Modularidad):** El programa debe estar modularizado, separando la interfaz de usuario, la lógica de negocio y el acceso a datos.
  * **RNF-02 (Encapsulación):** El diseño debe aplicar correctamente los conceptos de abstracción, encapsulación y ocultamiento de información.
  * **RNF-03 (Responsabilidades):** El sistema debe tener una apropiada distribución de responsabilidades entre las clases.
  * **RNF-04 (Inclusiones):** Se debe usar `#pragma once` para proteger contra inclusiones múltiples.
  * **RNF-05 (Espacios de Nombres):** Todo el código debe estar contenido dentro del namespace `program04`.
  * **RNF-06 (Lenguaje):** El sistema debe desarrollarse en C++.
  * **RNF-07 (Bibliotecas):** Solo se deben usar librerías básicas de C++ (std, string, etc.). No se deben usar contenedores de la STL (como `vector`, `map`, etc.), requiriendo el uso de arrays y gestión manual de memoria.
  * **RNF-08 (Reusabilidad):** El código debe ser desarrollado con la intención de ser reutilizable.

-----


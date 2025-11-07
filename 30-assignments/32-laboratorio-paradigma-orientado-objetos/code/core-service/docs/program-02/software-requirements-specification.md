# Software Requirements Specification - Programa 02 (Alumno)

Lista de requerimientos para el **Programa 02 (Alumno)**, basados en las consignas del desarrollo práctico y mis especificaciones.

## Requerimientos Funcionales y No Funcionales

### Requerimientos Funcionales (RF)

  * **RF-01 (Crear):** El sistema debe permitir registrar un nuevo alumno especificando su cédula, nombre y sus tres notas parciales.
  * **RF-02 (Leer):** El sistema debe permitir consultar la información de los alumnos existentes.
  * **RF-03 (Actualizar):** El sistema debe permitir modificar la cédula, nombre y/o notas parciales de un alumno existente.
  * **RF-04 (Eliminar):** El sistema debe permitir eliminar un alumno del sistema.
  * **RF-05 (Persistencia):** El sistema debe guardar los datos de los alumnos en un archivo para que la información no se pierda al cerrar la aplicación.
  * **RF-06 (Carga):** El sistema debe cargar automáticamente los alumnos desde el archivo al iniciar la aplicación.
  * **RF-07 (Cálculo Nota Final):** El sistema debe calcular la nota final del alumno basándose en sus tres notas parciales (según la lógica definida en el método `NotaFinal()`).
  * **RF-08 (Cálculo Aprobación):** El sistema debe determinar si un alumno "Aprobó" (si `nota final >= 48`) o "No Aprobó" (si `nota final < 48`).
  * **RF-09 (Visualización):** El sistema debe poder mostrar al usuario la cédula, nombre, nota final y el estado (Aprobó/No Aprobó) de un alumno.

### Requerimientos No Funcionales (RNF)

  * **RNF-01 (Modularidad):** El programa debe estar modularizado, separando la interfaz de usuario, la lógica de negocio y el acceso a datos.
  * **RNF-02 (Encapsulación):** El diseño debe aplicar correctamente los conceptos de abstracción, encapsulación y ocultamiento de información.
  * **RNF-03 (Responsabilidades):** El sistema debe tener una apropiada distribución de responsabilidades entre las clases.
  * **RNF-04 (Inclusiones):** Se debe usar `#pragma once` para proteger contra inclusiones múltiples.
  * **RNF-05 (Espacios de Nombres):** Todo el código debe estar contenido dentro del namespace `program02`.
  * **RNF-06 (Lenguaje):** El sistema debe desarrollarse en C++.
  * **RNF-07 (Bibliotecas):** Solo se deben usar librerías básicas de C++ (std, string, etc.). No se deben usar contenedores de la STL (como `vector`, `map`, etc.), requiriendo el uso de arrays y gestión manual de memoria.
  * **RNF-08 (Reusabilidad):** El código debe ser desarrollado con la intención de ser reutilizable.

-----

# Software Requirements Specification - Programa 01 (Articulo)

Lista de requerimientos para el **Programa 01 (Articulo)**, basados en las consignas del desarrollo práctico y mis especificaciones.

## Requerimientos Funcionales y No Funcionales

### Requerimientos Funcionales (RF)

  * **RF-01 (Crear):** El sistema debe permitir registrar un nuevo artículo especificando su costo base.
  * **RF-02 (Leer):** El sistema debe permitir consultar la información de los artículos existentes (costo base, PVP Detal, PVP Mayor).
  * **RF-03 (Actualizar):** El sistema debe permitir modificar el costo base de un artículo existente.
  * **RF-04 (Eliminar):** El sistema debe permitir eliminar un artículo del sistema.
  * **RF-05 (Persistencia):** El sistema debe guardar los artículos en un archivo para que los datos no se pierdan al cerrar la aplicación.
  * **RF-06 (Carga):** El sistema debe cargar automáticamente los artículos desde el archivo al iniciar la aplicación.
  * **RF-07 (Cálculo Detal):** El sistema debe calcular el Precio de Venta al Detal (PVP Detal) como el `costoBase` + 30%.
  * **RF-08 (Cálculo Mayor):** El sistema debe calcular el Precio de Venta al Mayor (PVP Mayor) como el `costoBase` + 15%.
  * **RF-09 (Visualización):** El sistema debe poder mostrar al usuario los distintos PVP (Detal y Mayor) de un artículo.

### Requerimientos No Funcionales (RNF)

  * **RNF-01 (Modularidad):** El programa debe estar modularizado, separando la interfaz de usuario, la lógica de negocio y el acceso a datos.
  * **RNF-02 (Encapsulación):** El diseño debe aplicar correctamente los conceptos de abstracción, encapsulación y ocultamiento de información.
  * **RNF-03 (Responsabilidades):** El sistema debe tener una apropiada distribución de responsabilidades entre las clases.
  * **RNF-04 (Inclusiones):** Se debe usar `#pragma once` para proteger contra inclusiones múltiples.
  * **RNF-05 (Espacios de Nombres):** Se deben aplicar espacios de nombres para organizar el código.
  * **RNF-06 (Lenguaje):** El sistema debe desarrollarse en C++.
  * **RNF-07 (Bibliotecas):** Solo se debe usar la librería `std` de C++. No se deben usar contenedores de la STL (como `vector`, `map`, etc.), requiriendo el uso de arrays y gestión manual de memoria si es necesario.
  * **RNF-08 (Reusabilidad):** El código debe ser desarrollado con la intención de ser reutilizable.

-----


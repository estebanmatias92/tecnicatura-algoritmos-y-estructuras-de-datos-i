
# Software Requirements Specification

Este documento describe los requerimientos funcionales y no funcionales para el desarrollo de la aplicación solicitada. El objetivo es implementar en C++ un sistema de consola que permita gestionar `Pedidos` ingresados por el usuario, los cuales se asocian a entidades (`Equipos`, `Clientes`, `Empleados`) que existen de forma estática (hardcodeada) en el sistema.

---

## 📋 Requerimientos Funcionales (FR)

### FR-G: Gestión General del Sistema
* **FR-G1:** El sistema debe presentar un menú principal en la consola que permita al usuario navegar a los diferentes módulos (Listar Equipos, Listar Clientes, Listar Empleados, Gestión de Pedidos, Reportes) y salir de la aplicación.
* **FR-G2:** El sistema debe proveer un sub-menú para las operaciones **CRUD** (Alta, Baja, Modificación y Listado) **exclusivamente para el módulo de Pedidos**.

### FR-M1: Módulo de Equipos (Datos Estáticos)
* **FR-M1.1:** El sistema debe **inicializarse con una lista maestra de Equipos pre-cargada (hardcodeada)** en el código fuente.
* **FR-M1.2:** El sistema debe permitir al usuario **Listar** los equipos hardcodeados (para consulta y selección).
* **FR-M1.3:** Los datos hardcodeados deben incluir atributos comunes (ej. ID, nombre, precio).
* **FR-M1.4:** Los datos hardcodeados deben manejar diferentes tipos de equipos (ej. `Ropa`, `Zapatos`, `Antiparras`) con sus atributos específicos (ej. "talle", "color").

### FR-M2: Módulo de Clientes (Datos Estáticos)
* **FR-M2.1:** El sistema debe **inicializarse con una lista de Clientes pre-cargada (hardcodeada)** en el código fuente.
* **FR-M2.2:** El sistema debe permitir al usuario **Listar** los clientes hardcodeados (para consulta y selección).
* **FR-M2.3:** Los datos hardcodeados deben incluir atributos básicos (ej. ID/CUIT, Razón Social).
* **FR-M2.4:** El sistema debe almacenar estos clientes en una colección.

### FR-M3: Módulo de Empleados (Datos Estáticos)
* **FR-M3.1:** El sistema debe **inicializarse con una lista de Empleados pre-cargada (hardcodeada)** en el código fuente.
* **FR-M3.2:** El sistema debe permitir al usuario **Listar** los empleados hardcodeados (para consulta y selección).
* **FR-M3.3:** Los datos hardcodeados deben incluir atributos básicos (ej. Legajo, Nombre, Apellido).
* **FR-M3.4:** El sistema debe almacenar estos empleados en una colección.

### FR-M4: Módulo de Pedidos (CRUD Dinámico)
* **FR-M4.1:** El sistema debe permitir al usuario **Cargar (Alta)** un nuevo pedido (Detalle Pedido) desde la consola.
* **FR-M4.2:** El sistema debe permitir al usuario **Listar** los pedidos existentes.
* **FR-M4.3:** El sistema debe permitir al usuario **Modificar** un pedido existente.
* **FR-M4.4:** El sistema debe permitir al usuario **Eliminar (Baja)** un pedido existente.
* **FR-M4.5:** Al crear un pedido, el sistema debe solicitar al usuario que **asigne un (1) Cliente existente** de la lista hardcodeada (FR-M2.2).
* **FR-M4.6:** Al crear un pedido, el sistema debe solicitar al usuario que **asigne un (1) Empleado existente** (el vendedor) de la lista hardcodeada (FR-M3.2).
* **FR-M4.7:** El sistema debe permitir al usuario **agregar uno o más Equipos** de la lista maestra hardcodeada (FR-M1.2) al pedido.
* **FR-M4.8:** El sistema debe almacenar los pedidos creados por el usuario en una colección.

### FR-R1: Módulo de Reportes
* **FR-R1.1:** El sistema debe tener una opción para **Mostrar los pedidos de los Clientes** (reporte específico).
* **FR-R1.2:** El reporte debe mostrarse por consola.
* **FR-R1.3:** La salida debe detallar, para cada pedido, el cliente que lo realizó, el empleado que lo gestionó y la lista de artículos (equipos) incluidos en dicho pedido.

---

## 🔒 Requerimientos No Funcionales (NFR)

### NFR-T: Restricciones Tecnológicas
* **NFR-T1:** La aplicación debe estar implementada íntegramente en lenguaje **C++**.
* **NFR-T2:** El código final **debe compilar** sin errores para ser considerado.
* **NFR-T3:** Se prohíbe el uso de la biblioteca **STL** (Standard Template Library).
* **NFR-T4:** Solo se permite el uso de bibliotecas estándar de C++ (ej. `iostream`, `string`).

### NFR-A: Arquitectura y Pilares POO
* **NFR-A1:** La solución debe estar diseñada bajo el paradigma de **Programación Orientada a Objetos (POO)**.
* **NFR-A2:** Se deben respetar los pilares de POO (Abstracción, Herencia, Encapsulamiento, Polimorfismo).
* **NFR-A3:** La clase `Equipo` debe ser una **abstracción** (clase base), y `Ropa`, `Zapatos`, etc., deben ser implementaciones (clases derivadas).
* **NFR-A4:** Se deben implementar clases para `Cliente`, `Empleado`, `Equipo` y `Pedido`.
* **NFR-A5:** La aplicación debe estar **modularizada** (ej. una clase `Sistema`).

### NFR-M: Gestión de Memoria y Colecciones
* **NFR-M1:** Todas las colecciones deben implementarse usando **Arrays de Objetos**.
* **NFR-M2:** Se debe dar preferencia al uso de **arrays en el stack** (tamaño fijo estático).
* **NFR-M3:** Para la colección polimórfica de `Equipos`, se debe utilizar un **array de punteros a la clase base** (`Equipo* listaEquipos[MAX_EQUIPOS];`).
* **NFR-M.4:** Los datos de `Cliente`, `Empleado` y `Equipo` (FR-M1.1, FR-M2.1, FR-M3.1) deben ser "hardcodeados" (cargados estáticamente en el código), preferiblemente en el constructor de la clase `Sistema` o en un módulo de inicialización.

### NFR-R: Relaciones y Ciclo de Vida
* **NFR-R1:** Una clase contenedora (ej. `Sistema`) debe gestionar el ciclo de vida de las colecciones maestras.
* **NFR-R2:** La relación entre `Sistema` y las listas maestras (array de `Cliente`, `Empleado`, `Equipo*`, `Pedido`) debe ser de **Composición**.
* **NFR-R3:** La clase `Pedido` **no debe poseer** las instancias de `Cliente`, `Empleado` o `Equipo`.
* **NFR-R4:** La relación entre `Pedido` y `Cliente` debe ser una **Asociación** simple (puntero).
* **NFR-R5:** La relación entre `Pedido` y `Empleado` debe ser una **Asociación** simple (puntero).
* **NFR-R6:** La relación entre `Pedido` y la lista de `Equipos` que contiene debe ser una **Agregación** (array de punteros).

### NFR-I: Interfaz de Usuario
* **NFR-I1:** Toda la interacción con el usuario (entrada de datos y visualización de reportes) debe realizarse a través de la **consola** del sistema.

### NFR-E: Entorno y Alcance
* **NFR-E1:** El proyecto se desarrolla en el contexto académico de un parcial.
* **NFR-E2:** La implementación debe **ceñirse estrictamente** a las consignas solicitadas.


___

## Class Diagram

[![](https://img.plantuml.biz/plantuml/svg/bLRRRjj647tNLmpueaih8RBJF0Hj4LLaNHLseienKBG8WX6vKZPPxZBBPGexRV-b7z2dV89_hBCNKbnRCLAzYBkSovdR6Jwh3MhJb68mXEbq2aibTtpVQCpvxIS91HEGSjnhB1566xR3t2ZDRx1GOojFMZzWJITW4cgrCt-WPbFDtZTSiv99CwqhblCTpz5m9MTb0IEwvGKMh8Otg8jS5GmBhCS3mNO6Z0BDzsyC56GWjpg3-XsN5H82o0NMzS8OpRUDOQjSoKj-m-3H881FsOvBtYA79OcJ5mjpu5JXajU6KIGV1q2_8In4YJcJM782HJ7KvlOVmtCVZS7y7OoU_xYPNio_1lT_CdQAqwMm2Wm4sSDmg7-_MFpwUdc-ofw_p2vVUS6ih0IpwN6IxScBPXVhysoHlcXbrwpWhQH_zdBhB5rrKeHPQxosuLKDUTMg1WI1iALO0zhJW3AZAbHg4doxG_3yozLgtLhqibmQa4tPnX9TTh2Zsm0nblHE3dQ7i4IzHmktG4DOknJN0UpiiKVxrGV52t3bGq4DfbChFnhtRPsHjYlk6PDCeu0HMJYRzmrGppLhpMNEAnInziNjfw8Hv3ZhORXKGi6vJP3kct4fqo6SqVqtRPwElEgoTTGxXBJ1QBcvIcdShBIXONAXdFJDeMZx8FAonRV7hajLk37JHzvvOC7pSLWRLYbD0JaScpYbgZQwK-z5_bSxLkqu-B6QaZYNUrYbhvTNgvVHdSOR6bfbQtpVGzzaDpYnJS7s-5P5LrALMysYAwoO40JsOHTXtbeks311fASavO2wTL5Ra9vANADkJZq7R1w7_szYBfWGExc7HStt4eFpZW0cmC9Jz3xo7MXhiTSKPT_rapi3pNnVfapu63nDlDW4gdXrR2OpwMKFRaENEM-XrKUnXoDTa3A3GZ2VHy-wFzCewlVDxRzkp7zYcj7qkUVWsZFmqFEntHSKuzPQomtw21T4MHYk83I0qxtNKfyj_KueD53Hqk1jtJajDYA9kFxm7UsBwFtV8VOGKjWQATFyWrrC1uGUs4PLU0UMIqbqanEjw8VRxpUi72D-ZAf5X1wR9cHhH_JuiBa5RLNQaXfRYqSaZw_9NkE7GirdXp9sqOU2VFidMR0vY2v2CD7T0P6rUJ9pPATgtkzi8hmXPA9Rp0djT4DZn18Yo9xu62nnMsFNDPH8Uu0Mtw3JcYSm8O_9ezciluIJZfcU4flwLVzPfMuT9mVo-GAri9sJbaw-n9DVlqdRuqyXsTlDfYIbE-z7dTZCdSvYRXAjgr7CH-7_YKrfH5-DRByLneEWcindiqb2zVxUeJkaAS50Ju39_xVJIrmN4frejJXZVMB3kvynFPi9A9ikR_kG9Dhgehcchnmy6B8fUiPaGL-m_m40)](https://editor.plantuml.com/uml/bLRRRjj647tNLmpueaih8RBJF0Hj4LLaNHLseienKBG8WX6vKZPPxZBBPGexRV-b7z2dV89_hBCNKbnRCLAzYBkSovdR6Jwh3MhJb68mXEbq2aibTtpVQCpvxIS91HEGSjnhB1566xR3t2ZDRx1GOojFMZzWJITW4cgrCt-WPbFDtZTSiv99CwqhblCTpz5m9MTb0IEwvGKMh8Otg8jS5GmBhCS3mNO6Z0BDzsyC56GWjpg3-XsN5H82o0NMzS8OpRUDOQjSoKj-m-3H881FsOvBtYA79OcJ5mjpu5JXajU6KIGV1q2_8In4YJcJM782HJ7KvlOVmtCVZS7y7OoU_xYPNio_1lT_CdQAqwMm2Wm4sSDmg7-_MFpwUdc-ofw_p2vVUS6ih0IpwN6IxScBPXVhysoHlcXbrwpWhQH_zdBhB5rrKeHPQxosuLKDUTMg1WI1iALO0zhJW3AZAbHg4doxG_3yozLgtLhqibmQa4tPnX9TTh2Zsm0nblHE3dQ7i4IzHmktG4DOknJN0UpiiKVxrGV52t3bGq4DfbChFnhtRPsHjYlk6PDCeu0HMJYRzmrGppLhpMNEAnInziNjfw8Hv3ZhORXKGi6vJP3kct4fqo6SqVqtRPwElEgoTTGxXBJ1QBcvIcdShBIXONAXdFJDeMZx8FAonRV7hajLk37JHzvvOC7pSLWRLYbD0JaScpYbgZQwK-z5_bSxLkqu-B6QaZYNUrYbhvTNgvVHdSOR6bfbQtpVGzzaDpYnJS7s-5P5LrALMysYAwoO40JsOHTXtbeks311fASavO2wTL5Ra9vANADkJZq7R1w7_szYBfWGExc7HStt4eFpZW0cmC9Jz3xo7MXhiTSKPT_rapi3pNnVfapu63nDlDW4gdXrR2OpwMKFRaENEM-XrKUnXoDTa3A3GZ2VHy-wFzCewlVDxRzkp7zYcj7qkUVWsZFmqFEntHSKuzPQomtw21T4MHYk83I0qxtNKfyj_KueD53Hqk1jtJajDYA9kFxm7UsBwFtV8VOGKjWQATFyWrrC1uGUs4PLU0UMIqbqanEjw8VRxpUi72D-ZAf5X1wR9cHhH_JuiBa5RLNQaXfRYqSaZw_9NkE7GirdXp9sqOU2VFidMR0vY2v2CD7T0P6rUJ9pPATgtkzi8hmXPA9Rp0djT4DZn18Yo9xu62nnMsFNDPH8Uu0Mtw3JcYSm8O_9ezciluIJZfcU4flwLVzPfMuT9mVo-GAri9sJbaw-n9DVlqdRuqyXsTlDfYIbE-z7dTZCdSvYRXAjgr7CH-7_YKrfH5-DRByLneEWcindiqb2zVxUeJkaAS50Ju39_xVJIrmN4frejJXZVMB3kvynFPi9A9ikR_kG9Dhgehcchnmy6B8fUiPaGL-m_m40)
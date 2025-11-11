# Software Requirements Specification

Este proyecto es una aplicación de consola en C++ para una empresa de cosméticos, enfocada en la gestión de pedidos. El sistema permite cargar artículos, registrar clientes y crear pedidos que vinculan artículos a un cliente específico. Siguiendo el paradigma de POO, utiliza clases para modelar las entidades y gestiona las colecciones de datos mediante arrays de punteros a objetos en memoria dinámica (heap), prescindiendo del uso de la biblioteca STL. La salida principal del programa es un reporte por consola que muestra los pedidos de los clientes.

___
## 📋 Requerimientos Funcionales (RF)

Definen **qué** debe hacer el sistema:

- **RF-01 (Gestión de Artículos):** El sistema debe permitir al usuario registrar (dar de alta) nuevos artículos. Como mínimo, se debe poder registrar un código de artículo y su nombre o descripción.

- **RF-02 (Gestión de Clientes):** El sistema debe permitir al usuario registrar (dar de alta) nuevos clientes. Como mínimo, se debe poder registrar un identificador (ID o DNI) y su nombre.

- **RF-03 (Gestión de Pedidos):** El sistema debe permitir al usuario crear un nuevo pedido, el cual debe estar obligatoriamente asociado a un cliente existente.

- **RF-04 (Asignación de Artículos):** El sistema debe permitir al usuario agregar uno o más artículos existentes a un pedido en proceso de creación.

- **RF-05 (Consulta de Pedidos):** El sistema debe tener una función para mostrar por consola un listado de todos los pedidos registrados.

- **RF-06 (Detalle de Consulta):** La consulta de pedidos (RF-05) debe mostrar la información del cliente al que pertenece el pedido y el detalle de los artículos que contiene.

- **RF-07 (Interfaz de Usuario):** Toda la interacción del usuario con el sistema (carga de datos, visualización de reportes) se realizará a través de la consola de comandos.
    

## ⚙️ Requerimientos No Funcionales (RNF)

Definen **cómo** debe ser el sistema y sus restricciones:

- **RNF-01 (Lenguaje):** El sistema debe ser desarrollado íntegramente en C++.
    
- **RNF-02 (Paradigma):** La solución debe estar diseñada siguiendo el paradigma de Programación Orientada a Objetos (POO), utilizando clases para modelar las entidades principales (Cliente, Artículo, Pedido).
    
- **RNF-03 (Bibliotecas):** El sistema solo debe utilizar las bibliotecas estándar de C++ (ej. `iostream`). Queda **explícitamente prohibido** el uso de la Standard Template Library (STL), incluyendo sus contenedores (`std::vector`, `std::list`, `std::map`, etc.).
    
- **RNF-04 (Manejo de Memoria):** La gestión de la memoria para los objetos (Clientes, Artículos, Pedidos) debe ser explícita y manual.
    
- **RNF-05 (Estructura de Datos):** Las colecciones de objetos deben implementarse utilizando arrays definidos en la pila (stack) que almacenen punteros (`*`) a objetos creados dinámicamente en el montículo (heap) mediante el operador `new`.
    
- **RNF-06 (Fiabilidad):** El sistema debe ser responsable de liberar toda la memoria dinámica solicitada (usando `delete` o `delete[]`) antes de finalizar su ejecución, para evitar fugas de memoria (memory leaks).
    
- **RNF-07 (Persistencia):** No se requiere persistencia de datos. Toda la información registrada se mantendrá en memoria y se perderá al cerrar la aplicación.
    
- **RNF-08 (Plataforma):** El sistema debe ser una aplicación de consola (CLI), no se requiere una interfaz gráfica de usuario (GUI).


___

## Class Diagram

[![](https://img.plantuml.biz/plantuml/svg/bLPHRzCm47xFhpZrPMreotZj0rhLLQXI6TEw8II4aEjuxK5Y1ziPAWZ-otu0J_o4_Z7EiPsa1IfDchJaSdVVTv_lphqmbcbR5Nbo1gFH26PAtkEcqepZ_hU4jsWgbhilYVcCicIQ5S1pPipKMethoee5LtA5tmIS9rlC18YYj3ieHB4MsdIYSfJ2xae1IjkjIWBUfRX7YHwCWcUKMfWQBwbXO8N6YeAz4iQYal0z0HWH0nJIakE48kh75Dw_dhxxE5ikvbUtyzK7xyQadRMkA6rjfeAHLxbojcbu3l7Jczl5x6xvffDWsl6E6KgHOLPRhkkd47qzlrnSTcEl6pyVIN_FZYhg3shZptzOwm-SwGtJeOhWx6sHs87H8mPJeOpLqMQY4Z7t2DQLuMrkeWYO3JgQTfmQiDQhaIxv4Gyh18PJmYo-jyf9LQorCn0pb9kQvY61OVWKN0ygwJlS1uLP2nbPD9YDuJJeKK5FHFMIDfZXjKNaJU47MfxklD0_frglfXNEE19l9Y20UkvieqMtILguIC9LjLOg_s-fVa9lH4xBGCaubcV78xdn_nc873XoKfu6-G4p1dskXLyappDoqXMlNmQKWroiofW1afDgeoqaET9ZIOV0iMIvC6EO6wWexqmLfJ9-IOoJ8_IKAFREn-Eq5uKuuH55EE7YnNLbtibup9bOqrvpcnAOmOraP6DmTzNqUtzg5D7tQso5HPcBmPXIp8yLgLUSZo4zetAKhbJwIDTn4j17evVGUz6KHmVKQrdq3fdsIBsyseaU2QT0GR5_h4Ta_yltqLE8DeFqHAO7IZksaLFig2jbwQIDSZDvu_e2UQV1pgIY8ZLkjXRK_H4KPO0qROB2hR5mTHGaZYziagRERqaWNEKY9k_7MsFOpk4mhlA1pqoYLOQHDBTBw8jFOzeAsMJo8BXLUf2cJYfO2S06K194GUUWDTiProFxHqgjZ7CaPcL5W9g4P-v6L1f9MPJxnm8vZSTMi78mTAvQVAbG4prIiTRQLLOmwIxVlXHVQNvoOVrPkSCAuqIi_huvY8LFQKeb3LldmZ79aUvZQc0tTJHqaGub951mcYV91JtIJu4_)](https://editor.plantuml.com/uml/bLPHRzCm47xFhpZrPMreotZj0rhLLQXI6TEw8II4aEjuxK5Y1ziPAWZ-otu0J_o4_Z7EiPsa1IfDchJaSdVVTv_lphqmbcbR5Nbo1gFH26PAtkEcqepZ_hU4jsWgbhilYVcCicIQ5S1pPipKMethoee5LtA5tmIS9rlC18YYj3ieHB4MsdIYSfJ2xae1IjkjIWBUfRX7YHwCWcUKMfWQBwbXO8N6YeAz4iQYal0z0HWH0nJIakE48kh75Dw_dhxxE5ikvbUtyzK7xyQadRMkA6rjfeAHLxbojcbu3l7Jczl5x6xvffDWsl6E6KgHOLPRhkkd47qzlrnSTcEl6pyVIN_FZYhg3shZptzOwm-SwGtJeOhWx6sHs87H8mPJeOpLqMQY4Z7t2DQLuMrkeWYO3JgQTfmQiDQhaIxv4Gyh18PJmYo-jyf9LQorCn0pb9kQvY61OVWKN0ygwJlS1uLP2nbPD9YDuJJeKK5FHFMIDfZXjKNaJU47MfxklD0_frglfXNEE19l9Y20UkvieqMtILguIC9LjLOg_s-fVa9lH4xBGCaubcV78xdn_nc873XoKfu6-G4p1dskXLyappDoqXMlNmQKWroiofW1afDgeoqaET9ZIOV0iMIvC6EO6wWexqmLfJ9-IOoJ8_IKAFREn-Eq5uKuuH55EE7YnNLbtibup9bOqrvpcnAOmOraP6DmTzNqUtzg5D7tQso5HPcBmPXIp8yLgLUSZo4zetAKhbJwIDTn4j17evVGUz6KHmVKQrdq3fdsIBsyseaU2QT0GR5_h4Ta_yltqLE8DeFqHAO7IZksaLFig2jbwQIDSZDvu_e2UQV1pgIY8ZLkjXRK_H4KPO0qROB2hR5mTHGaZYziagRERqaWNEKY9k_7MsFOpk4mhlA1pqoYLOQHDBTBw8jFOzeAsMJo8BXLUf2cJYfO2S06K194GUUWDTiProFxHqgjZ7CaPcL5W9g4P-v6L1f9MPJxnm8vZSTMi78mTAvQVAbG4prIiTRQLLOmwIxVlXHVQNvoOVrPkSCAuqIi_huvY8LFQKeb3LldmZ79aUvZQc0tTJHqaGub951mcYV91JtIJu4_)
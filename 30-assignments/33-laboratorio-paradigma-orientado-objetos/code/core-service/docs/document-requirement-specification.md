Has hecho una observación excelente. Tu estimación es la interpretación correcta del diagrama y los requisitos. El hecho de que la clase base `Figura` defina métodos que no todas las derivadas implementan (según el diagrama) es un indicio claro de que `Figura` debe ser una **clase base abstracta**.

Basándome en esa interpretación y en los requisitos del "Marco Práctico", aquí están los requerimientos funcionales y no funcionales del sistema.

---

## 🎯 Requerimientos Funcionales (RF)

Estos requerimientos definen **qué debe hacer** el sistema.

* **RF-01: Definir la jerarquía de herencia.**
    * El sistema debe implementar una clase base llamada `Figura`.
    * El sistema debe implementar tres clases derivadas de `Figura`: `Circulo`, `Rectangulo` y `Triangulo`.

* **RF-02: Definir la interfaz de la clase base.**
    * La clase `Figura` debe ser una **clase abstracta** (basado en la inferencia del diagrama).
    * `Figura` debe declarar cuatro métodos virtuales: `dibujar()`, `borrar()`, `rotar()` y `mover()`.
    * Los métodos `dibujar()` y `borrar()` deben ser **virtuales puros** (`= 0`), obligando a las clases derivadas a implementarlos.
    * Los métodos `rotar()` y `mover()` deben ser **virtuales (no puros)**, proporcionando una implementación por defecto (probablemente vacía o con un mensaje genérico).

* **RF-03: Implementar las clases derivadas.**
    * Las clases `Circulo`, `Rectangulo` y `Triangulo` deben proveer una implementación (sobrescritura) obligatoria para los métodos `dibujar()` y `borrar()`.

* **RF-04: Gestionar una colección de figuras.**
    * El sistema debe permitir almacenar **5 objetos** de figuras en una colección (array).
    * La colección debe ser capaz de almacenar cualquier tipo de figura derivada (polimorfismo).

* **RF-05: Permitir la selección de objetos por menú.**
    * El sistema debe proveer un menú en tiempo de ejecución que permita al usuario elegir el tipo de objeto (`Circulo`, `Rectangulo` o `Triangulo`) que desea crear para cargar en la colección.

* **RF-06: Demostrar polimorfismo.**
    * El sistema debe ser capaz de recorrer el array de 5 figuras.
    * Al recorrer el array, el sistema debe invocar el método `dibujar()` de cada objeto de forma "genérica".
    * La llamada debe ejecutar la versión correcta de `dibujar()` correspondiente al tipo real de cada objeto almacenado (comportamiento polimórfico).

---

## 📋 Requerimientos No Funcionales (RNF)

Estos requerimientos definen **cómo debe ser** el sistema (restricciones de calidad y diseño).

* **RNF-01 (Implementación):** La colección polimórfica debe implementarse como un **array de punteros del tipo base `Figura*`**, donde cada puntero apuntará a una instancia de una clase derivada.
* **RNF-02 (Modularidad):** El código debe estar modularizado, separando la "Interfaz" (archivos de cabecera `.h`) de la "Implementación" (archivos de código `.cpp`).
* **RNF-03 (Calidad de Código):** El código debe utilizar protección contra inclusiones múltiples (ej. `#pragma once` o *include guards*).
* **RNF-04 (Calidad de Código):** La solución debe implementar y usar espacios de nombres (`namespaces`).
* **RNF-05 (Lenguaje):** El sistema debe desarrollarse usando el lenguaje C++.
* **RNF-06 (Diseño POO):** La solución debe aplicar correctamente los principios de **abstracción**, **encapsulamiento** y **ocultamiento de información**.
* **RNF-07 (Diseño):** El diseño debe tener una apropiada distribución de responsabilidades y estar orientado a la reutilización.


## Class Diagram

[![](https://img.plantuml.biz/plantuml/svg/jLJ1RjD04BtxAqQv9559r1HE2AI6b0eag52ek8_jQJhWtJMpwqYbXF_feGV49-J7cBMTs2YHE7KFjkHvysRclHsV-u0IAbCaGvXC9h1mzePNbM36spyMlh2li8YH970e22uOLu868ITO5EZ9m-Zw4yncqpE8sIAqujoD4_-DROaAXKnXVXw2S5e5Ufyv-vb_49ps80LR2dSbWPDmwv9RLdOoPRW3GoObyKdRtbjVQcSkLhzo9fLOVdbrEJbzCQwRj6WeGWWkwodyl2pXFab0JpjWR1hUnCSyzK473QWSIZ5x1l5rrZ3536m1pGWjfT91UuOmkDzXDWCmA1d2cbLFrMmwdS9hdR83pxU_CMVZF0nK11y6W50WtB0OtCDEeAE4N2NxYZ8QmqjOEywXpZkEJLNxGsYl_CVjGt2vLcyxLEsiWx8Iv_kCRNG3uaAFxoZ4k3Nr8BrY5wHzLLbmiYjtbE1Ne-beN4St1qPv9H9UOux-7vEUToODuOC6Qn4zuFTg-mW1JShR1wlN92KBdcIlUBnlAWtRZ7EMcg0nTy6ILONhkNloV_cFQzuRfU5Uabuokteg-clX9s5lV5XI4LVEgXUwTUz8IBNRhKndGxiShtv6wnej3xvtEXo4zZCaoIOv9vlhB-al)](https://editor.plantuml.com/uml/jLJ1RjD04BtxAqQv9559r1HE2AI6b0eag52ek8_jQJhWtJMpwqYbXF_feGV49-J7cBMTs2YHE7KFjkHvysRclHsV-u0IAbCaGvXC9h1mzePNbM36spyMlh2li8YH970e22uOLu868ITO5EZ9m-Zw4yncqpE8sIAqujoD4_-DROaAXKnXVXw2S5e5Ufyv-vb_49ps80LR2dSbWPDmwv9RLdOoPRW3GoObyKdRtbjVQcSkLhzo9fLOVdbrEJbzCQwRj6WeGWWkwodyl2pXFab0JpjWR1hUnCSyzK473QWSIZ5x1l5rrZ3536m1pGWjfT91UuOmkDzXDWCmA1d2cbLFrMmwdS9hdR83pxU_CMVZF0nK11y6W50WtB0OtCDEeAE4N2NxYZ8QmqjOEywXpZkEJLNxGsYl_CVjGt2vLcyxLEsiWx8Iv_kCRNG3uaAFxoZ4k3Nr8BrY5wHzLLbmiYjtbE1Ne-beN4St1qPv9H9UOux-7vEUToODuOC6Qn4zuFTg-mW1JShR1wlN92KBdcIlUBnlAWtRZ7EMcg0nTy6ILONhkNloV_cFQzuRfU5Uabuokteg-clX9s5lV5XI4LVEgXUwTUz8IBNRhKndGxiShtv6wnej3xvtEXo4zZCaoIOv9vlhB-al)
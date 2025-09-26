# Algoritmos y Estructuras de Datos I - Unidad 08 - Laboratorio 14 - TDA, demo

## Descripción

Este repositorio contiene una serie de implementaciones en C++ que demuestran la evolución y refactorización de un programa simple, desde el uso de estructuras básicas (`struct`) hasta la implementación completa de abstracciones, modularidad y Programación Orientada a Objetos (POO) con Tipos de Datos Abstractos (TDA). Su propósito es educativo, permitiendo observar las diferentes etapas de diseño y las ventajas de la POO en la organización del código.

## Conceptos Demostrados

A través de las diferentes iteraciones, este proyecto ilustra:

-   **Uso de `struct`**: Implementaciones iniciales con estructuras de datos simples.
-   **Abstracción**: Cómo ocultar los detalles de implementación y exponer solo la interfaz necesaria.
-   **Modularidad**: La división del programa en módulos independientes y reutilizables.
-   **Encapsulamiento**: La agrupación de datos y funciones que operan sobre esos datos en una única unidad (clase).
-   **Programación Orientada a Objetos (POO)**: La aplicación de principios como clases, objetos y métodos para crear un diseño más robusto y mantenible.
-   **Tipos de Datos Abstractos (TDA)**: La definición de tipos de datos por su comportamiento, independientemente de su implementación.

## Estructura de directorios

```shell
 .
├──  iteraciones
│   ├──  TAD1.cpp
│   ├──  'TAD R0.cpp'
│   ├──  'TAD R00.cpp'
│   ├──  'TAD R1.cpp'
│   ├──  'TAD R2.cpp'
│   ├──  'TAD R3.cpp'
│   └──  TDA.cpp
└── 󰂺 README.md
```

## Uso

Para compilar y ejecutar cualquiera de las iteraciones, navega al directorio `iteraciones` y compila el archivo `.cpp` deseado. Por ejemplo, para `TDA.cpp`:

```bash
g++ iteraciones/TDA.cpp -o TDA_demo && ./TDA_demo
```

Asegúrate de reemplazar `TDA.cpp` con el nombre del archivo que deseas explorar (e.g., `TAD1.cpp`, `TAD R0.cpp`, etc.).

## Requisitos

-   Compilador C++ (g++ recomendado).
-   Sistema operativo con terminal.
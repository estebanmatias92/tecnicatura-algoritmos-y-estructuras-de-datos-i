# Algoritmos y Estructuras de Datos I - Evolución de la Abstracción

Este repositorio contiene las distintas **iteraciones de código** desarrolladas para comprender los conceptos de **Abstracción**, **Encapsulamiento** y **Tipo de Dato Abstracto (TDA)** en la programación orientada a objetos (POO).

El proyecto ilustra la progresión desde una implementación simple y procedural (datos y lógica separados) hasta la definición de un TDA robusto con ocultamiento de la información (encapsulamiento).

## 🚀 Progresión de la Abstracción

El proyecto se organiza en diferentes archivos, cada uno representando una etapa clave en la evolución de un TDA para un sistema de gestión de estudiantes.

| Archivo / Carpeta | Concepto Principal | Propiedad Emergente | Descripción |
| :--- | :--- | :--- | :--- |
| `iter1-Simple.cpp` | **Programación Procedural** | Datos Globales (Sin Encapsulamiento) | Los datos (`struct Estudiante`) y las funciones que los manipulan (`altaEstudiante()`) están completamente **separados** y operan sobre variables globales. |
| `iter2-dos-struct.cpp` | **Inicio del TDA** | Agrupamiento | Se agrupa la lógica (funciones) y los datos en un solo `struct`, `SistemaEstudiantes`. Es un TDA, pero los datos **siguen siendo públicos**. |
| `iter3-encapsulamiento.cpp` | **Abstracción de Representación** | Ocultamiento de la Estructura | Se cambia la forma de almacenar la información (de un `array` de `struct` a `arrays` paralelos), demostrando que el TDA puede **ocultar** su estructura interna. Aún no usa `private`. |
| `iter4-ociultamiento.cpp` | **Encapsulamiento Completo** | Ocultamiento de la Información (`private`) | Se introduce la palabra clave **`private`** para ocultar los atributos y los métodos internos (`buscarEstudiante`), forzando al usuario a interactuar solo a través de la interfaz pública. |
| Carpeta `5.` (Archivos `.h` y `.cpp`) | **Abstracción de Interfaz** | Modularidad | La separación en archivos (`interfaz.h` y `implementacion.cpp`) completa la abstracción. La interfaz (`.h`) actúa como un **contrato** para el usuario, que no necesita ver la complejidad de la implementación (`.cpp`). |

-----

## 🛠️ Cómo Compilar y Ejecutar

El código está escrito en C++ y puede ser compilado con cualquier compilador moderno como `g++`.

### Compilación de las Primeras Iteraciones (1 a 4)

Las iteraciones 1, 2, 3 y 4 son archivos únicos y se compilan directamente:

```bash
# Ejemplo para la iteración 4
g++ iter4-ociultamiento.cpp -o sistema-v4
./sistema-v4
```

### Compilación de la Iteración Final (5)

La Iteración 5 (`5.1 main.cpp`, `5.2 interfaz.h`, `5.3 implementacion.cpp`) requiere compilar múltiples archivos fuente.

```bash
# Compilar todos los archivos .cpp
g++ 5.1\ main.cpp 5.3\ implementacion.cpp -o sistema-v5

# Ejecutar el programa
./sistema-v5
```
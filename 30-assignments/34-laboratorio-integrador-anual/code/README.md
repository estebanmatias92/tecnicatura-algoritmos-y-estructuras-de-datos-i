# Algoritmos y Estructuras de Datos I - Parcial 02 - Simulación

## Descripción

Este proyecto es una aplicación de consola en C++ que simula un sistema de gestión de pedidos para "Ukelele Chicken - Boutique de Carnes" (una carnicería en Santa Clara del Mar). El sistema permite gestionar `Pedidos` que se asocian a `Clientes` y `Empleados` preexistentes, y que contienen distintos tipos de `Animales` (como `Pollo`, `Vacuno` y `Cerdo`).

La arquitectura sigue el paradigma de **Programación Orientada a Objetos (POO)**, con una clara separación de responsabilidades. La gestión de datos se realiza manualmente sin el uso de la **Standard Template Library (STL)**, utilizando arrays estáticos en el stack para las colecciones principales y un array de punteros para la gestión polimórfica de `Animales`.

## Características

- **Gestión de Entidades**:
  - Clases para modelar el dominio: `Cliente`, `Empleado`, `Pedido` y una jerarquía de herencia para `Animal` (`Pollo`, `Vacuno`, `Cerdo`).
  - Una clase `Sistema` que centraliza la lógica de negocio y la interacción con el usuario.
- **Programación Orientada a Objetos (POO)**:
  - **Abstracción**: Clase base abstracta `Animal` con métodos virtuales puros (`comer()`, `dormir()`).
  - **Herencia**: Clases `Pollo`, `Vacuno`, `Cerdo` heredan de `Animal`.
  - **Polimorfismo**: Uso de métodos virtuales (`mostrar()`, `comer()`, `dormir()`) para describir los diferentes tipos de animales.
  - **Encapsulamiento**: Atributos privados y métodos públicos en todas las clases.
- **Gestión de Memoria y Relaciones**:
  - **Composición**: El `Sistema` gestiona el ciclo de vida de las colecciones.
  - **Asociación**: El `Pedido` se asocia a un `Cliente` y un `Empleado` mediante punteros.
  - **Agregación**: El `Pedido` agrupa una colección de `Animales` mediante un array de punteros.
  - Las colecciones de `Clientes`, `Empleados` y `Pedidos` se almacenan en arrays en el **stack**.
  - La colección polimórfica de `Animales` se gestiona en el **heap** a través de un array de punteros.
- **Interfaz de Usuario por Consola**:
  - Menú de opciones interactivo para navegar por los módulos del sistema.
  - Operaciones CRUD completas para la entidad `Pedido` (Alta, Baja, Modificación, Listado).
  - Demo de polimorfismo mostrando comportamiento de diferentes animales.
- **Modularidad y Calidad de Código**:
  - Código organizado en namespaces (`app`, `app::domain`, `app::utils`).
  - Estructura de proyecto basada en el layout **Pitchfork**.
  - Protección contra inclusiones múltiples con _include guards_.
  - Documentación con comentarios doxygen.

## Estructura de directorios

```shell
.
├── compose.yaml
├── core-service
│   ├── build.sh
│   ├── compose.yaml
│   ├── data
│   ├── Dockerfile
│   ├── include
│   │   ├── app
│   │   │   └── Sistema.h
│   │   ├── domain
│   │   │   ├── Animal.h
│   │   │   ├── Cliente.h
│   │   │   ├── Empleado.h
│   │   │   └── Pedido.h
│   │   └── utils
│   │       └── helpers.h
│   ├── run.sh
│   └── src
│       ├── app
│       │   └── Sistema.cpp
│       ├── domain
│       │   ├── Animal.cpp
│       │   ├── Pollo.cpp
│       │   ├── Vacuno.cpp
│       │   ├── Cerdo.cpp
│       │   ├── Cliente.cpp
│       │   ├── Empleado.cpp
│       │   └── Pedido.cpp
│       ├── main.cpp
│       └── utils
│           └── helpers.cpp
├── Makefile
└── README.md
```

## Uso

### Ejecución sin Docker (desde el directorio `core-service`)

Para compilar y ejecutar la aplicación directamente en tu sistema:

1.  Navega al directorio `core-service`:
    ```bash
    cd ./core-service
    ```
2.  Asegúrate de que los scripts tengan permisos de ejecución:
    ```bash
    chmod +x ./build.sh ./run.sh
    ```
3.  Compila la aplicación. El script creará el directorio `build` si no existe.
    ```bash
    ./build.sh
    ```
4.  Ejecuta la aplicación:
    ```bash
    ./run.sh
    ```

### Para despliegue con Docker (desde la raíz del proyecto)

Ejecutar el siguiente comando desde del directorio raíz:

```shell
# Con Make
make up-prod

# Con compose
docker compose up --build
```

### Para desarrollo con Docker (desde la raíz del proyecto)

Ejecutar:

```shell
# Con Make
make run-dev

# Con compose desde ./core-service
docker compose --profile interactive run --rm dev_interactive
```

## Requisitos

- Compilador C++ (g++ recomendado).
- Docker y Docker Compose (opcional, para entornos contenerizados).
- `make` (opcional, para usar los atajos del Makefile).
- Un sistema operativo con terminal (Linux, macOS, o WSL en Windows).

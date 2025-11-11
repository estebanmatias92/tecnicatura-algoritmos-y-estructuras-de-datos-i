# Algoritmos y Estructuras de Datos I - Parcial 02 - Simulacion

## Descripción

Programa en C++ que implementa un sistema de gestión para una empresa de cosméticos. Permite registrar clientes, artículos y crear pedidos, asociando artículos a clientes específicos. El sistema sigue el paradigma de Programación Orientada a Objetos (POO) y gestiona colecciones de datos mediante arrays de punteros a objetos en memoria dinámica (heap), sin utilizar la Standard Template Library (STL). La aplicación es de consola y genera reportes de pedidos.

## Características

- **Gestión de Entidades**:
  - Clases `Cliente`, `Articulo` y `Pedido` para modelar las entidades del negocio.
  - `SistemaGestion` centraliza la lógica de negocio y la administración de las colecciones.
- **Programación Orientada a Objetos**:
  - Abstracción, encapsulamiento y gestión de relaciones entre objetos.
- **Gestión Manual de Memoria**:
  - Uso explícito de `new` y `delete` para la asignación y liberación de memoria en el heap.
  - Colecciones implementadas como arrays estáticos de punteros.
- **Interfaz de usuario interactiva**:
  - Menú de opciones claro y fácil de usar para cargar datos y visualizar reportes.
  - Mensajes informativos para guiar al usuario.
- **Modularidad**:
  - Código organizado en módulos (`app`, `domain`, `utils`) para facilitar el mantenimiento y la escalabilidad.
- **Calidad de Código**:
  - Uso de `namespaces` para organizar el código.
  - Protección contra inclusiones múltiples (`#pragma once` o *include guards*).

## Estructura de directorios

```shell
 .
├──  compose.yaml
├──  core-service
│   ├──  build.sh
│   ├──  compose.yaml
│   ├──  data
│   ├──  Dockerfile
│   ├──  include
│   │   ├──  app
│   │   │   └──  app_entrypoint.h
│   │   ├──  domain
│   │   │   ├──  Articulo.h
│   │   │   ├──  Cliente.h
│   │   │   ├──  Pedido.h
│   │   │   └──  SistemaGestion.h
│   │   └──  utils
│   │       └──  helpers.h
│   ├──  run.sh
│   └── 󰣞 src
│       ├──  app
│       │   └──  app_entrypoint.cpp
│       ├──  domain
│       │   ├──  Articulo.cpp
│       │   ├──  Cliente.cpp
│       │   ├──  Pedido.cpp
│       │   └──  SistemaGestion.cpp
│       ├──  main.cpp
│       └──  utils
│           └──  helpers.cpp
├──  Makefile
└── 󰂺 README.md
```

## Uso

### Ejecución sin Docker (desde el directorio `core-service`)

Para compilar y ejecutar la aplicación directamente en tu sistema:

1.  Navega al directorio `core-service`:
    ```bash
    cd ./core-service
    ```
2.  Crea el directorio `build` si no existe:
    ```bash
    mkdir -p build
    ```
3.  Asegúrate de que los scripts de compilación y ejecución tengan permisos de ejecución:
    ```bash
    chmod +x ./build.sh ./run.sh
    ```
4.  Compila la aplicación:
    ```bash
    ./build.sh
    ```
5.  Ejecuta la aplicación:
    ```bash
    ./run.sh
    ```

### Para despliegue con Docker (desde la raíz del proyecto)

Ejecutar el siguiente comando desde directorio raiz:

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

- Compilador C++ (g++ recomendado)

- Docker (opcional, solo para entornos containerizados)

- Sistema operativo con terminal

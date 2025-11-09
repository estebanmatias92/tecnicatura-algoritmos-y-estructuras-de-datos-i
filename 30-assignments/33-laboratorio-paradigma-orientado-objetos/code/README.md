# Algoritmos y Estructuras de Datos I - Unidad 11 - Laboratorio 19 - Paradigma Orientado Objeto

## Descripción

Programa en C++ que implementa una jerarquía de clases para figuras geométricas (`Figura`, `Circulo`, `Rectangulo`, `Triangulo`), demostrando los principios de la Programación Orientada a Objetos como la abstracción, el polimorfismo y la herencia. Permite gestionar una colección de figuras y realizar operaciones genéricas sobre ellas.

## Características

- **Jerarquía de Herencia**:
  - Clase base abstracta `Figura` con métodos virtuales puros (`dibujar`, `borrar`) y virtuales (`rotar`, `mover`).
  - Clases derivadas `Circulo`, `Rectangulo` y `Triangulo` que implementan los métodos abstractos.
- **Polimorfismo**:
  - Gestión de una colección de figuras mediante punteros a la clase base `Figura*`.
  - Invocación polimórfica de métodos para demostrar el comportamiento específico de cada figura.
- **Interfaz de usuario interactiva**:
  - Menú de opciones claro y fácil de usar para crear y manipular figuras.
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
│   │   │   ├──  figura.h
│   │   │   ├──  circulo.h
│   │   │   ├──  rectangulo.h
│   │   │   └──  triangulo.h
│   │   └──  utils
│   │       └──  helpers.h
│   ├──  run.sh
│   └── 󰣞 src
│       ├──  app
│       │   └──  app_entrypoint.cpp
│       ├──  domain
│       │   ├──  circulo.cpp
│       │   ├──  rectangulo.cpp
│       │   └──  triangulo.cpp
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
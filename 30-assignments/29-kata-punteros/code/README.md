# Algoritmos y Estructuras de Datos I - Unidad 10 - Kata 03 - Punteros

## Descripción

Programa en C++ que explora la manipulación de punteros, aritmética de punteros y gestión de memoria dinámica (heap) en C++. Demuestra el comportamiento de los operadores de incremento y decremento con punteros y la importancia de la liberación correcta de memoria.

## Características

- **Gestión de Memoria Dinámica**: Asignación y liberación explícita de memoria en el heap utilizando `new` y `delete`.
- **Aritmética de Punteros**: Demostración de los operadores `++` y `--` con punteros y sus implicaciones en la dirección de memoria.
- **Comportamiento Indefinido (Undefined Behavior)**: Ilustración de un caso donde la desreferenciación de un puntero a una ubicación de memoria no asignada puede llevar a un comportamiento indefinido.
- **Prevención de Punteros Colgantes**: Uso de `nullptr` para evitar punteros colgantes después de liberar memoria.
- **Conceptos Fundamentales de Punteros**: Refuerzo de la comprensión de cómo los punteros almacenan direcciones de memoria y cómo se manipulan.

## Estructura de directorios

```shell
 .
├──  .env
├── 󰊢 .gitignore
├──  compose.yaml
├──  core-service
│   ├──  .dockerignore
│   ├──  compose.yaml
│   ├──  Dockerfile
│   └── 󰣞 src
│       ├──  app
│       └──  main.cpp
├──  Makefile
└── 󰂺 README.md
```

## Uso

### Para ejecución directa

Compilar con:

```shell
# From ./core-service
mkdir -p build
g++ ./src/main.cpp -o ./build/main
```

Ejecutar con:

```shell
# From ./core-service
./build/main
```

### Para despliegue con Docker

Ejecutar el siguiente comando desde directorio raiz:

```shell
# With Make
make up-prod

# With compose
docker compose up --build
```

### Para desarrollo

Ejecutar:

```shell
# With Make
make run-dev

# With compose from ./core-service
docker compose --profile interactive run --rm dev_interactive
```

## Requisitos

- Compilador C++ (g++ recomendado)

- Docker (opcional, solo para entornos containerizados)

- Sistema operativo con terminal

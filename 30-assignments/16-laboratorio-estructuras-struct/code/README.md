# Algoritmos y Estructuras de Datos I - Unidad 05 - Laboratorio 11 - Estructuras Struct

## Descripción

Programa en C++ que resuelve ejercicios prácticos de la unidad 2, incluyendo cálculos matemáticos, conversiones y manejo de variables.

## Características

- Cálculo de edad a partir de fecha de nacimiento
- Operaciones con múltiples valores (promedio, producto)
- Cálculo de volumen de cono
- Conversiones: Fahrenheit a Celsius y segundos a horas/minutos
- Precisión decimal con variables double
- Interacción básica con usuario

## Estructura de directorios

```shell
 .
├──  .env
├──  .gitignore
├──  compose.yaml
├──  core-service
│   ├──  .dockerignore
│   ├──  compose.yaml
│   ├──  Dockerfile
│   └── 󱧼 src
│       └──  main.cpp
├──  Makefile
└──  README.md
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

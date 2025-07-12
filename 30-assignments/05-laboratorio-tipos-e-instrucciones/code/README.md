# Algoritmos y Estructuras de Datos I - Unidad 02 - Laboratorio 02 - Tipos e Instrucciones

## Descripción

Este es un programa simple en C++ que resuelve los ejercicios propuestos en el Trabajo Práctico de la Unidad 2.1 de Algoritmos y Estructuras de Datos I. El programa realiza operaciones matemáticas básicas y calcula volúmenes utilizando variables y operadores.

## Características

- **Operaciones Aritméticas Básicas**: Realiza sumas, restas, multiplicaciones y divisiones.
- **Cálculo de Volumen de Habitación**: Calcula el volumen de una habitación dadas sus dimensiones.
- **Cálculo de Volumen de Cono**: Calcula el volumen de un cono utilizando la fórmula proporcionada.
- **Uso de Variables `double`**: Emplea variables de doble precisión para asegurar resultados exactos en cálculos decimales.

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

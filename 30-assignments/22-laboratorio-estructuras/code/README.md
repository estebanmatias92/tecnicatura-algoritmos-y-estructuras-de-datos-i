# Algoritmos y Estructuras de Datos I - Unidad 06 - Laboratorio 13 - Estructuras

## Descripción

Programa en C++ para generación y visualización de arrays numéricos con diferentes criterios de selección, utilizando estructuras de datos básicas.

## Características

- **Generación de arrays**:
  - 100 primeros números enteros
  - Números primos entre 1-100
  - Números impares entre 1-100
- **Visualización organizada**:
  - 10 números por línea para mejor legibilidad
  - Conteo preciso de elementos
- **Algoritmos eficientes**:
  - Detección óptima de números primos
  - Identificación rápida de impares
- **Tipos personalizados**:
  - Uso de typedef para claridad en enteros y booleanos

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

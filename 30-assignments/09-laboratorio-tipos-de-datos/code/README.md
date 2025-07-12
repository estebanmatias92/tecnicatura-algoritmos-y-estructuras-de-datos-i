# Algoritmos y Estructuras de Datos I - Unidad 02 - Laboratorio 05 - Tipos de Datos

## Descripción

Programa en C++ que implementa funciones para cálculos comerciales, académicos y numéricos mediante un menú interactivo.

## Características

- Cálculo de descuentos por cantidad de productos  
- Determinación de salarios con horas extras  
- Evaluación de promedio y estado académico  
- Procesamiento de secuencias numéricas (promedio, sumas condicionales)  
- Validación de entrada ordenada (números crecientes)  
- Sumatorias específicas (pares/impares, rango 1-N)  
- Manejo de vectores para almacenamiento dinámico  

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

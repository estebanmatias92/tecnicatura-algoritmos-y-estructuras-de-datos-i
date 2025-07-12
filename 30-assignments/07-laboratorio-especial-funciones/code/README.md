# Algoritmos y Estructuras de Datos I - Unidad 02 - Laboratorio 04 - Especial Funciones

## Descripción

Programa en C++ que implementa funciones matemáticas, operaciones aritméticas, verificaciones lógicas y resolución de ecuaciones a través de un menú interactivo.

## Características

- Conversión de temperaturas (Celsius ↔ Fahrenheit)
- Operaciones aritméticas básicas (suma, resta, multiplicación, división)
- Verificación de números primos y rangos numéricos
- Cálculo de perímetros (cuadrado, rectángulo, triángulo)
- Resolución de ecuaciones lineales
- Cálculo de notas finales con ponderaciones
- Captura y visualización de datos personales (edad, sexo, altura)

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

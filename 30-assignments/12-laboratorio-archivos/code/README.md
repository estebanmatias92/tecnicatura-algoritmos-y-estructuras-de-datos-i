# Algoritmos y Estructuras de Datos I - Unidad 04 - Laboratorio 08 - Archivos

## Descripción

Programa en C++ para gestión de archivos de texto, que permite almacenar, visualizar y analizar contenido textual con diversas operaciones.

## Características

- **Almacenamiento de frases**: Guarda texto en archivos con modo append
- **Visualización de contenido**: Muestra el contenido completo del archivo
- **Análisis textual**:
  - Conteo de palabras por línea y total
  - Cálculo de promedio de palabras por línea
  - Detección de la palabra más larga
- **Manejo seguro de archivos**: Verificación de apertura correcta
- **Tipos personalizados**: typedef para claridad en nombres de archivos y frases

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

# Algoritmos y Estructuras de Datos I - Unidad 05 - Laboratorio 10 - Arreglos y Matrices

## Descripción

Programa en C++ para gestión de inventarios, análisis de texto y operaciones con matrices mediante un menú interactivo, con capacidad de persistencia de datos en archivos.

## Características

- **Gestión avanzada de productos**:
  - CRUD completo (Crear, Leer, Actualizar, Eliminar)
  - Búsqueda por valor máximo
  - Persistencia en archivos
- **Análisis de texto completo**:
  - Descomposición de frases en palabras
  - Cálculo de longitudes
  - Manejo de límites de tamaño
- **Operaciones matriciales avanzadas**:
  - Suma/Resta/Multiplicación
  - Traspuesta y puntos silla
  - Tamaño configurable
- **Tipos estructurados**:
  - Productos con ID, precio y unidades
  - Matrices NxN con constantes configurables
- **Manejo robusto de archivos**:
  - Lectura/escritura segura
  - Modo append para añadir productos

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

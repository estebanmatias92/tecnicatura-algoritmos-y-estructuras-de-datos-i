# Algoritmos y Estructuras de Datos I - Unidad 03 - Laboratorio 06 - Datos e Instrucciones

## Descripción

Programa en C++ para gestión de sistemas comerciales mediante tipos enumerados y estructuras, con menú interactivo para diferentes módulos.

## Características

- **Sistema de comandas** para restaurante (mesas, mozos, tipos de platos)  
- **Reservas de vuelos** con clases, aeropuertos y datos de pasajeros  
- **Pedidos a mayorista** para verdulería (proveedores, frutas, fechas)  
- **Tipos personalizados** con enumerados para opciones específicas  
- **Validación de entrada** y visualización formateada de datos  

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

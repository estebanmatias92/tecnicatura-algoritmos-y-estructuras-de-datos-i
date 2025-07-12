# Algoritmos y Estructuras de Datos I - Unidad 02 - Laboratorio 04 - Tipos e Instrucciones

## Descripción

Programa en C++ para gestión completa de clientes con persistencia en archivos, que permite realizar operaciones CRUD (Crear, Leer, Actualizar, Eliminar) sobre registros de clientes.

## Características

- **Gestión completa de clientes**:  
  - Altas con generación automática de códigos  
  - Bajas por código de cliente  
  - Modificación de datos existentes  
- **Búsqueda y listado**:  
  - Listado completo con formato tabular  
  - Búsqueda individual por código  
- **Persistencia de datos**:  
  - Carga automática al iniciar  
  - Guardado automático al modificar  
- **Validaciones y seguridad**:  
  - Límite máximo de clientes  
  - Manejo seguro de entrada/salida  
- **Interfaz intuitiva**:  
  - Menú interactivo claro  
  - Formateo profesional de salidas  

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

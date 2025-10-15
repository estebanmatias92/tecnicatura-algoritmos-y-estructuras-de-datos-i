# Algoritmos y Estructuras de Datos I - Unidad 06 - Laboratorio 11 - Ordenamiento

## Descripción

Programa en C++ para la gestión de un listado de alumnos utilizando un array estático. Permite cargar, guardar, insertar, eliminar, buscar y ordenar registros de alumnos, persistiendo los datos en un archivo de texto.

## Características

- **Gestión de Alumnos**:
  - Carga y guarda automática de datos de alumnos desde/hacia `Alumnos.txt`.
  - Capacidad máxima de 100 alumnos.
- **Operaciones CRUD**:
  - **Listar**: Muestra todos los alumnos registrados.
  - **Insertar**: Agrega un nuevo alumno, validando legajos duplicados.
  - **Eliminar**: Borra un alumno por su número de legajo.
  - **Buscar**: Encuentra y muestra los detalles de un alumno por legajo.
- **Ordenamiento Flexible**:
  - Permite ordenar el listado de alumnos por legajo, nombre, carrera o año.
  - Soporta ordenamiento ascendente y descendente.
- **Interfaz de Usuario Interactiva**:
  - Menú de opciones claro para facilitar la interacción.
  - Manejo básico de errores en la entrada de usuario.
- **Estructuras de Datos**:
  - Uso de `struct tAlumno` para representar la información de cada estudiante.
  - `struct ListaAlumnos` para gestionar el array estático de alumnos.

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

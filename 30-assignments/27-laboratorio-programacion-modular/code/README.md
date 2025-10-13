# Algoritmos y Estructuras de Datos I - Unidad 09 - Laboratorio 15 - Programación Modular

## Descripción

Programa en C++ para la administración de alumnos, permitiendo gestionar una lista de estudiantes con operaciones de alta, baja, búsqueda, listado y ordenamiento. Utiliza estructuras de datos básicas y persistencia de datos en archivo.

## Características

- **Gestión completa de alumnos**:
  - Alta de nuevos alumnos con validación de legajo único.
  - Baja de alumnos por número de legajo.
  - Búsqueda de alumnos por número de legajo.
  - Listado de todos los alumnos registrados.
  - Ordenamiento de la lista de alumnos por legajo (ascendente/descendente).
- **Persistencia de datos**:
  - Carga automática de datos desde un archivo (`Alumnos.txt`) al iniciar.
  - Guardado automático de cambios en el archivo al salir o bajo demanda.
- **Interfaz de usuario interactiva**:
  - Menú de opciones claro y fácil de usar.
  - Mensajes informativos y de error para guiar al usuario.
- **Modularidad**:
  - Código organizado en módulos (`app`, `domain`, `persistence`, `utils`) para facilitar el mantenimiento y la escalabilidad.
- **Tipos personalizados**:
  - Uso de `struct` y `typedef` para definir `tRegistro` (alumno) y `tListaAlumnos` (lista de alumnos).

## Estructura de directorios

```shell
 .
├──  compose.yaml
├──  core-service
│   ├──  build.sh
│   ├──  compose.yaml
│   ├──  Dockerfile
│   ├──  include
│   │   ├──  app
│   │   │   └──  app_entrypoint.h
│   │   ├──  domain
│   │   │   ├──  alumno_manager.h
│   │   │   └──  persistence_manager.h
│   │   ├──  types
│   │   │   └──  alumno_types.h
│   │   └──  utils
│   │       └──  helpers.h
│   ├──  run.sh
│   └── 󰣞 src
│       ├──  app
│       │   └──  app_entrypoint.cpp
│       ├──  domain
│       │   ├──  alumno_manager.cpp
│       │   └──  persistence_manager.cpp
│       ├──  main.cpp
│       ├──  types
│       │   └──  alumno_types.cpp
│       └──  utilities
│           └──  helpers.cpp
├──  Makefile
└── 󰂺 README.md
```

## Uso

### Ejecución sin Docker (desde el directorio `core-service`)

Para compilar y ejecutar la aplicación directamente en tu sistema:

1.  Navega al directorio `core-service`:
    ```bash
    cd ./core-service
    ```
2.  Crea el directorio `build` si no existe:
    ```bash
    mkdir -p build
    ```
3.  Asegúrate de que los scripts de compilación y ejecución tengan permisos de ejecución:
    ```bash
    chmod +x ./build.sh ./run.sh
    ```
4.  Compila la aplicación:
    ```bash
    ./build.sh
    ```
5.  Ejecuta la aplicación:
    ```bash
    ./run.sh
    ```

### Para despliegue con Docker (desde la raíz del proyecto)

Ejecutar el siguiente comando desde directorio raiz:

```shell
# Con Make
make up-prod

# Con compose
docker compose up --build
```

### Para desarrollo con Docker (desde la raíz del proyecto)

Ejecutar:

```shell
# Con Make
make run-dev

# Con compose desde ./core-service
docker compose --profile interactive run --rm dev_interactive
```

## Requisitos

- Compilador C++ (g++ recomendado)

- Docker (opcional, solo para entornos containerizados)

- Sistema operativo con terminal

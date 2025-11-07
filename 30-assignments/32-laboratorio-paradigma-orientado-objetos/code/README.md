# Algoritmos y Estructuras de Datos I - Unidad 11 - Laboratorio 18 - Paradigma Orientado Objetos

## Descripción

Este proyecto es una aplicación de consola en C++ que demuestra los principios del Paradigma Orientado a Objetos (POO) a través de una serie de programas modulares. La aplicación principal presenta un menú interactivo que permite ejecutar cada subprograma, cada uno enfocado en una entidad de negocio diferente y con persistencia de datos en archivos.

## Características

El programa incluye los siguientes módulos:

1.  **Gestión de Artículos**: Permite realizar un CRUD (Crear, Leer, Actualizar, Eliminar) de artículos. Calcula automáticamente el precio de venta al detal (+30%) y al por mayor (+15%) a partir de un costo base. Los datos se guardan en `articulos.dat`.
2.  **Gestión de Alumnos**: Permite gestionar datos de alumnos, incluyendo cédula, nombre y tres notas parciales. Calcula la nota final, determina si el alumno aprobó (nota >= 48) y persiste los datos en `alumnos.dat`.
3.  **Gestión de Rectángulos**: Permite administrar rectángulos, especificando su base y altura. Calcula automáticamente el área y el perímetro. Los datos se guardan en `rectangulos.dat`.
4.  **Gestión de Personas**: Permite registrar personas con su nombre y fecha de nacimiento. Calcula la edad de la persona basándose en una fecha "actual" ingresada por el usuario. La información se persiste en `personas.dat`.

## Estructura de directorios

```shell
 .
├──  compose.yaml
├──  core-service
│   ├──  alumnos.dat
│   ├──  articulos.dat
│   ├── 󱧼 build
│   │   └── 󰡯 main
│   ├──  build.sh
│   ├──  compose.yaml
│   ├──  Dockerfile
│   ├──  docs
│   │   ├──  program-01
│   │   │   ├──  class-diagram.md
│   │   │   └──  software-requirements-specification.md
│   │   ├──  program-02
│   │   │   ├──  class-diagram.md
│   │   │   └──  software-requirements-specification.md
│   │   ├──  program-03
│   │   │   ├──  class-diagram.md
│   │   │   └──  software-requirements-specification.md
│   │   └──  program-04
│   │       ├──  class-diagram.md
│   │       └──  software-requirements-specification.md
│   ├──  include
│   │   ├──  homework
│   │   │   ├──  homework.h
│   │   │   └──  utils.h
│   │   ├──  program-01
│   │   │   └──  program.h
│   │   ├──  program-02
│   │   │   └──  program.h
│   │   ├──  program-03
│   │   │   └──  program.h
│   │   └──  program-04
│   │       └──  program.h
│   ├──  personas.dat
│   ├──  rectangulos.dat
│   ├──  run.sh
│   └── 󰣞 src
│       ├──  homework
│       │   ├──  homework.cpp
│       │   └──  utils.cpp
│       ├──  main.cpp
│       ├──  program-01
│       │   └──  program.cpp
│       ├──  program-02
│       │   └──  program.cpp
│       ├──  program-03
│       │   └──  program.cpp
│       └──  program-04
│           └──  program.cpp
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

Ejecutar el siguiente comando para una sesión interactiva:

```shell
# Con Make
make run-dev
```

## Requisitos

- Compilador C++ (g++ recomendado)
- Docker (opcional, solo para entornos containerizados)
- Sistema operativo con terminal
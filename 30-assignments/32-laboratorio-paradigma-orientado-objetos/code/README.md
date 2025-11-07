# Algoritmos y Estructuras de Datos I - Unidad 10 - Laboratorio 17 - Punteros y Memoria Dinámica

## Descripción

Este proyecto contiene la resolución de una serie de ejercicios prácticos sobre punteros y memoria dinámica en C++. El programa presenta un menú interactivo que permite ejecutar cada uno de los ejercicios de forma individual.

## Características

El programa incluye los siguientes ejercicios:

1.  **Números Pares y Posición en Memoria**: Rellena un array de 10 números y, utilizando punteros, indica cuáles son números pares y su posición en memoria.
2.  **Menor Elemento de un Arreglo**: Rellena un arreglo con `n` números y, utilizando punteros, determina el menor elemento del vector.
3.  **Ordenar Arreglo Dinámico**: Pide al usuario `N` números, los almacena en un arreglo dinámico, los ordena en orden ascendente y los muestra en pantalla.
4.  **Contador de Vocales**: Pide al usuario una cadena de caracteres e indica cuántas veces aparece cada vocal ('a', 'e', 'i', 'o', 'u') en la cadena, utilizando punteros.
5.  **Suma de Matrices Dinámicas**: Calcula la suma de dos matrices dinámicas.
6.  **Matriz Traspuesta**: Lee una matriz dinámica de `NxM` y crea su matriz traspuesta.
7.  **Mejor Promedio de Alumnos**: Utiliza una estructura `alumno` para almacenar los datos de 3 alumnos, comprueba cuál de los 3 tiene el mejor promedio y muestra sus datos.

## Estructura de directorios

```shell
 .
├──  compose.yaml
├──  core-service
│   ├──  build.sh
│   ├──  compose.yaml
│   ├──  Dockerfile
│   ├──  include
│   │   └──  homework
│   │       └──  homework.h
│   ├──  run.sh
│   └── 󰣞 src
│       ├──  homework
│       │   └──  homework.cpp
│       └──  main.cpp
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
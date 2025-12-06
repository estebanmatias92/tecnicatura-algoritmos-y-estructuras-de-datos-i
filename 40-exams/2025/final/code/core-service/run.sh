#!/bin/bash
# Script para ejecutar la aplicación

# Aceptar el root path del proyecto como argumento, o usar el directorio actual si no se proporciona
PROJECT_ROOT="${1:-.}"

# Directorios
BUILD_DIR="${PROJECT_ROOT}/build"
EXECUTABLE_NAME="main"

# Ejecutar la aplicación
"${BUILD_DIR}/${EXECUTABLE_NAME}"

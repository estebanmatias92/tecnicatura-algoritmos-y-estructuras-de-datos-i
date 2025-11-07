#!/bin/bash
# Script para ejecutar la aplicación

# Obtener el directorio donde se encuentra el script
SCRIPT_DIR=$(cd "$(dirname "$0")" && pwd)

# Directorios
BUILD_DIR="${SCRIPT_DIR}/build"
EXECUTABLE_NAME="main"

# Ejecutar la aplicación
"${BUILD_DIR}/${EXECUTABLE_NAME}"

#!/bin/bash
# Script para compilar la aplicación C++

# Obtener el directorio donde se encuentra el script
SCRIPT_DIR=$(cd "$(dirname "$0")" && pwd)

# Directorios, ahora relativos al directorio del script
SRC_DIR="${SCRIPT_DIR}/src"
BUILD_DIR="${SCRIPT_DIR}/build"
INCLUDE_DIR="${SCRIPT_DIR}/include"
EXECUTABLE_NAME="main"

# Crear el directorio de build si no existe
mkdir -p "${BUILD_DIR}"

# Comando de compilación
# Busca todos los .cpp, los pasa a g++ y le dice dónde encontrar los headers (-I)
find "${SRC_DIR}" -name '*.cpp' -print0 | xargs -0 g++ -I"${INCLUDE_DIR}" -o "${BUILD_DIR}/${EXECUTABLE_NAME}"

# Comprobar si la compilación fue exitosa
if [ $? -eq 0 ]; then
  echo "✅ Compilación exitosa. Ejecutable creado en ${BUILD_DIR}/${EXECUTABLE_NAME}"
else
  echo "❌ Error de compilación."
  exit 1
fi

#!/bin/bash
# Script para compilar la aplicación C++

# Directorios
# Aceptar el root path del proyecto como argumento, o usar el directorio actual si no se proporciona
PROJECT_ROOT="${1:-.}"

SRC_DIR="${PROJECT_ROOT}/src"
BUILD_DIR="${PROJECT_ROOT}/build"
EXECUTABLE_NAME="main"
INCLUDE_DIR="${PROJECT_ROOT}/include"

# Comando de compilación
# Busca todos los .cpp, los pasa a g++ y le dice dónde encontrar los headers (-I)
find "${SRC_DIR}" -name '*.cpp' -print0 | xargs -0 g++ -I"${INCLUDE_DIR}" -I"${INCLUDE_DIR}/domain" -o "${BUILD_DIR}/${EXECUTABLE_NAME}"

# Comprobar si la compilación fue exitosa
if [ $? -eq 0 ]; then
  echo "✅ Compilación exitosa. Ejecutable creado en ${BUILD_DIR}/${EXECUTABLE_NAME}"
else
  echo "❌ Error de compilación."
  exit 1
fi

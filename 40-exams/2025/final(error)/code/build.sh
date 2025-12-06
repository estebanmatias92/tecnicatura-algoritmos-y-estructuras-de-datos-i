#!/bin/bash

# Build script for Vendor Management Application with CRUD Menu System

echo "Building Vendor Management Application with CRUD Menu System..."

# Create build directory if it doesn't exist
mkdir -p build

# Compile all C++ files
g++ -Wall -Wextra -Werror -std=c++11 -I./src \
    src/domain/*.cpp \
    src/persistence/*.cpp \
    src/application/*.cpp \
    src/utils/*.cpp \
    src/main.cpp \
    -o build/gestion_vendedores

if [ $? -eq 0 ]; then
    echo "Build successful! Executable is in build/gestion_vendedores"
else
    echo "Build failed!"
    exit 1
fi
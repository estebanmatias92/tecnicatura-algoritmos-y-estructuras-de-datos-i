# Pre-Agents Context - Ukelele Chicken Project

## Project Overview

This is a C++ console application for "Ukelele Chicken - Boutique de Carnes" (a meat store in Santa Clara del Mar). It's a refactored version of a boilerplate project for the university course "Algoritmos y Estructuras de Datos I".

## Assignment Requirements

The assignment requires demonstrating OOP concepts:
- **Modularization**: Separate `include/` and `src/` directories
- **Header guards**: `#ifndef` / `#define` / `#endif`
- **Namespaces**: `app::domain` hierarchy
- **Abstract classes**: Base class with pure virtual methods
- **Inheritance**: Derived classes extend base
- **Polymorphism**: Base class pointers with virtual methods
- **Pure virtual methods**: In the `Animal` base class
- **Runtime type selection**: Via menu
- **Arrays**: Fixed-size arrays (no STL)
- **CRUD**: Full Create/Read/Update/Delete for Pedidos
- **Compilation**: Must compile without errors

## Architecture

### Class Diagram

```
Animal (abstract base)
├── ID, nombre, precio, corte
├── comer() [pure virtual]
├── dormir() [pure virtual]
└── mostrar() [pure virtual]

Pollo (extends Animal)
├── esOrganico, pesoPromedio

Vacuno (extends Animal)
├── corteEspecifico, origen

Cerdo (extends Animal)
├── tipoCorte, esPorkBelly

Other classes:
- Cliente (CUIT, razonSocial)
- Empleado (legajo, nombre, apellido)
- Pedido (cliente*, empleado*, animales[])
- Sistema (manages all collections)
```

### File Structure

```
code/
├── Makefile
├── README.md
├── .env
├── compose.yaml
│
└── core-service/
    ├── docs/
    │   └── software-requirement-specification.md
    │
    ├── include/
    │   ├── app/
    │   │   └── Sistema.h
    │   │
    │   ├── domain/
    │   │   ├── Animal.h        # NEW: Abstract base + derived
    │   │   ├── Cliente.h       # Unchanged from boilerplate
    │   │   ├── Empleado.h     # Unchanged from boilerplate
    │   │   └── Pedido.h       # Modified: uses Animal*
    │   │
    │   └── utils/
    │       └── helpers.h
    │
    └── src/
        ├── main.cpp
        ├── app/
        │   └── Sistema.cpp     # Modified: uses Animal, new demo
        ├── domain/
        │   ├── Animal.cpp      # NEW: Implementation
        │   ├── Cliente.cpp     # Unchanged
        │   ├── Empleado.cpp   # Unchanged
        │   └── Pedido.cpp     # Modified: uses Animal*
        └── utils/
            └── helpers.cpp
```

## Key Changes from Boilerplate

| Boilerplate | Ukelele Chicken |
|-------------|-----------------|
| `Equipo` (abstract) | `Animal` (abstract) - with `comer()`, `dormir()` |
| `Ropa`, `Zapatos`, `Antiparras` | `Pollo`, `Vacuno`, `Cerdo` |
| `Equipo* listaEquipos[]` | `Animal* listaAnimales[]` |
| FR-M1 (Equipos hardcoded) | 7 different meat products |
| No demo menu | Added "Demo Polimorfismo" option (option 6) |

## Compilation

```bash
cd code/core-service
g++ -std=c++17 -I./include \
  src/main.cpp \
  src/app/Sistema.cpp \
  src/domain/Cliente.cpp \
  src/domain/Empleado.cpp \
  src/domain/Pedido.cpp \
  src/domain/Animal.cpp \
  src/utils/helpers.cpp \
  -o /tmp/ukelele
```

Or use Docker:
```bash
cd code && make run-dev
```

## Hardcoded Data

### Animales (7 products)
- P001: Pollo Entero ($1200)
- P002: Pechuga de Pollo ($1800)
- P003: Alas de Pollo ($950)
- V001: Asado ($4500)
- V002: Cuadril ($5200)
- C001: Costilla de Cerdo ($2800)
- C002: Lomo de Cerdo ($3200)

### Clientes (3)
- 20-12345678-9: Juan Lopez
- 30-87654321-5: Maria Garcia
- 27-11223344-5: Carlos Rodriguez

### Empleados (2)
- L001: Pedro Martinez
- L002: Laura Fernandez

## Known Issues

- The console clear function in `helpers.cpp` may cause issues when running interactively with piped input. This is a pre-existing boilerplate issue.

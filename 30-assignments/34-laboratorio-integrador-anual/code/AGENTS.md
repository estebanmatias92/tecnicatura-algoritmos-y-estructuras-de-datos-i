# AGENTS.md - Ukelele Chicken Project

## Project Overview

This is a C++ console application for "Ukelele Chicken - Boutique de Carnes" (a meat store in Santa Clara del Mar). It's a university project for "Algoritmos y Estructuras de Datos I".

## Build Commands

### Local Compilation

```bash
cd code/core-service
chmod +x ./build.sh ./run.sh
./build.sh
./run.sh
```

### Manual Compilation

```bash
cd code/core-service
g++ -std=c++17 -I./include \
  src/main.cpp src/app/Sistema.cpp \
  src/domain/Cliente.cpp src/domain/Empleado.cpp \
  src/domain/Pedido.cpp src/domain/Animal.cpp \
  src/utils/helpers.cpp -o build/main
```

### Docker

```bash
make run-dev      # Run in container
make up-prod      # Production
```

### Testing

**No unit tests exist** - university project without test framework.

## Code Style Guidelines

### Namespaces
- `app::domain` for entities
- `app::utils` for utilities  
- `app` for Sistema

### Header Files
- Header guards: `#ifndef NAME_H / #define NAME_H / #endif`
- Order: standard lib → domain → app → utils

### Classes
- PascalCase for class names
- public → protected → private sections
- Virtual destructor for polymorphic bases
- Getters return const or by value

```cpp
class Animal {
protected:
    std::string ID;
public:
    virtual ~Animal();
    virtual void comer() = 0;
};
```

### Inheritance
- Pure virtual (`= 0`) for abstract classes
- Use `override` keyword
- Base class pointers for collections

### Memory (No STL)
- Fixed-size arrays: `T arr[MAX]`
- Manual `new`/`delete`
- Delete heap objects in destructor

### Naming
- Classes: PascalCase
- Variables/methods: camelCase

### Formatting
- 4 spaces (no tabs)
- Brace on same line
- Initializer lists for constructors

### Comments
- **No comments** unless requested

### Error Handling
- Check array bounds
- Return `nullptr` or `-1` for not found

## Architecture

### File Structure

```
code/core-service/
├── include/
│   ├── app/Sistema.h
│   ├── domain/{Animal,Cliente,Empleado,Pedido}.h
│   └── utils/helpers.h
└── src/
    ├── main.cpp
    ├── app/Sistema.cpp
    ├── domain/*.cpp
    └── utils/helpers.cpp
```

### Class Hierarchy
- Animal (abstract) → Pollo, Vacuno, Cerdo
- Cliente, Empleado, Pedido, Sistema

### Assignment Requirements
- Modularization (include/src)
- Header guards
- Namespaces
- Abstract classes + pure virtual
- Inheritance
- Polymorphism
- Fixed arrays (no STL)
- CRUD for Pedidos

## Hardcoded Data

- **Animales**: 7 products (P001-P003, V001-V002, C001-C002)
- **Clientes**: 3 (Juan Lopez, Maria Garcia, Carlos Rodriguez)
- **Empleados**: 2 (Pedro Martinez, Laura Fernandez)

## Known Issues
- Console clear may fail with piped input

# Vendor Management Application

This application manages vendors of different categories (Particular, Profesional, Empresa) organized by branches, with a company structure that contains multiple branches.

## Build Instructions

To build the application, run:

```bash
./build.sh
```

This will create the executable in the `build/` directory.

## Run Instructions

To run the application, execute:

```bash
./build/gestion_vendedores
```

## Features

- Object-oriented design with inheritance and polymorphism
- Three vendor types with specific behaviors (Particular, Profesional, Empresa)
- Company structure with branches
- File-based persistence using gestion.db
- Console interface for user interaction
- Proper memory management using C arrays and pointers (no STL containers)
- Initialization with fake data (1 company, 1 branch, 3 vendors)

## Project Structure

```
src/
├── domain/              # Domain entities (Empleado, Vendedores, Sucursal, Empresa)
├── persistence/         # File-based persistence layer
├── application/         # Application services
└── utils/               # Utility functions
```

The application was built following the SOLID principles and composition over inheritance patterns as specified in the constitution.
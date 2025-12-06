# Quickstart Guide: Vendor Management Application

## Prerequisites

- C++ compiler compatible with C++11 standard (g++ recommended)
- Basic understanding of object-oriented programming concepts
- Console/terminal access

## Project Structure

The application follows the Pitchfork layout as specified in the technical scaffolding:

```
src/
├── domain/              # Domain entities and business logic
│   ├── empleado.h       # Abstract base class (Empleado/Vendedor)
│   ├── empleado.cpp
│   ├── vendedor_particular.h  # Vendedor category implementations
│   ├── vendedor_particular.cpp
│   ├── vendedor_profesional.h
│   ├── vendedor_profesional.cpp
│   ├── vendedor_empresa.h
│   ├── vendedor_empresa.cpp
│   ├── sucursal.h       # Branch entity
│   └── sucursal.cpp
├── persistence/         # File-based persistence layer
│   ├── file_repository.h
│   └── file_repository.cpp
├── application/         # Application services
│   ├── vendor_service.h
│   └── vendor_service.cpp
├── utils/              # Utility functions
│   ├── input_handler.h
│   └── input_handler.cpp
└── main.cpp             # Application entry point (orchestration only)
```

## Building the Application

1. Navigate to the project directory
2. Compile the application:
   ```bash
   g++ -Wall -Wextra -Werror -std=c++11 -I./src src/domain/*.cpp src/persistence/*.cpp src/application/*.cpp src/utils/*.cpp src/main.cpp -o gestion_vendedores
   ```
3. Ensure you have execute permissions on the compiled binary

## Running the Application

1. Execute the compiled application:
   ```bash
   ./gestion_vendedores
   ```
2. Follow the interactive prompts to create and manage vendors
3. The application will create a "gestion.db" file for data persistence

## How to Use

1. The application will prompt for information for 3 vendors (one of each category: Particular, Profesional, Empresa)
2. For each vendor, provide:
   - Name
   - Salary
   - Area
   - Contact information
   - Branch assignment
3. After input, the system will demonstrate polymorphic behavior by calling the `trabajar()` method for each vendor
4. The system will display all vendor information through polymorphic method calls

## Source Code Organization

- **Domain Layer**: Contains the core business entities (Empleado and its subclasses) with proper inheritance and polymorphism
- **Persistence Layer**: Handles file-based data storage using "gestion.db"
- **Application Layer**: Contains services that orchestrate business operations
- **Utils Layer**: Helper functions for input handling and validation
- **Main**: Application entry point that orchestrates the overall flow

## Key Implementation Notes

- The application uses C arrays and pointers instead of STL containers (as required)
- Abstract base class (Empleado) implements pure virtual functions to enforce polymorphic behavior
- Memory management is handled with dynamic allocation and proper cleanup
- File persistence layer stores data in text format in gestion.db file
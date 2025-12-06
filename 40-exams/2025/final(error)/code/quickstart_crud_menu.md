# Quickstart Guide: CRUD Operations with Menu System

## Prerequisites

- C++ compiler compatible with C++11 standard (g++ recommended)
- Basic understanding of object-oriented programming concepts
- Console/terminal access

## Project Structure

The application extends the existing vendor management structure with additional components for the menu system and CRUD operations:

```
src/
├── domain/              # Domain entities and business logic (existing)
│   ├── empleado.h       # Abstract base class (Empleado/Vendedor)
│   ├── empleado.cpp
│   ├── vendedor_particular.h  # Vendedor category implementations
│   ├── vendedor_particular.cpp
│   ├── vendedor_profesional.h
│   ├── vendedor_profesional.cpp
│   ├── vendedor_empresa.h
│   ├── vendedor_empresa.cpp
│   ├── sucursal.h       # Branch entity
│   ├── sucursal.cpp
│   ├── empresa.h        # Company entity (top-level business structure)
│   └── empresa.cpp
├── persistence/         # File-based persistence layer (existing)
│   ├── file_repository.h
│   └── file_repository.cpp
├── application/         # Application services (new CRUD components)
│   ├── vendor_service.h
│   ├── vendor_service.cpp
│   ├── menu_controller.h     # Menu navigation controller
│   ├── menu_controller.cpp
│   ├── sucursal_crud.h       # Sucursal CRUD operations
│   ├── sucursal_crud.cpp
│   ├── vendedor_crud.h       # Vendedor CRUD operations
│   └── vendedor_crud.cpp
├── utils/              # Utility functions (new validation component)
│   ├── input_handler.h
│   ├── input_handler.cpp
│   ├── validator.h           # Input validation
│   └── validator.cpp
└── main.cpp             # Application entry point (updated for menu system)
```

## Building the Application

1. Navigate to the project directory
2. Compile the application with the new components:
   ```bash
   g++ -Wall -Wextra -Werror -std=c++11 -I./src src/domain/*.cpp src/persistence/*.cpp src/application/*.cpp src/utils/*.cpp src/main.cpp -o gestion_vendedores_crud
   ```
3. Ensure you have execute permissions on the compiled binary

## Running the Application

1. Execute the compiled application:
   ```bash
   ./gestion_vendedores_crud
   ```
   or if using the existing build script:
   ```bash
   ./build/gestion_vendedores
   ```
2. The main menu will display with options for CRUD operations
3. Follow the interactive menu prompts to perform Create, Read, Update, or Delete operations

## How to Use the Menu System

1. **Main Menu**: Upon startup, the application presents the main menu with options to navigate to different CRUD operations
2. **Create Operations**: Select menu option to create new Sucursal or Vendedor records
3. **Read Operations**: Select menu option to view or query existing records
4. **Update Operations**: Select menu option to modify existing records
5. **Delete Operations**: Select menu option to remove records (with validation)

## Key Implementation Notes

- The application maintains all existing pre-populated data functionality
- New menu system provides interactive navigation for CRUD operations
- File persistence continues to use "gestion.db" text file
- All validation is performed to ensure data integrity
- Proper error handling prevents deletion of entities with dependencies
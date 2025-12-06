# Class Diagram: Vendor Management Application

## Core Class Hierarchy

```mermaid
classDiagram
    class Empleado {
        -string name
        -float salary
        -string area
        -string contact_info
        +trabajar() void <<abstract>>
        +displayInfo() void <<abstract>>
        +~Empleado() void
    }

    class VendedorParticular {
        +trabajar() void
        +displayInfo() void
    }

    class VendedorProfesional {
        +trabajar() void
        +displayInfo() void
    }

    class VendedorEmpresa {
        +trabajar() void
        +displayInfo() void
    }

    class Sucursal {
        -int id
        -string name
        -Empleado** vendedores
        -int vendedor_count
        -int max_vendedores
        +addVendedor(Empleado*) void
        +removeVendedor(Empleado*) void
        +listarVendedores() Empleado**
        +getVendedor(int) Empleado*
    }

    class Empresa {
        -int id
        -string name
        -Sucursal** sucursales
        -int sucursal_count
        -int max_sucursales
        +addSucursal(Sucursal*) void
        +removeSucursal(Sucursal*) void
        +listarSucursales() Sucursal**
        +getSucursal(int) Sucursal*
        +listarTodosVendedores() void
    }

    Empleado <|-- VendedorParticular
    Empleado <|-- VendedorProfesional
    Empleado <|-- VendedorEmpresa
    Empresa *-- Sucursal
    Sucursal --o Empleado
```

## Persistence Layer

```mermaid
classDiagram
    class FileRepository {
        -string filename
        +save() bool
        +load() bool
        +saveVendedor() bool
        +loadVendedores() Empleado**
    }
```

## Application Services

```mermaid
classDiagram
    class VendorService {
        +createVendedor() Empleado*
        +assignToBranch() bool
        +listVendedores() Empleado**
    }
```

## Utility Classes

```mermaid
classDiagram
    class InputHandler {
        +getStringInput() string
        +getFloatInput() float
        +getIntInput() int
    }
```

## Relationships

- **Inheritance**: VendedorParticular, VendedorProfesional, and VendedorEmpresa inherit from Empleado (abstract base class)
- **Composition**: Empresa "has" multiple Sucursal objects (Empresa is the owner of Sucursales)
- **Aggregation**: Sucursal "has" multiple Empleado objects (Sucursal aggregates Empleados)
- **Dependencies**: Main.cpp → (VendorService, InputHandler), VendorService → (Empleado*, Sucursal), FileRepository → (Empleado*)
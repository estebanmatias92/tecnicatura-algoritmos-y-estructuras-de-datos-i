# Data Model: Vendor Management Application

## Entities

### Empleado (Abstract Base Class)
- **name** (string) - Required: Employee/vendor name
- **salary** (float) - Required: Salary amount
- **area** (string) - Required: Work area/department  
- **contact_info** (string) - Required: Contact information
- **Methods**:
  - `virtual void trabajar() = 0` - Pure virtual method for category-specific work behavior
  - `virtual void displayInfo() = 0` - Pure virtual method for displaying vendor information
  - `virtual ~Empleado()` - Virtual destructor for proper cleanup

### VendedorParticular (Inherits from Empleado)
- **Attributes**: Inherits all from Empleado
- **Additional Methods**:
  - `void trabajar()` - Particular-specific work behavior
  - `void displayInfo()` - Particular-specific information display

### VendedorProfesional (Inherits from Empleado)
- **Attributes**: Inherits all from Empleado
- **Additional Methods**:
  - `void trabajar()` - Profesional-specific work behavior
  - `void displayInfo()` - Profesional-specific information display

### VendedorEmpresa (Inherits from Empleado)
- **Attributes**: Inherits all from Empleado
- **Additional Methods**:
  - `void trabajar()` - Empresa-specific work behavior
  - `void displayInfo()` - Empresa-specific information display

### Sucursal (Branch)
- **id** (int) - Required: Unique branch identifier
- **name** (string) - Required: Branch name
- **vendedores** (Empleado**) - Pointer to array of vendor pointers
- **vendedor_count** (int) - Current number of vendors in the branch
- **max_vendedores** (int) - Maximum capacity for vendors (using C array)
- **Methods**:
  - `void addVendedor(Empleado* vendedor)` - Add vendor to branch
  - `void removeVendedor(Empleado* vendedor)` - Remove vendor from branch
  - `void listarVendedores()` - List all vendors in the branch
  - `Empleado* getVendedor(int index)` - Get vendor at specific index

### Empresa (Company)
- **id** (int) - Required: Unique company identifier
- **name** (string) - Required: Company name
- **sucursales** (Sucursal**) - Pointer to array of branch pointers (composition relationship)
- **sucursal_count** (int) - Current number of branches in the company
- **max_sucursales** (int) - Maximum capacity for branches (using C array)
- **Methods**:
  - `void addSucursal(Sucursal* sucursal)` - Add branch to company
  - `void removeSucursal(Sucursal* sucursal)` - Remove branch from company
  - `void listarSucursales()` - List all branches in the company
  - `Sucursal* getSucursal(int index)` - Get branch at specific index
  - `void listarTodosVendedores()` - List all vendors across all branches

## Relationships

- **Inheritance**: VendedorParticular, VendedorProfesional, and VendedorEmpresa inherit from Empleado
- **Composition**: Sucursal "has" multiple Empleado objects (aggregation relationship)
- **Composition**: Empresa "has" multiple Sucursal objects (composition relationship - the company manages and contains branches)
- **Cardinality**: One Empresa contains many Sucursales (1 to many), One Sucursal contains many Empleados (1 to many)

## Validation Rules

- Salary must be a positive number
- Name and area cannot be empty
- Contact information must be provided
- Each vendor must be assigned to exactly one branch
- Branch names must be unique

## State Transitions

- Vendedores are created in an "active" state
- There are no state changes in this implementation (simple CRUD operations)
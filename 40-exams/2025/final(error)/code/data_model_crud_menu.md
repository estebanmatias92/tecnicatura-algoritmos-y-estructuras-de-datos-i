# Data Model: CRUD Operations with Menu System

## Entities

### Menu System
- **options** (string[]) - Array of available menu options for navigation
- **currentState** (enum) - Current menu state/screen the user is viewing
- **navigationHistory** (MenuState[]) - Stack of previous menu states for navigation history
- **Methods**:
  - `displayMenu()` - Render the current menu options to the console
  - `navigateTo(MenuState state)` - Transition to a new menu state
  - `handleInput(string input)` - Process user input and perform appropriate navigation

### Sucursal CRUD Handler
- **fileRepository** (FileRepository*) - Reference to file persistence layer
- **currentRecords** (Sucursal**) - Pointer to array of active Sucursal records
- **recordCount** (int) - Current number of loaded Sucursal records
- **Methods**:
  - `create(Sucursal* instance)` - Create and persist a new Sucursal record
  - `read(int id)` - Retrieve and return a specific Sucursal by ID
  - `update(Sucursal* instance)` - Update an existing Sucursal record
  - `delete(int id)` - Remove a Sucursal record from the system
  - `findAll()` - Return array of all Sucursal records

### Vendedor CRUD Handler
- **fileRepository** (FileRepository*) - Reference to file persistence layer
- **currentRecords** (Vendedor**) - Pointer to array of active Vendedor records
- **recordCount** (int) - Current number of loaded Vendedor records
- **Methods**:
  - `create(Vendedor* instance)` - Create and persist a new Vendedor record
  - `read(int id)` - Retrieve and return a specific Vendedor by ID
  - `update(Vendedor* instance)` - Update an existing Vendedor record
  - `delete(int id)` - Remove a Vendedor record from the system
  - `findAll()` - Return array of all Vendedor records

### Navigation Manager
- **currentMenu** (MenuSystem*) - Reference to current menu system
- **sucursalService** (SucursalCRUD*) - Reference to Sucursal CRUD handler
- **vendedorService** (VendedorCRUD*) - Reference to Vendedor CRUD handler
- **Methods**:
  - `processMenuChoice(MenuItem choice)` - Process menu selections and route to appropriate services
  - `switchContext(MenuContext context)` - Change operational context (menu state)

### Input Validator
- **validationRules** (ValidationRule[]) - Collection of validation rules
- **Methods**:
  - `validate(string input, ValidationRule rule)` - Validate input against specific rule
  - `validateRequired(string input)` - Ensure required field is not empty
  - `validateNumeric(string input)` - Verify input is numeric
  - `validateEmail(string input)` - Verify input is valid email format
  - `validateRange(float value, float min, float max)` - Verify value is within range

## Relationships

- **Association**: Menu System "connects to" Navigation Manager for state control
- **Dependency**: Navigation Manager "depends on" both CRUD Handlers for operations
- **Dependency**: CRUD Handlers "depend on" File Repository for persistence
- **Association**: Input Validator "validates for" all CRUD operations

## Validation Rules

- Required fields must not be empty
- Numeric fields must contain valid numbers
- Range validation for salary amounts (positive values)
- Email format validation for contact information
- Prevent deletion of Sucursal with active Vendedores assigned
- Ensure proper branch assignment when creating/updating Vendedores

## State Transitions

- Menu states transition based on user input (navigating between Create, Read, Update, Delete operations)
- Context switches occur when changing between Sucursal and Vendedor management
- Error states are handled gracefully with user feedback
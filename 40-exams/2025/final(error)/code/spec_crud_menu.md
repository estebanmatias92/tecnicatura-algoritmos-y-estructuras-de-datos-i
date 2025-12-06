# Feature Specification: CRUD Operations with Menu System

**Feature Branch**: `002-crud-menu`
**Created**: 2025-12-05
**Status**: Draft
**Input**: User description: "i need to change the app, so in addition to have the prepopulated data, i can do CRUD operations on Sucursal and Vendedor (whatever is called), create a new feature for this, but no new git branches (forget about git), remember i will need some menu system for this to navegate from terminal as an user and input data, read, modify, delete, etc. Remember we are working here @/home/matt/Obsidian_Vaults/Matias/04-projects/prj-tecnicatura-superior-sistemas/year/01/algoritmos-y-estructuras-de-datos-i/40-exams/2025/final/code/"

## User Scenarios & Testing *(mandatory)*

### User Story 1 - Navigate Menu System (Priority: P1)

System administrator needs to navigate through a menu system to access different CRUD operations for sucursal and vendor management, allowing easy access to create, read, update, and delete operations.

**Why this priority**: This is the core functionality that provides the interface for all other CRUD operations. Without a proper menu system, the administrator cannot access and perform management tasks.

**Independent Test**: Can be fully tested by launching the application and verifying the menu system presents options for different CRUD operations, allowing navigation between screens without errors.

**Acceptance Scenarios**:

1. **Given** administrator launches the application, **When** the main menu screen is displayed, **Then** the system shows clear options for navigation between different CRUD operations on sucursal and vendors.

2. **Given** administrator is on any menu screen, **When** administrator selects an option, **Then** the system navigates to the appropriate screen without crashing.

---

### User Story 2 - Create Sucursal and Vendedor Records (Priority: P2)

System administrator needs to create new sucursal and vendor records through the menu system, inputting the required information and saving it to the system.

**Why this priority**: This enables the expansion of the business by adding new branches and vendors to the system, extending the existing pre-populated data.

**Independent Test**: Can be tested by navigating to the create screens and successfully adding new sucursal and vendor records with appropriate validation.

**Acceptance Scenarios**:

1. **Given** administrator selects the "Create Sucursal" option, **When** administrator inputs all required fields and submits, **Then** a new sucursal is created and appears in the system.

2. **Given** administrator selects the "Create Vendedor" option, **When** administrator inputs all required fields and assigns to a branch, **Then** a new vendor is created and linked to the appropriate branch.

---

### User Story 3 - Read (View/Query) Sucursal and Vendedor Records (Priority: P2)

System administrator needs to view existing sucursal and vendor records through the menu system, including the ability to query and filter records.

**Why this priority**: This allows the administrator to inspect existing data and ensures data integrity and completeness.

**Independent Test**: Can be tested by navigating to the view screens and successfully retrieving and displaying information for existing records.

**Acceptance Scenarios**:

1. **Given** administrator selects the "View Sucursales" option, **When** the system retrieves data, **Then** all existing branches are displayed with their details.

2. **Given** administrator selects the "View Vendedores" option, **When** the system retrieves data, **Then** all existing vendors are displayed with their details and assigned branches.

---

### User Story 4 - Update Existing Sucursal and Vendedor Records (Priority: P3)

System administrator needs to modify existing sucursal and vendor records through the menu system, changing data fields as business requirements change.

**Why this priority**: This allows for maintenance and updating of existing records to reflect changes in the business.

**Independent Test**: Can be tested by selecting existing records and modifying their properties, then confirming the changes are persisted.

**Acceptance Scenarios**:

1. **Given** administrator selects the "Update Sucursal" option and chooses a branch, **When** administrator modifies the branch details and saves, **Then** the branch information is updated in the system.

2. **Given** administrator selects the "Update Vendedor" option and chooses a vendor, **When** administrator modifies the vendor details and saves, **Then** the vendor information is updated in the system.

---

### User Story 5 - Delete Sucursal and Vendedor Records (Priority: P3)

System administrator needs to remove obsolete or unwanted sucursal and vendor records from the system through the menu system.

**Why this priority**: This allows for data cleanup and management of records that are no longer needed.

**Independent Test**: Can be tested by selecting existing records and deleting them, then confirming they no longer appear in queries.

**Acceptance Scenarios**:

1. **Given** administrator selects the "Delete Sucursal" option and chooses a branch, **When** administrator confirms deletion, **Then** the branch is removed from the system.

2. **Given** administrator selects the "Delete Vendedor" option and chooses a vendor, **When** administrator confirms deletion, **Then** the vendor is removed from the system.

---

### Edge Cases

- What happens when a user tries to delete a sucursal that still has vendedores assigned?
- How does the system handle invalid input during creation or update operations?
- What if the system cannot persist changes to the data file?

## Requirements *(mandatory)*

### Functional Requirements

- **FR-001**: System MUST provide a main menu with options for CRUD operations on Sucursales and Vendedores
- **FR-002**: System MUST allow creating new Sucursal records with all required information
- **FR-003**: System MUST allow creating new Vendedor records with all required information and branch assignment
- **FR-004**: System MUST display all existing Sucursales with their details
- **FR-005**: System MUST display all existing Vendedores with their details and branch assignments
- **FR-006**: System MUST allow updating existing Sucursal records and persisting changes
- **FR-007**: System MUST allow updating existing Vendedor records and persisting changes
- **FR-008**: System MUST allow deleting existing Sucursal records that have no dependent Vendedores
- **FR-009**: System MUST allow deleting existing Vendedor records and persisting the change
- **FR-010**: System MUST validate all user inputs during CRUD operations to prevent data corruption
- **FR-011**: System MUST maintain data consistency after all CRUD operations
- **FR-012**: System MUST handle error cases gracefully (e.g., when trying to delete a Sucursal with Vendedores assigned)
- **FR-013**: System MUST continue to support the existing prepopulated data alongside new CRUD operations
- **FR-014**: System MUST provide clear navigation and user feedback during menu operations

### Key Entities

- **Menu System**: Interactive console-based navigation system that allows users to access different CRUD operations and move between different views.
- **Sucursal CRUD Handler**: Module responsible for Create, Read, Update, and Delete operations on Sucursal entities, including validation and persistence.
- **Vendedor CRUD Handler**: Module responsible for Create, Read, Update, and Delete operations on Vendedor entities, including validation, branch assignment, and persistence.
- **Navigation Manager**: Controller that manages the flow between different menus and CRUD operations.
- **Input Validator**: Component that validates user input for all CRUD operations to ensure data integrity.

## Success Criteria *(mandatory)*

### Measurable Outcomes

- **SC-001**: Users can navigate the menu system without crashes or errors
- **SC-002**: Administrator can create new Sucursal records in under 2 minutes each
- **SC-003**: Administrator can create new Vendedor records in under 2 minutes each
- **SC-004**: Administrator can view all existing records with complete information displayed correctly
- **SC-005**: Administrator can update existing records and verify changes are persisted
- **SC-006**: Administrator can delete appropriate records while preventing deletion of records with dependencies
- **SC-007**: All CRUD operations complete with success rates above 95%
- **SC-008**: System maintains data integrity across all CRUD operations

## Clarifications

### Session 2025-12-05

- Q: What should happen when trying to delete a Sucursal that still has Vendedores assigned? → A: The system should show an error message and prevent deletion until all Vendedores are reassigned or deleted.

## Key Entities

- **Menu System**: Interactive console-based navigation system that allows users to access different CRUD operations and move between different views.
- **Sucursal CRUD Handler**: Module responsible for Create, Read, Update, and Delete operations on Sucursal entities, including validation and persistence.
- **Vendedor CRUD Handler**: Module responsible for Create, Read, Update, and Delete operations on Vendedor entities, including validation, branch assignment, and persistence.
- **Navigation Manager**: Controller that manages the flow between different menus and CRUD operations.
- **Input Validator**: Component that validates user input for all CRUD operations to ensure data integrity.
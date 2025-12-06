# Tasks: Vendor Management Application

**Feature**: vendor-management-app
**Spec**: `/specs/001-vendor-management-app/spec.md`
**Plan**: `/specs/001-vendor-management-app/plan.md`
**Generated**: 2025-12-05

## Implementation Strategy

Build the application in priority order of user stories. Each story builds on the previous, creating a working MVP after US1. Focus on core OOP principles with inheritance and polymorphism, using C arrays and pointers instead of STL containers.

## Dependencies

- US1 (P1) must complete before US2 (P2) or US3 (P3)
- Foundational tasks must complete before any user story tasks
- Domain entities must be created before services and persistence layers

## Parallel Execution Examples

- T020-T022 [P] - Create all vendor category classes in parallel
- T030-T032 [P] - Implement trabajar() methods for each vendor type in parallel
- T035-T037 [P] - Implement displayInfo() methods for each vendor type in parallel

## Phase 1: Setup

- [X] T001 Create project directory structure per implementation plan
- [X] T002 Create src/ directory
- [X] T003 Create src/domain/ directory
- [X] T004 Create src/persistence/ directory
- [X] T005 Create src/application/ directory
- [X] T006 Create src/utils/ directory

## Phase 2: Foundational

- [X] T010 Implement Empleado abstract base class header in src/domain/empleado.h
- [X] T011 Implement Empleado abstract base class in src/domain/empleado.cpp
- [X] T012 Implement Sucursal class header in src/domain/sucursal.h
- [X] T013 Implement Sucursal class in src/domain/sucursal.cpp
- [X] T014 Implement Empresa class header in src/domain/empresa.h
- [X] T015 Implement Empresa class in src/domain/empresa.cpp
- [X] T016 Implement Empresa methods (addSucursal, removeSucursal, listarSucursales, getSucursal, listarTodosVendedores) in src/domain/empresa.cpp
- [X] T017 Create file repository header in src/persistence/file_repository.h
- [X] T018 Create file repository implementation in src/persistence/file_repository.cpp

## Phase 3: US1 - Create and Manage Vendor Hierarchy (P1)

**Goal**: System administrator can register vendors of three categories and assign them to branches, establishing the fundamental data model and relationships.

**Independent Test**: Create one vendor of each category and one branch, verify relationships are established correctly, confirm proper object creation and assignment.

- [X] T022 Implement VendedorParticular class header in src/domain/vendedor_particular.h [US1]
- [X] T023 Implement VendedorParticular class in src/domain/vendedor_particular.cpp [US1]
- [X] T024 Implement VendedorProfesional class header in src/domain/vendedor_profesional.h [US1]
- [X] T025 Implement VendedorProfesional class in src/domain/vendedor_profesional.cpp [US1]
- [X] T026 Implement VendedorEmpresa class header in src/domain/vendedor_empresa.h [US1]
- [X] T027 Implement VendedorEmpresa class in src/domain/vendedor_empresa.cpp [US1]
- [X] T032 Implement trabajar() method in VendedorParticular [US1]
- [X] T033 Implement trabajar() method in VendedorProfesional [US1]
- [X] T034 Implement trabajar() method in VendedorEmpresa [US1]
- [X] T037 Implement displayInfo() method in VendedorParticular [US1]
- [X] T038 Implement displayInfo() method in VendedorProfesional [US1]
- [X] T039 Implement displayInfo() method in VendedorEmpresa [US1]
- [X] T042 Update Sucursal to support vendor assignment using C arrays [US1]
- [X] T043 Add validation to prevent empty name, area and contact info [US1]
- [X] T044 Create vendor service header in src/application/vendor_service.h [US1]
- [X] T045 Create vendor service implementation in src/application/vendor_service.cpp [US1]
- [X] T046 Implement vendor creation in vendor service [US1]
- [X] T047 Implement branch assignment logic in vendor service [US1]

## Phase 4: US2 - Execute Category-Specific Vendor Operations (P2)

**Goal**: System administrator can execute vendor-specific operations where each vendor type behaves differently according to its category when performing work tasks.

**Independent Test**: Execute work operation on vendor records and verify that each category displays its specific behavior.

- [X] T052 Verify trabalhar() methods demonstrate category-specific behavior [US2]
- [X] T053 Implement collection iteration with polymorphic behavior [US2]
- [X] T054 Update vendor service to execute trabalhar() on all vendors [US2]
- [X] T055 Implement notification display for each vendor category [US2]
- [X] T056 Add category-specific task implementation to each vendor class [US2]

## Phase 5: US3 - Display Vendor Information by Category (P3)

**Goal**: System administrator can view detailed information for each vendor (salary, area, personal data) with the system automatically handling the vendor type differences.

**Independent Test**: Request vendor information and verify that appropriate category-specific data is shown for each vendor.

- [X] T062 Update displayInfo() methods to show all required data (salary, area, personal data) [US3]
- [X] T063 Implement list vendors functionality in Sucursal class [US3]
- [X] T064 Enhance vendor service to list vendors by branch [US3]
- [X] T065 Implement polymorphic iteration for displaying vendor information [US3]
- [X] T066 Add input validation in vendor service methods [US3]
- [X] T067 Handle invalid data during vendor creation [US3]

## Phase 6: Input/Output & Console Interface

**Goal**: Create console interface for administrator to interact with the system via prompts.

- [X] T074 Create input handler header in src/utils/input_handler.h
- [X] T075 Create input handler implementation in src/utils/input_handler.cpp
- [X] T076 Implement string input with validation in input handler
- [X] T077 Implement float input with validation in input handler
- [X] T078 Implement int input with validation in input handler
- [X] T079 Create main.cpp with basic application flow
- [X] T080 Implement vendor creation prompts in main.cpp [P]
- [X] T081 Implement branch assignment prompts in main.cpp [P]
- [X] T082 Integrate input handler with vendor service

## Phase 7: Persistence Implementation

**Goal**: Implement file-based persistence using "gestion.db" text file.

- [X] T084 Complete file repository implementation for vendor persistence
- [X] T085 Implement vendor saving to gestion.db file
- [X] T086 Implement vendor loading from gestion.db file
- [X] T087 Implement branch data persistence
- [X] T088 Add persistence integration to vendor service

## Phase 8: Integration & Orchestration

**Goal**: Integrate all components and ensure main.cpp only orchestrates.

- [X] T092 Update main.cpp to orchestrate vendor creation (not contain business logic)
- [X] T093 Implement the flow to create exactly 3 vendors (one per category) via console
- [X] T094 Execute polymorphic behavior demonstration after input
- [X] T095 Display all vendor information through polymorphic calls
- [X] T096 Test complete workflow end-to-end

## Phase 9: Polish & Cross-Cutting Concerns

**Goal**: Final touches and quality improvements.

- [X] T104 Implement error handling for invalid inputs
- [X] T105 Validate essential data fields during vendor creation
- [X] T106 Add support for optional fields in vendor creation
- [X] T107 Add memory management (proper constructor/destructor usage)
- [X] T108 Review and ensure no STL containers are used (only C arrays and pointers)
- [X] T109 Compile with -Wall -Wextra -Werror flags and fix any warnings
- [X] T110 Document any remaining classes and methods
- [X] T111 Create build script to compile the application
- [X] T112 Update README with build and run instructions
- [X] T113 Perform final testing with console input scenarios
- [X] T114 Verify all constitution principles are followed (modularity, inheritance, etc.)
- [X] T115 Implement initialization with 1 empresa, 1 sucursal, and 3 employees populated with fake data [FR14]
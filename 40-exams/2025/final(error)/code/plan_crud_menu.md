# Implementation Plan: crud-menu

**Branch**: `002-crud-menu` | **Date**: 2025-12-05 | **Spec**: [link to spec_crud_menu.md]
**Input**: Feature specification from `spec_crud_menu.md`

**Note**: This template is filled in by the `/speckit.plan` command. See `.specify/templates/commands/plan.md` for the execution workflow.

## Summary

Extend the existing vendor management application to include a comprehensive menu system with full CRUD operations for Sucursal and Vendedor entities. The system will maintain compatibility with existing pre-populated data while providing interactive terminal-based menu navigation, input validation, and data persistence management.

## Technical Context

**Language/Version**: C++ (C++11 compatible)
**Primary Dependencies**: Standard C++ libraries only (no STL vectors, must use C arrays and simple pointers)
**Storage**: Text file named "gestion.db" for persistence (maintaining existing approach)
**Testing**: Not implemented (as specified by user requirements)
**Target Platform**: Linux/Unix console application
**Project Type**: Single console application (extending existing architecture)
**Performance Goals**: Interactive menu response times under 0.5 seconds
**Constraints**: No STL library usage (vectors prohibited), must use C arrays and simple pointers; must follow OOP principles (inheritance, polymorphism); must follow constitution principles
**Scale/Scope**: Small application supporting CRUD operations on existing vendor/branch entities

## Constitution Check

*GATE: Must pass before Phase 0 research. Re-check after Phase 1 design.*

- **I. Modularity**: PASS - Will maintain separate classes for menu system, CRUD handlers, and validation components with clear responsibilities
- **II. Inheritance & Polymorphism**: PASS - Will leverage existing inheritance structure for operations on vendor types
- **III. Composition over Inheritance (NON-NEGOTIABLE)**: PASS - Will compose menu system with CRUD handlers following existing patterns
- **IV. Inversion of Control (IoC)**: PASS - Will structure with dependency injection where appropriate
- **V. SOLID Compliance (NON-NEGOTIABLE)**: PASS - Will implement classes following SOLID principles with single-responsibility for each CRUD handler
- **Design & Quality Standards**: PASS - Will follow Clean Code practices and proper header/implementation separation
- **Development Workflow**: PASS - Domain logic will remain outside main() with main() only orchestrating

All constitution gates PASS.

## Project Structure

### Documentation (this feature)

```text
specs/002-crud-menu/
├── plan.md              # This file (/speckit.plan command output)
├── research.md          # Phase 0 output (/speckit.plan command)
├── data-model.md        # Phase 1 output (/speckit.plan command)
├── quickstart.md        # Phase 1 output (/speckit.plan command)
├── contracts/           # Phase 1 output (/speckit.plan command)
└── tasks.md             # Phase 2 output (/speckit.tasks command - NOT created by /speckit.plan)
```

### Source Code (repository root)

```text
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
├── application/         # Application services (extended)
│   ├── vendor_service.h
│   └── vendor_service.cpp
│   ├── menu_controller.h     # NEW: Menu navigation controller
│   ├── menu_controller.cpp
│   ├── sucursal_crud.h       # NEW: Sucursal CRUD operations
│   ├── sucursal_crud.cpp
│   ├── vendedor_crud.h       # NEW: Vendedor CRUD operations
│   └── vendedor_crud.cpp
├── utils/              # Utility functions (extended)
│   ├── input_handler.h
│   └── input_handler.cpp
│   ├── validator.h           # NEW: Input validation
│   └── validator.cpp
└── main.cpp             # Application entry point (updated for menu system)
```

**Structure Decision**: Extended single project structure maintaining existing architecture with new modules for menu system and CRUD operations. Code is organized by responsibility with domain entities in domain/ folder, persistence in persistence/, application services in application/ (with new CRUD handlers), and utilities in utils/. Main.cpp will be updated to implement the menu-driven flow while continuing to only orchestrate the application flow as required by the constitution.

## Complexity Tracking

> **Fill ONLY if Constitution Check has violations that must be justified**

| Violation | Why Needed | Simpler Alternative Rejected Because |
|-----------|------------|-------------------------------------|
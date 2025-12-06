<!-- SYNC IMPACT REPORT:
Version change: N/A (initial version) → 1.0.0
Modified principles: N/A
Added sections: All principles and sections added as initial constitution
Removed sections: N/A
Templates requiring updates: ⚠ pending (plan-template.md, spec-template.md, tasks-template.md, commands/*.toml) - need manual review
Follow-up TODOs: None
-->
# Aplicación de Gestión de Pedidos Constitution

## Core Principles

### I. Modularity
Logical separation via classes, namespaces, and filesystem structure (`src/`, `include/`, etc.). No god classes or monolithic `main`. Each file should have ≤1 core responsibility; dependencies explicit and minimal.
<!-- Rationale: Enables maintainable, testable code with clear boundaries -->

### II. Inheritance & Polymorphism
Use of abstract base classes (≥1 pure virtual function); concrete subclasses override behavior meaningfully. `dynamic_cast`/`typeid` should not be needed to differentiate types at runtime.
<!-- Rationale: Promotes extensibility and code reuse through proper object-oriented design -->

### III. Composition over Inheritance (NON-NEGOTIABLE)
Aggregation (e.g., `Sucursal` has `Vendedores`) preferred for has-a relationships. Object graphs must be constructible without deep inheritance chains.
<!-- Rationale: Creates more flexible and maintainable object relationships -->

### IV. Inversion of Control (IoC)
Dependencies (e.g., notification channels, data sources) injected — not hardcoded. Classes must support construction with mock/test doubles.
<!-- Rationale: Reduces coupling and enables testability -->

### V. SOLID Compliance (NON-NEGOTIABLE)
- **S**RP: One reason to change per class
- **O**CP: Open for extension, closed for modification (new vendedor types added without modifying existing logic)
- **L**SP: Liskov Substitution Principle (Substitutable in collections like `Empleado*`)
- **I**SP: Interface Segregation Principle (no fat interfaces)
- **D**IP: Dependency Inversion Principle (Depend on abstractions, not concretions)
<!-- Rationale: Ensures code is maintainable, extensible, and follows proven design principles -->

## Design & Quality Standards

All code must conform to foundational object-oriented design and software craftsmanship principles as specified in the design constraints document. This includes:
- GRASP-informed responsibility assignment (Information Expert, Creator, Controller)
- Clean Code practices (intention-revealing names, functions ≤ 20 LOC, no duplication)
- Proper use of header files (.h) with corresponding implementation files (.cpp)
- Compilation with -Wall -Wextra -Werror flags yielding zero warnings

## Development Workflow

- All domain behavior must reside outside `main()` — `main` only orchestrates
- No explicit memory management (`new`/`delete`) outside factory-like contexts
- No conditional logic based on object type — use polymorphism instead
- Every class header has a corresponding implementation file with proper header guards
- Code must compile successfully and execute without errors

## Governance

This constitution supersedes all other practices. All code reviews and implementations must verify compliance with these principles. Complexity must be justified against these standards. Amendments require documentation and approval based on their impact to these core principles.

**Version**: 1.0.0 | **Ratified**: 2025-12-05 | **Last Amended**: 2025-12-05
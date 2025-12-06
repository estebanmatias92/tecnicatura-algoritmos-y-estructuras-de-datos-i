# Design & Quality Constraints

The implementation must conform to foundational object-oriented design and software craftsmanship principles. These constraints are _non-negotiable_ and directly verifiable in code review or static analysis.

## 🧱 Core Design Expectations

| Layer                                        | Expectation                                                                                                                                                                                                                                                                                  | Rationale / Validation Cue                                                                   |
| -------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------- |
| **Modularity**                               | Logical separation via classes, namespaces, and filesystem structure (`src/`, `include/`, etc.). No god classes or monolithic `main`.                                                                                                                                                        | Each file should have ≤1 core responsibility; dependencies explicit and minimal.             |
| **Inheritance & Polymorphism**               | Use of abstract base classes (≥1 pure virtual function); concrete subclasses override behavior meaningfully.                                                                                                                                                                                 | `dynamic_cast`/`typeid` should _not_ be needed to differentiate types at runtime.            |
| **Composition over Inheritance**             | Aggregation (e.g., `Sucursal` _has_ `Vendedores`) preferred for _has-a_ relationships.                                                                                                                                                                                                       | Object graphs must be constructible without deep inheritance chains.                         |
| **Inversion of Control (IoC)**               | Dependencies (e.g., notification channels, data sources) injected — not hardcoded.                                                                                                                                                                                                           | Classes must support construction with mock/test doubles.                                    |
| **GRASP-Informed Responsibility Assignment** | Apply patterns such as: <br> • _Information Expert_ (who owns the data?) <br> • _Creator_ (who instantiates?) <br> • _Controller_ (who coordinates?)                                                                                                                                         | Each method should answer _“why does this class do this?”_ with a clear GRASP justification. |
| **SOLID Compliance**                         | <ul><li>**S**RP: One reason to change per class</li><li>**O**CP: New vendedor types added without modifying existing logic</li><li>**L**SP: Substitutable in collections (`Empleado*`)</li><li>**I**SP: No fat interfaces</li><li>**D**IP: Depend on abstractions, not concretions</li></ul> | Test: Can you add a `VendedorGubernamental` without touching `Sucursal.cpp`?                 |
| **Clean Code Practices**                     | <ul><li>Intention-revealing names (`calcularComision()` vs `calc()`)</li><li>Functions ≤ 20 LOC, indentation ≤ 2 levels</li><li>No duplication (DRY)</li><li>Minimal comments — code must self-explain</li></ul>                                                                             | Run `cppcheck`/`clang-tidy` with default rules: zero warnings.                               |

## ✅ Acceptance Criteria (Design-Focused)

- [ ] All domain behavior resides _outside_ `main()` — `main` only orchestrates.
- [ ] Zero `new`/`delete` outside factory-like contexts (prefer stack or smart pointers if allowed; otherwise, strict RAII wrappers).
- [ ] No conditional logic based on object type (e.g., `if (type == "Profesional")`) — use polymorphism.
- [ ] Every class `.h` has a corresponding `.cpp`; header guards or `#pragma once` used.
- [ ] Compilation succeeds with `-Wall -Wextra -Werror`.

---

> ℹ️ **Usage note for AI agents**:  
> Treat each row as a _design invariant_. When generating/refactoring code, validate output against these constraints _before_ functional testing. Prioritize structural correctness over syntactic brevity.

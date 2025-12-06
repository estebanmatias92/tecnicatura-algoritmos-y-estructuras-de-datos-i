# Research: Vendor Management Application

## Decision: C++ Implementation without STL
**Rationale**: Requirement from user input specifies implementation in C++ with no STL library, prohibiting use of vectors. Must use C arrays and simple pointers instead. This aligns with educational requirements for understanding fundamental data structures.
**Alternatives considered**: 
- Using STL containers like std::vector, std::list (prohibited by requirements)
- Using C-style arrays and manual memory management (selected approach)

## Decision: File-based Persistence with gestion.db
**Rationale**: Requirement from user input specifies adding a persistence layer using a text file named "gestion.db". This provides simple data persistence without complex database systems.
**Alternatives considered**:
- Database systems (SQLite, MySQL) (more complex than required)
- In-memory only (no persistence)
- Custom binary file format (selected text file format for simplicity and readability)

## Decision: Minimal Entity Design
**Rationale**: Requirement to keep the project with the less amount of entities possible given design constraints and PRD. This reduces complexity while meeting requirements.
**Alternatives considered**:
- Complex entity relationships with many classes (rejected to minimize entities)
- Single monolithic class (violates modularity principles)
- Multiple specialized entities (selected a balanced approach with essential entities only)

## Decision: Inheritance and Polymorphism Implementation
**Rationale**: Core requirement from both the feature spec and constitution to implement proper OOP principles with abstract base classes and polymorphic behavior for different vendor types.
**Alternatives considered**:
- Switch statements to handle different vendor types (violates constitution principle)
- Separate functions for each vendor type (violates OOP principles)
- Proper inheritance hierarchy with virtual methods (selected approach)

## Decision: Console Interface
**Rationale**: Based on PRD requirements for administrator input via console and display of information through console output.
**Alternatives considered**:
- GUI interface (more complex than required)
- Web interface (not suitable for console application)
- Console interface (selected for simplicity and alignment with requirements)
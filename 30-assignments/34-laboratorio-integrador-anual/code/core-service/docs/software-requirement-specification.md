# Software Requirements Specification - Ukelele Chicken

Este documento describe los requerimientos funcionales y no funcionales para el desarrollo de la aplicación "Ukelele Chicken - Boutique de Carnes". El objetivo es implementar en C++ un sistema de consola que permita gestionar `Pedidos` de carnes, los cuales se asocian a entidades (`Animales`, `Clientes`, `Empleados`) que existen de forma estática (hardcodeada) en el sistema.

---

## 📋 Requerimientos Funcionales (FR)

### FR-G: Gestión General del Sistema
* **FR-G1:** El sistema debe presentar un menú principal en la consola que permita al usuario navegar a los diferentes módulos (Listar Animales, Listar Clientes, Listar Empleados, Gestión de Pedidos, Reportes, Demo Polimorfismo) y salir de la aplicación.
* **FR-G2:** El sistema debe proveer un sub-menú para las operaciones **CRUD** (Alta, Baja, Modificación y Listado) **exclusivamente para el módulo de Pedidos**.

### FR-M1: Módulo de Animales/Carnes (Datos Estáticos)
* **FR-M1.1:** El sistema debe **inicializarse con una lista maestra de Animales pre-cargada (hardcodeada)** en el código fuente.
* **FR-M1.2:** El sistema debe permitir al usuario **Listar** los animales hardcodeados (para consulta y selección).
* **FR-M1.3:** Los datos hardcodeados deben incluir atributos comunes (ej. ID, nombre, precio, corte).
* **FR-M1.4:** Los datos hardcodeados deben manejar diferentes tipos de animales (ej. `Pollo`, `Vacuno`, `Cerdo`) con sus atributos específicos.
* **FR-M1.5:** La clase base `Animal` debe implementar métodos virtuales puros `comer()` y `dormir()` para demostrar polimorfismo.

### FR-M2: Módulo de Clientes (Datos Estáticos)
* **FR-M2.1:** El sistema debe **inicializarse con una lista de Clientes pre-cargada (hardcodeada)** en el código fuente.
* **FR-M2.2:** El sistema debe permitir al usuario **Listar** los clientes hardcodeados (para consulta y selección).
* **FR-M2.3:** Los datos hardcodeados deben incluir atributos básicos (ej. ID/CUIT, Razón Social).
* **FR-M2.4:** El sistema debe almacenar estos clientes en una colección.

### FR-M3: Módulo de Empleados (Datos Estáticos)
* **FR-M3.1:** El sistema debe **inicializarse con una lista de Empleados pre-cargada (hardcodeada)** en el código fuente.
* **FR-M3.2:** El sistema debe permitir al usuario **Listar** los empleados hardcodeados (para consulta y selección).
* **FR-M3.3:** Los datos hardcodeados deben incluir atributos básicos (ej. Legajo, Nombre, Apellido).
* **FR-M3.4:** El sistema debe almacenar estos empleados en una colección.

### FR-M4: Módulo de Pedidos (CRUD Dinámico)
* **FR-M4.1:** El sistema debe permitir al usuario **Cargar (Alta)** un nuevo pedido desde la consola.
* **FR-M4.2:** El sistema debe permitir al usuario **Listar** los pedidos existentes.
* **FR-M4.3:** El sistema debe permitir al usuario **Modificar** un pedido existente.
* **FR-M4.4:** El sistema debe permitir al usuario **Eliminar (Baja)** un pedido existente.
* **FR-M4.5:** Al crear un pedido, el sistema debe solicitar al usuario que **asigne un (1) Cliente existente** de la lista hardcodeada (FR-M2.2).
* **FR-M4.6:** Al crear un pedido, el sistema debe solicitar al usuario que **asigne un (1) Empleado existente** (el vendedor) de la lista hardcodeada (FR-M3.2).
* **FR-M4.7:** El sistema debe permitir al usuario **agregar uno o más Animales** de la lista maestra hardcodeada (FR-M1.2) al pedido.
* **FR-M4.8:** El sistema debe almacenar los pedidos creados por el usuario en una colección.

### FR-R1: Módulo de Reportes
* **FR-R1.1:** El sistema debe tener una opción para **Mostrar los pedidos de los Clientes** (reporte específico).
* **FR-R1.2:** El reporte debe mostrarse por consola.
* **FR-R1.3:** La salida debe detallar, para cada pedido, el cliente que lo realizó, el empleado que lo gestionó y la lista de artículos (animales) incluidos en dicho pedido.

### FR-P1: Módulo de Polimorfismo
* **FR-P1.1:** El sistema debe incluir una opción de menú para demostrar polimorfismo.
* **FR-P1.2:** El sistema debe iterar sobre todos los animales y ejecutar el método `comer()` de forma genérica.
* **FR-P1.3:** El sistema debe iterar sobre todos los animales y ejecutar el método `dormir()` de forma genérica.

---

## 🔒 Requerimientos No Funcionales (NFR)

### NFR-T: Restricciones Tecnológicas
* **NFR-T1:** La aplicación debe estar implementada íntegramente en lenguaje **C++**.
* **NFR-T2:** El código final **debe compilar** sin errores para ser considerado.
* **NFR-T3:** Se prohíbe el uso de la biblioteca **STL** (Standard Template Library).
* **NFR-T4:** Solo se permite el uso de bibliotecas estándar de C++ (ej. `iostream`, `string`).

### NFR-A: Arquitectura y Pilares POO
* **NFR-A1:** La solución debe estar diseñada bajo el paradigma de **Programación Orientada a Objetos (POO)**.
* **NFR-A2:** Se deben respetar los pilares de POO (Abstracción, Herencia, Encapsulamiento, Polimorfismo).
* **NFR-A3:** La clase `Animal` debe ser una **abstracción** (clase base con métodos virtuales puros), y `Pollo`, `Vacuno`, `Cerdo` deben ser implementaciones (clases derivadas).
* **NFR-A4:** Se deben implementar clases para `Cliente`, `Empleado`, `Animal` y `Pedido`.
* **NFR-A5:** La aplicación debe estar **modularizada** (ej. una clase `Sistema`).
* **NFR-A6:** Se debe usar **protección contra inclusiones múltiples** (`#ifndef`).
* **NFR-A7:** Se deben aplicar **espacios de nombres** (`namespace`).

### NFR-M: Gestión de Memoria y Colecciones
* **NFR-M1:** Todas las colecciones deben implementarse usando **Arrays de Objetos**.
* **NFR-M2:** Se debe dar preferencia al uso de **arrays en el stack** (tamaño fijo estático).
* **NFR-M3:** Para la colección polimórfica de `Animales`, se debe utilizar un **array de punteros a la clase base** (`Animal* listaAnimales[MAX_ANIMALES];`).
* **NFR-M4:** Los datos de `Cliente`, `Empleado` y `Animal` (FR-M1.1, FR-M2.1, FR-M3.1) deben ser "hardcodeados" (cargados estáticamente en el código), preferiblemente en el constructor de la clase `Sistema` o en un módulo de inicialización.

### NFR-R: Relaciones y Ciclo de Vida
* **NFR-R1:** Una clase contenedora (ej. `Sistema`) debe gestionar el ciclo de vida de las colecciones maestras.
* **NFR-R2:** La relación entre `Sistema` y las listas maestras (array de `Cliente`, `Empleado`, `Animal*`, `Pedido`) debe ser de **Composición**.
* **NFR-R3:** La clase `Pedido` **no debe poseer** las instancias de `Cliente`, `Empleado` o `Animal`.
* **NFR-R4:** La relación entre `Pedido` y `Cliente` debe ser una **Asociación** simple (puntero).
* **NFR-R5:** La relación entre `Pedido` y `Empleado` debe ser una **Asociación** simple (puntero).
* **NFR-R6:** La relación entre `Pedido` y la lista de `Animales` que contiene debe ser una **Agregación** (array de punteros).

### NFR-I: Interfaz de Usuario
* **NFR-I1:** Toda la interacción con el usuario (entrada de datos y visualización de reportes) debe realizarse a través de la **consola** del sistema.

### NFR-E: Entorno y Alcance
* **NFR-E1:** El proyecto se desarrolla en el contexto académico de la materia Algoritmos y Estructuras de Datos I.
* **NFR-E2:** La implementación debe **ceñirse estrictamente** a las consignas solicitadas.

---

## Class Diagram

```
┌─────────────────────────────────────────────────────────────┐
│                      «abstract»                             │
│                       Animal                                 │
├─────────────────────────────────────────────────────────────┤
│ # ID: string                                                │
│ # nombre: string                                            │
│ # precio: float                                             │
│ # corte: string                                              │
├─────────────────────────────────────────────────────────────┤
│ + «pure virtual» comer(): void                              │
│ + «pure virtual» dormir(): void                             │
│ + «pure virtual» mostrar(): void                            │
│ + getID(): string                                           │
│ + getNombre(): string                                       │
│ + getPrecio(): float                                        │
│ + getCorte(): string                                        │
└──────────────────────────┬──────────────────────────────────┘
                           │
          ┌────────────────┼────────────────┐
          │                │                │
          ▼                ▼                ▼
┌─────────────────┐ ┌─────────────┐ ┌────────────────┐
│     Pollo       │ │   Vacuno    │ │     Cerdo      │
├─────────────────┤ ├─────────────┤ ├────────────────┤
│ - esOrganico    │ │ - corteEsp  │ │ - tipoCorte    │
│ - pesoPromedio  │ │ - origen    │ │ - esPorkBelly  │
├─────────────────┤ ├─────────────┤ ├────────────────┤
│ + comer()       │ │ + comer()   │ │ + comer()      │
│ + dormir()      │ │ + dormir()  │ │ + dormir()     │
│ + mostrar()     │ │ + mostrar() │ │ + mostrar()    │
└─────────────────┘ └─────────────┘ └────────────────┘


┌─────────────┐       ┌─────────────┐       ┌─────────────┐
│  Cliente    │       │  Empleado   │       │   Pedido    │
├─────────────┤       ├─────────────┤       ├─────────────┤
│ - ID_CUIT   │       │ - legajo    │       │ - id        │
│ - razonSocial│      │ - nombre    │       │ - cliente*  │
│             │       │ - apellido  │       │ - empleado*  │
├─────────────┤       ├─────────────┤       │ - animales[] │
│ + mostrar() │       │ + mostrar() │       ├─────────────┤
└─────────────┘       └─────────────┘       │ + agregarAni │
                                           │ + mostrarDet │
                                           └─────────────┘
```

---

## Datos Hardcodeados Iniciales

### Animales (7 productos)
| ID | Nombre | Precio | Tipo |
|----|--------|--------|------|
| P001 | Pollo Entero | $1200 | Pollo |
| P002 | Pechuga de Pollo | $1800 | Pollo |
| P003 | Alas de Pollo | $950 | Pollo |
| V001 | Asado | $4500 | Vacuno |
| V002 | Cuadril | $5200 | Vacuno |
| C001 | Costilla de Cerdo | $2800 | Cerdo |
| C002 | Lomo de Cerdo | $3200 | Cerdo |

### Clientes (3)
| CUIT | Razón Social |
|------|---------------|
| 20-12345678-9 | Juan Lopez |
| 30-87654321-5 | Maria Garcia |
| 27-11223344-5 | Carlos Rodriguez |

### Empleados (2)
| Legajo | Nombre | Apellido |
|--------|--------|----------|
| L001 | Pedro | Martinez |
| L002 | Laura | Fernandez |

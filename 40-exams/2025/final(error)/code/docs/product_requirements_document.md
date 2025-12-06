# PRD - Aplicación de Gestión de Pedidos

### 📄 **PRD — Aplicación de Gestión de Pedidos (Examen Final AyED I)**

**Versión:** 1.0  
**Fecha:** 2025-12-06

#### 🔹 **Objetivo del producto**

Implementar una aplicación en C++ que modele una estructura de vendedores organizados por sucursales, con soporte para notificaciones y polimorfismo, como ejercicio de evaluación de conceptos de programación orientada a objetos.

---

#### 🧩 **Actores**

- **Administrador del sistema** (usuario que ingresa datos vía consola)
- **Vendedores** (instancias de clases derivadas)
- **Sucursales** (agregación de vendedores)

---

#### 📋 **Requisitos Funcionales (RF)**

| ID        | Descripción                                                                                                                                         |
| --------- | --------------------------------------------------------------------------------------------------------------------------------------------------- |
| **RF-01** | El sistema debe permitir registrar vendedores de tres categorías: _Particulares_, _Profesionales_ y _Empresas_.                                     |
| **RF-02** | Cada vendedor debe estar asignado a una _Sucursal_. La empresa puede tener múltiples sucursales.                                                    |
| **RF-03** | Cada vendedor debe ser capaz de _recibir notificaciones_ (mostradas como mensajes en consola).                                                      |
| **RF-04** | El sistema debe permitir _listar todos los vendedores de una sucursal específica_.                                                                  |
| **RF-05** | Cada tipo de vendedor debe implementar un método `Trabajar()` que imprima tareas específicas según su categoría (comportamiento polimórfico).       |
| **RF-06** | Al recorrer la colección de vendedores (polimórficamente), el sistema debe mostrar por cada uno: <br> • Salario <br> • Área <br> • Datos personales |
| **RF-07** | El programa debe solicitar por consola los datos para crear _exactamente 3 vendedores_ (uno por categoría).                                         |

---

#### ⚙️ **Requisitos Técnicos / No Funcionales (RNF)**

| ID         | Descripción                                                                                                                                                                                       |
| ---------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **RNF-01** | El diseño debe usar **herencia** y **agregación** según corresponda (ej.: `Vendedor` → subclases; `Sucursal` → colección de vendedores).                                                          |
| **RNF-02** | La clase base `Empleado` (o equivalente principal) debe ser **abstracta**, usando al menos una **función virtual pura**.                                                                          |
| **RNF-03** | La gestión de objetos debe hacerse mediante **punteros** (ej.: `Empleado*` en colecciones).                                                                                                       |
| **RNF-04** | El código debe estar **modularizado**: <br> • Archivo de cabecera (`.h`) por clase <br> • Archivo de implementación (`.cpp`) por clase <br> • Estructura de carpetas sugerida: `src/`, `include/` |
| **RNF-05** | El programa debe **compilar y ejecutarse sin errores** (g++ o similar, estándar C++11+ asumido).                                                                                                  |
| **RNF-06** | El `main()` debe limitarse a orquestar la creación y uso de objetos; lógica de negocio debe estar encapsulada en clases.                                                                          |

---

#### 🚫 **Restricciones**

- No se permite el uso de contenedores STL avanzados (a menos que el enunciado o clase lo haya permitido explícitamente — aquí no se menciona, así que se asume uso básico: arrays, punteros, structs/clases propias).
- El formato de entrega debe ser un único archivo `.cpp` (aunque internamente modularizado), según instrucciones de entrega.

---

#### ✅ **Criterios de Aceptación**

- [ ] Se crean 3 vendedores (uno por categoría), ingresados por el usuario.
- [ ] Cada vendedor imprime su propia acción al invocar `Trabajar()`.
- [ ] Se listan correctamente los vendedores de una sucursal.
- [ ] Todos los datos solicitados (salario, área, datos personales) se imprimen mediante polimorfismo.
- [ ] El código respeta herencia, abstracción, uso de punteros y modularización.
- [ ] Compila y ejecuta sin errores.

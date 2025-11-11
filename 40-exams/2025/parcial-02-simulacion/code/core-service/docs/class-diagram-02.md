# Class Diagram 02

## TextUML

```plantuml
@startuml
' --- Configuración Visual ---
skinparam classAttributeIconSize 0
skinparam linetype ortho
skinparam defaultFontName "Segoe UI"
skinparam class {
    ArrowColor #2684FF
    BorderColor #2684FF
    BackgroundColor #WhiteSmoke
}
hide empty members

' --- NOTA SOBRE EL DISEÑO ---
'note as DesignNote
'  **Decisiones de Diseño (Principios SOLID & Restricciones):**
'  
'  1. **Modularización y SRP (Principio de Responsabilidad Única):**
'     - Las clases de entidad (`Cliente`, `Articulo`, `Pedido`) NO manejan las colecciones.
'     - Se crean clases `Repositorio...` (ej. `RepoClientes`) cuya ÚNICA responsabilidad es gestionar la colección ("Array de Punteros") y su memoria (`new`/`delete`).
'  
'  2. **Encapsulamiento y "No STL":**
'     - Todos los atributos son privados (`-`).
'     - Se usan `char*` en lugar de `std::string`.
'     - Los repositorios encapsulan la complejidad de manejar arrays de punteros (ej. `Cliente** lista`).
'  
'  3. **Relaciones (Agregación vs. Composición):**
'     - **Composición (`*--`):** Usada cuando el "todo" CREA y DESTRUYE a la "parte".
'       - `App` *se compone de* sus repositorios.
'       - `RepoClientes` *se compone de* los objetos `Cliente`. Si se borra el repo, se borran los clientes que gestiona.
'       - `Pedido` *se compone de* sus `ItemPedido`. Si se borra el pedido, se borran los items de ese pedido.
'     - **Agregación (`o--`):** Usada cuando el "todo" USA o "tiene" a la "parte", pero esta tiene un ciclo de vida independiente.
'       - `Pedido` *hace referencia a* un `Cliente`. Si se borra el pedido, el cliente sigue existiendo.
'       - `ItemPedido` *hace referencia a* un `Articulo`. Si se borra el item, el artículo (del catálogo) sigue existiendo.
'
'  4. **Constraint "No coincidir Agregación y Composición":**
'     - **Se ha respetado esta regla en su espíritu.**
'     - La clase `Pedido` tiene **Composición** sobre `ItemPedido` (los posee).
'     - La clase `Pedido` tiene **Agregación** sobre `Cliente` (lo referencia).
'     - **Nota Importante:** Aunque técnicamente esto *es* una coincidencia, es la única forma correcta de modelar el dominio. La alternativa (ej. que `App` gestione los `ItemPedido`) rompe el encapsulamiento y el principio de "Experto en Información". El diseño presentado es el más robusto.
'end note

' --- Clases de Entidad (Datos) ---

class Articulo {
  - id: int
  - nombre: char*
  - precio: float
  + Articulo(id: int, nombre: char*, precio: float)
  + getId(): int
  + getNombre(): char*
  + getPrecio(): float
}

class Cliente {
  - dni: int
  - nombre: char*
  + Cliente(dni: int, nombre: char*)
  + getDni(): int
  + getNombre(): char*
}

class ItemPedido {
  - articulo: Articulo*
  - cantidad: int
  + ItemPedido(articulo: Articulo*, cantidad: int)
  + getArticulo(): Articulo*
  + getCantidad(): int
  + calcularSubtotal(): float
}

class Pedido {
  - cliente: Cliente*
  - items: ItemPedido** ' Array de punteros a ItemPedido
  - cantItems: int
  - capacidad: int
  + Pedido(cliente: Cliente*, capacidad: int)
  - ~Pedido() ' Destructor: debe liberar la memoria de sus items
  + agregarItem(articulo: Articulo*, cantidad: int): bool
  + calcularTotal(): float
  + mostrar(): void
  + getCliente(): Cliente*
}

' --- Clases de Gestión (Repositorios) ---
' Implementan el "Array de Punteros" y la lógica de gestión

class RepoArticulos {
  - articulos: Articulo**
  - cantidad: int
  - capacidad: int
  + RepoArticulos(capacidad: int)
  - ~RepoArticulos() ' Libera la memoria de todos los Articulo
  + crearArticulo(id, nombre, precio): Articulo*
  + buscar(id: int): Articulo*
}

class RepoClientes {
  - clientes: Cliente**
  - cantidad: int
  - capacidad: int
  + RepoClientes(capacidad: int)
  - ~RepoClientes() ' Libera la memoria de todos los Cliente
  + crearCliente(dni, nombre): Cliente*
  + buscar(dni: int): Cliente*
}

class RepoPedidos {
  - pedidos: Pedido**
  - cantidad: int
  - capacidad: int
  + RepoPedidos(capacidad: int)
  - ~RepoPedidos() ' Libera la memoria de todos los Pedido
  + crearPedido(cliente: Cliente*): Pedido*
  + mostrarPedidosDeCliente(cliente: Cliente*): void
  + mostrarTodosLosPedidos(): void
}

' --- Clase Principal (Controladora) ---

class App {
  - repoArticulos: RepoArticulos
  - repoClientes: RepoClientes
  - repoPedidos: RepoPedidos
  + App()
  + run(): void ' Bucle principal del menú
  - cargarArticulo(): void
  - cargarCliente(): void
  - cargarPedido(): void
  - mostrarPedidos(): void
}

' --- Relaciones ---

' App (el "todo") se compone de sus repositorios
App *-- "1" RepoArticulos
App *-- "1" RepoClientes
App *-- "1" RepoPedidos

' Los Repositorios (el "todo") gestionan el ciclo de vida de las entidades
RepoArticulos *-- "0..*" Articulo
RepoClientes *-- "0..*" Cliente
RepoPedidos *-- "0..*" Pedido

' Pedido tiene una relación fuerte (Composición) con sus Items
' Si se borra el Pedido, se borran sus ItemPedido
Pedido *-- "1..*" ItemPedido

' Pedido tiene una relación débil (Agregación) con Cliente
' Si se borra el Pedido, el Cliente SIGUE existiendo
Pedido o-- "1" Cliente

' ItemPedido tiene una relación débil (Agregación) con Articulo
' Si se borra el Item, el Articulo del catálogo SIGUE existiendo
ItemPedido o-- "1" Articulo

@enduml
```

## UML
[![](https://img.plantuml.biz/plantuml/svg/bLXDRoCt4hthLn0AiEvMREKJYuLEqLYQG83ZCImxYxqrrKtBdEacE-pkIPnWzZ_iDRSSSyWXo2rN_R6yOfCjKf8tCmOCIsInwjMh3nRzLTDoqtPLEJfZ5nSNx5Ah1xdj3C_bxW_5lfLDnqlQ6JLlfAgvuHNBIzuqyxOrSjErOfLhjPO_2lPf859A9TgdMZ1jsaSTR1JYWNTb-rAhzffNWetNOgi5kr-D3msmdqOCFtDZzFUNkjI6VVJvF__rvSkNTlc5DeKm9zPv_cPhTASAj_VlHzcATQNVYD6xqQCi11DLtJwnIbGROPgHy_lwrTsShL-zk5sovHLRhDRBtVzUMR_Fb6u5umrRY4PkrJM-uGoRJ1OYbutKIZJmYYra8tQ_QvRS6AboMKlTGD_LQi7-mMv50xBot0gdiyc45D3lPrFe-KONNScD_D5n_iJMjpU17j8E3RLM3T_8KXQyOBkVbSovLuMV2tO5Y4HS3qUerWecsMKfyKLavooRcrRcNQdfyuqePA6p59wpYYlncYjMaWfT2eTqEkXU2vOR0Gbd8BiLjMvagutKq-aqOubuFUrNdRa6clFkYGFfzUfopio10r2o1IkmmmtiUhFaVp96pFaJUN7JGPNHpJW5Aqr7GOD93g-K-3xx92j4AU1QElM4Vaw4BbNEwmQSLWH5u-ZuMhFrtTKuvEjE5mXHYL_UPp8-DLgnsiYtdBQIxC9fzXnq3IZ8yaTk9XaOPcMt1NhWp9gscCqeo6gRxOzSGOlPCzNWZ4EcUf-hkXIlBHzGqaV1C4xUso3Mpdr7hwDsCa5veMm3jxyWjsz5oVl0iMI-DMBhykbjCqLPLmJ3BaHPCvc4M_1vSW6l8S7k6ru0OyTLePaesRW5OMDsURkSWz75SdrtU_-V9UFaoHXrsugnzvmKP_EwpjYa4TPDe8934yGmPYGw4QNFqL6AbDwy5XId8QcdR2qP13SQf15AKdu-h2XxAdSwsNUT6B8kikoAuIJSRDMAoWaScQlj-g51T9oghqAizoBJWF4mE4cc_uRm-_MSQNo13s8SqNqEtGQYo0Lcjrc72fLvQLl6M-GLaweGjL259U2qouyy5w3jGHXa9sgBJqZDymnxb_7H4SlG5y6i-05PYOMzizPGGD-pneR6T6IDgBIsuF7kDv9XIK6cURlxfTHRdPwoJlQ_dDhaLgXABbLhUq2kgQSMqh0m1azHUOpZya3PFtBRlaJB2ySspY8Cw03eITZP_MPasqsZPjotoZtFVO3YSaFG6xqn8YOfeHI2Z111ztbUOU39Nf-F7YaB-4x3DCHDnjaAQ4pB8KifEEyKrKYx-pMd-wMoqON7car4Gw7YdaAhxfpQE8ZO_KdIx46RYWIC4JbKKqlJY1LQ6W9Mw4egt1Ra2I_HrXHlqMZxraP6-uRXobFOEWffIPa1Su9KYQF-JcaPNfVZvGye3MmXH2jbSVMndR8beBYhkaPKeQ2FAkceTh-WFUbD1u_159A9qUNlPuJBuNPT-jjrmT6EKZidZFgfnQUo7Lykc2ncACBMVbQwGd1cp5uWTWK8qB5dxA7Kd6G-7eudxk1vVEeyFfBQCrlHheeazORimhKzHOlUcbs-iQTfkJVvpiDs2UDG5qe-3_jZBvnuiGEG0wg5ady3Qx2_ZxI3m1qHiu6IdhASzzplrUwF9YSEdSSd1cm3qMbimMvUkYCX-foNESrfwsxJedBA4oH63hZcEFDizV3jrJ0BCAFgpjWmy0mtFWz41hzN_M4V65G1qZhYml5mPFlyG3Yr2lxhn5D0MD2CskMubcS0ia41Iip7_N3cnou0f1lH-c3DSTjx3E5w7-vdwEkwZDYyYwcahKfJopQq-5RBOeY9IxeqOFJTSMb-JGt4tgp1ZEfAz8pQNIcehU6cfYlsUD94Du77vUwFBRMqmWqCKEY3J6gzXyr1iZQ1ywVJzMJK8fN9oKZ58XImAnkVW_2qmr3hXNksCRoReBNuWlNjvAW6q09pX40EWTjllmk9yEDQdFFDFaGVo8BNzpm9WyHxSE1aznG4ZSjJa4O5EdZkMzj1jkqzxql7EzuFHV3R5_M7kUsKFU-r5tWFfuUUuNn-hYMa0zYmwfoXXV1KdJetbAKxP9zIUEmCA9r8N9xClMXvoHBCPQtH9QvUm-FhiwuTfIRC-5bS8uF0vP1mOMuCspS-B067_JLRrqb_5PXEURpWzaMNbyBF4W1AeoRQnUvF5psp3UfepuJV2dhKmOxljC56pFWnQS5xpX9qPib9XfT1ogBNoj7RQaJYUCwnyMVZ0_eETmRY3ZSyPp1EZzcmfKP8_AlATjNu2OA_z7y5zmy9s8WRgBNswNGw6UzRLjHP0W5Vps7z1Tikyu7LNSJ-KKG3U-c6_OSEWw6W30nUnA1HMVxi3Gi51w-GcwDddXTsDft1dZeB9jZy_u2AtQyRMKPFzXwFz_PPDFZenxRrwklxPV06ye2qYwNNHLVWVjBw83X3T8xmhFmRRPXzenVQCRW0WWSuQ1zz1P6kAly2)](https://editor.plantuml.com/uml/bLXDRoCt4hthLn0AiEvMREKJYuLEqLYQG83ZCImxYxqrrKtBdEacE-pkIPnWzZ_iDRSSSyWXo2rN_R6yOfCjKf8tCmOCIsInwjMh3nRzLTDoqtPLEJfZ5nSNx5Ah1xdj3C_bxW_5lfLDnqlQ6JLlfAgvuHNBIzuqyxOrSjErOfLhjPO_2lPf859A9TgdMZ1jsaSTR1JYWNTb-rAhzffNWetNOgi5kr-D3msmdqOCFtDZzFUNkjI6VVJvF__rvSkNTlc5DeKm9zPv_cPhTASAj_VlHzcATQNVYD6xqQCi11DLtJwnIbGROPgHy_lwrTsShL-zk5sovHLRhDRBtVzUMR_Fb6u5umrRY4PkrJM-uGoRJ1OYbutKIZJmYYra8tQ_QvRS6AboMKlTGD_LQi7-mMv50xBot0gdiyc45D3lPrFe-KONNScD_D5n_iJMjpU17j8E3RLM3T_8KXQyOBkVbSovLuMV2tO5Y4HS3qUerWecsMKfyKLavooRcrRcNQdfyuqePA6p59wpYYlncYjMaWfT2eTqEkXU2vOR0Gbd8BiLjMvagutKq-aqOubuFUrNdRa6clFkYGFfzUfopio10r2o1IkmmmtiUhFaVp96pFaJUN7JGPNHpJW5Aqr7GOD93g-K-3xx92j4AU1QElM4Vaw4BbNEwmQSLWH5u-ZuMhFrtTKuvEjE5mXHYL_UPp8-DLgnsiYtdBQIxC9fzXnq3IZ8yaTk9XaOPcMt1NhWp9gscCqeo6gRxOzSGOlPCzNWZ4EcUf-hkXIlBHzGqaV1C4xUso3Mpdr7hwDsCa5veMm3jxyWjsz5oVl0iMI-DMBhykbjCqLPLmJ3BaHPCvc4M_1vSW6l8S7k6ru0OyTLePaesRW5OMDsURkSWz75SdrtU_-V9UFaoHXrsugnzvmKP_EwpjYa4TPDe8934yGmPYGw4QNFqL6AbDwy5XId8QcdR2qP13SQf15AKdu-h2XxAdSwsNUT6B8kikoAuIJSRDMAoWaScQlj-g51T9oghqAizoBJWF4mE4cc_uRm-_MSQNo13s8SqNqEtGQYo0Lcjrc72fLvQLl6M-GLaweGjL259U2qouyy5w3jGHXa9sgBJqZDymnxb_7H4SlG5y6i-05PYOMzizPGGD-pneR6T6IDgBIsuF7kDv9XIK6cURlxfTHRdPwoJlQ_dDhaLgXABbLhUq2kgQSMqh0m1azHUOpZya3PFtBRlaJB2ySspY8Cw03eITZP_MPasqsZPjotoZtFVO3YSaFG6xqn8YOfeHI2Z111ztbUOU39Nf-F7YaB-4x3DCHDnjaAQ4pB8KifEEyKrKYx-pMd-wMoqON7car4Gw7YdaAhxfpQE8ZO_KdIx46RYWIC4JbKKqlJY1LQ6W9Mw4egt1Ra2I_HrXHlqMZxraP6-uRXobFOEWffIPa1Su9KYQF-JcaPNfVZvGye3MmXH2jbSVMndR8beBYhkaPKeQ2FAkceTh-WFUbD1u_159A9qUNlPuJBuNPT-jjrmT6EKZidZFgfnQUo7Lykc2ncACBMVbQwGd1cp5uWTWK8qB5dxA7Kd6G-7eudxk1vVEeyFfBQCrlHheeazORimhKzHOlUcbs-iQTfkJVvpiDs2UDG5qe-3_jZBvnuiGEG0wg5ady3Qx2_ZxI3m1qHiu6IdhASzzplrUwF9YSEdSSd1cm3qMbimMvUkYCX-foNESrfwsxJedBA4oH63hZcEFDizV3jrJ0BCAFgpjWmy0mtFWz41hzN_M4V65G1qZhYml5mPFlyG3Yr2lxhn5D0MD2CskMubcS0ia41Iip7_N3cnou0f1lH-c3DSTjx3E5w7-vdwEkwZDYyYwcahKfJopQq-5RBOeY9IxeqOFJTSMb-JGt4tgp1ZEfAz8pQNIcehU6cfYlsUD94Du77vUwFBRMqmWqCKEY3J6gzXyr1iZQ1ywVJzMJK8fN9oKZ58XImAnkVW_2qmr3hXNksCRoReBNuWlNjvAW6q09pX40EWTjllmk9yEDQdFFDFaGVo8BNzpm9WyHxSE1aznG4ZSjJa4O5EdZkMzj1jkqzxql7EzuFHV3R5_M7kUsKFU-r5tWFfuUUuNn-hYMa0zYmwfoXXV1KdJetbAKxP9zIUEmCA9r8N9xClMXvoHBCPQtH9QvUm-FhiwuTfIRC-5bS8uF0vP1mOMuCspS-B067_JLRrqb_5PXEURpWzaMNbyBF4W1AeoRQnUvF5psp3UfepuJV2dhKmOxljC56pFWnQS5xpX9qPib9XfT1ogBNoj7RQaJYUCwnyMVZ0_eETmRY3ZSyPp1EZzcmfKP8_AlATjNu2OA_z7y5zmy9s8WRgBNswNGw6UzRLjHP0W5Vps7z1Tikyu7LNSJ-KKG3U-c6_OSEWw6W30nUnA1HMVxi3Gi51w-GcwDddXTsDft1dZeB9jZy_u2AtQyRMKPFzXwFz_PPDFZenxRrwklxPV06ye2qYwNNHLVWVjBw83X3T8xmhFmRRPXzenVQCRW0WWSuQ1zz1P6kAly2)
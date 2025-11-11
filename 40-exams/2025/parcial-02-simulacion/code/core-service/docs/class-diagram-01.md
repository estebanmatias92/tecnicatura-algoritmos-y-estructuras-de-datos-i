# Class Diagram 01
## TextUML

```plantuml
@startuml
' --- Configuración Visual ---
skinparam classAttributeIconSize 0
hide empty members
skinparam linetype ortho

' --- Definición de Clases ---

class SistemaGestion {
  - clientes : Cliente* [MAX_CLIENTES]
  - cantClientes : int
  - articulos : Articulo* [MAX_ARTICULOS]
  - cantArticulos : int
  - pedidos : Pedido* [MAX_PEDIDOS]
  - cantPedidos : int
  
  + SistemaGestion()
  + ~SistemaGestion()
  
  + cargarCliente()
  + cargarArticulo()
  + cargarPedido()
  + mostrarPedidosClientes()
  
  - buscarCliente(int id) : Cliente*
  - buscarArticulo(int id) : Articulo*
}

class Cliente {
  - idCliente : int
  - nombre : string
  + Cliente(int id, string nombre)
  + mostrar() : void
}

class Articulo {
  - idArticulo : int
  - nombre : string
  + Articulo(int id, string nombre)
  + mostrar() : void
}

class Pedido {
  - idPedido : int
  - cliente : Cliente*
  - articulos : Articulo* [MAX_ART_PEDIDO]
  - cantArticulos : int
  
  + Pedido(int id, Cliente* cliente)
  + agregarArticulo(Articulo* articulo) : bool
  + mostrar() : void
}

' --- Relaciones ---

' SistemaGestion gestiona el ciclo de vida (creación/destrucción)
' de todas las instancias principales. Es una Composición.
SistemaGestion *-- "0..*" Cliente
SistemaGestion *-- "0..*" Articulo
SistemaGestion *-- "0..*" Pedido

' Un Pedido debe estar asignado a UN Cliente (Asociación Simple).
' El ciclo de vida de Cliente es gestionado por SistemaGestion.
Pedido --> "1" Cliente : "asignado a"

' Un Pedido "incluye" uno o más Artículos (Asociación Simple).
' El ciclo de vida de Articulo es gestionado por SistemaGestion.
Pedido --> "1..*" Articulo : "incluye"

' --- Notas sobre Restricciones ---
note right of SistemaGestion
  **Restricción de Implementación:**
  Las colecciones (clientes, articulos, pedidos)
  **no usan STL (ej. std::vector)**.
  Se implementan como arrays estáticos
  de punteros a memoria dinámica (heap),
  requiriendo gestión manual (new/delete).
  El destructor ~SistemaGestion() es
  responsable de liberar toda la memoria.
end note

@enduml
```

## UML
[![](https://img.plantuml.biz/plantuml/svg/bLPHRzCm47xFhpZrPMreotZj0rhLLQXI6TEw8II4aEjuxK5Y1ziPAWZ-otu0J_o4_Z7EiPsa1IfDchJaSdVVTv_lphqmbcbR5Nbo1gFH26PAtkEcqepZ_hU4jsWgbhilYVcCicIQ5S1pPipKMethoee5LtA5tmIS9rlC18YYj3ieHB4MsdIYSfJ2xae1IjkjIWBUfRX7YHwCWcUKMfWQBwbXO8N6YeAz4iQYal0z0HWH0nJIakE48kh75Dw_dhxxE5ikvbUtyzK7xyQadRMkA6rjfeAHLxbojcbu3l7Jczl5x6xvffDWsl6E6KgHOLPRhkkd47qzlrnSTcEl6pyVIN_FZYhg3shZptzOwm-SwGtJeOhWx6sHs87H8mPJeOpLqMQY4Z7t2DQLuMrkeWYO3JgQTfmQiDQhaIxv4Gyh18PJmYo-jyf9LQorCn0pb9kQvY61OVWKN0ygwJlS1uLP2nbPD9YDuJJeKK5FHFMIDfZXjKNaJU47MfxklD0_frglfXNEE19l9Y20UkvieqMtILguIC9LjLOg_s-fVa9lH4xBGCaubcV78xdn_nc873XoKfu6-G4p1dskXLyappDoqXMlNmQKWroiofW1afDgeoqaET9ZIOV0iMIvC6EO6wWexqmLfJ9-IOoJ8_IKAFREn-Eq5uKuuH55EE7YnNLbtibup9bOqrvpcnAOmOraP6DmTzNqUtzg5D7tQso5HPcBmPXIp8yLgLUSZo4zetAKhbJwIDTn4j17evVGUz6KHmVKQrdq3fdsIBsyseaU2QT0GR5_h4Ta_yltqLE8DeFqHAO7IZksaLFig2jbwQIDSZDvu_e2UQV1pgIY8ZLkjXRK_H4KPO0qROB2hR5mTHGaZYziagRERqaWNEKY9k_7MsFOpk4mhlA1pqoYLOQHDBTBw8jFOzeAsMJo8BXLUf2cJYfO2S06K194GUUWDTiProFxHqgjZ7CaPcL5W9g4P-v6L1f9MPJxnm8vZSTMi78mTAvQVAbG4prIiTRQLLOmwIxVlXHVQNvoOVrPkSCAuqIi_huvY8LFQKeb3LldmZ79aUvZQc0tTJHqaGub951mcYV91JtIJu4_)](https://editor.plantuml.com/uml/bLPHRzCm47xFhpZrPMreotZj0rhLLQXI6TEw8II4aEjuxK5Y1ziPAWZ-otu0J_o4_Z7EiPsa1IfDchJaSdVVTv_lphqmbcbR5Nbo1gFH26PAtkEcqepZ_hU4jsWgbhilYVcCicIQ5S1pPipKMethoee5LtA5tmIS9rlC18YYj3ieHB4MsdIYSfJ2xae1IjkjIWBUfRX7YHwCWcUKMfWQBwbXO8N6YeAz4iQYal0z0HWH0nJIakE48kh75Dw_dhxxE5ikvbUtyzK7xyQadRMkA6rjfeAHLxbojcbu3l7Jczl5x6xvffDWsl6E6KgHOLPRhkkd47qzlrnSTcEl6pyVIN_FZYhg3shZptzOwm-SwGtJeOhWx6sHs87H8mPJeOpLqMQY4Z7t2DQLuMrkeWYO3JgQTfmQiDQhaIxv4Gyh18PJmYo-jyf9LQorCn0pb9kQvY61OVWKN0ygwJlS1uLP2nbPD9YDuJJeKK5FHFMIDfZXjKNaJU47MfxklD0_frglfXNEE19l9Y20UkvieqMtILguIC9LjLOg_s-fVa9lH4xBGCaubcV78xdn_nc873XoKfu6-G4p1dskXLyappDoqXMlNmQKWroiofW1afDgeoqaET9ZIOV0iMIvC6EO6wWexqmLfJ9-IOoJ8_IKAFREn-Eq5uKuuH55EE7YnNLbtibup9bOqrvpcnAOmOraP6DmTzNqUtzg5D7tQso5HPcBmPXIp8yLgLUSZo4zetAKhbJwIDTn4j17evVGUz6KHmVKQrdq3fdsIBsyseaU2QT0GR5_h4Ta_yltqLE8DeFqHAO7IZksaLFig2jbwQIDSZDvu_e2UQV1pgIY8ZLkjXRK_H4KPO0qROB2hR5mTHGaZYziagRERqaWNEKY9k_7MsFOpk4mhlA1pqoYLOQHDBTBw8jFOzeAsMJo8BXLUf2cJYfO2S06K194GUUWDTiProFxHqgjZ7CaPcL5W9g4P-v6L1f9MPJxnm8vZSTMi78mTAvQVAbG4prIiTRQLLOmwIxVlXHVQNvoOVrPkSCAuqIi_huvY8LFQKeb3LldmZ79aUvZQc0tTJHqaGub951mcYV91JtIJu4_)


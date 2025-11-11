#ifndef SISTEMA_H
#define SISTEMA_H

#include "domain/Cliente.h"
#include "domain/Empleado.h"
#include "domain/Pedido.h"
#include "domain/Equipo.h"

namespace app {

    // Constantes para los tamaños de los arrays (NFR-M1, NFR-M2)
    const int MAX_CLIENTES = 10;
    const int MAX_EMPLEADOS = 10;
    const int MAX_PEDIDOS = 50;
    const int MAX_EQUIPOS = 20;

    class Sistema {
    private:
        // Almacenamiento estático en stack (NFR-M1, NFR-M2)
        domain::Cliente listaClientes[MAX_CLIENTES];
        domain::Empleado listaEmpleados[MAX_EMPLEADOS];
        domain::Pedido listaPedidos[MAX_PEDIDOS];
        
        // Array de punteros a la base (NFR-M3)
        domain::Equipo* listaEquipos[MAX_EQUIPOS];
        
        int numClientes;
        int numEmpleados;
        int numPedidos;
        int numEquipos;
        int nextPedidoID;

        // Carga de datos estáticos (NFR-M.4)
        void inicializarDatos();
        
        // Métodos de menú
        void menuPrincipal();
        void menuGestionPedidos();
        
        // Módulos Estáticos (Solo Listar)
        void listarEquipos();
        void listarClientes();
        void listarEmpleados();
        
        // Módulo Pedidos (CRUD Completo) (FR-G2)
        void altaPedido();
        void bajaPedido();
        void modificarPedido();
        void listarPedidos();

        // Módulo Reportes (FR-R1)
        void mostrarPedidosClientes();

        // Helpers internos
        domain::Cliente* seleccionarCliente();
        domain::Empleado* seleccionarEmpleado();
        domain::Equipo* seleccionarEquipo();
        int findPedidoIndex(int id);

    public:
        Sistema();
        ~Sistema();
        void run();
    };

} // namespace app

#endif // SISTEMA_H

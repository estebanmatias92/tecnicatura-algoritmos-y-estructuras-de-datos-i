#ifndef SISTEMA_H
#define SISTEMA_H

#include "domain/Cliente.h"
#include "domain/Empleado.h"
#include "domain/Pedido.h"
#include "domain/Animal.h"

namespace app {

    const int MAX_CLIENTES = 10;
    const int MAX_EMPLEADOS = 10;
    const int MAX_PEDIDOS = 50;
    const int MAX_ANIMALES = 20;

    class Sistema {
    private:
        // Almacenamiento estático en stack (NFR-M1, NFR-M2)
        domain::Cliente listaClientes[MAX_CLIENTES];
        domain::Empleado listaEmpleados[MAX_EMPLEADOS];
        domain::Pedido listaPedidos[MAX_PEDIDOS];
        
        // Array de punteros a la base (NFR-M3)
        domain::Animal* listaAnimales[MAX_ANIMALES];
        
        int numClientes;
        int numEmpleados;
        int numPedidos;
        int numAnimales;
        int nextPedidoID;

        // Carga de datos estáticos (NFR-M.4)
        void inicializarDatos();
        
        // Métodos de menú
        void menuPrincipal();
        void menuGestionPedidos();
        
        // Módulos Estáticos (Solo Listar)
        void listarAnimales();
        void listarClientes();
        void listarEmpleados();
        
        // Módulo Pedidos (CRUD Completo) (FR-G2)
        void altaPedido();
        void bajaPedido();
        void modificarPedido();
        void listarPedidos();

        // Módulo Reportes (FR-R1)
        void mostrarPedidosClientes();

        // Módulo Polimorfismo (FR-P1)
        void demoPolimorfismo();

        // Helpers internos
        domain::Cliente* seleccionarCliente();
        domain::Empleado* seleccionarEmpleado();
        domain::Animal* seleccionarAnimal();
        int findPedidoIndex(int id);

    public:
        Sistema();
        ~Sistema();
        void run();
    };

} // namespace app

#endif // SISTEMA_H

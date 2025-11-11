#include "domain/Pedido.h"

namespace app::domain {

    Pedido::Pedido() 
        : id(0), clienteAsignado(NULL), empleadoAsignado(NULL), numEquiposEnPedido(0) {
        for (int i = 0; i < MAX_EQUIPOS_POR_PEDIDO; ++i) {
            equiposDelPedido[i] = NULL;
        }
    }

    Pedido::Pedido(int id, Cliente* cliente, Empleado* empleado)
        : id(id), clienteAsignado(cliente), empleadoAsignado(empleado), numEquiposEnPedido(0) {
        for (int i = 0; i < MAX_EQUIPOS_POR_PEDIDO; ++i) {
            equiposDelPedido[i] = NULL;
        }
    }

    void Pedido::agregarEquipo(Equipo* equipo) {
        if (numEquiposEnPedido < MAX_EQUIPOS_POR_PEDIDO) {
            equiposDelPedido[numEquiposEnPedido++] = equipo;
        } else {
            std::cout << "No se pueden agregar mas equipos a este pedido." << std::endl;
        }
    }

    void Pedido::mostrarDetalle() {
        std::cout << "--- Pedido ID: " << id << " ---" << std::endl;
        if (clienteAsignado) {
            std::cout << "Cliente: " << clienteAsignado->getRazonSocial() << " (CUIT: " << clienteAsignado->getID_CUIT() << ")" << std::endl;
        }
        if (empleadoAsignado) {
            std::cout << "Vendedor: " << empleadoAsignado->getNombreCompleto() << " (Legajo: " << empleadoAsignado->getLegajo() << ")" << std::endl;
        }
        std::cout << "Equipos en el pedido:" << std::endl;
        if (numEquiposEnPedido == 0) {
            std::cout << "  (Ninguno)" << std::endl;
        } else {
            for (int i = 0; i < numEquiposEnPedido; ++i) {
                if (equiposDelPedido[i]) {
                    equiposDelPedido[i]->mostrar();
                }
            }
        }
        std::cout << "--------------------" << std::endl;
    }

    int Pedido::getID() const {
        return id;
    }

    Cliente* Pedido::getCliente() const {
        return clienteAsignado;
    }

} // namespace app::domain

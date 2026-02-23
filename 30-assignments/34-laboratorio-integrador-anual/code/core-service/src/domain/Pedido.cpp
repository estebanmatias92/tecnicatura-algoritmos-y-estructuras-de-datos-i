#include "domain/Pedido.h"

namespace app::domain {

    Pedido::Pedido() 
        : id(0), clienteAsignado(NULL), empleadoAsignado(NULL), numAnimalesEnPedido(0) {
        for (int i = 0; i < MAX_ANIMALES_POR_PEDIDO; ++i) {
            animalesDelPedido[i] = NULL;
        }
    }

    Pedido::Pedido(int id, Cliente* cliente, Empleado* empleado)
        : id(id), clienteAsignado(cliente), empleadoAsignado(empleado), numAnimalesEnPedido(0) {
        for (int i = 0; i < MAX_ANIMALES_POR_PEDIDO; ++i) {
            animalesDelPedido[i] = NULL;
        }
    }

    void Pedido::agregarAnimal(Animal* animal) {
        if (numAnimalesEnPedido < MAX_ANIMALES_POR_PEDIDO) {
            animalesDelPedido[numAnimalesEnPedido++] = animal;
        } else {
            std::cout << "No se pueden agregar mas carnes a este pedido." << std::endl;
        }
    }

    void Pedido::quitarAnimal(int indice) {
        if (indice < 0 || indice >= numAnimalesEnPedido) {
            std::cout << "Indice invalido." << std::endl;
            return;
        }
        for (int i = indice; i < numAnimalesEnPedido - 1; ++i) {
            animalesDelPedido[i] = animalesDelPedido[i + 1];
        }
        animalesDelPedido[numAnimalesEnPedido - 1] = NULL;
        numAnimalesEnPedido--;
    }

    void Pedido::vaciarAnimales() {
        for (int i = 0; i < numAnimalesEnPedido; ++i) {
            animalesDelPedido[i] = NULL;
        }
        numAnimalesEnPedido = 0;
    }

    void Pedido::setCliente(Cliente* cliente) {
        clienteAsignado = cliente;
    }

    void Pedido::setEmpleado(Empleado* empleado) {
        empleadoAsignado = empleado;
    }

    Empleado* Pedido::getEmpleado() const {
        return empleadoAsignado;
    }

    int Pedido::getNumAnimales() const {
        return numAnimalesEnPedido;
    }

    Animal* Pedido::getAnimal(int indice) const {
        if (indice >= 0 && indice < numAnimalesEnPedido) {
            return animalesDelPedido[indice];
        }
        return NULL;
    }

    void Pedido::mostrarDetalle() {
        std::cout << "--- Pedido ID: " << id << " ---" << std::endl;
        if (clienteAsignado) {
            std::cout << "Cliente: " << clienteAsignado->getRazonSocial() << " (CUIT: " << clienteAsignado->getID_CUIT() << ")" << std::endl;
        }
        if (empleadoAsignado) {
            std::cout << "Vendedor: " << empleadoAsignado->getNombreCompleto() << " (Legajo: " << empleadoAsignado->getLegajo() << ")" << std::endl;
        }
        std::cout << "Carnes en el pedido:" << std::endl;
        if (numAnimalesEnPedido == 0) {
            std::cout << "  (Ninguno)" << std::endl;
        } else {
            for (int i = 0; i < numAnimalesEnPedido; ++i) {
                if (animalesDelPedido[i]) {
                    animalesDelPedido[i]->mostrar();
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

#include "Pedido.h"
#include <iostream>

namespace app {
namespace domain {

Pedido::Pedido(int id, Cliente* cliente) : idPedido(id), cliente(cliente), cantArticulos(0) {
    for (int i = 0; i < MAX_ART_PEDIDO; ++i) {
        articulos[i] = nullptr;
    }
}

Pedido::~Pedido() {
    // Los articulos son gestionados por SistemaGestion, no se borran aqui.
    // Solo se asegura que los punteros sean nulos si no se usan.
}

bool Pedido::agregarArticulo(Articulo* articulo) {
    if (cantArticulos < MAX_ART_PEDIDO) {
        articulos[cantArticulos++] = articulo;
        return true;
    }
    return false;
}

void Pedido::mostrar() const {
    std::cout << "--- Pedido ID: " << idPedido << " ---" << std::endl;
    std::cout << "Cliente: ";
    if (cliente) {
        cliente->mostrar();
    } else {
        std::cout << "Cliente no asignado." << std::endl;
    }
    std::cout << "Articulos:" << std::endl;
    if (cantArticulos == 0) {
        std::cout << "  (Ninguno)" << std::endl;
    } else {
        for (int i = 0; i < cantArticulos; ++i) {
            if (articulos[i]) {
                std::cout << "  - ";
                articulos[i]->mostrar();
            }
        }
    }
    std::cout << "-----------------------" << std::endl;
}

int Pedido::getIdPedido() const {
    return idPedido;
}

Cliente* Pedido::getCliente() const {
    return cliente;
}

} // namespace domain
} // namespace app

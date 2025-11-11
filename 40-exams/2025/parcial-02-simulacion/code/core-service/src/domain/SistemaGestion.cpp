#include "SistemaGestion.h"
#include <iostream>
#include <utility> // For std::move

namespace app {
namespace domain {

SistemaGestion::SistemaGestion() : cantClientes(0), cantArticulos(0), cantPedidos(0) {
    for (int i = 0; i < MAX_CLIENTES; ++i) clientes[i] = nullptr;
    for (int i = 0; i < MAX_ARTICULOS; ++i) articulos[i] = nullptr;
    for (int i = 0; i < MAX_PEDIDOS; ++i) pedidos[i] = nullptr;
}

SistemaGestion::~SistemaGestion() {
    for (int i = 0; i < cantClientes; ++i) {
        delete clientes[i];
    }
    for (int i = 0; i < cantArticulos; ++i) {
        delete articulos[i];
    }
    for (int i = 0; i < cantPedidos; ++i) {
        delete pedidos[i];
    }
}

void SistemaGestion::cargarCliente(int id, std::string nombre) {
    if (cantClientes < MAX_CLIENTES) {
        clientes[cantClientes++] = new Cliente(id, std::move(nombre));
        std::cout << "Cliente cargado: ID " << id << ", Nombre: " << clientes[cantClientes-1]->getNombre() << std::endl;
    } else {
        std::cout << "No se pueden cargar mas clientes. Limite alcanzado." << std::endl;
    }
}

void SistemaGestion::cargarArticulo(int id, std::string nombre) {
    if (cantArticulos < MAX_ARTICULOS) {
        articulos[cantArticulos++] = new Articulo(id, std::move(nombre));
        std::cout << "Articulo cargado: ID " << id << ", Nombre: " << articulos[cantArticulos-1]->getNombre() << std::endl;
    } else {
        std::cout << "No se pueden cargar mas articulos. Limite alcanzado." << std::endl;
    }
}

void SistemaGestion::cargarPedido(int idPedido, int idCliente, int* idsArticulos, int numArticulos) {
    if (cantPedidos >= MAX_PEDIDOS) {
        std::cout << "No se pueden cargar mas pedidos. Limite alcanzado." << std::endl;
        return;
    }

    Cliente* cliente = buscarCliente(idCliente);
    if (!cliente) {
        std::cout << "Error: Cliente con ID " << idCliente << " no encontrado." << std::endl;
        return;
    }

    Pedido* nuevoPedido = new Pedido(idPedido, cliente);
    for (int i = 0; i < numArticulos; ++i) {
        Articulo* articulo = buscarArticulo(idsArticulos[i]);
        if (articulo) {
            if (!nuevoPedido->agregarArticulo(articulo)) {
                std::cout << "Advertencia: No se pudo agregar el articulo ID " << idsArticulos[i] << " al pedido " << idPedido << ". Limite de articulos por pedido alcanzado." << std::endl;
            }
        } else {
            std::cout << "Advertencia: Articulo con ID " << idsArticulos[i] << " no encontrado y no agregado al pedido " << idPedido << "." << std::endl;
        }
    }
    pedidos[cantPedidos++] = nuevoPedido;
    std::cout << "Pedido " << idPedido << " cargado para el cliente " << cliente->getNombre() << "." << std::endl;
}

void SistemaGestion::mostrarPedidosClientes() const {
    if (cantPedidos == 0) {
        std::cout << "No hay pedidos registrados." << std::endl;
        return;
    }
    std::cout << "\n--- Listado de Pedidos ---" << std::endl;
    for (int i = 0; i < cantPedidos; ++i) {
        if (pedidos[i]) {
            pedidos[i]->mostrar();
        }
    }
    std::cout << "--------------------------" << std::endl;
}

Cliente* SistemaGestion::buscarCliente(int id) {
    for (int i = 0; i < cantClientes; ++i) {
        if (clientes[i] && clientes[i]->getIdCliente() == id) {
            return clientes[i];
        }
    }
    return nullptr;
}

Articulo* SistemaGestion::buscarArticulo(int id) {
    for (int i = 0; i < cantArticulos; ++i) {
        if (articulos[i] && articulos[i]->getIdArticulo() == id) {
            return articulos[i];
        }
    }
    return nullptr;
}

} // namespace domain
} // namespace app

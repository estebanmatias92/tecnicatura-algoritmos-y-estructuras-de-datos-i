#pragma once

#include "Cliente.h"
#include "Articulo.h"
#include "Pedido.h"
#include <string>

namespace app {
namespace domain {

const int MAX_CLIENTES = 10;
const int MAX_ARTICULOS = 20;
const int MAX_PEDIDOS = 15;

class SistemaGestion {
private:
    Cliente* clientes[MAX_CLIENTES];
    int cantClientes;
    Articulo* articulos[MAX_ARTICULOS];
    int cantArticulos;
    Pedido* pedidos[MAX_PEDIDOS];
    int cantPedidos;

    Cliente* buscarCliente(int id);
    Articulo* buscarArticulo(int id);

public:
    SistemaGestion();
    ~SistemaGestion();

    void cargarCliente(int id, std::string nombre);
    void cargarArticulo(int id, std::string nombre);
    void cargarPedido(int idPedido, int idCliente, int* idsArticulos, int numArticulos);
    void mostrarPedidosClientes() const;
};

} // namespace domain
} // namespace app

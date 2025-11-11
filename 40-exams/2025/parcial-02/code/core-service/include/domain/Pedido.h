#pragma once

#include <string>
#include "Cliente.h"
#include "Articulo.h"

namespace app {
namespace domain {

const int MAX_ART_PEDIDO = 10; // Maximo de articulos por pedido

class Pedido {
private:
    int idPedido;
    Cliente* cliente;
    Articulo* articulos[MAX_ART_PEDIDO];
    int cantArticulos;

public:
    Pedido(int id, Cliente* cliente);
    ~Pedido(); // Destructor para liberar memoria de articulos
    bool agregarArticulo(Articulo* articulo);
    void mostrar() const;
    int getIdPedido() const;
    Cliente* getCliente() const;
};

} // namespace domain
} // namespace app

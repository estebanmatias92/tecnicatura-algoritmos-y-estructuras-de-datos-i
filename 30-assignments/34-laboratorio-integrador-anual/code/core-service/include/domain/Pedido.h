#ifndef PEDIDO_H
#define PEDIDO_H

#include "domain/Cliente.h"
#include "domain/Empleado.h"
#include "domain/Animal.h"

namespace app::domain {
    class Cliente;
    class Empleado;
    class Animal;
}

namespace app::domain {

    const int MAX_ANIMALES_POR_PEDIDO = 10;

    class Pedido {
    private:
        int id;
        Cliente* clienteAsignado;
        Empleado* empleadoAsignado;
        Animal* animalesDelPedido[MAX_ANIMALES_POR_PEDIDO];
        int numAnimalesEnPedido;

    public:
        Pedido();
        Pedido(int id, Cliente* cliente, Empleado* empleado);

        void agregarAnimal(Animal* animal);
        void mostrarDetalle();

        int getID() const;
        Cliente* getCliente() const;
    };

} // namespace app::domain

#endif // PEDIDO_H

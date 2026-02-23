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
        void quitarAnimal(int indice);
        void vaciarAnimales();
        void mostrarDetalle();

        void setCliente(Cliente* cliente);
        void setEmpleado(Empleado* empleado);

        int getID() const;
        Cliente* getCliente() const;
        Empleado* getEmpleado() const;
        int getNumAnimales() const;
        Animal* getAnimal(int indice) const;
    };

} // namespace app::domain

#endif // PEDIDO_H

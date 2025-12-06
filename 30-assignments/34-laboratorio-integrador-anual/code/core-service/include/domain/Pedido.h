#ifndef PEDIDO_H
#define PEDIDO_H

#include "domain/Cliente.h"
#include "domain/Empleado.h"
#include "domain/Equipo.h"

// Forward declarations to avoid circular dependencies if needed, though not strictly necessary here.
namespace app::domain {
    class Cliente;
    class Empleado;
    class Equipo;
}

namespace app::domain {

    const int MAX_EQUIPOS_POR_PEDIDO = 10; // As per diagram, MAX_POR_PEDIDO

    class Pedido {
    private:
        int id; // Added an ID for easier management
        Cliente* clienteAsignado;
        Empleado* empleadoAsignado;
        Equipo* equiposDelPedido[MAX_EQUIPOS_POR_PEDIDO];
        int numEquiposEnPedido;

    public:
        Pedido();
        Pedido(int id, Cliente* cliente, Empleado* empleado);

        void agregarEquipo(Equipo* equipo);
        void mostrarDetalle();

        int getID() const;
        Cliente* getCliente() const;
    };

} // namespace app::domain

#endif // PEDIDO_H

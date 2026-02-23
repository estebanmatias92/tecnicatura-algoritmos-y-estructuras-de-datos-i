#include "domain/Pedido.h"

namespace app::domain {

    /**
     * @brief Default constructor
     * @details Initializes empty pedido with NULL pointers and empty array.
     *          Initializer list syntax: member(value), member(value)
     * @note Pointer members initialized to NULL, not delete (no heap allocation)
     */
    Pedido::Pedido() 
        : id(0), clienteAsignado(NULL), empleadoAsignado(NULL), numAnimalesEnPedido(0) {
        for (int i = 0; i < MAX_ANIMALES_POR_PEDIDO; ++i) {
            animalesDelPedido[i] = NULL;
        }
    }

    /**
     * @brief Parameterized constructor
     * @param[in] id Unique order ID
     * @param[in] cliente Pointer to Cliente (association)
     * @param[in] empleado Pointer to Empleado (association)
     */
    Pedido::Pedido(int id, Cliente* cliente, Empleado* empleado)
        : id(id), clienteAsignado(cliente), empleadoAsignado(empleado), numAnimalesEnPedido(0) {
        for (int i = 0; i < MAX_ANIMALES_POR_PEDIDO; ++i) {
            animalesDelPedido[i] = NULL;
        }
    }

    /**
     * @brief Adds an animal to the order
     * @param[in] animal Pointer to Animal (aggregation)
     */
    void Pedido::agregarAnimal(Animal* animal) {
        if (numAnimalesEnPedido < MAX_ANIMALES_POR_PEDIDO) {
            animalesDelPedido[numAnimalesEnPedido++] = animal;
        } else {
            std::cout << "No se pueden agregar mas carnes a este pedido." << std::endl;
        }
    }

    /**
     * @brief Removes an animal by index
     * @param[in] indice Index of animal to remove (0-based)
     */
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

    /**
     * @brief Removes all animals from order
     */
    void Pedido::vaciarAnimales() {
        for (int i = 0; i < numAnimalesEnPedido; ++i) {
            animalesDelPedido[i] = NULL;
        }
        numAnimalesEnPedido = 0;
    }

    /**
     * @brief Sets the client (association)
     * @param[in] cliente Pointer to Cliente
     */
    void Pedido::setCliente(Cliente* cliente) {
        clienteAsignado = cliente;
    }

    /**
     * @brief Sets the employee (association)
     * @param[in] empleado Pointer to Empleado
     */
    void Pedido::setEmpleado(Empleado* empleado) {
        empleadoAsignado = empleado;
    }

    /**
     * @brief Gets the employee
     * @return Pointer to Empleado
     */
    Empleado* Pedido::getEmpleado() const {
        return empleadoAsignado;
    }

    /**
     * @brief Gets number of animals in order
     * @return Count of animals
     */
    int Pedido::getNumAnimales() const {
        return numAnimalesEnPedido;
    }

    /**
     * @brief Gets animal by index
     * @param[in] indice Index (0-based)
     * @return Pointer to Animal or NULL if invalid
     */
    Animal* Pedido::getAnimal(int indice) const {
        if (indice >= 0 && indice < numAnimalesEnPedido) {
            return animalesDelPedido[indice];
        }
        return NULL;
    }

    /**
     * @brief Displays complete order details
     */
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

    /**
     * @brief Gets order ID
     * @return Order ID
     */
    int Pedido::getID() const {
        return id;
    }

    /**
     * @brief Gets the client
     * @return Pointer to Cliente
     */
    Cliente* Pedido::getCliente() const {
        return clienteAsignado;
    }

} // namespace app::domain

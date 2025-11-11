#include "Cliente.h"
#include <iostream>

namespace app {
namespace domain {

Cliente::Cliente(int id, std::string nombre) : idCliente(id), nombre(std::move(nombre)) {}

void Cliente::mostrar() const {
    std::cout << "ID Cliente: " << idCliente << ", Nombre: " << nombre << std::endl;
}

int Cliente::getIdCliente() const {
    return idCliente;
}

std::string Cliente::getNombre() const {
    return nombre;
}

} // namespace domain
} // namespace app

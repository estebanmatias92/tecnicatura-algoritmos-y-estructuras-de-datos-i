#include "Articulo.h"
#include <iostream>

namespace app {
namespace domain {

Articulo::Articulo(int id, std::string nombre) : idArticulo(id), nombre(std::move(nombre)) {}

void Articulo::mostrar() const {
    std::cout << "ID Articulo: " << idArticulo << ", Nombre: " << nombre << std::endl;
}

int Articulo::getIdArticulo() const {
    return idArticulo;
}

std::string Articulo::getNombre() const {
    return nombre;
}

} // namespace domain
} // namespace app

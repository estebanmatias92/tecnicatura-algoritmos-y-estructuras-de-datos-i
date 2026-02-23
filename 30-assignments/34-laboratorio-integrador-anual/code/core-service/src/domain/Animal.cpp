#include "domain/Animal.h"

namespace app::domain {

    Animal::Animal(const std::string& id, const std::string& nombre, float precio, const std::string& corte)
        : ID(id), nombre(nombre), precio(precio), corte(corte) {
    }

    Animal::~Animal() {
    }

    std::string Animal::getID() const {
        return ID;
    }

    std::string Animal::getNombre() const {
        return nombre;
    }

    float Animal::getPrecio() const {
        return precio;
    }

    std::string Animal::getCorte() const {
        return corte;
    }

} // namespace app::domain

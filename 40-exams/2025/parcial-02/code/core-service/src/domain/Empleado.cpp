#include "domain/Empleado.h"

namespace app::domain {

    Empleado::Empleado() : legajo(""), nombre(""), apellido("") {}

    Empleado::Empleado(const std::string& legajo, const std::string& nombre, const std::string& apellido)
        : legajo(legajo), nombre(nombre), apellido(apellido) {}

    void Empleado::mostrar() {
        std::cout << "  - Legajo: " << legajo << ", Nombre: " << nombre << " " << apellido << std::endl;
    }

    std::string Empleado::getLegajo() const {
        return legajo;
    }

    std::string Empleado::getNombreCompleto() const {
        return nombre + " " + apellido;
    }

} // namespace app::domain

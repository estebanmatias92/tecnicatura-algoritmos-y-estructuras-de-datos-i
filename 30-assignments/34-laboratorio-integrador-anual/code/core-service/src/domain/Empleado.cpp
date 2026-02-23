#include "domain/Empleado.h"

namespace app::domain {

    /**
     * @brief Default constructor
     * @details Initializes Empleado with empty values.
     *          Uses initializer list syntax: member(param)
     */
    Empleado::Empleado() : legajo(""), nombre(""), apellido("") {}

    /**
     * @brief Parameterized constructor
     * @param[in] legajo Employee ID
     * @param[in] nombre First name
     * @param[in] apellido Last name
     */
    Empleado::Empleado(const std::string& legajo, const std::string& nombre, const std::string& apellido)
        : legajo(legajo), nombre(nombre), apellido(apellido) {}

    /**
     * @brief Displays employee information to console
     */
    void Empleado::mostrar() {
        std::cout << "  - Legajo: " << legajo << ", Nombre: " << nombre << " " << apellido << std::endl;
    }

    /**
     * @brief Gets the employee ID
     * @return Employee legajo as string
     */
    std::string Empleado::getLegajo() const {
        return legajo;
    }

    /**
     * @brief Gets full name
     * @return Nombre + apellido combined
     */
    std::string Empleado::getNombreCompleto() const {
        return nombre + " " + apellido;
    }

} // namespace app::domain

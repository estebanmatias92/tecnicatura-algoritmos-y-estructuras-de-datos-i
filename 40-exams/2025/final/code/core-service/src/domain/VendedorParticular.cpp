#include "domain/VendedorParticular.h"
#include <iostream>

namespace app::domain {

    VendedorParticular::VendedorParticular() : Empleado() {}

    VendedorParticular::VendedorParticular(const std::string& name, float salary, const std::string& area, const std::string& contact_info)
        : Empleado(name, salary, area, contact_info) {}

    void VendedorParticular::trabajar() {
        std::cout << "El vendedor particular " << name << " esta realizando tareas especificas de vendedor particular." << std::endl;
    }

    void VendedorParticular::displayInfo() {
        std::cout << "Vendedor Particular - Nombre: " << name 
                  << ", Salario: $" << salary 
                  << ", Area: " << area 
                  << ", Contacto: " << contact_info << std::endl;
    }

} // namespace app::domain
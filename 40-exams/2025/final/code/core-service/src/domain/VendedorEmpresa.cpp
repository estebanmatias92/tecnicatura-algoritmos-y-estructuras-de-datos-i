#include "domain/VendedorEmpresa.h"
#include <iostream>

namespace app::domain {

    VendedorEmpresa::VendedorEmpresa() : Empleado() {}

    VendedorEmpresa::VendedorEmpresa(const std::string& name, float salary, const std::string& area, const std::string& contact_info)
        : Empleado(name, salary, area, contact_info) {}

    void VendedorEmpresa::trabajar() {
        std::cout << "El vendedor empresa " << name << " esta realizando tareas especificas de vendedor empresa." << std::endl;
    }

    void VendedorEmpresa::displayInfo() {
        std::cout << "Vendedor Empresa - Nombre: " << name 
                  << ", Salario: $" << salary 
                  << ", Area: " << area 
                  << ", Contacto: " << contact_info << std::endl;
    }

} // namespace app::domain
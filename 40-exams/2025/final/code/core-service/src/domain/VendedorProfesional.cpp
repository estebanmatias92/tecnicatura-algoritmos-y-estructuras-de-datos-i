#include "domain/VendedorProfesional.h"
#include <iostream>

namespace app::domain {

    VendedorProfesional::VendedorProfesional() : Empleado() {}

    VendedorProfesional::VendedorProfesional(const std::string& name, float salary, const std::string& area, const std::string& contact_info)
        : Empleado(name, salary, area, contact_info) {}

    void VendedorProfesional::trabajar() {
        std::cout << "El vendedor profesional " << name << " esta realizando tareas especificas de vendedor profesional." << std::endl;
    }

    void VendedorProfesional::displayInfo() {
        std::cout << "Vendedor Profesional - Nombre: " << name 
                  << ", Salario: $" << salary 
                  << ", Area: " << area 
                  << ", Contacto: " << contact_info << std::endl;
    }

} // namespace app::domain
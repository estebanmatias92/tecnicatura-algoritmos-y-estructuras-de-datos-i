#include "vendedor_profesional.h"
#include <iostream>

VendedorProfesional::VendedorProfesional(const std::string& n, float s, const std::string& a, const std::string& c) 
    : Empleado(n, s, a, c) {
}

VendedorProfesional::~VendedorProfesional() {
}

void VendedorProfesional::trabajar() {
    std::cout << "Vendedor Profesional " << name << " is doing professional vendor tasks." << std::endl;
}

void VendedorProfesional::displayInfo() {
    std::cout << "Profesional: " << name << ", Salary: " << salary << ", Area: " << area 
              << ", Contact: " << contact_info << std::endl;
}
#include "vendedor_empresa.h"
#include <iostream>

VendedorEmpresa::VendedorEmpresa(const std::string& n, float s, const std::string& a, const std::string& c) 
    : Empleado(n, s, a, c) {
}

VendedorEmpresa::~VendedorEmpresa() {
}

void VendedorEmpresa::trabajar() {
    std::cout << "Vendedor Empresa " << name << " is doing enterprise vendor tasks." << std::endl;
}

void VendedorEmpresa::displayInfo() {
    std::cout << "Empresa: " << name << ", Salary: " << salary << ", Area: " << area 
              << ", Contact: " << contact_info << std::endl;
}
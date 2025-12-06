#include "vendedor_particular.h"
#include <iostream>

VendedorParticular::VendedorParticular(const std::string& n, float s, const std::string& a, const std::string& c) 
    : Empleado(n, s, a, c) {
}

VendedorParticular::~VendedorParticular() {
}

void VendedorParticular::trabajar() {
    std::cout << "Vendedor Particular " << name << " is doing particular vendor tasks." << std::endl;
}

void VendedorParticular::displayInfo() {
    std::cout << "Particular: " << name << ", Salary: " << salary << ", Area: " << area 
              << ", Contact: " << contact_info << std::endl;
}
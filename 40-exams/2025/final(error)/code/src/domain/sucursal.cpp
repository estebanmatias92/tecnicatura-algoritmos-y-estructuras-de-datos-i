#include "sucursal.h"
#include <iostream>

// Constructor implementation
Sucursal::Sucursal(int id, const std::string& name, int max_vend) 
    : id(id), name(name), max_vendedores(max_vend), vendedor_count(0) {
    vendedores = new Empleado*[max_vendedores];
}

// Destructor implementation - important to avoid memory leaks
Sucursal::~Sucursal() {
    // Note: We don't delete the Empleado objects here since they might be managed elsewhere
    delete[] vendedores;
}

// Add a vendor to the branch
void Sucursal::addVendedor(Empleado* vendedor) {
    if (vendedor_count < max_vendedores) {
        vendedores[vendedor_count] = vendedor;
        vendedor_count++;
    } else {
        std::cout << "Cannot add more vendors. Branch " << name << " is full." << std::endl;
    }
}

// Remove a vendor from the branch
void Sucursal::removeVendedor(Empleado* vendedor) {
    for (int i = 0; i < vendedor_count; i++) {
        if (vendedores[i] == vendedor) {
            // Shift elements to fill the gap
            for (int j = i; j < vendedor_count - 1; j++) {
                vendedores[j] = vendedores[j + 1];
            }
            vendedores[vendedor_count - 1] = nullptr;
            vendedor_count--;
            break;
        }
    }
}

// List all vendors in the branch
void Sucursal::listarVendedores() {
    std::cout << "Vendedores in branch " << name << " (ID: " << id << "):" << std::endl;
    for (int i = 0; i < vendedor_count; i++) {
        std::cout << "  - ";
        vendedores[i]->displayInfo();
    }
}

// Get vendor at specific index
Empleado* Sucursal::getVendedor(int index) {
    if (index >= 0 && index < vendedor_count) {
        return vendedores[index];
    }
    return nullptr;
}

// Getters
int Sucursal::getId() const {
    return id;
}

std::string Sucursal::getName() const {
    return name;
}

int Sucursal::getVendedorCount() const {
    return vendedor_count;
}

// Setters
void Sucursal::setName(const std::string& newName) {
    name = newName;
}
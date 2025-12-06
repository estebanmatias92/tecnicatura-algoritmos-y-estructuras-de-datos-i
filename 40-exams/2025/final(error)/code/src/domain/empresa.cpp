#include "empresa.h"
#include <iostream>

// Constructor implementation
Empresa::Empresa(int id, const std::string& name, int max_suc) 
    : id(id), name(name), max_sucursales(max_suc), sucursal_count(0) {
    sucursales = new Sucursal*[max_sucursales];
}

// Destructor implementation
Empresa::~Empresa() {
    // Delete the Sucursal array (but not the Sucursal objects themselves as they might be managed elsewhere)
    delete[] sucursales;
}

// Add a branch to the company
void Empresa::addSucursal(Sucursal* sucursal) {
    if (sucursal_count < max_sucursales) {
        sucursales[sucursal_count] = sucursal;
        sucursal_count++;
    } else {
        std::cout << "Cannot add more branches. Company " << name << " is full." << std::endl;
    }
}

// Remove a branch from the company
void Empresa::removeSucursal(Sucursal* sucursal) {
    for (int i = 0; i < sucursal_count; i++) {
        if (sucursales[i] == sucursal) {
            // Shift elements to fill the gap
            for (int j = i; j < sucursal_count - 1; j++) {
                sucursales[j] = sucursales[j + 1];
            }
            sucursales[sucursal_count - 1] = nullptr;
            sucursal_count--;
            break;
        }
    }
}

// List all branches in the company
void Empresa::listarSucursales() {
    std::cout << "Sucursales in company " << name << " (ID: " << id << "):" << std::endl;
    for (int i = 0; i < sucursal_count; i++) {
        std::cout << "  - " << sucursales[i]->getName() << " (ID: " << sucursales[i]->getId() << ")" << std::endl;
    }
}

// Get branch at specific index
Sucursal* Empresa::getSucursal(int index) {
    if (index >= 0 && index < sucursal_count) {
        return sucursales[index];
    }
    return nullptr;
}

// List all vendors across all branches
void Empresa::listarTodosVendedores() {
    std::cout << "All vendedores in company " << name << ":" << std::endl;
    for (int i = 0; i < sucursal_count; i++) {
        std::cout << "From branch " << sucursales[i]->getName() << ":" << std::endl;
        sucursales[i]->listarVendedores();
    }
}

// Getters
int Empresa::getId() const {
    return id;
}

std::string Empresa::getName() const {
    return name;
}

int Empresa::getSucursalCount() const {
    return sucursal_count;
}
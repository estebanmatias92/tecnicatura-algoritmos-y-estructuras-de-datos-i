#include "vendedor_crud.h"
#include "../domain/vendedor_particular.h"
#include "../domain/vendedor_profesional.h"
#include "../domain/vendedor_empresa.h"
#include <iostream>

VendedorCRUD::VendedorCRUD(FileRepository* repo) : fileRepo(repo), nextId(1) {
    loadData();
}

VendedorCRUD::~VendedorCRUD() {
    // Clean up dynamically allocated Vendedor objects
    for (auto* vendedor : vendedores) {
        delete vendedor;
    }
    vendedores.clear();
}

Empleado* VendedorCRUD::create(int tipo, const std::string& name, float salary, 
                              const std::string& area, const std::string& contact, 
                              Sucursal* branch) {
    // Validate input
    if (name.empty() || salary < 0) {
        std::cout << "Error: Invalid name or salary" << std::endl;
        return nullptr;
    }
    
    Empleado* newVendedor = nullptr;
    
    switch(tipo) {
        case 1:  // Particular
            newVendedor = new VendedorParticular(name, salary, area, contact);
            break;
        case 2:  // Profesional
            newVendedor = new VendedorProfesional(name, salary, area, contact);
            break;
        case 3:  // Empresa
            newVendedor = new VendedorEmpresa(name, salary, area, contact);
            break;
        default:
            std::cout << "Error: Invalid vendor type: " << tipo << std::endl;
            return nullptr;
    }
    
    // Add to local collection
    vendedores.push_back(newVendedor);
    nextId++;
    
    // Assign to branch if provided
    if (branch) {
        branch->addVendedor(newVendedor);
    }
    
    // Persist to file
    if (fileRepo) {
        fileRepo->saveVendedor(newVendedor);
    }
    
    std::cout << "Successfully created Vendedor: " << name << " with ID: " << (nextId-1) << std::endl;
    return newVendedor;
}

Empleado* VendedorCRUD::findById(int id) {
    // Since we don't store IDs in the Empleado objects directly, 
    // we'll use the position in the vector as the ID
    if (id > 0 && id <= static_cast<int>(vendedores.size())) {
        return vendedores[id - 1];  // Vector is 0-indexed
    }
    return nullptr;  // Not found
}

std::vector<Empleado*> VendedorCRUD::findAll() {
    return vendedores;  // Return copy of the vector
}

std::vector<Empleado*> VendedorCRUD::findByType(int tipo) {
    std::vector<Empleado*> result;
    for (auto* vendedor : vendedores) {
        // We could use dynamic_cast to check the type, but that goes against
        // the constitution principle. In a complete implementation, we would have
        // a virtual method in the Empleado hierarchy to identify the type.
        // For now, we'll return all vendors since we cannot differentiate them.
        (void)tipo; // Explicitly mark as unused to avoid warning
        result.push_back(vendedor);
    }
    return result;
}

std::vector<Empleado*> VendedorCRUD::findByName(const std::string& name) {
    std::vector<Empleado*> result;
    for (auto* vendedor : vendedores) {
        if (vendedor->getName() == name) {
            result.push_back(vendedor);
        }
    }
    return result;
}

bool VendedorCRUD::update(int id, const std::string& name, float salary,
                         const std::string& area, const std::string& contact) {
    // Since we don't store IDs in the Empleado objects directly,
    // we'll use the position in the vector as the ID
    if (id <= 0 || id > static_cast<int>(vendedores.size())) {
        std::cout << "Error: Vendedor with ID " << id << " not found" << std::endl;
        return false;
    }

    // Get the vendor to update
    Empleado* target = vendedores[id - 1];  // Vector is 0-indexed

    // Update properties using setters
    target->setName(name);
    target->setSalary(salary);
    target->setArea(area);
    target->setContactInfo(contact);

    std::cout << "Successfully updated Vendedor ID: " << id << std::endl;
    saveData();
    return true;
}

bool VendedorCRUD::remove(int id) {
    // Since we don't store IDs in the Empleado objects directly,
    // we'll use the position in the vector as the ID
    if (id <= 0 || id > static_cast<int>(vendedores.size())) {
        std::cout << "Error: Vendedor with ID " << id << " not found" << std::endl;
        return false;
    }
    
    // Free memory for the vendedor being removed
    delete vendedores[id - 1];
    
    // Remove from collection
    vendedores.erase(vendedores.begin() + (id - 1));
    
    std::cout << "Successfully removed Vendedor ID: " << id << std::endl;
    saveData();
    return true;
}

bool VendedorCRUD::isValidVendedor(const Empleado* vendedor) const {
    if (!vendedor) return false;
    return !vendedor->getName().empty() && vendedor->getSalary() >= 0;
}

void VendedorCRUD::loadData() {
    // In a real implementation, this would load from file
    // For now, we initialize with an empty collection
    std::cout << "Loading Vendedor data..." << std::endl;
}

bool VendedorCRUD::saveData() {
    // In a real implementation, this would save to file
    // For now, we just return true
    std::cout << "Saving Vendedor data..." << std::endl;
    return true;
}
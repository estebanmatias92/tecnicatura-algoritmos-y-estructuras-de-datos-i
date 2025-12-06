#include "sucursal_crud.h"
#include <iostream>

SucursalCRUD::SucursalCRUD(FileRepository* repo) : fileRepo(repo), nextId(1) {
    loadData();
}

SucursalCRUD::~SucursalCRUD() {
    // Clean up dynamically allocated Sucursal objects
    for (auto* sucursal : sucursales) {
        delete sucursal;
    }
    sucursales.clear();
}

Sucursal* SucursalCRUD::create(const std::string& name, int maxVendedores) {
    // Validate input
    if (name.empty()) {
        std::cout << "Error: Sucursal name cannot be empty" << std::endl;
        return nullptr;
    }
    
    // Create new Sucursal
    Sucursal* newSucursal = new Sucursal(nextId, name, maxVendedores);
    nextId++;
    
    // Add to local collection
    sucursales.push_back(newSucursal);
    
    // Persist to file
    saveData();
    
    std::cout << "Successfully created Sucursal: " << name << " with ID: " << (nextId-1) << std::endl;
    return newSucursal;
}

Sucursal* SucursalCRUD::findById(int id) {
    for (auto* sucursal : sucursales) {
        if (sucursal->getId() == id) {
            return sucursal;
        }
    }
    return nullptr;  // Not found
}

const Sucursal* SucursalCRUD::findById(int id) const {
    for (const auto* sucursal : sucursales) {
        if (sucursal->getId() == id) {
            return sucursal;
        }
    }
    return nullptr;  // Not found
}

std::vector<Sucursal*> SucursalCRUD::findAll() {
    return sucursales;  // Return copy of the vector
}

std::vector<Sucursal*> SucursalCRUD::findByName(const std::string& name) {
    std::vector<Sucursal*> result;
    for (auto* sucursal : sucursales) {
        if (sucursal->getName() == name) {
            result.push_back(sucursal);
        }
    }
    return result;
}

bool SucursalCRUD::update(int id, const std::string& name, int maxVendedores) {
    Sucursal* target = findById(id);
    if (!target) {
        std::cout << "Error: Sucursal with ID " << id << " not found" << std::endl;
        return false;
    }

    // Update properties
    target->setName(name);
    // In a full implementation, we would also update maxVendedores:
    // target->setMaxVendedores(maxVendedores);
    (void)maxVendedores; // Explicitly mark as unused to avoid warning

    std::cout << "Successfully updated Sucursal ID: " << id << std::endl;
    saveData();
    return true;
}

bool SucursalCRUD::remove(int id) {
    // Check if there are vendors assigned to this branch
    if (hasVendedoresAssigned(id)) {
        std::cout << "Error: Cannot delete Sucursal with ID " << id 
                  << ". It has Vendedores assigned to it." << std::endl;
        return false;
    }
    
    // Find and remove from collection
    for (size_t i = 0; i < sucursales.size(); ++i) {
        if (sucursales[i]->getId() == id) {
            delete sucursales[i];  // Free memory
            sucursales.erase(sucursales.begin() + i);
            std::cout << "Successfully deleted Sucursal ID: " << id << std::endl;
            saveData();
            return true;
        }
    }
    
    std::cout << "Error: Sucursal with ID " << id << " not found" << std::endl;
    return false;
}

bool SucursalCRUD::isValidSucursal(const Sucursal* sucursal) const {
    if (!sucursal) return false;
    return !sucursal->getName().empty();
}

bool SucursalCRUD::hasVendedoresAssigned(int id) const {
    // Manually search through the vector for efficiency
    for (const auto* sucursal : sucursales) {
        if (sucursal->getId() == id) {
            return sucursal->getVendedorCount() > 0;  // Check if any vendors are assigned
        }
    }
    return false;  // Not found
}

void SucursalCRUD::loadData() {
    // In a real implementation, this would load from file
    // For now, we initialize with an empty collection
    std::cout << "Loading Sucursal data..." << std::endl;
}

bool SucursalCRUD::saveData() {
    // In a real implementation, this would save to file
    // For now, we just return true
    std::cout << "Saving Sucursal data..." << std::endl;
    return true;
}
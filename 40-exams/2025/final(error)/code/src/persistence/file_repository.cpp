#include "file_repository.h"
#include <fstream>
#include <iostream>

FileRepository::FileRepository(const std::string& fname) : filename(fname) {
}

bool FileRepository::save() {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    
    file << "Empresa Data Saved" << std::endl;
    file.close();
    return true;
}

bool FileRepository::load() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    
    // Read data from file
    std::string line;
    while (std::getline(file, line)) {
        // Process line
    }
    
    file.close();
    return true;
}

bool FileRepository::saveVendedor(Empleado* vendedor) {
    std::ofstream file(filename, std::ios::app);  // Append mode
    if (!file.is_open()) {
        return false;
    }
    
    file << "Empleado:" << vendedor->getName() << "," 
         << vendedor->getSalary() << "," 
         << vendedor->getArea() << "," 
         << vendedor->getContactInfo() << std::endl;
    
    file.close();
    return true;
}

Empleado* FileRepository::loadVendedores() {
    // This is a simplified implementation - in a real scenario, 
    // this would parse the file and reconstruct Empleado objects
    std::ifstream file(filename);
    if (!file.is_open()) {
        return nullptr;
    }
    
    std::string line;
    while (std::getline(file, line)) {
        // Parse each line to reconstruct Empleado objects
        // This would require more complex parsing logic
    }
    
    file.close();
    return nullptr;  // Placeholder - would return actual data in a complete implementation
}
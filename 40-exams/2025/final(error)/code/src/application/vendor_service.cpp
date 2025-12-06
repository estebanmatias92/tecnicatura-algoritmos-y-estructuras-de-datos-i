#include "vendor_service.h"
#include <iostream>

Empleado* VendorService::createVendedor(int tipo, const std::string& name, float salary, 
                                       const std::string& area, const std::string& contact) {
    switch(tipo) {
        case 1:  // Particular
            return new VendedorParticular(name, salary, area, contact);
        case 2:  // Profesional
            return new VendedorProfesional(name, salary, area, contact);
        case 3:  // Empresa
            return new VendedorEmpresa(name, salary, area, contact);
        default:
            std::cout << "Invalid vendor type: " << tipo << std::endl;
            return nullptr;
    }
}

bool VendorService::assignToBranch(Empleado* vendor, Sucursal* branch) {
    if (vendor && branch) {
        branch->addVendedor(vendor);
        return true;
    }
    return false;
}

void VendorService::listVendedores(Sucursal* branch) {
    if (branch) {
        branch->listarVendedores();
    } else {
        std::cout << "Branch is null." << std::endl;
    }
}
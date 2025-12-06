#include "domain/empleado.h"
#include "domain/sucursal.h"
#include "domain/empresa.h"
#include "domain/vendedor_particular.h"
#include "domain/vendedor_profesional.h"
#include "domain/vendedor_empresa.h"
#include "application/vendor_service.h"
#include "application/menu_controller.h"  // NEW: Include menu controller
#include "utils/input_handler.h"
#include "utils/validator.h"              // NEW: Include validator
#include "persistence/file_repository.h"
#include <iostream>
#include <string>

int main() {
    std::cout << "=== Vendor Management Application with CRUD Menu System ===" << std::endl;

    // Initialize with 1 empresa, 1 sucursal, and 3 employees with fake data (FR-014)
    Empresa* empresa = new Empresa(1, "Empresa Test S.A.", 5);
    Sucursal* sucursal = new Sucursal(1, "Sucursal Central");

    // Create 3 employees with fake data (one of each category)
    Empleado* particular = new VendedorParticular("Carlos Garcia", 2500.0, "Ventas", "carlos@example.com");
    Empleado* profesional = new VendedorProfesional("Maria Lopez", 4500.0, "Marketing", "maria@example.com");
    Empleado* empresa_emp = new VendedorEmpresa("Jose Martinez", 6000.0, "Gerencia", "jose@example.com");

    // Assign vendors to the branch
    sucursal->addVendedor(particular);
    sucursal->addVendedor(profesional);
    sucursal->addVendedor(empresa_emp);

    // Add branch to company
    empresa->addSucursal(sucursal);

    // Free the pre-initialized objects as the menu system will handle CRUD operations
    delete particular;
    delete profesional;
    delete empresa_emp;
    delete sucursal;
    delete empresa;

    // Initialize and run the menu system
    MenuController menu;
    menu.run();

    std::cout << "Application completed successfully." << std::endl;
    return 0;
}
#ifndef VENDOR_SERVICE_H
#define VENDOR_SERVICE_H

#include "../domain/empleado.h"
#include "../domain/sucursal.h"
#include "../domain/vendedor_particular.h"
#include "../domain/vendedor_profesional.h"
#include "../domain/vendedor_empresa.h"
#include <string>

class VendorService {
public:
    // Create a vendor of specific type
    static Empleado* createVendedor(int tipo, const std::string& name, float salary, 
                                   const std::string& area, const std::string& contact);
    
    // Assign vendor to branch
    static bool assignToBranch(Empleado* vendor, Sucursal* branch);
    
    // List vendors by branch
    static void listVendedores(Sucursal* branch);
};

#endif // VENDOR_SERVICE_H
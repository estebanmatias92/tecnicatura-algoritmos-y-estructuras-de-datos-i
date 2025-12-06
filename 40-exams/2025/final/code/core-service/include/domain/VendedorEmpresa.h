#ifndef VENDEDOREMPRESA_H
#define VENDEDOREMPRESA_H

#include "domain/Empleado.h"
#include <string>

namespace app::domain {

    class VendedorEmpresa : public Empleado {
    public:
        VendedorEmpresa();
        VendedorEmpresa(const std::string& name, float salary, const std::string& area, const std::string& contact_info);

        // Override virtual functions
        void trabajar() override;
        void displayInfo() override;
    };

} // namespace app::domain

#endif // VENDEDOREMPRESA_H
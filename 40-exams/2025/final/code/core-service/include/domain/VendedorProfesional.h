#ifndef VENDEDORPROFESIONAL_H
#define VENDEDORPROFESIONAL_H

#include "domain/Empleado.h"
#include <string>

namespace app::domain {

    class VendedorProfesional : public Empleado {
    public:
        VendedorProfesional();
        VendedorProfesional(const std::string& name, float salary, const std::string& area, const std::string& contact_info);

        // Override virtual functions
        void trabajar() override;
        void displayInfo() override;
    };

} // namespace app::domain

#endif // VENDEDORPROFESIONAL_H
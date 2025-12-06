#ifndef VENDEDORPARTICULAR_H
#define VENDEDORPARTICULAR_H

#include "domain/Empleado.h"
#include <string>

namespace app::domain {

    class VendedorParticular : public Empleado {
    public:
        VendedorParticular();
        VendedorParticular(const std::string& name, float salary, const std::string& area, const std::string& contact_info);

        // Override virtual functions
        void trabajar() override;
        void displayInfo() override;
    };

} // namespace app::domain

#endif // VENDEDORPARTICULAR_H
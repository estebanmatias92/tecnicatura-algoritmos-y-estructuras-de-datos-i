#ifndef SUCURSAL_H
#define SUCURSAL_H

#include "domain/Empleado.h"
#include <string>

namespace app::domain {

    const int MAX_VENDEDORES = 20;

    class Sucursal {
    private:
        int id;
        std::string name;
        Empleado* vendedores[MAX_VENDEDORES];
        int vendedor_count;
        int max_vendedores;

    public:
        Sucursal();
        Sucursal(int id, const std::string& name);

        void addVendedor(Empleado* vendedor);
        void removeVendedor(Empleado* vendedor);
        Empleado** listarVendedores();
        Empleado* getVendedor(int index);
        int getVendedorCount() const;
        std::string getName() const;

        void displayInfo();

        ~Sucursal(); // Destructor to manage memory
    };

} // namespace app::domain

#endif // SUCURSAL_H
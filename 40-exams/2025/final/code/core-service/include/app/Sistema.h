#ifndef SISTEMA_H
#define SISTEMA_H

#include "domain/Empleado.h"
#include "domain/VendedorParticular.h"
#include "domain/VendedorProfesional.h"
#include "domain/VendedorEmpresa.h"
#include "domain/Sucursal.h"
#include <string>

namespace app {

    const int MAX_SUCURSALES = 10;

    class Sistema {
    private:
        domain::Sucursal* sucursales[MAX_SUCURSALES];
        int sucursal_count;
        int next_sucursal_id;

        // Métodos de menú
        void menuPrincipal();

        // Funcionalidades solicitadas
        void crearVendedores();
        void listarVendedoresEnSucursal();
        void listarTodosVendedores();
        void eliminarVendedor();
        void modificarVendedor();

    public:
        Sistema();
        ~Sistema();
        void run();
    };

} // namespace app

#endif // SISTEMA_H
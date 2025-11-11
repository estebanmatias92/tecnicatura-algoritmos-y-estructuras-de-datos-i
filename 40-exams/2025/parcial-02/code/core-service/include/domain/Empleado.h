#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
#include <iostream>

namespace app::domain {

    class Empleado {
    private:
        std::string legajo;
        std::string nombre;
        std::string apellido;

    public:
        Empleado();
        Empleado(const std::string& legajo, const std::string& nombre, const std::string& apellido);
        
        void mostrar();

        std::string getLegajo() const;
        std::string getNombreCompleto() const;
    };

} // namespace app::domain

#endif // EMPLEADO_H

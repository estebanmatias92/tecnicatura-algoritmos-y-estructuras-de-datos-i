#pragma once

#include <string>

namespace app {
namespace domain {

class Cliente {
private:
    int idCliente;
    std::string nombre;

public:
    Cliente(int id, std::string nombre);
    void mostrar() const;
    int getIdCliente() const;
    std::string getNombre() const;
};

} // namespace domain
} // namespace app

#pragma once

#include <string>

namespace app {
namespace domain {

class Articulo {
private:
    int idArticulo;
    std::string nombre;

public:
    Articulo(int id, std::string nombre);
    void mostrar() const;
    int getIdArticulo() const;
    std::string getNombre() const;
};

} // namespace domain
} // namespace app

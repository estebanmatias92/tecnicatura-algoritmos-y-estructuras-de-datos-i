#include "triangulo.h"
#include <iostream>

namespace Geometria {

void Triangulo::dibujar() const {
    std::cout << "Dibujando un Triangulo." << std::endl;
}

void Triangulo::borrar() const {
    std::cout << "Borrando un Triangulo." << std::endl;
}

} // namespace Geometria

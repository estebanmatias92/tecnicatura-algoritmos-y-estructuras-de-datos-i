#include "circulo.h"
#include <iostream>

namespace Geometria {

void Circulo::dibujar() const {
    std::cout << "Dibujando un Circulo." << std::endl;
}

void Circulo::borrar() const {
    std::cout << "Borrando un Circulo." << std::endl;
}

} // namespace Geometria

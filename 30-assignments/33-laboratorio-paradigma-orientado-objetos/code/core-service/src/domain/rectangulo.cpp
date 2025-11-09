#include "rectangulo.h"
#include <iostream>

namespace Geometria {

void Rectangulo::dibujar() const {
    std::cout << "Dibujando un Rectangulo." << std::endl;
}

void Rectangulo::borrar() const {
    std::cout << "Borrando un Rectangulo." << std::endl;
}

} // namespace Geometria

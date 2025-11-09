#ifndef FIGURA_H
#define FIGURA_H

#include <iostream> // For std::cout
#include <string>   // For std::string

namespace Geometria {

class Figura {
public:
    // Virtual pure methods (RF-02)
    virtual void dibujar() const = 0;
    virtual void borrar() const = 0;

    // Virtual methods with default implementation (RF-02)
    virtual void rotar() const {
        std::cout << "Rotando una figura generica." << std::endl;
    }
    virtual void mover() const {
        std::cout << "Moviendo una figura generica." << std::endl;
    }

    // Virtual destructor to ensure proper cleanup of derived objects
    virtual ~Figura() = default;
};

} // namespace Geometria

#endif // FIGURA_H

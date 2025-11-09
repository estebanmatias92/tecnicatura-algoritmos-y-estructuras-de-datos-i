#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "figura.h" // Include the base class

namespace Geometria {

class Triangulo : public Figura {
public:
    // Override pure virtual methods
    void dibujar() const override;
    void borrar() const override;

    // Constructor
    Triangulo() = default;
    ~Triangulo() override = default;
};

} // namespace Geometria

#endif // TRIANGULO_H

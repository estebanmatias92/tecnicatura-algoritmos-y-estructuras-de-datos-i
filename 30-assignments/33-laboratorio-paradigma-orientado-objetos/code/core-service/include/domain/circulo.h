#ifndef CIRCULO_H
#define CIRCULO_H

#include "figura.h" // Include the base class

namespace Geometria {

class Circulo : public Figura {
public:
    // Override pure virtual methods
    void dibujar() const override;
    void borrar() const override;

    // Constructor
    Circulo() = default;
    ~Circulo() override = default;
};

} // namespace Geometria

#endif // CIRCULO_H

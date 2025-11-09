#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "figura.h" // Include the base class

namespace Geometria {

class Rectangulo : public Figura {
public:
    // Override pure virtual methods
    void dibujar() const override;
    void borrar() const override;

    // Constructor
    Rectangulo() = default;
    ~Rectangulo() override = default;
};

} // namespace Geometria

#endif // RECTANGULO_H

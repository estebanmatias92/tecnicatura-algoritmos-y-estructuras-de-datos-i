#ifndef VENDEDOR_PARTICULAR_H
#define VENDEDOR_PARTICULAR_H

#include "empleado.h"
#include <string>

class VendedorParticular : public Empleado {
public:
    VendedorParticular(const std::string& n, float s, const std::string& a, const std::string& c);
    virtual ~VendedorParticular();

    // Implement pure virtual methods
    void trabajar() override;
    void displayInfo() override;
};

#endif // VENDEDOR_PARTICULAR_H
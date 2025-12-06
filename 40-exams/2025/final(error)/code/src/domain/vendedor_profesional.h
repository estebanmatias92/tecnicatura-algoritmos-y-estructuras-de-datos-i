#ifndef VENDEDOR_PROFESIONAL_H
#define VENDEDOR_PROFESIONAL_H

#include "empleado.h"
#include <string>

class VendedorProfesional : public Empleado {
public:
    VendedorProfesional(const std::string& n, float s, const std::string& a, const std::string& c);
    virtual ~VendedorProfesional();

    // Implement pure virtual methods
    void trabajar() override;
    void displayInfo() override;
};

#endif // VENDEDOR_PROFESIONAL_H
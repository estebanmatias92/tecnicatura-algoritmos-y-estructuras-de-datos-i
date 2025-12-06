#ifndef VENDEDOR_EMPRESA_H
#define VENDEDOR_EMPRESA_H

#include "empleado.h"
#include <string>

class VendedorEmpresa : public Empleado {
public:
    VendedorEmpresa(const std::string& n, float s, const std::string& a, const std::string& c);
    virtual ~VendedorEmpresa();

    // Implement pure virtual methods
    void trabajar() override;
    void displayInfo() override;
};

#endif // VENDEDOR_EMPRESA_H
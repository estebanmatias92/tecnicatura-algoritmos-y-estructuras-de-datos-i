#ifndef SUCURSAL_H
#define SUCURSAL_H

#include "empleado.h"
#include <string>

class Sucursal {
private:
    int id;
    std::string name;
    int max_vendedores;
    int vendedor_count;
    Empleado** vendedores;        // Pointer to array of vendor pointers

public:
    // Constructor
    Sucursal(int id, const std::string& name, int max_vend = 10);
    
    // Destructor
    ~Sucursal();
    
    // Methods
    void addVendedor(Empleado* vendedor);
    void removeVendedor(Empleado* vendedor);
    void listarVendedores();
    Empleado* getVendedor(int index);
    
    // Getters
    int getId() const;
    std::string getName() const;
    int getVendedorCount() const;

    // Setters
    void setName(const std::string& newName);
};

#endif // SUCURSAL_H
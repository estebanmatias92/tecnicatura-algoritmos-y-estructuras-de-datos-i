#ifndef EMPRESA_H
#define EMPRESA_H

#include "sucursal.h"
#include <string>

class Empresa {
private:
    int id;
    std::string name;
    int max_sucursales;
    int sucursal_count;
    Sucursal** sucursales;        // Pointer to array of branch pointers

public:
    // Constructor
    Empresa(int id, const std::string& name, int max_suc = 5);
    
    // Destructor
    ~Empresa();
    
    // Methods
    void addSucursal(Sucursal* sucursal);
    void removeSucursal(Sucursal* sucursal);
    void listarSucursales();
    Sucursal* getSucursal(int index);
    void listarTodosVendedores();
    
    // Getters
    int getId() const;
    std::string getName() const;
    int getSucursalCount() const;
};

#endif // EMPRESA_H
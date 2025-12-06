#ifndef VENDEDOR_CRUD_H
#define VENDEDOR_CRUD_H

#include "../domain/empleado.h"
#include "../domain/sucursal.h"
#include "../persistence/file_repository.h"
#include <vector>

class VendedorCRUD {
private:
    FileRepository* fileRepo;
    std::vector<Empleado*> vendedores;
    int nextId;

public:
    VendedorCRUD(FileRepository* repo);
    ~VendedorCRUD();

    // Create operations
    Empleado* create(int tipo, const std::string& name, float salary, 
                    const std::string& area, const std::string& contact, 
                    Sucursal* branch = nullptr);
    
    // Read operations
    Empleado* findById(int id);
    std::vector<Empleado*> findAll();
    std::vector<Empleado*> findByType(int tipo);
    std::vector<Empleado*> findByName(const std::string& name);
    
    // Update operations
    bool update(int id, const std::string& name, float salary, 
               const std::string& area, const std::string& contact);
    
    // Delete operations
    bool remove(int id);
    
    // Validation methods
    bool isValidVendedor(const Empleado* vendedor) const;
    
    // Data management
    void loadData();
    bool saveData();
};

#endif // VENDEDOR_CRUD_H
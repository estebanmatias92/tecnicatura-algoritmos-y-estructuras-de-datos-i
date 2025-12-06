#ifndef SUCURSAL_CRUD_H
#define SUCURSAL_CRUD_H

#include "../domain/sucursal.h"
#include "../domain/empresa.h"
#include "../domain/empleado.h"
#include "../persistence/file_repository.h"
#include <vector>

class SucursalCRUD {
private:
    FileRepository* fileRepo;
    std::vector<Sucursal*> sucursales;
    int nextId;

public:
    SucursalCRUD(FileRepository* repo);
    ~SucursalCRUD();

    // Create operations
    Sucursal* create(const std::string& name, int maxVendedores = 10);
    
    // Read operations
    Sucursal* findById(int id);
    std::vector<Sucursal*> findAll();
    std::vector<Sucursal*> findByName(const std::string& name);
    
    // Update operations
    bool update(int id, const std::string& name, int maxVendedores);
    
    // Delete operations
    bool remove(int id);  // Will check for dependencies before deletion
    
    // Validation methods
    bool isValidSucursal(const Sucursal* sucursal) const;
    bool hasVendedoresAssigned(int id) const;
    const Sucursal* findById(int id) const;
    
    // Data management
    void loadData();
    bool saveData();
};

#endif // SUCURSAL_CRUD_H
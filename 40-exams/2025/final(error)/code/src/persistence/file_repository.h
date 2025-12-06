#ifndef FILE_REPOSITORY_H
#define FILE_REPOSITORY_H

#include <string>
#include "../domain/empleado.h"
#include "../domain/sucursal.h"

class FileRepository {
private:
    std::string filename;

public:
    FileRepository(const std::string& fname);
    
    bool save();
    bool load();
    bool saveVendedor(Empleado* vendedor);
    Empleado* loadVendedores();  // Note: This should return a collection, but using C arrays as required
};

#endif // FILE_REPOSITORY_H
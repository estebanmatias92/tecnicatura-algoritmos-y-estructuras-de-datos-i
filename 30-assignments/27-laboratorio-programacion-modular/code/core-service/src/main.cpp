#include "app/app_entrypoint.h"         // Includes executeApplication
#include "domain/persistence_manager.h" // Includes loadFromFile
#include "types/alumno_types.h"         // Includes tStudentList
#include "utils/helpers.h"              // Includes clearScreen

// Using declarations for convenience
using StudentManagement::App::ejecutarAplicacion;
using StudentManagement::Domain::cargarDesdeArchivo;
using StudentManagement::Types::tListaAlumnos;
using StudentManagement::Utils::limpiarPantalla;

/**
 * @brief Main function and application entry point.
 */
int main() {
    tListaAlumnos listaPrincipal; 

    // 1. Initialization: Clears the screen and loads data from the file.
    limpiarPantalla();
    cargarDesdeArchivo(listaPrincipal); 
    
    // 2. Delegate control of the menu loop to the application entrypoint.
    ejecutarAplicacion(listaPrincipal);

    return 0;
}

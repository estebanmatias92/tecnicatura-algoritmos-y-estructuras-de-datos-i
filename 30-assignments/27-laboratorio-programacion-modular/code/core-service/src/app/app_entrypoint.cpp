#include "app/app_entrypoint.h"
#include "domain/alumno_manager.h"
#include "domain/persistence_manager.h"
#include "types/alumno_types.h"
#include "utils/helpers.h"
#include <iostream>

// Using declarations for convenience
using std::cout;
using StudentManagement::Types::tListaAlumnos;
using StudentManagement::Domain::mostrarListado;
using StudentManagement::Domain::buscarYMostrarAlumno;
using StudentManagement::Domain::insertarAlumno;
using StudentManagement::Domain::eliminarAlumno;
using StudentManagement::Domain::ordenarYMostrar;
using StudentManagement::Domain::guardarEnArchivo;
using StudentManagement::Utils::limpiarPantalla;
using StudentManagement::Utils::pausaConsola;
using StudentManagement::Utils::mostrarMenu;

namespace StudentManagement {
namespace App {

// ----------------------------------------------------------------------------------
// --- MAIN LOOP IMPLEMENTATION ---
// ----------------------------------------------------------------------------------

/**
 * @brief Function containing the main application loop and menu.
 * * Calls Persistence, Utility (menu, pause) and Domain (tasks) functions.
 * @param lista The list of students to manage.
 */
void ejecutarAplicacion(tListaAlumnos& lista) {
    int opcion;
    
    do {
        // 1. Displays the menu and gets the option
        opcion = mostrarMenu();
        
        // Clears the screen before executing the selected task (except Exit/Invalid)
        if (opcion != 0 && opcion != -1) {
            limpiarPantalla();
        }

        switch (opcion) {
            case 1:
                mostrarListado(lista);
                break;
            case 2:
                buscarYMostrarAlumno(lista);
                break;
            case 3:
                insertarAlumno(lista);
                break;
            case 4:
                mostrarListado(lista);
                eliminarAlumno(lista);
                break;
            case 5:
                ordenarYMostrar(lista);
                break;
            case 6:
                // Persistence Task (Save)
                guardarEnArchivo(lista);
                break;
            case 0:
                // Persistence Task (Save) and Exit
                guardarEnArchivo(lista);
                cout << "\n👋 Programa finalizado. ¡Hasta pronto!\n";
                break;
            default:
                if (opcion != -1) {
                    cout << "❌ Opción inválida. Por favor, ingrese un número del 0 al 6.\n";
                }
                break;
        }

        // 2. Pause after the task (except on exit or if it's an invalid option)
        if (opcion >= 1 && opcion <= 6) {
            pausaConsola("\n\nPresione ENTER para volver al menú...");     
            limpiarPantalla();        
        }

    } while (opcion != 0);
}

} // namespace App
} // namespace StudentManagement

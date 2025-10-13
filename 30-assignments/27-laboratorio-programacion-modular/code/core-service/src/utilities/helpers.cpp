#include "utils/helpers.h"
#include <iostream>
#include <limits>
#include <string>
#include <cstdlib> // Required for the system() function

// Using declarations for convenience
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::numeric_limits;
using std::streamsize;

namespace StudentManagement {
namespace Utils {

// ----------------------------------------------------------------------------------
// --- Utility Function Implementation ---
// ----------------------------------------------------------------------------------

/**
 * @brief Helper function to clear the console screen.
 * * Uses operating system specific commands.
 */
void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

/**
 * @brief Clears any leftover input in the standard input buffer.
 */
void limpiarBufferEntrada() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 * @brief Helper function to pause execution and wait for user input.
 * @param mensaje Message to display to the user.
 */
void pausaConsola(const string& mensaje) {
    cout << mensaje;
    // Clear any error flags
    cin.clear();
    // Only ignore if there's data waiting in the buffer
    if (cin.rdbuf()->in_avail() > 0) {
        limpiarBufferEntrada();
    }
    cin.get(); // Wait for the user to press ENTER
}

/**
 * @brief Displays the main menu and asks the user for an option.
 * @return The chosen option number (0-6) or -1 if the input is invalid.
 */
int mostrarMenu() {
    int opcion;
    cout << "\n\n======== MENU ADMINISTRACION DE ALUMNOS ========\n";
    cout << "1. Mostrar Listado de Alumnos\n";
    cout << "2. Buscar y Mostrar un Alumno\n";
    cout << "3. Insertar un Nuevo Alumno\n";
    cout << "4. Eliminar un Alumno\n";
    cout << "5. Ordenar y Mostrar Listado (por Legajo)\n";
    cout << "------------------------------------------------\n";
    cout << "6. Guardar Cambios en Archivo\n";
    cout << "0. Salir (Guardar y Salir)\n";
    cout << "================================================\n";
    cout << "Ingrese su opción (0-6): ";
    
    // Tries to read the option. If it fails (non-numeric input), or if it's out of range, returns -1
    if (!(cin >> opcion)) {
        cin.clear();
        limpiarBufferEntrada();
        return -1;
    }

    limpiarBufferEntrada();
    
    return opcion;
}

} // namespace Utils
} // namespace StudentManagement

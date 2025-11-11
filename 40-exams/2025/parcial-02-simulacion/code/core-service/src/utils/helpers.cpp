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

namespace app {
namespace utils {

// ----------------------------------------------------------------------------------
// --- Utility Function Implementation ---
// ----------------------------------------------------------------------------------

/**
 * @brief Helper function to clear the console screen.
 * * Uses operating system specific commands.
 */
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

/**
 * @brief Clears any leftover input in the standard input buffer.
 */
void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 * @brief Helper function to pause execution and wait for user input.
 * @param message Message to display to the user.
 */
void pauseConsole(const string& message) {
    cout << message;
    // Clear any error flags
    cin.clear();
    // Only ignore if there's data waiting in the buffer
    if (cin.rdbuf()->in_avail() > 0) {
        clearInputBuffer();
    }
    cin.get(); // Wait for the user to press ENTER
}

/**
 * @brief Displays the main menu and asks the user for an option.
 * @return The chosen option number (0-4) or -1 if the input is invalid.
 */
int displayMenu() {
    int opcion;
    cout << "\n\n======== MENU GESTION DE FIGURAS ========\n";
    cout << "1. Crear y Agregar Figura\n";
    cout << "2. Dibujar Todas las Figuras\n";
    cout << "3. Rotar Todas las Figuras\n";
    cout << "4. Mover Todas las Figuras\n";
    cout << "------------------------------------------------\n";
    cout << "0. Salir\n";
    cout << "================================================\n";
    cout << "Ingrese su opción (0-4): ";
    
    // Tries to read the option. If it fails (non-numeric input), or if it's out of range, returns -1
    if (!(cin >> opcion)) {
        cin.clear();
        clearInputBuffer();
        return -1;
    }

    clearInputBuffer();
    
    return opcion;
}

} // namespace utils
} // namespace app

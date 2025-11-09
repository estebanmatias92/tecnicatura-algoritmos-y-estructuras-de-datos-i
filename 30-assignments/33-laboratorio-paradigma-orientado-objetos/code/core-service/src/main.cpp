#include "app/app_entrypoint.h" // Includes executeApplication
#include "utils/helpers.h"      // Includes clearScreen

// Using declarations for convenience
using Geometria::App::ejecutarAplicacion;
using Geometria::Utils::limpiarPantalla;

/**
 * @brief Main function and application entry point.
 */
int main() {
    // 1. Initialization: Clears the screen.
    limpiarPantalla();
    
    // 2. Delegate control of the menu loop to the application entrypoint.
    ejecutarAplicacion();

    return 0;
}

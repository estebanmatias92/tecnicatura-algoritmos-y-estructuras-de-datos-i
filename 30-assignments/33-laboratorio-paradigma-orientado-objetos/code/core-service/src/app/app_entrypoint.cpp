#include "app/app_entrypoint.h"
#include "domain/figura.h"
#include "domain/circulo.h"
#include "domain/rectangulo.h"
#include "domain/triangulo.h"
#include "utils/helpers.h"
#include <iostream>

#include <limits> // For numeric_limits

// Using declarations for convenience
using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;
using std::streamsize;
using Geometria::Figura;
using Geometria::Circulo;
using Geometria::Rectangulo;
using Geometria::Triangulo;
using Geometria::Utils::limpiarPantalla;
using Geometria::Utils::pausaConsola;
using Geometria::Utils::mostrarMenu;
using Geometria::Utils::limpiarBufferEntrada;

namespace Geometria {
namespace App {

const int MAX_FIGURAS = 5; // RF-04: Allow storing 5 figure objects

// ----------------------------------------------------------------------------------
// --- MAIN LOOP IMPLEMENTATION ---
// ----------------------------------------------------------------------------------

/**
 * @brief Function containing the main application loop and menu.
 */
void ejecutarAplicacion() {
    Figura* figuras[MAX_FIGURAS]; // RF-04 & RNF-01: Array of Figura pointers
    
    for (int i = 0; i < MAX_FIGURAS; ++i) {
        figuras[i] = nullptr;
    }

    int contadorFiguras = 0;
    int opcion;
    
    do {
        // 1. Displays the menu and gets the option
        opcion = mostrarMenu();
        
        // Clears the screen before executing the selected task (except Exit/Invalid)
        if (opcion != 0 && opcion != -1) {
            limpiarPantalla();
        }

        switch (opcion) {
            case 1: { // Create and add a figure
                if (contadorFiguras >= MAX_FIGURAS) {
                    cout << "❌ La colección de figuras está llena (Máx: " << MAX_FIGURAS << ").\n";
                    break;
                }
                int tipoFigura;
                cout << "\n--- Seleccione el tipo de figura a crear ---\n";
                cout << "1. Círculo\n";
                cout << "2. Rectángulo\n";
                cout << "3. Triángulo\n";
                cout << "Ingrese su opción: ";
                if (!(cin >> tipoFigura)) {
                    cout << "❌ Entrada inválida.\n";
                    limpiarBufferEntrada();
                    break;
                }
                limpiarBufferEntrada();

                Figura* nuevaFigura = nullptr;
                switch (tipoFigura) {
                    case 1: nuevaFigura = new Circulo(); break;
                    case 2: nuevaFigura = new Rectangulo(); break;
                    case 3: nuevaFigura = new Triangulo(); break;
                    default:
                        cout << "❌ Opción de figura inválida.\n";
                        break;
                }

                if (nuevaFigura) {
                    figuras[contadorFiguras++] = nuevaFigura;
                    cout << "✅ Figura agregada correctamente.\n";
                }
                break;
            }
            case 2: { // Draw all figures (RF-06)
                if (contadorFiguras == 0) {
                    cout << "La colección de figuras está vacía.\n";
                    break;
                }
                cout << "\n--- Dibujando todas las figuras ---\n";
                for (int i = 0; i < contadorFiguras; ++i) {
                    if (figuras[i]) {
                        figuras[i]->dibujar(); // Polymorphic call
                    }
                }
                break;
            }
            case 3: { // Rotate all figures
                if (contadorFiguras == 0) {
                    cout << "La colección de figuras está vacía.\n";
                    break;
                }
                cout << "\n--- Rotando todas las figuras ---\n";
                for (int i = 0; i < contadorFiguras; ++i) {
                    if (figuras[i]) {
                        figuras[i]->rotar();
                    }
                }
                break;
            }
            case 4: { // Move all figures
                if (contadorFiguras == 0) {
                    cout << "La colección de figuras está vacía.\n";
                    break;
                }
                cout << "\n--- Moviendo todas las figuras ---\n";
                for (int i = 0; i < contadorFiguras; ++i) {
                    if (figuras[i]) {
                        figuras[i]->mover();
                    }
                }
                break;
            }
            case 0:
                cout << "\n👋 Programa finalizado. ¡Hasta pronto!\n";
                break;
            default:
                if (opcion != -1) {
                    cout << "❌ Opción inválida. Por favor, ingrese un número del 0 al 4.\n";
                }
                break;
        }

        // 2. Pause after the task (except on exit or if it's an invalid option)
        if (opcion >= 1 && opcion <= 4) {
            pausaConsola("\n\nPresione ENTER para volver al menú...");     
            limpiarPantalla();        
        }

    } while (opcion != 0);

    // Clean up dynamically allocated memory
    for (int i = 0; i < contadorFiguras; ++i) {
        delete figuras[i];
        figuras[i] = nullptr;
    }
}

} // namespace App
} // namespace Geometria
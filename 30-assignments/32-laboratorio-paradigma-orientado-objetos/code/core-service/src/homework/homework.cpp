#include "homework/utils.h"
#include "homework/homework.h"
#include "program-01/program.h"
#include "program-02/program.h"
#include "program-03/program.h"
#include "program-04/program.h"
#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::numeric_limits;
using std::streamsize;

namespace Homework {

void showMenu() {
    cout << "\n--- Menú Principal de Tareas ---\n";
    cout << "1. Programa 01: Gestión de Artículos\n";
    cout << "2. Programa 02: Gestión de Alumnos\n";
    cout << "3. Programa 03: Gestión de Rectángulos\n";
    cout << "4. Programa 04: Gestión de Personas\n";
    cout << "0. Salir\n";
    cout << "Ingrese su opción: ";
}

void execute() {
    int choice;
    do {
        showMenu();
        cin >> choice;

        // Limpiar el buffer de entrada si la entrada no es un entero
        if (cin.fail()) {
            cout << "Entrada inválida. Por favor ingrese un número.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = -1; // Asignar un valor inválido para continuar el bucle
            continue;
        }

        switch (choice) {
            case 1: {
                program01::Programa p1;
                p1.ejecutar();
                break;
            }
            case 2: {
                program02::Programa p2;
                p2.ejecutar();
                break;
            }
            case 3: {
                program03::Programa p3;
                p3.ejecutar();
                break;
            }
            case 4: {
                program04::Programa p4;
                p4.ejecutar();
                break;
            }
            case 0:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (choice != 0);
}

} // namespace Homework
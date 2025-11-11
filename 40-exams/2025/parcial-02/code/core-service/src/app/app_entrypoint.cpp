#include "app_entrypoint.h"
#include "SistemaGestion.h"
#include "utils/helpers.h" // Include the refactored helpers
#include <iostream>
#include <limits> // Required for numeric_limits

namespace app {
namespace app_entrypoint {

void run() {
    domain::SistemaGestion sistema;
    int opcion;

    do {
        app::utils::clearScreen(); // Clear screen before each menu display
        std::cout << "\n--- Menu Principal ---" << std::endl;
        std::cout << "1. Cargar Cliente" << std::endl;
        std::cout << "2. Cargar Articulo" << std::endl;
        std::cout << "3. Cargar Pedido" << std::endl;
        std::cout << "4. Mostrar Pedidos de Clientes" << std::endl;
        std::cout << "0. Salir" << std::endl << std::endl;
        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;

        if (std::cin.fail()) {
            std::cout << "Entrada invalida. Por favor, ingrese un numero." << std::endl;
            std::cin.clear();
            app::utils::clearInputBuffer(); // Use the helper function
            continue;
        }
        app::utils::clearInputBuffer(); // Use the helper function // Clear the rest of the line after reading the integer

        switch (opcion) {
            case 1: {
                int id;
                std::string nombre;
                std::cout << std::endl << "Ingrese ID del cliente: ";
                std::cin >> id;
                app::utils::clearInputBuffer(); // Use the helper function
                std::cout << "Ingrese nombre del cliente: ";
                std::getline(std::cin, nombre);
                sistema.cargarCliente(id, nombre);
                break;
            }
            case 2: {
                int id;
                std::string nombre;
                std::cout << std::endl << "Ingrese ID del articulo: ";
                std::cin >> id;
                app::utils::clearInputBuffer(); // Use the helper function
                std::cout << "Ingrese nombre del articulo: ";
                std::getline(std::cin, nombre);
                sistema.cargarArticulo(id, nombre);
                break;
            }
            case 3: {
                int idPedido, idCliente;
                std::cout << std::endl << "Ingrese ID del pedido: ";
                std::cin >> idPedido;
                std::cout << "Ingrese ID del cliente para este pedido: ";
                std::cin >> idCliente;
                app::utils::clearInputBuffer(); // Use the helper function

                std::cout << std::endl << "Cuantos articulos desea agregar al pedido? ";
                int numArticulos;
                std::cin >> numArticulos;
                app::utils::clearInputBuffer(); // Use the helper function

                if (numArticulos > 0) {
                    int* idsArticulos = new int[numArticulos];
                    for (int i = 0; i < numArticulos; ++i) {
                        std::cout << std::endl << "Ingrese ID del articulo " << (i + 1) << ": " << std::endl;
                        std::cin >> idsArticulos[i];
                    }
                    app::utils::clearInputBuffer(); // Use the helper function
                    sistema.cargarPedido(idPedido, idCliente, idsArticulos, numArticulos);
                    delete[] idsArticulos;
                } else {
                    sistema.cargarPedido(idPedido, idCliente, nullptr, 0);
                }
                break;
            }
            case 4: {
                sistema.mostrarPedidosClientes();
                break;
            }
            case 0: {
                std::cout << std::endl << "Saliendo del programa." << std::endl;
                break;
            }
            default: {
                std::cout << std::endl << "Opcion no valida. Intente de nuevo." << std::endl;
                break;
            }
        }
        app::utils::pauseConsole("\nPresione ENTER para continuar...");

    } while (opcion != 0);
}

} // namespace app_entrypoint
} // namespace app

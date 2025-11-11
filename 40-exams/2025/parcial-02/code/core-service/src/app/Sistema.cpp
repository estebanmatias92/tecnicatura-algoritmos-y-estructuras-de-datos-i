#include "app/Sistema.h"
#include "utils/helpers.h"
#include <iostream>
#include <string>
#include <limits>

// Using declarations for convenience
using std::cin;
using std::cout;
using std::endl;
using std::string;

namespace app {

// --- Constructor y Destructor ---

Sistema::Sistema() : numClientes(0), numEmpleados(0), numPedidos(0), numEquipos(0), nextPedidoID(1) {
    inicializarDatos();
}

Sistema::~Sistema() {
    // Liberar memoria de los equipos (NFR-M3)
    for (int i = 0; i < numEquipos; ++i) {
        delete listaEquipos[i];
    }
}

// --- Inicialización de Datos ---

void Sistema::inicializarDatos() {
    // Carga de Equipos (FR-M1.1)
    listaEquipos[numEquipos++] = new domain::Ropa("R001", "Camisa de Trabajo", 25.50, "L", "Azul");
    listaEquipos[numEquipos++] = new domain::Ropa("R002", "Pantalon Cargo", 45.00, "32", "Beige");
    listaEquipos[numEquipos++] = new domain::Zapatos("Z001", "Botas de Seguridad", 80.00, 42, "Punta de Acero");
    listaEquipos[numEquipos++] = new domain::Zapatos("Z002", "Zapatos de Oficina", 60.00, 41, "Punta Redonda");
    listaEquipos[numEquipos++] = new domain::Antiparras("A001", "Antiparras de Seguridad", 15.00);

    // Carga de Clientes (FR-M2.1)
    listaClientes[numClientes++] = domain::Cliente("20-12345678-9", "Constructora XYZ S.A.");
    listaClientes[numClientes++] = domain::Cliente("30-87654321-5", "Industrias Acme S.R.L.");

    // Carga de Empleados (FR-M3.1)
    listaEmpleados[numEmpleados++] = domain::Empleado("L001", "Juan", "Perez");
    listaEmpleados[numEmpleados++] = domain::Empleado("L002", "Maria", "Gomez");
}

// --- Flujo Principal de la Aplicación ---

void Sistema::run() {
    menuPrincipal();
}

void Sistema::menuPrincipal() {
    int opcion;
    do {
        utils::clearScreen();
        cout << "==== SISTEMA DE GESTION DE PEDIDOS ====\n"
             << "1. Listar Equipos\n"
             << "2. Listar Clientes\n"
             << "3. Listar Empleados\n"
             << "4. Gestion de Pedidos\n"
             << "5. Ver Reporte de Pedidos por Cliente\n"
             << "---------------------------------------\n"
             << "0. Salir\n"
             << "=======================================\n"
             << "Ingrese su opcion: ";
        
        if (!(cin >> opcion)) {
            cout << "Opcion invalida. Por favor, ingrese un numero." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            opcion = -1; 
        } else {
             cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (opcion) {
            case 1: listarEquipos(); break;
            case 2: listarClientes(); break;
            case 3: listarEmpleados(); break;
            case 4: menuGestionPedidos(); break;
            case 5: mostrarPedidosClientes(); break;
            case 0: cout << "Saliendo del sistema..." << endl; break;
            default: cout << "Opcion no valida." << endl; break;
        }

        if (opcion != 0) {
            utils::pauseConsole("Presione ENTER para continuar...");
        }

    } while (opcion != 0);
}

void Sistema::menuGestionPedidos() {
    int opcion;
    do {
        utils::clearScreen();
        cout << "==== GESTION DE PEDIDOS ====\n"
             << "1. Alta de Pedido\n"
             << "2. Baja de Pedido\n"
             << "3. Modificar Pedido\n"
             << "4. Listar Pedidos\n"
             << "----------------------------\n"
             << "0. Volver al Menu Principal\n"
             << "============================\n"
             << "Ingrese su opcion: ";

        if (!(cin >> opcion)) {
            cout << "Opcion invalida. Por favor, ingrese un numero." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            opcion = -1;
        } else {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (opcion) {
            case 1: altaPedido(); break;
            case 2: bajaPedido(); break;
            case 3: modificarPedido(); break;
            case 4: listarPedidos(); break;
            case 0: break;
            default: cout << "Opcion no valida." << endl; break;
        }
        
        if (opcion != 0) {
            utils::pauseConsole("Presione ENTER para continuar...");
        }

    } while (opcion != 0);
}


// --- Implementación de Módulos ---

void Sistema::listarEquipos() {
    utils::clearScreen();
    cout << "--- Lista de Equipos Disponibles ---" << endl;
    for (int i = 0; i < numEquipos; ++i) {
        listaEquipos[i]->mostrar();
    }
}

void Sistema::listarClientes() {
    utils::clearScreen();
    cout << "--- Lista de Clientes ---" << endl;
    for (int i = 0; i < numClientes; ++i) {
        listaClientes[i].mostrar();
    }
}

void Sistema::listarEmpleados() {
    utils::clearScreen();
    cout << "--- Lista de Empleados ---" << endl;
    for (int i = 0; i < numEmpleados; ++i) {
        listaEmpleados[i].mostrar();
    }
}

void Sistema::altaPedido() {
    utils::clearScreen();
    cout << "--- Alta de Pedido ---" << endl;
    if (numPedidos >= MAX_PEDIDOS) {
        cout << "No se pueden agregar mas pedidos. Capacidad maxima alcanzada." << endl;
        return;
    }

    domain::Cliente* cliente = seleccionarCliente();
    if (!cliente) return;

    domain::Empleado* empleado = seleccionarEmpleado();
    if (!empleado) return;

    domain::Pedido nuevoPedido(nextPedidoID, cliente, empleado); 
    
    char agregarOtro;
    do {
        domain::Equipo* equipo = seleccionarEquipo();
        if (equipo) {
            nuevoPedido.agregarEquipo(equipo);
            cout << "Equipo agregado." << endl;
        }
        cout << "Desea agregar otro equipo? (s/n): ";
        cin >> agregarOtro;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (agregarOtro == 's' || agregarOtro == 'S');

    listaPedidos[numPedidos++] = nuevoPedido;
    nextPedidoID++;
    cout << "Pedido dado de alta con exito (ID: " << nuevoPedido.getID() << ")." << endl;
}

void Sistema::bajaPedido() {
    utils::clearScreen();
    cout << "--- Baja de Pedido ---" << endl;
    listarPedidos();
    if (numPedidos == 0) return;

    cout << "Ingrese el ID del pedido a eliminar: ";
    int id;
    cin >> id;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int index = findPedidoIndex(id);

    if (index != -1) {
        for (int i = index; i < numPedidos - 1; ++i) {
            listaPedidos[i] = listaPedidos[i + 1];
        }
        numPedidos--;
        cout << "Pedido eliminado con exito." << endl;
    } else {
        cout << "Pedido no encontrado." << endl;
    }
}

void Sistema::modificarPedido() {
    utils::clearScreen();
    cout << "--- Modificar Pedido ---" << endl;
    listarPedidos();
    if (numPedidos == 0) return;

    cout << "Ingrese el ID del pedido a modificar: ";
    int id;
    cin >> id;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int index = findPedidoIndex(id);

    if (index != -1) {
        cout << "Funcionalidad de modificacion no implementada en este prototipo." << endl;
        // Aquí iría la lógica para modificar el pedido.
        // Por ejemplo, permitir cambiar el cliente, empleado o agregar/quitar equipos.
    } else {
        cout << "Pedido no encontrado." << endl;
    }
}

void Sistema::listarPedidos() {
    utils::clearScreen();
    cout << "--- Lista de Pedidos ---" << endl;
    if (numPedidos == 0) {
        cout << "No hay pedidos registrados." << endl;
    } else {
        for (int i = 0; i < numPedidos; ++i) {
            listaPedidos[i].mostrarDetalle();
        }
    }
}

void Sistema::mostrarPedidosClientes() {
    utils::clearScreen();
    cout << "--- Reporte: Pedidos por Cliente ---" << endl;

    domain::Cliente* clienteSeleccionado = seleccionarCliente();

    if (clienteSeleccionado) {
        cout << "\n>> Mostrando pedidos para el cliente: " << clienteSeleccionado->getRazonSocial() << endl;
        bool clienteTienePedidos = false;
        for (int i = 0; i < numPedidos; ++i) {
            if (listaPedidos[i].getCliente() == clienteSeleccionado) {
                listaPedidos[i].mostrarDetalle();
                clienteTienePedidos = true;
            }
        }

        if (!clienteTienePedidos) {
            cout << "Este cliente no tiene pedidos registrados." << endl;
        }
    }
    // Si no se selecciona un cliente, la función simplemente termina.
}


// --- Helpers Internos ---

domain::Cliente* Sistema::seleccionarCliente() {
    cout << "\nSeleccione un cliente:" << endl;
    for (int i = 0; i < numClientes; ++i) {
        cout << i + 1 << ". " << listaClientes[i].getRazonSocial() << endl;
    }
    cout << "Opcion: ";
    int opcion;
    cin >> opcion;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (opcion > 0 && opcion <= numClientes) {
        return &listaClientes[opcion - 1];
    }
    cout << "Seleccion invalida." << endl;
    return NULL;
}

domain::Empleado* Sistema::seleccionarEmpleado() {
    cout << "\nSeleccione un empleado:" << endl;
    for (int i = 0; i < numEmpleados; ++i) {
        cout << i + 1 << ". " << listaEmpleados[i].getNombreCompleto() << endl;
    }
    cout << "Opcion: ";
    int opcion;
    cin >> opcion;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (opcion > 0 && opcion <= numEmpleados) {
        return &listaEmpleados[opcion - 1];
    }
    cout << "Seleccion invalida." << endl;
    return NULL;
}

domain::Equipo* Sistema::seleccionarEquipo() {
    cout << "\nSeleccione un equipo para agregar:" << endl;
    for (int i = 0; i < numEquipos; ++i) {
        cout << i + 1 << ". " << listaEquipos[i]->getNombre() << " ($" << listaEquipos[i]->getPrecio() << ")" << endl;
    }
    cout << "Opcion: ";
    int opcion;
    cin >> opcion;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (opcion > 0 && opcion <= numEquipos) {
        return listaEquipos[opcion - 1];
    }
    cout << "Seleccion invalida." << endl;
    return NULL;
}

int Sistema::findPedidoIndex(int id) {
    for (int i = 0; i < numPedidos; ++i) {
        if (listaPedidos[i].getID() == id) {
            return i;
        }
    }
    return -1; // No encontrado
}

} // namespace app

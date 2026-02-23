#include "app/Sistema.h"
#include "utils/helpers.h"
#include <iostream>
#include <string>
#include <limits>

using std::cin;
using std::cout;
using std::endl;
using std::string;

namespace app {

Sistema::Sistema() : numClientes(0), numEmpleados(0), numPedidos(0), numAnimales(0), nextPedidoID(1) {
    inicializarDatos();
}

Sistema::~Sistema() {
    for (int i = 0; i < numAnimales; ++i) {
        delete listaAnimales[i];
    }
}

void Sistema::inicializarDatos() {
    listaAnimales[numAnimales++] = new domain::Pollo("P001", "Pollo Entero", 1200.00, "Pollo", true, 2.5f);
    listaAnimales[numAnimales++] = new domain::Pollo("P002", "Pechuga de Pollo", 1800.00, "Pollo", false, 1.2f);
    listaAnimales[numAnimales++] = new domain::Pollo("P003", "Alas de Pollo", 950.00, "Pollo", true, 0.8f);
    listaAnimales[numAnimales++] = new domain::Vacuno("V001", "Asado", 4500.00, "Vacuno", "Asado", "Santa Clara del Mar");
    listaAnimales[numAnimales++] = new domain::Vacuno("V002", "Cuadril", 5200.00, "Vacuno", "Cuadril", "Buenos Aires");
    listaAnimales[numAnimales++] = new domain::Cerdo("C001", "Costilla de Cerdo", 2800.00, "Cerdo", "Costilla", true);
    listaAnimales[numAnimales++] = new domain::Cerdo("C002", "Lomo de Cerdo", 3200.00, "Cerdo", "Lomo", false);

    listaClientes[numClientes++] = domain::Cliente("20-12345678-9", "Juan Lopez");
    listaClientes[numClientes++] = domain::Cliente("30-87654321-5", "Maria Garcia");
    listaClientes[numClientes++] = domain::Cliente("27-11223344-5", "Carlos Rodriguez");

    listaEmpleados[numEmpleados++] = domain::Empleado("L001", "Pedro", "Martinez");
    listaEmpleados[numEmpleados++] = domain::Empleado("L002", "Laura", "Fernandez");
}

void Sistema::run() {
    menuPrincipal();
}

void Sistema::menuPrincipal() {
    int opcion;
    do {
        utils::clearScreen();
        cout << "=======================================\n"
             << "   UKELE CHICKEN - BOUTIQUE DE CARNES\n"
             << "=======================================\n"
             << "1. Listar Animales (Carnes)\n"
             << "2. Listar Clientes\n"
             << "3. Listar Empleados\n"
             << "4. Gestion de Pedidos\n"
             << "5. Ver Reporte de Pedidos por Cliente\n"
             << "6. Demo Polimorfismo (Comer/Dormir)\n"
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
            case 1: listarAnimales(); break;
            case 2: listarClientes(); break;
            case 3: listarEmpleados(); break;
            case 4: menuGestionPedidos(); break;
            case 5: mostrarPedidosClientes(); break;
            case 6: demoPolimorfismo(); break;
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

void Sistema::listarAnimales() {
    utils::clearScreen();
    cout << "--- Lista de Carnes Disponibles ---" << endl;
    for (int i = 0; i < numAnimales; ++i) {
        listaAnimales[i]->mostrar();
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
        domain::Animal* animal = seleccionarAnimal();
        if (animal) {
            nuevoPedido.agregarAnimal(animal);
            cout << "Carne agregada al pedido." << endl;
        }
        cout << "Desea agregar otra carne? (s/n): ";
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
}

void Sistema::demoPolimorfismo() {
    utils::clearScreen();
    cout << "--- Demo Polimorfismo: Todos los animales Comen ---" << endl;
    for (int i = 0; i < numAnimales; ++i) {
        cout << "\nAnimal " << (i + 1) << ":" << endl;
        listaAnimales[i]->mostrar();
        listaAnimales[i]->comer();
    }

    cout << "\n\n--- Demo Polimorfismo: Todos los animales Duermen ---" << endl;
    for (int i = 0; i < numAnimales; ++i) {
        cout << "\nAnimal " << (i + 1) << ":" << endl;
        listaAnimales[i]->mostrar();
        listaAnimales[i]->dormir();
    }
}

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

domain::Animal* Sistema::seleccionarAnimal() {
    cout << "\nSeleccione una carne para agregar al pedido:" << endl;
    for (int i = 0; i < numAnimales; ++i) {
        cout << i + 1 << ". " << listaAnimales[i]->getNombre() << " ($" << listaAnimales[i]->getPrecio() << ")" << endl;
    }
    cout << "Opcion: ";
    int opcion;
    cin >> opcion;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (opcion > 0 && opcion <= numAnimales) {
        return listaAnimales[opcion - 1];
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
    return -1;
}

} // namespace app

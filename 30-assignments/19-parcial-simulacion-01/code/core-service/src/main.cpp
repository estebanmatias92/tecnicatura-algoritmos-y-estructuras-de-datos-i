#include <iostream> // Para entrada y salida (cin, cout)
#include <fstream>  // Para manejo de archivos (ifstream, ofstream)
#include <string>   // Para usar std::string
#include <limits>   // Para std::numeric_limits
#include <iomanip>  // Para formatear la salida (setw, left)

// --- Constantes ---
#define MAX_CLIENTES 100 // Máximo número de clientes en el array
const char* NOMBRE_ARCHIVO_CLIENTES = "clientes.txt";

// --- Definición de tipos con typedef ---

// Consigna 1.a (implícita): Declarar tipo tCliente
typedef struct {
    int codigoCliente; // Código del cliente (índice + 100)
    std::string dni;
    std::string apellido;
    std::string nombre;
} tCliente;

// Consigna 1 (implícita): Estructura para manejar la lista de clientes
typedef struct {
    tCliente clientes[MAX_CLIENTES];
    int cantidad; // Número actual de clientes en la lista
} tListaClientes;


// --- Prototipos de Funciones ---

// Funciones de utilidad para archivo y datos
void cargarClientesDesdeArchivo(tListaClientes* lista);
void guardarClientesEnArchivo(const tListaClientes* lista);
int generarCodigoCliente(int indice); // Consigna 1.a: Código del cliente se obtiene sumando 100 al índice

// Consigna 1: Gestionar los Clientes
// Consigna 1.a: Dar de alta el cliente
void darDeAltaCliente(tListaClientes* lista);
// Consigna 1.b: Dar de Baja los clientes x código de cliente
void darDeBajaCliente(tListaClientes* lista, int codigo);
// Consigna 1.c: Modificar los clientes
void modificarCliente(tListaClientes* lista, int codigo);

// Consigna 2: Listar los Clientes
// Consigna 2.a: Listar todos los Clientes
void listarTodosLosClientes(const tListaClientes* lista);
// Consigna 2.b: Buscar un Clientes x código y mostrarlo
void buscarClientePorCodigo(const tListaClientes* lista, int codigo);

// Función para mostrar el menú principal
void mostrarMenu();


int main() {
    tListaClientes listaClientes;
    listaClientes.cantidad = 0; // Inicializar la cantidad de clientes

    // Cargar clientes existentes al inicio del programa
    cargarClientesDesdeArchivo(&listaClientes);

    int opcion;

    do {
        mostrarMenu();
        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;

        // Limpiar el buffer de entrada después de leer un entero
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcion) {
            case 1: { // Consigna 1.a: Dar de alta el cliente
                darDeAltaCliente(&listaClientes);
                break;
            }
            case 2: { // Consigna 1.b: Dar de Baja los clientes x código de cliente
                int codigoBaja;
                std::cout << "Ingrese el codigo del cliente a dar de baja: ";
                std::cin >> codigoBaja;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                darDeBajaCliente(&listaClientes, codigoBaja);
                break;
            }
            case 3: { // Consigna 1.c: Modificar los clientes
                int codigoModificar;
                std::cout << "Ingrese el codigo del cliente a modificar: ";
                std::cin >> codigoModificar;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                modificarCliente(&listaClientes, codigoModificar);
                break;
            }
            case 4: { // Consigna 2.a: Listar todos los Clientes
                listarTodosLosClientes(&listaClientes);
                break;
            }
            case 5: { // Consigna 2.b: Buscar un Clientes x código y mostrarlo
                int codigoBuscar;
                std::cout << "Ingrese el codigo del cliente a buscar: ";
                std::cin >> codigoBuscar;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                buscarClientePorCodigo(&listaClientes, codigoBuscar);
                break;
            }
            case 0:
                std::cout << "Saliendo del programa. Guardando cambios..." << std::endl;
                guardarClientesEnArchivo(&listaClientes); // Guardar cambios al salir
                break;
            default:
                std::cout << "Opcion invalida. Por favor, intente de nuevo." << std::endl;
                break;
        }
    } while (opcion != 0);

    return 0;
}


// --- Implementaciones de Funciones ---

// Función para mostrar el menú principal
void mostrarMenu() {
    std::cout << "\n--- MENU DE GESTION DE CLIENTES ---" << std::endl;
    std::cout << "1. Dar de Alta Cliente" << std::endl;
    std::cout << "2. Dar de Baja Cliente" << std::endl;
    std::cout << "3. Modificar Cliente" << std::endl;
    std::cout << "4. Listar Todos los Clientes" << std::endl;
    std::cout << "5. Buscar Cliente por Codigo" << std::endl;
    std::cout << "0. Salir" << std::endl;
}

// Carga clientes desde el archivo al inicio del programa
void cargarClientesDesdeArchivo(tListaClientes* lista) {
    std::ifstream archivo(NOMBRE_ARCHIVO_CLIENTES);
    if (!archivo.is_open()) {
        std::cerr << "Advertencia: No se pudo abrir el archivo de clientes. Se creara uno nuevo al guardar." << std::endl;
        return;
    }

    lista->cantidad = 0;
    int codigo;
    std::string dni, apellido, nombre;

    while (archivo >> codigo >> dni >> apellido >> nombre && lista->cantidad < MAX_CLIENTES) {
        lista->clientes[lista->cantidad].codigoCliente = codigo;
        lista->clientes[lista->cantidad].dni = dni;
        lista->clientes[lista->cantidad].apellido = apellido;
        lista->clientes[lista->cantidad].nombre = nombre;
        lista->cantidad++;
    }
    archivo.close();
    std::cout << "Clientes cargados desde " << NOMBRE_ARCHIVO_CLIENTES << std::endl;
}

// Guarda todos los clientes en el archivo (sobrescribe el archivo)
void guardarClientesEnArchivo(const tListaClientes* lista) {
    std::ofstream archivo(NOMBRE_ARCHIVO_CLIENTES); // Abre en modo truncar (sobrescribir)
    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo de clientes para guardar." << std::endl;
        return;
    }

    for (int i = 0; i < lista->cantidad; ++i) {
        archivo << lista->clientes[i].codigoCliente << " "
                << lista->clientes[i].dni << " "
                << lista->clientes[i].apellido << " "
                << lista->clientes[i].nombre << std::endl;
    }
    archivo.close();
    std::cout << "Clientes guardados en " << NOMBRE_ARCHIVO_CLIENTES << std::endl;
}

// Consigna 1.a: Generar código de cliente (índice + 100)
int generarCodigoCliente(int indice) {
    return indice + 100;
}

// Consigna 1.a: Dar de alta el cliente
void darDeAltaCliente(tListaClientes* lista) {
    if (lista->cantidad >= MAX_CLIENTES) {
        std::cout << "Error: No se pueden agregar mas clientes. Limite alcanzado." << std::endl;
        return;
    }

    tCliente nuevoCliente;
    nuevoCliente.codigoCliente = generarCodigoCliente(lista->cantidad); // Asigna código basado en el índice

    std::cout << "\n--- Dar de Alta Nuevo Cliente ---" << std::endl;
    std::cout << "Codigo de Cliente asignado: " << nuevoCliente.codigoCliente << std::endl;
    std::cout << "Ingrese DNI: ";
    std::getline(std::cin, nuevoCliente.dni);
    std::cout << "Ingrese Apellido: ";
    std::getline(std::cin, nuevoCliente.apellido);
    std::cout << "Ingrese Nombre: ";
    std::getline(std::cin, nuevoCliente.nombre);

    lista->clientes[lista->cantidad] = nuevoCliente;
    lista->cantidad++;
    std::cout << "Cliente dado de alta exitosamente." << std::endl;

    guardarClientesEnArchivo(lista); // Guardar cambios inmediatamente
}

// Consigna 1.b: Dar de Baja los clientes x código de cliente
void darDeBajaCliente(tListaClientes* lista, int codigo) {
    int indiceEncontrado = -1;
    for (int i = 0; i < lista->cantidad; ++i) {
        if (lista->clientes[i].codigoCliente == codigo) {
            indiceEncontrado = i;
            break;
        }
    }

    if (indiceEncontrado != -1) {
        // Desplazar los elementos restantes para eliminar
        for (int i = indiceEncontrado; i < lista->cantidad - 1; ++i) {
            lista->clientes[i] = lista->clientes[i + 1];
        }
        lista->cantidad--; // Decrementar la cantidad de clientes
        std::cout << "Cliente con codigo " << codigo << " dado de baja exitosamente." << std::endl;
        guardarClientesEnArchivo(lista); // Guardar cambios inmediatamente
    } else {
        std::cout << "Cliente con codigo " << codigo << " no encontrado." << std::endl;
    }
}

// Consigna 1.c: Modificar los clientes
void modificarCliente(tListaClientes* lista, int codigo) {
    int indiceEncontrado = -1;
    for (int i = 0; i < lista->cantidad; ++i) {
        if (lista->clientes[i].codigoCliente == codigo) {
            indiceEncontrado = i;
            break;
        }
    }

    if (indiceEncontrado != -1) {
        std::cout << "\n--- Modificar Cliente (Codigo: " << codigo << ") ---" << std::endl;
        std::cout << "Datos actuales:" << std::endl;
        std::cout << "  DNI: " << lista->clientes[indiceEncontrado].dni << std::endl;
        std::cout << "  Apellido: " << lista->clientes[indiceEncontrado].apellido << std::endl;
        std::cout << "  Nombre: " << lista->clientes[indiceEncontrado].nombre << std::endl;

        std::cout << "\nIngrese nuevo DNI (o presione Enter para mantener): ";
        std::string nuevoDni;
        std::getline(std::cin, nuevoDni);
        if (!nuevoDni.empty()) {
            lista->clientes[indiceEncontrado].dni = nuevoDni;
        }

        std::cout << "Ingrese nuevo Apellido (o presione Enter para mantener): ";
        std::string nuevoApellido;
        std::getline(std::cin, nuevoApellido);
        if (!nuevoApellido.empty()) {
            lista->clientes[indiceEncontrado].apellido = nuevoApellido;
        }

        std::cout << "Ingrese nuevo Nombre (o presione Enter para mantener): ";
        std::string nuevoNombre;
        std::getline(std::cin, nuevoNombre);
        if (!nuevoNombre.empty()) {
            lista->clientes[indiceEncontrado].nombre = nuevoNombre;
        }

        std::cout << "Cliente modificado exitosamente." << std::endl;
        guardarClientesEnArchivo(lista); // Guardar cambios inmediatamente
    } else {
        std::cout << "Cliente con codigo " << codigo << " no encontrado." << std::endl;
    }
}

// Consigna 2.a: Listar todos los Clientes
void listarTodosLosClientes(const tListaClientes* lista) {
    if (lista->cantidad == 0) {
        std::cout << "No hay clientes para mostrar." << std::endl;
        return;
    }
    std::cout << "\n--- LISTADO DE CLIENTES ---" << std::endl;
    std::cout << std::left << std::setw(10) << "Codigo"
              << std::setw(15) << "DNI"
              << std::setw(20) << "Apellido"
              << std::setw(20) << "Nombre" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    for (int i = 0; i < lista->cantidad; ++i) {
        std::cout << std::left << std::setw(10) << lista->clientes[i].codigoCliente
                  << std::setw(15) << lista->clientes[i].dni
                  << std::setw(20) << lista->clientes[i].apellido
                  << std::setw(20) << lista->clientes[i].nombre << std::endl;
    }
    std::cout << "------------------------------------------------------------------" << std::endl;
}

// Consigna 2.b: Buscar un Clientes x código y mostrarlo
void buscarClientePorCodigo(const tListaClientes* lista, int codigo) {
    int indiceEncontrado = -1;
    for (int i = 0; i < lista->cantidad; ++i) {
        if (lista->clientes[i].codigoCliente == codigo) {
            indiceEncontrado = i;
            break;
        }
    }

    if (indiceEncontrado != -1) {
        std::cout << "\n--- Cliente Encontrado (Codigo: " << codigo << ") ---" << std::endl;
        std::cout << "  DNI: " << lista->clientes[indiceEncontrado].dni << std::endl;
        std::cout << "  Apellido: " << lista->clientes[indiceEncontrado].apellido << std::endl;
        std::cout << "  Nombre: " << lista->clientes[indiceEncontrado].nombre << std::endl;
    } else {
        std::cout << "Cliente con codigo " << codigo << " NO encontrado." << std::endl;
    }
}

#include <iostream> // Para entrada y salida (cin, cout)
#include <string>   // Para usar std::string
#include <iomanip>  // Para formatear la salida (setw, left)

// Define un tamaño máximo para los arrays de frutas
#define MAX_FRUTAS 10

// --- Tipos Enumerados (enum) ---
// Consigna: Se recomienda utilizar Enumeradores
enum TipoPlato {
    PRIMER_PLATO = 1,
    PLATO_PRINCIPAL,
    POSTRE
};

enum ClaseVuelo {
    PRIMERA = 1,
    BUSINESS,
    ECONOMICA
};

enum CodigoAeropuerto {
    BAHIA_BLANCA = 1, // BHI
    AEROPARQUE,       // AER
    EL_PALOMAR,       // EPA
    EZEIZA,           // EZE
    BARILOCHE,        // BRC
    CATAMARCA,        // CTC
    COMODORO_RIVADAVIA // CRD
};

enum Fruta {
    MANZANA = 1,
    BANANA,
    NARANJA,
    PERA,
    UVA,
    KIWI
};

// --- Tipos Definidos por el Usuario (typedef struct) ---
// Consigna: Se recomienda utilizar Tipos definidos x el usuario
typedef struct {
    int numeroMesa;
    std::string nombreMozo;
    std::string fecha;
    std::string hora;
    TipoPlato primerPlato;
    TipoPlato platoPrincipal;
    TipoPlato poste;
} ComandaRestaurante;

typedef struct {
    std::string dni;
    std::string apellido;
    std::string nombre;
    ClaseVuelo clase;
    CodigoAeropuerto origen;
    CodigoAeropuerto destino;
} ReservaAvion;

typedef struct {
    int codigoProveedor;
    std::string razonSocial;
    std::string fechaSolicitud;
    std::string fechaEntrega;
    Fruta frutasPedidas[MAX_FRUTAS]; // Array de frutas
    int numFrutasPedidas;            // Contador de frutas en el array
} PedidoVerduleria;


// --- Prototipos de Funciones ---

// Consigna 1.a: Aplicación de restaurante
void tomarYMostrarComanda();
std::string obtenerNombrePlato(TipoPlato plato);

// Consigna 1.b: Programa de reservas de avión
void tomarYMostrarReservaAvion();
std::string obtenerNombreClaseVuelo(ClaseVuelo clase);
std::string obtenerNombreAeropuerto(CodigoAeropuerto codigo);

// Consigna 1.c: Pedido de verdulería al mayorista
void tomarYMostrarPedidoVerduleria();
std::string obtenerNombreFruta(Fruta fruta);


int main() {
    int opcion;

    do {
        std::cout << "\n--- MENU PRINCIPAL - TP Unidad 3.1 ---" << std::endl;
        std::cout << "1. Aplicacion de Restaurante (Comanda)" << std::endl;
        std::cout << "2. Programa de Reservas de Avion" << std::endl;
        std::cout << "3. Pedido de Verduleria al Mayorista" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: // Consigna 1.a: Aplicación de restaurante
                tomarYMostrarComanda();
                break;
            case 2: // Consigna 1.b: Programa de reservas de avión
                tomarYMostrarReservaAvion();
                break;
            case 3: // Consigna 1.c: Pedido de verdulería al mayorista
                tomarYMostrarPedidoVerduleria();
                break;
            case 0:
                std::cout << "Saliendo del programa." << std::endl;
                break;
            default:
                std::cout << "Opcion invalida. Por favor, intente de nuevo." << std::endl;
                break;
        }
    } while (opcion != 0);

    return 0;
}


// --- Implementaciones de Funciones ---

// Consigna 1.a: Aplicación de restaurante
void tomarYMostrarComanda() {
    ComandaRestaurante comanda;
    int opcionPlato;

    std::cout << "\n--- Tomar Comanda de Restaurante ---" << std::endl;
    std::cout << "Numero de Mesa: ";
    std::cin >> comanda.numeroMesa;
    std::cin.ignore(); // Limpiar el buffer de entrada
    std::cout << "Nombre del Mozo: ";
    std::getline(std::cin, comanda.nombreMozo);
    std::cout << "Fecha (DD/MM/AAAA): ";
    std::getline(std::cin, comanda.fecha);
    std::cout << "Hora (HH:MM): ";
    std::getline(std::cin, comanda.hora);

    std::cout << "Seleccione Primer Plato (1:PRIMER_PLATO, 2:PLATO_PRINCIPAL, 3:POSTRE): ";
    std::cin >> opcionPlato;
    comanda.primerPlato = static_cast<TipoPlato>(opcionPlato);

    std::cout << "Seleccione Plato Principal (1:PRIMER_PLATO, 2:PLATO_PRINCIPAL, 3:POSTRE): ";
    std::cin >> opcionPlato;
    comanda.platoPrincipal = static_cast<TipoPlato>(opcionPlato);

    std::cout << "Seleccione Postre (1:PRIMER_PLATO, 2:PLATO_PRINCIPAL, 3:POSTRE): ";
    std::cin >> opcionPlato;
    comanda.poste = static_cast<TipoPlato>(opcionPlato);

    std::cout << "\n--- Informacion de la Comanda ---" << std::endl;
    std::cout << "Numero de Mesa: " << comanda.numeroMesa << std::endl;
    std::cout << "Nombre del Mozo: " << comanda.nombreMozo << std::endl;
    std::cout << "Fecha: " << comanda.fecha << std::endl;
    std::cout << "Hora: " << comanda.hora << std::endl;
    std::cout << "Primer Plato: " << obtenerNombrePlato(comanda.primerPlato) << std::endl;
    std::cout << "Plato Principal: " << obtenerNombrePlato(comanda.platoPrincipal) << std::endl;
    std::cout << "Postre: " << obtenerNombrePlato(comanda.poste) << std::endl;
}

// Helper para obtener el nombre del plato (Consigna 1.a)
std::string obtenerNombrePlato(TipoPlato plato) {
    switch (plato) {
        case PRIMER_PLATO: return "Primer Plato";
        case PLATO_PRINCIPAL: return "Plato Principal";
        case POSTRE: return "Postre";
        default: return "Desconocido";
    }
}

// Consigna 1.b: Programa de reservas de avión
void tomarYMostrarReservaAvion() {
    ReservaAvion reserva;
    int opcionClase, opcionOrigen, opcionDestino;

    std::cout << "\n--- Tomar Reserva de Avion ---" << std::endl;
    std::cin.ignore(); // Limpiar el buffer de entrada
    std::cout << "DNI: ";
    std::getline(std::cin, reserva.dni);
    std::cout << "Apellido: ";
    std::getline(std::cin, reserva.apellido);
    std::cout << "Nombre: ";
    std::getline(std::cin, reserva.nombre);

    std::cout << "Seleccione Clase (1:PRIMERA, 2:BUSINESS, 3:ECONOMICA): ";
    std::cin >> opcionClase;
    reserva.clase = static_cast<ClaseVuelo>(opcionClase);

    std::cout << "Seleccione Aeropuerto de Origen:" << std::endl;
    std::cout << "1. Bahia Blanca-BHI" << std::endl;
    std::cout << "2. Buenos Aires Aeroparque-AER" << std::endl;
    std::cout << "3. Buenos Aires El Palomar-EPA" << std::endl;
    std::cout << "4. Buenos Aires Ezeiza-EZE" << std::endl;
    std::cout << "5. San Carlos de Bariloche-BRC" << std::endl;
    std::cout << "6. San Fernando del Valle de Catamarca-CTC" << std::endl;
    std::cout << "7. Comodoro Rivadavia-CRD" << std::endl;
    std::cout << "Opcion: ";
    std::cin >> opcionOrigen;
    reserva.origen = static_cast<CodigoAeropuerto>(opcionOrigen);

    std::cout << "Seleccione Aeropuerto de Destino: ";
    std::cin >> opcionDestino;
    reserva.destino = static_cast<CodigoAeropuerto>(opcionDestino);

    std::cout << "\n--- Informacion de la Reserva ---" << std::endl;
    std::cout << "DNI: " << reserva.dni << std::endl;
    std::cout << "Apellido y Nombre: " << reserva.apellido << ", " << reserva.nombre << std::endl;
    std::cout << "Clase de Vuelo: " << obtenerNombreClaseVuelo(reserva.clase) << std::endl;
    std::cout << "Origen: " << obtenerNombreAeropuerto(reserva.origen) << std::endl;
    std::cout << "Destino: " << obtenerNombreAeropuerto(reserva.destino) << std::endl;
}

// Helper para obtener el nombre de la clase de vuelo (Consigna 1.b)
std::string obtenerNombreClaseVuelo(ClaseVuelo clase) {
    switch (clase) {
        case PRIMERA: return "Primera";
        case BUSINESS: return "Business";
        case ECONOMICA: return "Economica";
        default: return "Desconocida";
    }
}

// Helper para obtener el nombre del aeropuerto (Consigna 1.b)
std::string obtenerNombreAeropuerto(CodigoAeropuerto codigo) {
    switch (codigo) {
        case BAHIA_BLANCA: return "Bahia Blanca-BHI";
        case AEROPARQUE: return "Buenos Aires Aeroparque-AER";
        case EL_PALOMAR: return "Buenos Aires El Palomar-EPA";
        case EZEIZA: return "Buenos Aires Ezeiza-EZE";
        case BARILOCHE: return "San Carlos de Bariloche-BRC";
        case CATAMARCA: return "San Fernando del Valle de Catamarca-CTC";
        case COMODORO_RIVADAVIA: return "Comodoro Rivadavia-CRD";
        default: return "Desconocido";
    }
}

// Consigna 1.c: Pedido de verdulería al mayorista
void tomarYMostrarPedidoVerduleria() {
    PedidoVerduleria pedido;
    int opcionFruta;
    pedido.numFrutasPedidas = 0; // Inicializar el contador de frutas

    std::cout << "\n--- Armar Pedido para Mayorista (Verduleria) ---" << std::endl;
    std::cout << "Codigo de Proveedor: ";
    std::cin >> pedido.codigoProveedor;
    std::cin.ignore(); // Limpiar el buffer de entrada
    std::cout << "Razon Social: ";
    std::getline(std::cin, pedido.razonSocial);
    std::cout << "Fecha de Solicitud (DD/MM/AAAA): ";
    std::getline(std::cin, pedido.fechaSolicitud);
    std::cout << "Fecha de Entrega (DD/MM/AAAA): ";
    std::getline(std::cin, pedido.fechaEntrega);

    std::cout << "Seleccione las frutas a pedir (ingrese 0 para terminar):" << std::endl;
    std::cout << "1. Manzana" << std::endl;
    std::cout << "2. Banana" << std::endl;
    std::cout << "3. Naranja" << std::endl;
    std::cout << "4. Pera" << std::endl;
    std::cout << "5. Uva" << std::endl;
    std::cout << "6. Kiwi" << std::endl;

    while (true) {
        if (pedido.numFrutasPedidas >= MAX_FRUTAS) {
            std::cout << "Se ha alcanzado el limite maximo de frutas (" << MAX_FRUTAS << "). No se pueden agregar mas." << std::endl;
            break;
        }
        std::cout << "Opcion de fruta: ";
        std::cin >> opcionFruta;
        if (opcionFruta == 0) {
            break;
        }
        if (opcionFruta >= 1 && opcionFruta <= 6) {
            pedido.frutasPedidas[pedido.numFrutasPedidas++] = static_cast<Fruta>(opcionFruta);
        } else {
            std::cout << "Opcion invalida. Intente de nuevo." << std::endl;
        }
    }

    std::cout << "\n--- Informacion del Pedido al Mayorista ---" << std::endl;
    std::cout << "Codigo de Proveedor: " << pedido.codigoProveedor << std::endl;
    std::cout << "Razon Social: " << pedido.razonSocial << std::endl;
    std::cout << "Fecha de Solicitud: " << pedido.fechaSolicitud << std::endl;
    std::cout << "Fecha de Entrega: " << pedido.fechaEntrega << std::endl;
    std::cout << "Frutas Pedidas:" << std::endl;
    if (pedido.numFrutasPedidas == 0) {
        std::cout << "  Ninguna fruta seleccionada." << std::endl;
    } else {
        for (int i = 0; i < pedido.numFrutasPedidas; ++i) {
            std::cout << "  - " << obtenerNombreFruta(pedido.frutasPedidas[i]) << std::endl;
        }
    }
}

// Helper para obtener el nombre de la fruta (Consigna 1.c)
std::string obtenerNombreFruta(Fruta fruta) {
    switch (fruta) {
        case MANZANA: return "Manzana";
        case BANANA: return "Banana";
        case NARANJA: return "Naranja";
        case PERA: return "Pera";
        case UVA: return "Uva";
        case KIWI: return "Kiwi";
        default: return "Desconocida";
    }
}

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

// --- Constantes Globales ---
const int MAX_ALUMNOS = 100; // Capacidad máxima fija del array 
const string NOMBRE_ARCHIVO = "Alumnos.txt";

// --- Estructura para los datos del Alumno ---
struct tAlumno {
    int legajo;
    string nombre;
    string carrera;
    int anio;
};

// --- Estructura con memoria estática ---
struct ListaAlumnos {
    tAlumno elementos[MAX_ALUMNOS]; // Array estático con tamaño fijo 
    int cantidad;                  // Contador de elementos en uso 
};

// --- Variables Globales para el Ordenamiento ---
string g_campoOrdenamiento = "legajo";

// --- Sobrecarga de Operadores para tAlumno ---
// bool operator>(tRegistro oplzq, tRegistro opDer); 
bool operator>(const tAlumno& opIzq, const tAlumno& opDer) {
    if (g_campoOrdenamiento == "legajo") return opIzq.legajo > opDer.legajo;
    if (g_campoOrdenamiento == "nombre") return opIzq.nombre > opDer.nombre;
    if (g_campoOrdenamiento == "carrera") return opIzq.carrera > opDer.carrera;
    if (g_campoOrdenamiento == "anio") return opIzq.anio > opDer.anio;
    return false;
}

// bool operator<(tRegistro oplzq, tRegistro opDer);
bool operator<(const tAlumno& opIzq, const tAlumno& opDer) {
    if (g_campoOrdenamiento == "legajo") return opIzq.legajo < opDer.legajo;
    if (g_campoOrdenamiento == "nombre") return opIzq.nombre < opDer.nombre;
    if (g_campoOrdenamiento == "carrera") return opIzq.carrera < opDer.carrera;
    if (g_campoOrdenamiento == "anio") return opIzq.anio < opDer.anio;
    return false;
}

// --- Prototipos de Funciones ---
void cargarAlumnosDesdeArchivo(ListaAlumnos& lista);
void guardarAlumnosEnArchivo(const ListaAlumnos& lista);
void procesarOpciones(ListaAlumnos& lista);
void mostrarMenu();
void mostrarListado(const ListaAlumnos& lista); // a. Mostrar Listado de los Alumnos x pantalla
void insertarAlumno(ListaAlumnos& lista); // c. Insertar un Alumno
int buscarIndicePorLegajo(const ListaAlumnos& lista, int legajo);
void buscarYMostrarAlumno(const ListaAlumnos& lista); // b. Mostrar un Alumno Determinado, f. Buscar un alumno
void eliminarAlumno(ListaAlumnos& lista); // d. Eliminar un Alumno
void ordenarYMostrarAlumnos(ListaAlumnos& lista); // f. Que permita Ordenar de Forma Ascendente y Descendente
void limpiarBufferEntrada();

// --- Función Principal ---
// Mantener el Main lo mas pequeño posible.
int main() {
    ListaAlumnos listaDeAlumnos;
    listaDeAlumnos.cantidad = 0; // Inicializamos el contador

    // Usar Archivo para persistir y recuperar
    cargarAlumnosDesdeArchivo(listaDeAlumnos);

    procesarOpciones(listaDeAlumnos);

    guardarAlumnosEnArchivo(listaDeAlumnos);

    return 0;
}

// --- Implementaciones de Funciones ---

void procesarOpciones(ListaAlumnos& lista) {
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;

        while (cin.fail()) {
            limpiarBufferEntrada();
            cout << "Entrada invalida. Por favor, ingrese un numero: ";
            cin >> opcion;
        }
        limpiarBufferEntrada();

        switch (opcion) {
            case 1: mostrarListado(lista); break;
            case 2: insertarAlumno(lista); break;
            case 3: eliminarAlumno(lista); break;
            case 4: buscarYMostrarAlumno(lista); break;
            case 5: ordenarYMostrarAlumnos(lista); break;
            case 0: cout << "Guardando cambios y saliendo..." << endl; break;
            default: cout << "Opcion no valida. Intente de nuevo." << endl; break;
        }
        if (opcion != 0) {
           cout << "\nPresione Enter para continuar...";
           cin.get();
        }
    } while (opcion != 0);
}

void cargarAlumnosDesdeArchivo(ListaAlumnos& lista) {
    ifstream archivo(NOMBRE_ARCHIVO);
    string linea;

    if (!archivo.is_open()) {
        cout << "Advertencia: No se encontro '" << NOMBRE_ARCHIVO << "'. Se creara al salir." << endl;
        return;
    }

    while (getline(archivo, linea)) {
        if (lista.cantidad >= MAX_ALUMNOS) {
            cerr << "Error: Se alcanzo la capacidad maxima de alumnos (" << MAX_ALUMNOS << "). No se cargaran mas datos." << endl;
            break;
        }
        
        stringstream ss(linea);
        tAlumno& alumnoActual = lista.elementos[lista.cantidad];
        string token;

        getline(ss, token, ','); alumnoActual.legajo = stoi(token);
        getline(ss, token, ','); alumnoActual.nombre = token;
        getline(ss, token, ','); alumnoActual.carrera = token;
        getline(ss, token, ','); alumnoActual.anio = stoi(token);

        lista.cantidad++;
    }
    archivo.close();
    cout << "Se cargaron " << lista.cantidad << " alumnos." << endl;
}

void guardarAlumnosEnArchivo(const ListaAlumnos& lista) {
    ofstream archivo(NOMBRE_ARCHIVO);
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo para guardar." << endl;
        return;
    }
    for (int i = 0; i < lista.cantidad; ++i) {
        archivo << lista.elementos[i].legajo << ","
                << lista.elementos[i].nombre << ","
                << lista.elementos[i].carrera << ","
                << lista.elementos[i].anio << endl;
    }
    archivo.close();
}

void insertarAlumno(ListaAlumnos& lista) {
    if (lista.cantidad >= MAX_ALUMNOS) {
        cout << "\nError: La lista de alumnos esta llena. No se puede agregar otro." << endl;
        return;
    }
    
    tAlumno nuevo;
    cout << "\n--- INSERTAR NUEVO ALUMNO ---" << endl;
    cout << "Ingrese Legajo: ";
    cin >> nuevo.legajo;
    
    if (buscarIndicePorLegajo(lista, nuevo.legajo) != -1) {
        cout << "Error: Ya existe un alumno con ese legajo." << endl;
        limpiarBufferEntrada();
        return;
    }

    limpiarBufferEntrada();
    cout << "Ingrese Nombre Completo: ";
    getline(cin, nuevo.nombre);
    cout << "Ingrese Carrera: ";
    getline(cin, nuevo.carrera);
    cout << "Ingrese Anio: ";
    cin >> nuevo.anio;
    limpiarBufferEntrada();

    lista.elementos[lista.cantidad] = nuevo;
    lista.cantidad++;

    cout << "Alumno insertado correctamente." << endl;
}

int buscarIndicePorLegajo(const ListaAlumnos& lista, int legajo) {
    for (int i = 0; i < lista.cantidad; ++i) {
        if (lista.elementos[i].legajo == legajo) {
            return i;
        }
    }
    return -1;
}

void eliminarAlumno(ListaAlumnos& lista) {
    cout << "\n--- ELIMINAR ALUMNO ---" << endl;
    if (lista.cantidad == 0) {
        cout << "No hay alumnos para eliminar." << endl;
        return;
    }
    int legajo;
    cout << "Ingrese el legajo del alumno a eliminar: ";
    cin >> legajo;
    limpiarBufferEntrada();

    int indice = buscarIndicePorLegajo(lista, legajo);

    if (indice != -1) {
        for (int i = indice; i < lista.cantidad - 1; ++i) {
            lista.elementos[i] = lista.elementos[i + 1];
        }
        lista.cantidad--;
        cout << "Alumno con legajo " << legajo << " eliminado." << endl;
    } else {
        cout << "No se encontro ningun alumno con el legajo " << legajo << "." << endl;
    }
}

// --- Función auxiliar para copiar la lista ---
ListaAlumnos copiarLista(const ListaAlumnos& original) {
    ListaAlumnos copia;
    copia.cantidad = original.cantidad;
    for (int i = 0; i < original.cantidad; ++i) {
        copia.elementos[i] = original.elementos[i];
    }
    return copia;
}

// g. Opcional Que permita elegir el campo de Ordenamiento.
void ordenarYMostrarAlumnos(ListaAlumnos& lista) {
    if (lista.cantidad < 2) {
        cout << "\nNo hay suficientes alumnos para ordenar." << endl;
        return;
    }

    int opcionCampo, opcionOrden;
    cout << "\n--- CONFIGURAR ORDENAMIENTO ---" << endl;
    cout << "Seleccione el campo para ordenar:\n1. Legajo\n2. Nombre\n3. Carrera\n4. Anio" << endl;
    cout << "Opcion: ";
    cin >> opcionCampo;
    switch (opcionCampo) {
        case 1: g_campoOrdenamiento = "legajo"; break;
        case 2: g_campoOrdenamiento = "nombre"; break;
        case 3: g_campoOrdenamiento = "carrera"; break;
        case 4: g_campoOrdenamiento = "anio"; break;
        default: cout << "Opcion invalida. Usando legajo." << endl; g_campoOrdenamiento = "legajo"; break;
    }

    cout << "\nSeleccione el orden:\n1. Ascendente\n2. Descendente" << endl;
    cout << "Opcion: ";
    cin >> opcionOrden;
    limpiarBufferEntrada();

    // Crear una copia de la lista para no modificar el original
    ListaAlumnos listaCopia = copiarLista(lista);

    // Ordenar la copia
    for (int i = 0; i < listaCopia.cantidad - 1; ++i) {
        for (int j = 0; j < listaCopia.cantidad - i - 1; ++j) {
            bool intercambiar = (opcionOrden == 1) ? 
                (listaCopia.elementos[j] > listaCopia.elementos[j+1]) : 
                (listaCopia.elementos[j] < listaCopia.elementos[j+1]);
            if (intercambiar) {
                tAlumno temp = listaCopia.elementos[j];
                listaCopia.elementos[j] = listaCopia.elementos[j+1];
                listaCopia.elementos[j+1] = temp;
            }
        }
    }
    
    cout << "\nListado de alumnos ordenado:" << endl;
    mostrarListado(listaCopia);  // Mostrar la copia ordenada
    cout << "\n(Nota: El orden original se mantiene sin cambios)" << endl;
}

void limpiarBufferEntrada() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void mostrarMenu() {
    system("cls || clear");
    cout << "--- MENU DE GESTION DE ALUMNOS ---" << endl;
    cout << "1. Mostrar listado de Alumnos" << endl;
    cout << "2. Insertar un Alumno" << endl;
    cout << "3. Eliminar un Alumno" << endl;
    cout << "4. Buscar un Alumno por legajo" << endl;
    cout << "5. Ordenar y Mostrar Alumnos" << endl;
    cout << "0. Guardar y Salir" << endl;
    cout << "Ingrese su opcion: ";
}

void mostrarListado(const ListaAlumnos& lista) {
    cout << "\n--- LISTADO DE ALUMNOS (" << lista.cantidad << "/" << MAX_ALUMNOS << ") ---" << endl;
    if (lista.cantidad == 0) {
        cout << "No hay alumnos registrados." << endl;
        return;
    }
    cout << "----------------------------------------------------------" << endl;
    cout << "LEGAJO\tNOMBRE\t\tCARRERA\t\tANIO" << endl;
    cout << "----------------------------------------------------------" << endl;
    for (int i = 0; i < lista.cantidad; ++i) {
        cout << lista.elementos[i].legajo << "\t"
                  << lista.elementos[i].nombre << "\t\t"
                  << lista.elementos[i].carrera << "\t\t"
                  << lista.elementos[i].anio << endl;
    }
    cout << "----------------------------------------------------------" << endl;
}

void buscarYMostrarAlumno(const ListaAlumnos& lista) {
    cout << "\n--- BUSCAR ALUMNO ---" << endl;
    if (lista.cantidad == 0) {
        cout << "No hay alumnos para buscar." << endl;
        return;
    }
    int legajo;
    cout << "Ingrese el legajo del alumno a buscar: ";
    cin >> legajo;
    limpiarBufferEntrada();

    int indice = buscarIndicePorLegajo(lista, legajo);

    if (indice != -1) {
        cout << "Alumno encontrado:" << endl;
        cout << "Legajo: " << lista.elementos[indice].legajo << endl;
        cout << "Nombre: " << lista.elementos[indice].nombre << endl;
        cout << "Carrera: " << lista.elementos[indice].carrera << endl;
        cout << "Anio: " << lista.elementos[indice].anio << endl;
    } else {
        cout << "No se encontro ningun alumno con el legajo " << legajo << "." << endl;
    }
}
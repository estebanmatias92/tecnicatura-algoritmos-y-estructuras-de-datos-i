#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> // Para usar std::swap si es necesario, aunque implementaremos nuestra propia lógica de ordenamiento con el operador
#include <limits>    // Para std::numeric_limits

using namespace std;

// --- Constantes Globales ---
const int MAX_ALUMNOS = 100;
const string NOMBRE_ARCHIVO = "Alumnos.txt";

// --- Estructura para el Registro del Alumno ---
struct tRegistro {
    int legajo;
    string nombre;
    string carrera;
    int anio; // Año de cursada

    // Constructor por defecto
    tRegistro() : legajo(0), nombre(""), carrera(""), anio(0) {}
    
    // Constructor con parámetros
    tRegistro(int l, const string& n, const string& c, int a)
        : legajo(l), nombre(n), carrera(c), anio(a) {}
};

// --- Array y Contador Globales ---
// Aunque se recomienda evitar variables globales, para esta primera iteración monolítica
// y cumpliendo con "contador y _arrays_ (max 100 alumnos)" los manejaremos de esta forma.
tRegistro listaAlumnos[MAX_ALUMNOS];
int contadorAlumnos = 0; // Cantidad actual de alumnos en el array

// ----------------------------------------------------------------------------------
// --- Sobrecarga de Operadores de Comparación (Punto 3 de las Consideraciones) ---
// La comparación se basará en el Legajo del alumno por simplicidad,
// ya que el punto opcional (elegir campo) se abordaría en la modularización avanzada.

/**
 * @brief Sobrecarga del operador > (mayor que) para comparar dos registros.
 * @param opIzq Operando Izquierdo.
 * @param opDer Operando Derecho.
 * @return true si el Legajo del opIzq es mayor que el del opDer, false en caso contrario.
 */
bool operator>(const tRegistro& opIzq, const tRegistro& opDer) {
    return opIzq.legajo > opDer.legajo;
}

/**
 * @brief Sobrecarga del operador < (menor que) para comparar dos registros.
 * @param opIzq Operando Izquierdo.
 * @param opDer Operando Derecho.
 * @return true si el Legajo del opIzq es menor que el del opDer, false en caso contrario.
 */
bool operator<(const tRegistro& opIzq, const tRegistro& opDer) {
    return opIzq.legajo < opDer.legajo;
}
// ----------------------------------------------------------------------------------


// ----------------------------------------------------------------------------------
// --- Funciones de Persistencia (Punto 1 y 4 de las Consideraciones) ---

/**
 * @brief Carga los datos de los alumnos desde el archivo al array global.
 */
void cargarDesdeArchivo() {
    ifstream archivo(NOMBRE_ARCHIVO);
    contadorAlumnos = 0;
    
    if (archivo.is_open()) {
        while (contadorAlumnos < MAX_ALUMNOS && 
               archivo >> listaAlumnos[contadorAlumnos].legajo &&
               archivo.ignore() >> listaAlumnos[contadorAlumnos].nombre && // Se usa ignore() si se leyó un int para luego leer string
               archivo >> listaAlumnos[contadorAlumnos].carrera &&
               archivo >> listaAlumnos[contadorAlumnos].anio) {
            
            contadorAlumnos++;
        }
        cout << "✅ Datos cargados exitosamente (" << contadorAlumnos << " alumnos).\n";
        archivo.close();
    } else {
        cout << "⚠️ Archivo '" << NOMBRE_ARCHIVO << "' no encontrado. Se iniciará con lista vacía.\n";
    }
}

/**
 * @brief Guarda los datos de los alumnos del array global al archivo.
 */
void guardarEnArchivo() {
    ofstream archivo(NOMBRE_ARCHIVO);

    if (archivo.is_open()) {
        for (int i = 0; i < contadorAlumnos; ++i) {
            // Formato de guardado: Legajo Nombre Carrera Año
            archivo << listaAlumnos[i].legajo << " "
                    << listaAlumnos[i].nombre << " "
                    << listaAlumnos[i].carrera << " "
                    << listaAlumnos[i].anio << "\n";
        }
        cout << "✅ Datos guardados exitosamente en '" << NOMBRE_ARCHIVO << "'.\n";
        archivo.close();
    } else {
        cout << "❌ Error: No se pudo abrir/crear el archivo para guardar.\n";
    }
}

// ----------------------------------------------------------------------------------
// --- Funciones de Utilidad y Tareas (Puntos a-g) ---

/**
 * @brief Muestra los datos de un único alumno.
 * @param alumno El registro del alumno a mostrar.
 */
void mostrarAlumno(const tRegistro& alumno) {
    cout << "---------------------------------\n";
    cout << "  Legajo: " << alumno.legajo << "\n";
    cout << "  Nombre: " << alumno.nombre << "\n";
    cout << "  Carrera: " << alumno.carrera << "\n";
    cout << "  Año: " << alumno.anio << "\n";
    cout << "---------------------------------\n";
}

// Tarea a. Mostrar Listado de los Alumnos x pantalla
void mostrarListado() {
    if (contadorAlumnos == 0) {
        cout << "\nℹ️ La lista de alumnos está vacía.\n";
        return;
    }

    cout << "\n=========================================\n";
    cout << "       LISTADO DE ALUMNOS (Total: " << contadorAlumnos << ")\n";
    cout << "=========================================\n";
    for (int i = 0; i < contadorAlumnos; ++i) {
        cout << i + 1 << ". Legajo: " << listaAlumnos[i].legajo
             << ", Nombre: " << listaAlumnos[i].nombre
             << ", Carrera: " << listaAlumnos[i].carrera
             << ", Año: " << listaAlumnos[i].anio << "\n";
    }
    cout << "=========================================\n";
}

/**
 * @brief Busca la posición de un alumno por legajo.
 * @param legajo El legajo a buscar.
 * @return El índice del alumno en el array, o -1 si no se encuentra.
 */
int buscarAlumnoPorLegajo(int legajo) {
    for (int i = 0; i < contadorAlumnos; ++i) {
        if (listaAlumnos[i].legajo == legajo) {
            return i;
        }
    }
    return -1;
}

// Tarea b. y e. Mostrar un Alumno Determinado y Buscar un alumno
void buscarYMostrarAlumno() {
    int legajoBusqueda;
    cout << "\nIngrese el Legajo del alumno a buscar: ";
    if (!(cin >> legajoBusqueda)) {
        cout << "❌ Entrada inválida. Intente de nuevo.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    int indice = buscarAlumnoPorLegajo(legajoBusqueda);

    if (indice != -1) {
        cout << "\n✅ Alumno Encontrado:\n";
        mostrarAlumno(listaAlumnos[indice]);
    } else {
        cout << "\n❌ Alumno con Legajo " << legajoBusqueda << " NO encontrado.\n";
    }
}

// Tarea c. Insertar un Alumno
void insertarAlumno() {
    if (contadorAlumnos >= MAX_ALUMNOS) {
        cout << "\n❌ Error: La lista de alumnos está llena (Máximo " << MAX_ALUMNOS << ").\n";
        return;
    }

    tRegistro nuevoAlumno;
    
    // 1. Pedir Legajo y validar que no exista
    int legajoIngresado;
    bool legajoExistente = true;
    while (legajoExistente) {
        cout << "\nIngrese Legajo (entero): ";
        if (!(cin >> legajoIngresado)) {
            cout << "❌ Entrada inválida. Intente de nuevo.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        
        if (buscarAlumnoPorLegajo(legajoIngresado) == -1) {
            legajoExistente = false;
        } else {
            cout << "❌ Error: Ya existe un alumno con ese Legajo. Ingrese otro.\n";
        }
    }
    nuevoAlumno.legajo = legajoIngresado;
    
    // Limpiar buffer para leer strings
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    // 2. Pedir Nombre
    cout << "Ingrese Nombre: ";
    getline(cin, nuevoAlumno.nombre);

    // 3. Pedir Carrera
    cout << "Ingrese Carrera: ";
    getline(cin, nuevoAlumno.carrera);

    // 4. Pedir Año
    cout << "Ingrese Año de Cursada (entero): ";
    while (!(cin >> nuevoAlumno.anio)) {
        cout << "❌ Entrada inválida. Ingrese un número para el Año: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    // 5. Insertar y actualizar contador
    listaAlumnos[contadorAlumnos] = nuevoAlumno;
    contadorAlumnos++;
    cout << "\n✅ Alumno insertado exitosamente! No olvide guardar los cambios.\n";
}

// Tarea d. Eliminar un Alumno
void eliminarAlumno() {
    if (contadorAlumnos == 0) {
        cout << "\nℹ️ La lista está vacía, no hay alumnos para eliminar.\n";
        return;
    }

    int legajoEliminar;
    cout << "\nIngrese el Legajo del alumno a eliminar: ";
    if (!(cin >> legajoEliminar)) {
        cout << "❌ Entrada inválida. Intente de nuevo.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    int indice = buscarAlumnoPorLegajo(legajoEliminar);

    if (indice != -1) {
        // Mover el último elemento a la posición del eliminado
        listaAlumnos[indice] = listaAlumnos[contadorAlumnos - 1];
        // Decrementar el contador
        contadorAlumnos--;
        cout << "\n✅ Alumno con Legajo " << legajoEliminar << " ELIMINADO exitosamente! No olvide guardar los cambios.\n";
    } else {
        cout << "\n❌ Alumno con Legajo " << legajoEliminar << " NO encontrado. No se puede eliminar.\n";
    }
}


/**
 * @brief Implementa el algoritmo de ordenamiento por burbuja (Bubble Sort).
 * @param ascendente true para orden ascendente (usando <), false para descendente (usando >).
 */
void ordenarAlumnos(bool ascendente) {
    if (contadorAlumnos <= 1) return;

    // Usaremos Bubble Sort por simplicidad para la primera iteración
    for (int i = 0; i < contadorAlumnos - 1; ++i) {
        for (int j = 0; j < contadorAlumnos - 1 - i; ++j) {
            
            bool debeIntercambiar = false;

            if (ascendente) {
                // Orden ascendente: si el actual es mayor que el siguiente, se intercambia.
                // Usando el operador > sobrecargado (compara Legajo)
                if (listaAlumnos[j] > listaAlumnos[j+1]) { 
                    debeIntercambiar = true;
                }
            } else {
                // Orden descendente: si el actual es menor que el siguiente, se intercambia.
                // Usando el operador < sobrecargado (compara Legajo)
                if (listaAlumnos[j] < listaAlumnos[j+1]) { 
                    debeIntercambiar = true;
                }
            }

            if (debeIntercambiar) {
                // Intercambio de registros
                tRegistro temp = listaAlumnos[j];
                listaAlumnos[j] = listaAlumnos[j+1];
                listaAlumnos[j+1] = temp;
            }
        }
    }
}

// Tarea f. Que permita Ordenar de Forma Ascendente y Descendente los Alumnos y Mostrarlos x pantalla
void ordenarYMostrar() {
    if (contadorAlumnos == 0) {
        cout << "\nℹ️ La lista está vacía, no hay alumnos para ordenar.\n";
        return;
    }

    int opcion;
    cout << "\n--- Opciones de Ordenamiento (por Legajo) ---\n";
    cout << "1. Orden Ascendente\n";
    cout << "2. Orden Descendente\n";
    cout << "Ingrese su opción: ";

    if (!(cin >> opcion) || (opcion != 1 && opcion != 2)) {
        cout << "❌ Opción inválida. Volviendo al menú principal.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    bool ascendente = (opcion == 1);
    ordenarAlumnos(ascendente);

    cout << "\n✅ Lista ordenada (" << (ascendente ? "Ascendente" : "Descendente") << ").\n";
    mostrarListado();
}

// ----------------------------------------------------------------------------------
// --- Función del Menú Principal y Loop ---

/**
 * @brief Muestra el menú principal y pide la opción al usuario.
 * @return La opción elegida (entero).
 */
int mostrarMenu() {
    int opcion;
    cout << "\n\n======== MENU ADMINISTRACION DE ALUMNOS ========\n";
    cout << "1. Mostrar Listado de Alumnos (a)\n";
    cout << "2. Buscar y Mostrar un Alumno (b, e)\n";
    cout << "3. Insertar un Nuevo Alumno (c)\n";
    cout << "4. Eliminar un Alumno (d)\n";
    cout << "5. Ordenar y Mostrar Listado (f, g - Ordena por Legajo)\n";
    cout << "------------------------------------------------\n";
    cout << "6. Guardar Cambios en Archivo\n";
    cout << "0. Salir (Guardar y Salir)\n";
    cout << "================================================\n";
    cout << "Ingrese su opcion: ";

    if (!(cin >> opcion)) {
        // Manejo de error si la entrada no es un número
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1; // Retorna un valor que indicará un error
    }
    return opcion;
}

// ----------------------------------------------------------------------------------
// --- Función Main (Punto 5: Mantener el Main lo mas pequeño posible) ---

int main() {
    // 1. Cargar datos iniciales
    cargarDesdeArchivo();

    int opcion;
    
    // 2. Bucle principal del programa
    do {
        opcion = mostrarMenu(); // Mostrar menú y obtener opción

        switch (opcion) {
            case 1:
                mostrarListado();
                break;
            case 2:
                buscarYMostrarAlumno(); // Cubre b y e
                break;
            case 3:
                insertarAlumno();
                break;
            case 4:
                eliminarAlumno();
                break;
            case 5:
                ordenarYMostrar(); // Cubre f y g (por defecto Legajo)
                break;
            case 6:
                guardarEnArchivo();
                break;
            case 0:
                // Tarea de salida: Guardar y terminar
                guardarEnArchivo();
                cout << "\n👋 Programa finalizado. ¡Hasta pronto!\n";
                break;
            default:
                if (opcion != -1) { // -1 es para errores de entrada no numérica
                    cout << "❌ Opción inválida. Por favor, ingrese un número del 0 al 6.\n";
                }
                break;
        }

    } while (opcion != 0);

    return 0;
}
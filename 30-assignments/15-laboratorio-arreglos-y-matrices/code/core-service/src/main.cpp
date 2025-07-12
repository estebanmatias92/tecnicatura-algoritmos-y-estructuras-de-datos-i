#include <iostream> // Para entrada y salida (cin, cout)
#include <fstream>  // Para manejo de archivos (ifstream, ofstream)
#include <string>   // Para usar std::string
#include <limits>   // Para std::numeric_limits
#include <sstream>  // Para std::stringstream
#include <iomanip>  // Para formatear la salida (setw, fixed, setprecision)
#include <algorithm> // Para std::min

// --- Constantes ---
#define MAX_PRODUCTOS 100 // Máximo número de productos en el almacén
#define MAX_PALABRAS_FRASE 50 // Máximo número de palabras en una frase para el array
#define MAX_LONGITUD_PALABRA 50 // Máxima longitud de una palabra
#define MAX_MATRIX_SIZE 3 // Tamaño máximo para las matrices (NxN, por ejemplo 3x3)

// --- Definición de tipos con typedef ---

// Consigna 1.a: Declarar tipo tProducto
typedef struct {
    int id;
    double precio;
    int unidades;
} tProducto;

// Consigna 1.a: Declarar tipo tLista
typedef struct {
    tProducto productos[MAX_PRODUCTOS];
    int cantidad; // Número actual de productos en la lista
} tListaProductos;

// Consigna 2: Para almacenar palabras y sus longitudes
typedef struct {
    char palabra[MAX_LONGITUD_PALABRA];
    int longitud;
} tPalabraInfo;

// Consigna 3: Para matrices
typedef double tMatriz[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];


// --- Prototipos de Funciones ---

// Consigna 1: Gestión de Productos en Almacén
// Consigna 1.b: Leer datos del archivo, guardar en lista y mostrar
void leerProductosDesdeArchivo(const char* nombreArchivo, tListaProductos* lista);
void mostrarProductos(const tListaProductos* lista);
// Consigna 1.c: Encontrar producto con máximo valor
tProducto encontrarProductoMaxValor(const tListaProductos* lista);
// Consigna 1.d: Eliminar producto por identificador
void eliminarProducto(tListaProductos* lista, int idAEliminar);
// Nueva funcionalidad: Añadir producto al archivo
void agregarProductoAArchivo(const char* nombreArchivo, int id, double precio, int unidades);

// Consigna 2: Análisis de Frases
void analizarFrase();

// Consigna 3: Operaciones sobre Matrices NxN
// Subprograma para leer una matriz
void leerMatriz(tMatriz matriz, int N);
// Subprograma para mostrar una matriz
void mostrarMatriz(const tMatriz matriz, int N);
// Consigna 3.a: Sumar 2 matrices
void sumarMatrices(const tMatriz mat1, const tMatriz mat2, tMatriz resultado, int N);
// Consigna 3.b: Restar 2 matrices
void restarMatrices(const tMatriz mat1, const tMatriz mat2, tMatriz resultado, int N);
// Consigna 3.c: Multiplicar 2 matrices
void multiplicarMatrices(const tMatriz mat1, const tMatriz mat2, tMatriz resultado, int N);
// Consigna 3.d: Trasponer una matriz
void trasponerMatriz(const tMatriz original, tMatriz traspuesta, int N);
// Consigna 3.e: Mostrar puntos de silla
void encontrarPuntosSilla(const tMatriz matriz, int N);


int main() {
    int opcion;
    const char* NOMBRE_ARCHIVO_PRODUCTOS = "productos.txt";

    // Crear un archivo de prueba para la Consigna 1 si no existe
    std::ofstream archivoTest(NOMBRE_ARCHIVO_PRODUCTOS, std::ios::app);
    if (archivoTest.is_open()) {
        archivoTest.close();
    }

    do {
        std::cout << "\n--- MENU PRINCIPAL - TP Unidad 5 ---" << std::endl;
        std::cout << "1. Gestion de Productos en Almacen" << std::endl;
        std::cout << "2. Analisis de Frases" << std::endl;
        std::cout << "3. Operaciones sobre Matrices" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;

        // Limpiar el buffer de entrada después de leer un entero
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcion) {
            case 1: { // Consigna 1: Gestión de Productos en Almacén
                tListaProductos miLista;
                miLista.cantidad = 0; // Inicializar la cantidad de productos
                int subOpcion1;
                do {
                    std::cout << "\n--- Gestion de Productos ---" << std::endl;
                    std::cout << "1. Leer y mostrar productos desde archivo" << std::endl;
                    std::cout << "2. Encontrar producto con maximo valor" << std::endl;
                    std::cout << "3. Eliminar producto por ID" << std::endl;
                    std::cout << "4. Agregar nuevo producto al archivo" << std::endl; // Nueva opción
                    std::cout << "0. Volver al Menu Principal" << std::endl;
                    std::cout << "Ingrese su opcion: ";
                    std::cin >> subOpcion1;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar buffer

                    switch (subOpcion1) {
                        case 1: // Consigna 1.b: Leer y mostrar productos
                            leerProductosDesdeArchivo(NOMBRE_ARCHIVO_PRODUCTOS, &miLista);
                            mostrarProductos(&miLista);
                            break;
                        case 2: { // Consigna 1.c: Encontrar producto con máximo valor
                            if (miLista.cantidad > 0) {
                                tProducto productoMax = encontrarProductoMaxValor(&miLista);
                                std::cout << "\nProducto con maximo valor:" << std::endl;
                                std::cout << "  ID: " << productoMax.id
                                          << ", Precio: " << std::fixed << std::setprecision(2) << productoMax.precio
                                          << ", Unidades: " << productoMax.unidades
                                          << ", Valor Total: " << std::fixed << std::setprecision(2) << (productoMax.precio * productoMax.unidades) << std::endl;
                            } else {
                                std::cout << "La lista de productos esta vacia." << std::endl;
                            }
                            break;
                        }
                        case 3: { // Consigna 1.d: Eliminar producto por identificador
                            if (miLista.cantidad > 0) {
                                int idEliminar;
                                std::cout << "Ingrese el ID del producto a eliminar: ";
                                std::cin >> idEliminar;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar buffer
                                eliminarProducto(&miLista, idEliminar);
                                std::cout << "Lista de productos despues de la eliminacion:" << std::endl;
                                mostrarProductos(&miLista);
                            } else {
                                std::cout << "La lista de productos esta vacia." << std::endl;
                            }
                            break;
                        }
                        case 4: { // Nueva funcionalidad: Agregar producto al archivo
                            int idNuevo;
                            double precioNuevo;
                            int unidadesNuevas;
                            std::cout << "\n--- Agregar Nuevo Producto ---" << std::endl;
                            std::cout << "Ingrese ID del producto: ";
                            std::cin >> idNuevo;
                            std::cout << "Ingrese Precio del producto: ";
                            std::cin >> precioNuevo;
                            std::cout << "Ingrese Unidades del producto: ";
                            std::cin >> unidadesNuevas;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar buffer
                            agregarProductoAArchivo(NOMBRE_ARCHIVO_PRODUCTOS, idNuevo, precioNuevo, unidadesNuevas);
                            break;
                        }
                        case 0:
                            std::cout << "Volviendo al Menu Principal." << std::endl;
                            break;
                        default:
                            std::cout << "Opcion invalida. Intente de nuevo." << std::endl;
                            break;
                    }
                } while (subOpcion1 != 0);
                break;
            }
            case 2: { // Consigna 2: Análisis de Frases
                analizarFrase();
                break;
            }
            case 3: { // Consigna 3: Operaciones sobre Matrices NxN
                tMatriz matA, matB, matResultado;
                int N_matrix = MAX_MATRIX_SIZE; // Usamos el tamaño máximo definido
                int subOpcion3;

                do {
                    std::cout << "\n--- Operaciones sobre Matrices (" << N_matrix << "x" << N_matrix << ") ---" << std::endl;
                    std::cout << "1. Leer Matriz A" << std::endl;
                    std::cout << "2. Leer Matriz B" << std::endl;
                    std::cout << "3. Mostrar Matriz A" << std::endl;
                    std::cout << "4. Mostrar Matriz B" << std::endl;
                    std::cout << "5. Sumar Matrices (A + B)" << std::endl;
                    std::cout << "6. Restar Matrices (A - B)" << std::endl;
                    std::cout << "7. Multiplicar Matrices (A * B)" << std::endl;
                    std::cout << "8. Trasponer Matriz A" << std::endl;
                    std::cout << "9. Encontrar Puntos de Silla en Matriz A" << std::endl;
                    std::cout << "0. Volver al Menu Principal" << std::endl;
                    std::cout << "Ingrese su opcion: ";
                    std::cin >> subOpcion3;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar buffer

                    switch (subOpcion3) {
                        case 1:
                            std::cout << "\n--- Leer Matriz A ---" << std::endl;
                            leerMatriz(matA, N_matrix);
                            break;
                        case 2:
                            std::cout << "\n--- Leer Matriz B ---" << std::endl;
                            leerMatriz(matB, N_matrix);
                            break;
                        case 3:
                            std::cout << "\n--- Matriz A ---" << std::endl;
                            mostrarMatriz(matA, N_matrix);
                            break;
                        case 4:
                            std::cout << "\n--- Matriz B ---" << std::endl;
                            mostrarMatriz(matB, N_matrix);
                            break;
                        case 5: // Consigna 3.a: Sumar 2 matrices
                            std::cout << "\n--- Suma de Matrices (A + B) ---" << std::endl;
                            sumarMatrices(matA, matB, matResultado, N_matrix);
                            mostrarMatriz(matResultado, N_matrix);
                            break;
                        case 6: // Consigna 3.b: Restar 2 matrices
                            std::cout << "\n--- Resta de Matrices (A - B) ---" << std::endl;
                            restarMatrices(matA, matB, matResultado, N_matrix);
                            mostrarMatriz(matResultado, N_matrix);
                            break;
                        case 7: // Consigna 3.c: Multiplicar 2 matrices
                            std::cout << "\n--- Multiplicacion de Matrices (A * B) ---" << std::endl;
                            multiplicarMatrices(matA, matB, matResultado, N_matrix);
                            mostrarMatriz(matResultado, N_matrix);
                            break;
                        case 8: { // Consigna 3.d: Trasponer una matriz
                            tMatriz matTraspuesta;
                            std::cout << "\n--- Transpuesta de Matriz A ---" << std::endl;
                            trasponerMatriz(matA, matTraspuesta, N_matrix);
                            mostrarMatriz(matTraspuesta, N_matrix);
                            break;
                        }
                        case 9: // Consigna 3.e: Mostrar puntos de silla
                            std::cout << "\n--- Puntos de Silla en Matriz A ---" << std::endl;
                            encontrarPuntosSilla(matA, N_matrix);
                            break;
                        case 0:
                            std::cout << "Volviendo al Menu Principal." << std::endl;
                            break;
                        default:
                            std::cout << "Opcion invalida. Intente de nuevo." << std::endl;
                            break;
                    }
                } while (subOpcion3 != 0);
                break;
            }
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

// Consigna 1: Gestión de Productos en Almacén

// Consigna 1.b: Leer datos del archivo, guardar en lista y mostrar
void leerProductosDesdeArchivo(const char* nombreArchivo, tListaProductos* lista) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << " para lectura." << std::endl;
        lista->cantidad = 0; // Asegurarse de que la lista esté vacía en caso de error
        return;
    }

    lista->cantidad = 0; // Reiniciar la lista antes de leer
    int id;
    double precio;
    int unidades;

    while (archivo >> id && id != -1 && lista->cantidad < MAX_PRODUCTOS) {
        archivo >> precio >> unidades;
        lista->productos[lista->cantidad].id = id;
        lista->productos[lista->cantidad].precio = precio;
        lista->productos[lista->cantidad].unidades = unidades;
        lista->cantidad++;
    }
    archivo.close();
    std::cout << "Productos cargados desde " << nombreArchivo << std::endl;
}

void mostrarProductos(const tListaProductos* lista) {
    if (lista->cantidad == 0) {
        std::cout << "No hay productos para mostrar." << std::endl;
        return;
    }
    std::cout << "\n--- Lista de Productos ---" << std::endl;
    std::cout << std::setw(5) << "ID" << std::setw(10) << "Precio" << std::setw(10) << "Unidades" << std::endl;
    std::cout << "---------------------------" << std::endl;
    for (int i = 0; i < lista->cantidad; ++i) {
        std::cout << std::setw(5) << lista->productos[i].id
                  << std::setw(10) << std::fixed << std::setprecision(2) << lista->productos[i].precio
                  << std::setw(10) << lista->productos[i].unidades << std::endl;
    }
    std::cout << "---------------------------" << std::endl;
}

// Consigna 1.c: Encontrar producto con máximo valor
tProducto encontrarProductoMaxValor(const tListaProductos* lista) {
    tProducto productoMax;
    if (lista->cantidad == 0) {
        productoMax.id = -1; // Indicar que no se encontró ningún producto
        return productoMax;
    }

    double maxValor = -1.0; // Inicializar con un valor muy bajo
    int indiceMax = -1;

    for (int i = 0; i < lista->cantidad; ++i) {
        double valorActual = lista->productos[i].precio * lista->productos[i].unidades;
        if (valorActual > maxValor) {
            maxValor = valorActual;
            indiceMax = i;
        }
    }
    return lista->productos[indiceMax];
}

// Consigna 1.d: Eliminar producto por identificador
void eliminarProducto(tListaProductos* lista, int idAEliminar) {
    int indiceEncontrado = -1;
    for (int i = 0; i < lista->cantidad; ++i) {
        if (lista->productos[i].id == idAEliminar) {
            indiceEncontrado = i;
            break;
        }
    }

    if (indiceEncontrado != -1) {
        // Desplazar los elementos restantes
        for (int i = indiceEncontrado; i < lista->cantidad - 1; ++i) {
            lista->productos[i] = lista->productos[i + 1];
        }
        lista->cantidad--; // Decrementar la cantidad de productos
        std::cout << "Producto con ID " << idAEliminar << " eliminado exitosamente." << std::endl;
    } else {
        std::cout << "Producto con ID " << idAEliminar << " no encontrado." << std::endl;
    }
}

// Nueva funcionalidad: Añadir producto al archivo
void agregarProductoAArchivo(const char* nombreArchivo, int id, double precio, int unidades) {
    std::ofstream archivo(nombreArchivo, std::ios::app); // Abrir en modo append
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << " para escritura." << std::endl;
        return;
    }

    // Escribir el nuevo producto en el formato especificado: id precio unidades
    archivo << id << " " << precio << " " << unidades << std::endl;
    archivo.close();
    std::cout << "Producto agregado al archivo " << nombreArchivo << " exitosamente." << std::endl;
}


// Consigna 2: Análisis de Frases
void analizarFrase() {
    std::string fraseCompleta;
    std::cout << "\n--- Analisis de Frase ---" << std::endl;
    std::cout << "Ingrese una frase: ";
    std::getline(std::cin, fraseCompleta);

    std::stringstream ss(fraseCompleta);
    std::string palabraStr;
    tPalabraInfo palabras[MAX_PALABRAS_FRASE];
    int numPalabras = 0;

    std::cout << "\nPalabras y su longitud:" << std::endl;
    while (ss >> palabraStr && numPalabras < MAX_PALABRAS_FRASE) {
        // Copiar la palabra a un array de char (limitado por MAX_LONGITUD_PALABRA)
        for (int i = 0; i < palabraStr.length() && i < MAX_LONGITUD_PALABRA - 1; ++i) {
            palabras[numPalabras].palabra[i] = palabraStr[i];
        }
        palabras[numPalabras].palabra[std::min((int)palabraStr.length(), MAX_LONGITUD_PALABRA - 1)] = '\0'; // Null-terminate

        palabras[numPalabras].longitud = palabraStr.length();
        std::cout << palabras[numPalabras].palabra << " (" << palabras[numPalabras].longitud << " letras)" << std::endl;
        numPalabras++;
    }
    if (numPalabras >= MAX_PALABRAS_FRASE) {
        std::cout << "Advertencia: Se alcanzo el limite de palabras a procesar (" << MAX_PALABRAS_FRASE << ")." << std::endl;
    }
}

// Consigna 3: Operaciones sobre Matrices NxN

// Subprograma para leer una matriz
void leerMatriz(tMatriz matriz, int N) {
    std::cout << "Ingrese los elementos de la matriz (" << N << "x" << N << "):" << std::endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << "Elemento [" << i << "][" << j << "]: ";
            std::cin >> matriz[i][j];
        }
    }
}

// Subprograma para mostrar una matriz
void mostrarMatriz(const tMatriz matriz, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << std::setw(8) << std::fixed << std::setprecision(2) << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Consigna 3.a: Sumar 2 matrices
void sumarMatrices(const tMatriz mat1, const tMatriz mat2, tMatriz resultado, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            resultado[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// Consigna 3.b: Restar 2 matrices
void restarMatrices(const tMatriz mat1, const tMatriz mat2, tMatriz resultado, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            resultado[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

// Consigna 3.c: Multiplicar 2 matrices
void multiplicarMatrices(const tMatriz mat1, const tMatriz mat2, tMatriz resultado, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            resultado[i][j] = 0; // Inicializar el elemento
            for (int k = 0; k < N; ++k) {
                resultado[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// Consigna 3.d: Trasponer una matriz
void trasponerMatriz(const tMatriz original, tMatriz traspuesta, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            traspuesta[j][i] = original[i][j];
        }
    }
}

// Consigna 3.e: Mostrar puntos de silla
void encontrarPuntosSilla(const tMatriz matriz, int N) {
    bool encontrado = false;
    for (int i = 0; i < N; ++i) {
        // Encontrar el mínimo de la fila
        double minFila = matriz[i][0];
        int colMin = 0;
        for (int j = 1; j < N; ++j) {
            if (matriz[i][j] < minFila) {
                minFila = matriz[i][j];
                colMin = j;
            }
        }

        // Verificar si ese mínimo es también el máximo de su columna
        bool esMaxColumna = true;
        for (int k = 0; k < N; ++k) {
            if (matriz[k][colMin] > minFila) {
                esMaxColumna = false;
                break;
            }
        }

        if (esMaxColumna) {
            std::cout << "Punto de silla encontrado en [" << i << "][" << colMin << "] con valor " << matriz[i][colMin] << std::endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        std::cout << "No se encontraron puntos de silla en la matriz." << std::endl;
    }
}

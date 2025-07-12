#include <iostream> // Para entrada y salida (cin, cout)
#include <fstream>  // Para manejo de archivos (ifstream, ofstream)
#include <string>   // Para usar std::string
#include <limits>   // Para std::numeric_limits
#include <sstream>  // Para std::stringstream

// --- Definición de tipos con typedef ---
typedef std::string Frase;
typedef std::string NombreArchivo;

// --- Prototipos de Funciones ---

// Consigna 1.a: Guardar frases en un archivo
void guardarFrasesEnArchivo(const NombreArchivo& nombreArchivo);

// Consigna 1.b: Abrir y mostrar frases del archivo
void mostrarFrasesDeArchivo(const NombreArchivo& nombreArchivo);

// Consigna 1.c: Contar palabras por línea, total y promedio
void contarPalabrasEnArchivo(const NombreArchivo& nombreArchivo);

// Consigna 1.d: Encontrar la palabra más larga en el archivo
void encontrarPalabraMasLarga(const NombreArchivo& nombreArchivo);


int main() {
    int opcion;
    const NombreArchivo FILE_NAME = "frasesDeBjarne.txt";

    do {
        std::cout << "\n--- MENU PRINCIPAL - TP Unidad 4.1 (Archivos) ---" << std::endl;
        std::cout << "1. Guardar frases en el archivo" << std::endl;
        std::cout << "2. Mostrar frases del archivo" << std::endl;
        std::cout << "3. Contar palabras y promedio en el archivo" << std::endl;
        std::cout << "4. Encontrar la palabra mas larga en el archivo" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;

        // Limpiar el buffer de entrada después de leer un entero
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcion) {
            case 1: // Consigna 1.a: Guardar frases en un archivo
                guardarFrasesEnArchivo(FILE_NAME);
                break;
            case 2: // Consigna 1.b: Abrir y mostrar frases del archivo
                mostrarFrasesDeArchivo(FILE_NAME);
                break;
            case 3: // Consigna 1.c: Contar palabras por línea, total y promedio
                contarPalabrasEnArchivo(FILE_NAME);
                break;
            case 4: // Consigna 1.d: Encontrar la palabra más larga en el archivo
                encontrarPalabraMasLarga(FILE_NAME);
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

// Consigna 1.a: Guardar frases en un archivo
void guardarFrasesEnArchivo(const NombreArchivo& nombreArchivo) {
    std::ofstream archivo(nombreArchivo, std::ios::app); // Abrir en modo append
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << " para escritura." << std::endl;
        return;
    }

    Frase frase;
    std::cout << "\n--- Guardar frases (escriba 'fin' para terminar) ---" << std::endl;
    while (true) {
        std::cout << "Ingrese una frase: ";
        std::getline(std::cin, frase);
        if (frase == "fin") {
            break;
        }
        archivo << frase << std::endl;
    }
    archivo.close();
    std::cout << "Frases guardadas en " << nombreArchivo << std::endl;
}

// Consigna 1.b: Abrir y mostrar frases del archivo
void mostrarFrasesDeArchivo(const NombreArchivo& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << " para lectura." << std::endl;
        return;
    }

    Frase frase;
    std::cout << "\n--- Frases en el archivo " << nombreArchivo << " ---" << std::endl;
    while (std::getline(archivo, frase)) {
        std::cout << frase << std::endl; // Cada frase en una línea
        std::cout << std::endl;          // Interlineado
    }
    archivo.close();
}

// Consigna 1.c: Contar palabras por línea, total y promedio
void contarPalabrasEnArchivo(const NombreArchivo& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << " para lectura." << std::endl;
        return;
    }

    Frase linea;
    int totalLineas = 0;
    int totalPalabras = 0;

    std::cout << "\n--- Conteo de palabras en " << nombreArchivo << " ---" << std::endl;
    while (std::getline(archivo, linea)) {
        totalLineas++;
        std::stringstream ss(linea);
        std::string palabra;
        int palabrasPorLinea = 0;
        while (ss >> palabra) {
            palabrasPorLinea++;
        }
        std::cout << "Linea " << totalLineas << ": " << palabrasPorLinea << " palabras." << std::endl;
        totalPalabras += palabrasPorLinea;
    }
    archivo.close();

    std::cout << "\nCantidad total de palabras: " << totalPalabras << std::endl;
    if (totalLineas > 0) {
        std::cout << "Promedio de palabras por linea: " << static_cast<double>(totalPalabras) / totalLineas << std::endl;
    } else {
        std::cout << "El archivo esta vacio, no se puede calcular el promedio." << std::endl;
    }
}

// Consigna 1.d: Encontrar la palabra más larga en el archivo
void encontrarPalabraMasLarga(const NombreArchivo& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << " para lectura." << std::endl;
        return;
    }

    std::string palabraMasLarga = "";
    std::string linea;

    std::cout << "\n--- Buscando la palabra mas larga en " << nombreArchivo << " ---" << std::endl;
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string palabra;
        while (ss >> palabra) {
            // Eliminar puntuación si es necesario para una comparación precisa
            std::string palabraLimpia;
            for (char c : palabra) {
                if (std::isalnum(c)) { // Solo caracteres alfanuméricos
                    palabraLimpia += c;
                }
            }
            if (palabraLimpia.length() > palabraMasLarga.length()) {
                palabraMasLarga = palabraLimpia;
            }
        }
    }
    archivo.close();

    if (!palabraMasLarga.empty()) {
        std::cout << "La palabra mas larga encontrada es: '" << palabraMasLarga << "' (Longitud: " << palabraMasLarga.length() << ")" << std::endl;
    } else {
        std::cout << "El archivo esta vacio o no contiene palabras." << std::endl;
    }
}

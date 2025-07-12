#include <iostream> // Para entrada y salida (cin, cout)
#include <string>   // Para usar std::string
#include <cmath>    // Para funciones matemáticas como sqrt (raíz cuadrada)

// --- Definición de tipos con typedef ---
typedef int Entero;
typedef bool Booleano;

// --- Prototipos de Funciones ---

// Consigna 1: Rellenar y mostrar un array con los 100 primeros números enteros
void rellenarYMostrarCienEnteros(Entero arr[], Entero size);

// Consigna 2: Rellenar y mostrar un array con números primos entre 1 y 100
Booleano esPrimo(Entero numero);
void rellenarYMostrarPrimos(Entero arr[], Entero& count, Entero limit);

// Consigna 3: Rellenar y mostrar un array con números impares entre 1 y 100
void rellenarYMostrarImpares(Entero arr[], Entero& count, Entero limit);


int main() {
    int opcion;

    // Arrays para las consignas
    Entero arrayCienEnteros[100];
    Entero arrayPrimos[100]; // Suficiente espacio para primos hasta 100
    Entero countPrimos = 0;
    Entero arrayImpares[50]; // 50 impares entre 1 y 100
    Entero countImpares = 0;

    do {
        std::cout << "\n--- MENU PRINCIPAL - TP Unidad 7 (Estructuras) ---" << std::endl;
        std::cout << "1. Rellenar y mostrar 100 primeros enteros" << std::endl;
        std::cout << "2. Rellenar y mostrar primos entre 1 y 100" << std::endl;
        std::cout << "3. Rellenar y mostrar impares entre 1 y 100" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: { // Consigna 1: Rellenar y mostrar un array con los 100 primeros números enteros
                std::cout << "\n--- 100 Primeros Numeros Enteros ---" << std::endl;
                rellenarYMostrarCienEnteros(arrayCienEnteros, 100);
                break;
            }
            case 2: { // Consigna 2: Rellenar y mostrar un array con números primos entre 1 y 100
                std::cout << "\n--- Numeros Primos entre 1 y 100 ---" << std::endl;
                countPrimos = 0; // Resetear contador para cada ejecución
                rellenarYMostrarPrimos(arrayPrimos, countPrimos, 100);
                break;
            }
            case 3: { // Consigna 3: Rellenar y mostrar un array con números impares entre 1 y 100
                std::cout << "\n--- Numeros Impares entre 1 y 100 ---" << std::endl;
                countImpares = 0; // Resetear contador para cada ejecución
                rellenarYMostrarImpares(arrayImpares, countImpares, 100);
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

// Consigna 1: Rellenar y mostrar un array con los 100 primeros números enteros
void rellenarYMostrarCienEnteros(Entero arr[], Entero size) {
    for (Entero i = 0; i < size; ++i) {
        arr[i] = i + 1; // Rellenar con números del 1 al 100
    }

    std::cout << "Array con los 100 primeros numeros enteros:" << std::endl;
    for (Entero i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
        if ((i + 1) % 10 == 0) { // Imprimir 10 números por línea para mejor visualización
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

// Consigna 2: Rellenar y mostrar un array con números primos entre 1 y 100
Booleano esPrimo(Entero numero) {
    if (numero <= 1) {
        return false;
    }
    for (Entero i = 2; i * i <= numero; ++i) {
        if (numero % i == 0) {
            return false;
        }
    }
    return true;
}

void rellenarYMostrarPrimos(Entero arr[], Entero& count, Entero limit) {
    count = 0; // Reiniciar el contador
    for (Entero i = 1; i <= limit; ++i) {
        if (esPrimo(i)) {
            arr[count++] = i;
        }
    }

    std::cout << "Array con numeros primos entre 1 y " << limit << ":" << std::endl;
    for (Entero i = 0; i < count; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Consigna 3: Rellenar y mostrar un array con números impares entre 1 y 100
void rellenarYMostrarImpares(Entero arr[], Entero& count, Entero limit) {
    count = 0; // Reiniciar el contador
    for (Entero i = 1; i <= limit; ++i) {
        if (i % 2 != 0) { // Si es impar
            arr[count++] = i;
        }
    }

    std::cout << "Array con numeros impares entre 1 y " << limit << ":" << std::endl;
    for (Entero i = 0; i < count; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

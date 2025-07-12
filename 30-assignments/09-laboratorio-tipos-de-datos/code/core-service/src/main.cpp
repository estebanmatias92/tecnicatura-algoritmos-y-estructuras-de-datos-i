#include <iostream> // Para entrada y salida (cin, cout)
#include <vector>   // Para usar std::vector en la consigna 4
#include <numeric>  // Para usar std::accumulate en la consigna 4

// --- Prototipos de Funciones ---

// Consigna 1: Cálculo de descuento en bazar
double calcularDescuentoBazar(int cantidadProductos);

// Consigna 2: Cálculo de salario semanal
double calcularSalarioSemanal(double horasTrabajadas);

// Consigna 3: Promedio de tres notas y estado de aprobación
void verificarAprobacion(double nota1, double nota2, double nota3);

// Consigna 4: Pedir números hasta 99 y calcular promedio
void numerosHasta99();

// Consigna 5: Suma desde 1 hasta un número dado
int sumarHastaN(int n);

// Consigna 6: Suma de números pares e impares hasta n
void sumarParesImpares(int n);

// Consigna 7: Pedir dos números, el segundo mayor que el primero
void pedirNumerosOrdenados();

// Consigna 8: Suma de números hasta que se introduzca un negativo
void sumarHastaNegativo();


int main() {
    int opcion;

    do {
        std::cout << "\n--- MENU PRINCIPAL - TP Unidad 2.4 ---" << std::endl;
        std::cout << "1. Descuento en Bazar" << std::endl;
        std::cout << "2. Salario Semanal del Trabajador" << std::endl;
        std::cout << "3. Promedio de Notas y Aprobacion" << std::endl;
        std::cout << "4. Numeros hasta 99 y Promedio" << std::endl;
        std::cout << "5. Suma desde 1 hasta N" << std::endl;
        std::cout << "6. Suma de Pares e Impares hasta N" << std::endl;
        std::cout << "7. Pedir Numeros Ordenados" << std::endl;
        std::cout << "8. Sumar Numeros hasta Negativo" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: { // Consigna 1: Descuento en Bazar
                int cantidad;
                std::cout << "\n--- Descuento en Bazar ---" << std::endl;
                std::cout << "Ingrese la cantidad de productos: ";
                std::cin >> cantidad;
                double precioTotal = cantidad * 80.0;
                double descuento = calcularDescuentoBazar(cantidad);
                double precioFinal = precioTotal * (1.0 - descuento);
                std::cout << "Precio original: $" << precioTotal << std::endl;
                std::cout << "Descuento aplicado: " << (descuento * 100) << "%" << std::endl;
                std::cout << "Precio final a pagar: $" << precioFinal << std::endl;
                break;
            }
            case 2: { // Consigna 2: Salario Semanal del Trabajador
                double horas;
                std::cout << "\n--- Salario Semanal del Trabajador ---" << std::endl;
                std::cout << "Ingrese las horas trabajadas en la semana: ";
                std::cin >> horas;
                std::cout << "El salario semanal es: $" << calcularSalarioSemanal(horas) << std::endl;
                break;
            }
            case 3: { // Consigna 3: Promedio de Notas y Aprobación
                double n1, n2, n3;
                std::cout << "\n--- Promedio de Notas y Aprobacion ---" << std::endl;
                std::cout << "Ingrese la nota 1: ";
                std::cin >> n1;
                std::cout << "Ingrese la nota 2: ";
                std::cin >> n2;
                std::cout << "Ingrese la nota 3: ";
                std::cin >> n3;
                verificarAprobacion(n1, n2, n3);
                break;
            }
            case 4: { // Consigna 4: Números hasta 99 y Promedio
                std::cout << "\n--- Numeros hasta 99 y Promedio ---" << std::endl;
                numerosHasta99();
                break;
            }
            case 5: { // Consigna 5: Suma desde 1 hasta N
                int num;
                std::cout << "\n--- Suma desde 1 hasta N ---" << std::endl;
                std::cout << "Ingrese un numero entero positivo: ";
                std::cin >> num;
                if (num > 0) {
                    std::cout << "La suma desde 1 hasta " << num << " es: " << sumarHastaN(num) << std::endl;
                } else {
                    std::cout << "Por favor, ingrese un numero positivo." << std::endl;
                }
                break;
            }
            case 6: { // Consigna 6: Suma de Pares e Impares hasta N
                int num;
                std::cout << "\n--- Suma de Pares e Impares hasta N ---" << std::endl;
                std::cout << "Ingrese un numero entero positivo (N): ";
                std::cin >> num;
                if (num > 0) {
                    sumarParesImpares(num);
                } else {
                    std::cout << "Por favor, ingrese un numero positivo." << std::endl;
                }
                break;
            }
            case 7: { // Consigna 7: Pedir Números Ordenados
                std::cout << "\n--- Pedir Numeros Ordenados ---" << std::endl;
                pedirNumerosOrdenados();
                break;
            }
            case 8: { // Consigna 8: Sumar Números hasta Negativo
                std::cout << "\n--- Sumar Numeros hasta Negativo ---" << std::endl;
                sumarHastaNegativo();
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

// Consigna 1: Cálculo de descuento en bazar
double calcularDescuentoBazar(int cantidadProductos) {
    if (cantidadProductos > 30) {
        return 0.40; // 40% de descuento
    } else if (cantidadProductos > 20) { // Mayor de 20 pero menor o igual a 30
        return 0.25; // 25% de descuento
    } else if (cantidadProductos > 10) { // Mayor de 10 pero menor o igual a 20
        return 0.12; // 12% de descuento
    } else {
        return 0.0; // Sin descuento
    }
}

// Consigna 2: Cálculo de salario semanal
double calcularSalarioSemanal(double horasTrabajadas) {
    double salario;
    if (horasTrabajadas <= 40) {
        salario = horasTrabajadas * 200.0;
    } else {
        salario = (40 * 200.0) + ((horasTrabajadas - 40) * 250.0);
    }
    return salario;
}

// Consigna 3: Promedio de tres notas y estado de aprobación
void verificarAprobacion(double nota1, double nota2, double nota3) {
    double promedio = (nota1 + nota2 + nota3) / 3.0;
    std::cout << "El promedio es: " << promedio << std::endl;
    if (promedio >= 6.0) { // Asumiendo 6.0 como nota de aprobación
        std::cout << "El estudiante APROBO." << std::endl;
    } else {
        std::cout << "El estudiante NO APROBO." << std::endl;
    }
}

// Consigna 4: Pedir números hasta 99 y calcular promedio
void numerosHasta99() {
    std::vector<int> numeros;
    int numero;
    int suma = 0;
    int contador = 0;

    std::cout << "Ingrese numeros (99 para terminar):" << std::endl;
    while (true) {
        std::cout << "Numero: ";
        std::cin >> numero;
        if (numero == 99) {
            break;
        }
        numeros.push_back(numero);
        suma += numero;
        contador++;
    }

    if (contador > 0) {
        std::cout << "Numeros introducidos: ";
        for (int num : numeros) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
        double promedio = static_cast<double>(suma) / contador;
        std::cout << "El promedio de los numeros es: " << promedio << std::endl;
    } else {
        std::cout << "No se introdujeron numeros para calcular el promedio." << std::endl;
    }
}

// Consigna 5: Suma desde 1 hasta un número dado
int sumarHastaN(int n) {
    int suma = 0;
    for (int i = 1; i <= n; ++i) {
        suma += i;
    }
    return suma;
}

// Consigna 6: Suma de números pares e impares hasta n
void sumarParesImpares(int n) {
    long long sumaPares = 0;
    long long sumaImpares = 0;

    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 0) {
            sumaPares += i;
        } else {
            sumaImpares += i;
        }
    }
    std::cout << "Suma de numeros pares entre 1 y " << n << ": " << sumaPares << std::endl;
    std::cout << "Suma de numeros impares entre 1 y " << n << ": " << sumaImpares << std::endl;
}

// Consigna 7: Pedir dos números, el segundo mayor que el primero
void pedirNumerosOrdenados() {
    int num1, num2;
    std::cout << "Ingrese el primer numero entero: ";
    std::cin >> num1;
    do {
        std::cout << "Ingrese el segundo numero entero (debe ser mayor que " << num1 << "): ";
        std::cin >> num2;
        if (num2 <= num1) {
            std::cout << "El segundo numero debe ser mayor que el primero. Intente de nuevo." << std::endl;
        }
    } while (num2 <= num1);
    std::cout << "Los numeros introducidos son: " << num1 << " y " << num2 << std::endl;
}

// Consigna 8: Suma de números hasta que se introduzca un negativo
void sumarHastaNegativo() {
    int numero;
    long long suma = 0;
    std::cout << "Ingrese numeros (un numero negativo para terminar):" << std::endl;
    while (true) {
        std::cout << "Numero: ";
        std::cin >> numero;
        if (numero < 0) {
            break;
        }
        suma += numero;
    }
    std::cout << "La suma de los numeros introducidos (positivos) es: " << suma << std::endl;
}

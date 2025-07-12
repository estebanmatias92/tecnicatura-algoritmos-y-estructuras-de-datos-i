#include <iostream> // Para entrada y salida (cin, cout)
#include <string>   // Para usar std::string
#include <cmath>    // Para funciones matemáticas como abs (valor absoluto)

// --- Prototipos de Funciones ---

// Consigna 1: Conversión de Grados Centígrados a Fahrenheit y viceversa
double celsiusToFahrenheit(double celsius);
double fahrenheitToCelsius(double fahrenheit);

// Consigna 2: Operaciones aritméticas (suma, resta, multiplicación, división)
double sumar(double a, double b);
double restar(double a, double b);
double multiplicar(double a, double b);
double dividir(double a, double b);

// Consigna 3: Determinar si un número está dentro de un rango
bool estaEnRango(int numero, int limiteInferior, int limiteSuperior);

// Consigna 4: Determinar si un número es primo
bool esPrimo(int numero);

// Consigna 1.a (del segundo "Marco Práctico"): Leer y mostrar datos de una persona
void leerYMostrarDatosPersona();

// Consigna 1.b (del segundo "Marco Práctico"): Calcular nota final de estudiante
double calcularNotaFinal(double notaLaboratorio, double notaTeorica, double notaPractica);

// Consigna 1.c (del segundo "Marco Práctico"): Calcular perímetros
double perimetroCuadrado(double lado);
double perimetroRectangulo(double largo, double ancho);
double perimetroTriangulo(double ladoA, double ladoB, double ladoC);

// Consigna 1.d (del segundo "Marco Práctico"): Resolver ecuaciones
double resolverEcuacion1(double m, double x, double x1);
double resolverEcuacion2(double m, double x, double b);
double resolverEcuacion3(double m1, double m2, double x1, double x2);

// Consigna 1.e (del segundo "Marco Práctico"): Resolver función lineal y = 2x + 1
double funcionLineal(double x);


int main() {
    int opcion;
    double num1, num2, num3, num4; // Variables para uso general
    int intNum, limiteInf, limiteSup; // Variables para rango y primo

    do {
        std::cout << "\n--- MENU PRINCIPAL ---" << std::endl;
        std::cout << "1. Conversion de Temperaturas (Consigna 1)" << std::endl;
        std::cout << "2. Operaciones Aritmeticas (Consigna 2)" << std::endl;
        std::cout << "3. Verificar Numero en Rango (Consigna 3)" << std::endl;
        std::cout << "4. Verificar Numero Primo (Consigna 4)" << std::endl;
        std::cout << "5. Leer y Mostrar Datos de Persona (Consigna 1.a)" << std::endl;
        std::cout << "6. Calcular Nota Final de Estudiante (Consigna 1.b)" << std::endl;
        std::cout << "7. Calcular Perimetros (Consigna 1.c)" << std::endl;
        std::cout << "8. Resolver Ecuaciones (Consigna 1.d)" << std::endl;
        std::cout << "9. Resolver Funcion Lineal y=2x+1 (Consigna 1.e)" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: { // Consigna 1: Conversión de Temperaturas
                int subOpcion;
                std::cout << "\n--- Conversion de Temperaturas ---" << std::endl;
                std::cout << "1. Celsius a Fahrenheit" << std::endl;
                std::cout << "2. Fahrenheit a Celsius" << std::endl;
                std::cout << "Ingrese su opcion: ";
                std::cin >> subOpcion;
                double temp;
                std::cout << "Ingrese la temperatura: ";
                std::cin >> temp;
                if (subOpcion == 1) {
                    std::cout << temp << " Celsius son " << celsiusToFahrenheit(temp) << " Fahrenheit." << std::endl;
                } else if (subOpcion == 2) {
                    std::cout << temp << " Fahrenheit son " << fahrenheitToCelsius(temp) << " Celsius." << std::endl;
                } else {
                    std::cout << "Opcion invalida." << std::endl;
                }
                break;
            }
            case 2: { // Consigna 2: Operaciones Aritméticas
                int subOpcion;
                std::cout << "\n--- Operaciones Aritmeticas ---" << std::endl;
                std::cout << "Ingrese el primer numero: ";
                std::cin >> num1;
                std::cout << "Ingrese el segundo numero: ";
                std::cin >> num2;
                std::cout << "1. Suma" << std::endl;
                std::cout << "2. Resta" << std::endl;
                std::cout << "3. Multiplicacion" << std::endl;
                std::cout << "4. Division" << std::endl;
                std::cout << "Ingrese su opcion: ";
                std::cin >> subOpcion;
                switch (subOpcion) {
                    case 1: std::cout << "Suma: " << sumar(num1, num2) << std::endl; break;
                    case 2: std::cout << "Resta: " << restar(num1, num2) << std::endl; break;
                    case 3: std::cout << "Multiplicacion: " << multiplicar(num1, num2) << std::endl; break;
                    case 4: std::cout << "Division: " << dividir(num1, num2) << std::endl; break;
                    default: std::cout << "Opcion invalida." << std::endl; break;
                }
                break;
            }
            case 3: { // Consigna 3: Verificar Número en Rango
                std::cout << "\n--- Verificar Numero en Rango ---" << std::endl;
                std::cout << "Ingrese el limite inferior del rango: ";
                std::cin >> limiteInf;
                std::cout << "Ingrese el limite superior del rango: ";
                std::cin >> limiteSup;
                std::cout << "Ingrese el numero a verificar: ";
                std::cin >> intNum;
                if (estaEnRango(intNum, limiteInf, limiteSup)) {
                    std::cout << "El numero " << intNum << " esta dentro del rango [" << limiteInf << ", " << limiteSup << "]." << std::endl;
                } else {
                    std::cout << "El numero " << intNum << " NO esta dentro del rango [" << limiteInf << ", " << limiteSup << "]." << std::endl;
                }
                break;
            }
            case 4: { // Consigna 4: Verificar Numero Primo
                std::cout << "\n--- Verificar Numero Primo ---" << std::endl;
                std::cout << "Ingrese un numero para verificar si es primo: ";
                std::cin >> intNum;
                if (esPrimo(intNum)) {
                    std::cout << "El numero " << intNum << " es primo." << std::endl;
                } else {
                    std::cout << "El numero " << intNum << " NO es primo." << std::endl;
                }
                break;
            }
            case 5: { // Consigna 1.a (segundo Marco Práctico): Leer y Mostrar Datos de Persona
                std::cout << "\n--- Leer y Mostrar Datos de Persona ---" << std::endl;
                leerYMostrarDatosPersona();
                break;
            }
            case 6: { // Consigna 1.b (segundo Marco Práctico): Calcular Nota Final de Estudiante
                double lab, teorica, practica;
                std::cout << "\n--- Calcular Nota Final de Estudiante ---" << std::endl;
                std::cout << "Ingrese la nota de laboratorio (30%): ";
                std::cin >> lab;
                std::cout << "Ingrese la nota teorica (60%): ";
                std::cin >> teorica;
                std::cout << "Ingrese la nota de practica (10%): ";
                std::cin >> practica;
                std::cout << "La nota final del estudiante es: " << calcularNotaFinal(lab, teorica, practica) << std::endl;
                break;
            }
            case 7: { // Consigna 1.c (segundo Marco Práctico): Calcular Perímetros
                int subOpcion;
                std::cout << "\n--- Calcular Perimetros ---" << std::endl;
                std::cout << "1. Cuadrado" << std::endl;
                std::cout << "2. Rectangulo" << std::endl;
                std::cout << "3. Triangulo" << std::endl;
                std::cout << "Ingrese su opcion: ";
                std::cin >> subOpcion;
                switch (subOpcion) {
                    case 1: {
                        double lado;
                        std::cout << "Ingrese la longitud del lado del cuadrado: ";
                        std::cin >> lado;
                        std::cout << "El perimetro del cuadrado es: " << perimetroCuadrado(lado) << std::endl;
                        break;
                    }
                    case 2: {
                        double largo, ancho;
                        std::cout << "Ingrese el largo del rectangulo: ";
                        std::cin >> largo;
                        std::cout << "Ingrese el ancho del rectangulo: ";
                        std::cin >> ancho;
                        std::cout << "El perimetro del rectangulo es: " << perimetroRectangulo(largo, ancho) << std::endl;
                        break;
                    }
                    case 3: {
                        double ladoA, ladoB, ladoC;
                        std::cout << "Ingrese la longitud del lado A del triangulo: ";
                        std::cin >> ladoA;
                        std::cout << "Ingrese la longitud del lado B del triangulo: ";
                        std::cin >> ladoB;
                        std::cout << "Ingrese la longitud del lado C del triangulo: ";
                        std::cin >> ladoC;
                        std::cout << "El perimetro del triangulo es: " << perimetroTriangulo(ladoA, ladoB, ladoC) << std::endl;
                        break;
                    }
                    default: std::cout << "Opcion invalida." << std::endl; break;
                }
                break;
            }
            case 8: { // Consigna 1.d (segundo Marco Práctico): Resolver Ecuaciones
                int subOpcion;
                std::cout << "\n--- Resolver Ecuaciones ---" << std::endl;
                std::cout << "1. y = m(x - x1)" << std::endl;
                std::cout << "2. y = mx + b" << std::endl;
                std::cout << "3. y = (m2 - m1) / (x2 - x1)" << std::endl;
                std::cout << "Ingrese su opcion: ";
                std::cin >> subOpcion;
                switch (subOpcion) {
                    case 1: {
                        double m, x, x1;
                        std::cout << "Ingrese m: "; std::cin >> m;
                        std::cout << "Ingrese x: "; std::cin >> x;
                        std::cout << "Ingrese x1: "; std::cin >> x1;
                        std::cout << "Resultado y = " << resolverEcuacion1(m, x, x1) << std::endl;
                        break;
                    }
                    case 2: {
                        double m, x, b;
                        std::cout << "Ingrese m: "; std::cin >> m;
                        std::cout << "Ingrese x: "; std::cin >> x;
                        std::cout << "Ingrese b: "; std::cin >> b;
                        std::cout << "Resultado y = " << resolverEcuacion2(m, x, b) << std::endl;
                        break;
                    }
                    case 3: {
                        double m1, m2, x1_eq, x2_eq;
                        std::cout << "Ingrese m1: "; std::cin >> m1;
                        std::cout << "Ingrese m2: "; std::cin >> m2;
                        std::cout << "Ingrese x1: "; std::cin >> x1_eq;
                        std::cout << "Ingrese x2: "; std::cin >> x2_eq;
                        std::cout << "Resultado y = " << resolverEcuacion3(m1, m2, x1_eq, x2_eq) << std::endl;
                        break;
                    }
                    default: std::cout << "Opcion invalida." << std::endl; break;
                }
                break;
            }
            case 9: { // Consigna 1.e (segundo Marco Práctico): Resolver Función Lineal y = 2x + 1
                std::cout << "\n--- Resolver Funcion Lineal y = 2x + 1 ---" << std::endl;
                for (int i = 0; i < 4; ++i) {
                    double x_val;
                    std::cout << "Ingrese el valor de x #" << (i + 1) << ": ";
                    std::cin >> x_val;
                    std::cout << "Para x = " << x_val << ", y = " << funcionLineal(x_val) << std::endl;
                }
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

// Consigna 1: Conversión de Grados Centígrados a Fahrenheit y viceversa
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Consigna 2: Operaciones aritméticas (suma, resta, multiplicación, división)
double sumar(double a, double b) {
    return a + b;
}

double restar(double a, double b) {
    return a - b;
}

double multiplicar(double a, double b) {
    return a * b;
}

double dividir(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        std::cout << "Error: Division por cero." << std::endl;
        return 0.0; // O manejar el error de otra manera
    }
}

// Consigna 3: Determinar si un número está dentro de un rango
bool estaEnRango(int numero, int limiteInferior, int limiteSuperior) {
    return (numero >= limiteInferior && numero <= limiteSuperior);
}

// Consigna 4: Determinar si un número es primo
bool esPrimo(int numero) {
    if (numero <= 1) {
        return false;
    }
    for (int i = 2; i * i <= numero; ++i) {
        if (numero % i == 0) {
            return false;
        }
    }
    return true;
}

// Consigna 1.a (del segundo "Marco Práctico"): Leer y mostrar datos de una persona
void leerYMostrarDatosPersona() {
    int edad;
    char sexo;
    double altura;

    std::cout << "Ingrese la edad: ";
    std::cin >> edad;
    std::cout << "Ingrese el sexo (M/F): ";
    std::cin >> sexo;
    std::cout << "Ingrese la altura en metros (ej. 1.75): ";
    std::cin >> altura;

    std::cout << "\n--- Datos de la Persona ---" << std::endl;
    std::cout << "Edad: " << edad << std::endl;
    std::cout << "Sexo: " << sexo << std::endl;
    std::cout << "Altura: " << altura << " metros" << std::endl;
}

// Consigna 1.b (del segundo "Marco Práctico"): Calcular nota final de estudiante
double calcularNotaFinal(double notaLaboratorio, double notaTeorica, double notaPractica) {
    return (notaLaboratorio * 0.30) + (notaTeorica * 0.60) + (notaPractica * 0.10);
}

// Consigna 1.c (del segundo "Marco Práctico"): Calcular perímetros
double perimetroCuadrado(double lado) {
    return 4 * lado;
}

double perimetroRectangulo(double largo, double ancho) {
    return 2 * largo + 2 * ancho;
}

double perimetroTriangulo(double ladoA, double ladoB, double ladoC) {
    return ladoA + ladoB + ladoC;
}

// Consigna 1.d (del segundo "Marco Práctico"): Resolver ecuaciones
double resolverEcuacion1(double m, double x, double x1) {
    return m * (x - x1);
}

double resolverEcuacion2(double m, double x, double b) {
    return m * x + b;
}

double resolverEcuacion3(double m1, double m2, double x1, double x2) {
    if (x2 - x1 == 0) {
        std::cout << "Error: Division por cero en la ecuacion." << std::endl;
        return 0.0; // O manejar el error
    }
    return (m2 - m1) / (x2 - x1);
}

// Consigna 1.e (del segundo "Marco Práctico"): Resolver función lineal y = 2x + 1
double funcionLineal(double x) {
    return 2 * x + 1;
}

#include <iostream> // Para entrada y salida (cin, cout)
#include <cmath>    // Para funciones matemáticas como pow (potencia)
#include <iomanip>  // Para formatear la salida (setprecision)

int main() {
    // Consigna 1.a: Calcular la edad a partir de la fecha de nacimiento
    int diaNacimiento, mesNacimiento, anioNacimiento;
    int diaActual = 11, mesActual = 7, anioActual = 2025; // Asumimos fecha actual

    std::cout << "--- Consigna 1.a: Calcular Edad ---" << std::endl;
    std::cout << "Ingrese su dia de nacimiento: ";
    std::cin >> diaNacimiento;
    std::cout << "Ingrese su mes de nacimiento: ";
    std::cin >> mesNacimiento;
    std::cout << "Ingrese su anio de nacimiento: ";
    std::cin >> anioNacimiento;

    int edad = anioActual - anioNacimiento;
    if (mesActual < mesNacimiento || (mesActual == mesNacimiento && diaActual < diaNacimiento)) {
        edad--;
    }
    std::cout << "Su edad es: " << edad << " anios." << std::endl << std::endl;

    // Consigna 1.b: Calcular el promedio de 3 datos
    double dato1, dato2, dato3;
    std::cout << "--- Consigna 1.b: Promedio de 3 datos ---" << std::endl;
    std::cout << "Ingrese el primer dato: ";
    std::cin >> dato1;
    std::cout << "Ingrese el segundo dato: ";
    std::cin >> dato2;
    std::cout << "Ingrese el tercer dato: ";
    std::cin >> dato3;
    double promedio = (dato1 + dato2 + dato3) / 3.0;
    std::cout << "El promedio es: " << promedio << std::endl << std::endl;

    // Consigna 1.c: Calcular el producto de 4 datos
    double datoA, datoB, datoC, datoD;
    std::cout << "--- Consigna 1.c: Producto de 4 datos ---" << std::endl;
    std::cout << "Ingrese el primer dato: ";
    std::cin >> datoA;
    std::cout << "Ingrese el segundo dato: ";
    std::cin >> datoB;
    std::cout << "Ingrese el tercer dato: ";
    std::cin >> datoC;
    std::cout << "Ingrese el cuarto dato: ";
    std::cin >> datoD;
    double producto = datoA * datoB * datoC * datoD;
    std::cout << "El producto de los 4 datos es: " << producto << std::endl << std::endl;

    // Consigna 1.d: Calcular el volumen de un cono (valores fijos)
    const double PI = 3.141592;
    double radioCono = 14.5;
    double alturaCono = 26.79;
    double volumenCono = (PI * pow(radioCono, 2) * alturaCono) / 3.0;
    std::cout << "--- Consigna 1.d: Volumen de un Cono (valores fijos) ---" << std::endl;
    std::cout << "El volumen del cono es: " << std::fixed << std::setprecision(2) << volumenCono << std::endl << std::endl;

    // Consigna 1.e: Modificación del programa anterior con variables double
    double radio, altura, volumen;
    radio = 14.5;
    altura = 26.79;
    volumen = (PI * pow(radio, 2) * altura) / 3.0;
    std::cout << "--- Consigna 1.e: Volumen de un Cono (variables double) ---" << std::endl;
    std::cout << "El volumen del cono (con variables double) es: " << std::fixed << std::setprecision(2) << volumen << std::endl << std::endl;

    // Consigna 1.f: Convertir grados Fahrenheit a Celsius
    double fahrenheit;
    std::cout << "--- Consigna 1.f: Fahrenheit a Celsius ---" << std::endl;
    std::cout << "Ingrese la temperatura en grados Fahrenheit: ";
    std::cin >> fahrenheit;
    double celsius = (5.0 / 9.0) * (fahrenheit - 32.0);
    std::cout << "La temperatura en grados Celsius es: " << std::fixed << std::setprecision(2) << celsius << std::endl << std::endl;

    // Consigna 1.g: Convertir segundos a horas, minutos y segundos
    long long totalSegundos;
    std::cout << "--- Consigna 1.g: Segundos a Horas, Minutos, Segundos ---" << std::endl;
    std::cout << "Ingrese el tiempo transcurrido en segundos: ";
    std::cin >> totalSegundos;

    long long horas = totalSegundos / 3600;
    long long minutos = (totalSegundos % 3600) / 60;
    long long segundos = totalSegundos % 60;

    std::cout << "Tiempo equivalente: " << horas << " horas, "
              << minutos << " minutos, " << segundos << " segundos." << std::endl << std::endl;

    return 0;
}

#include <iostream> // Incluye la librería iostream para entrada/salida de datos
#include <cmath>    // Incluye la librería cmath para funciones matemáticas como pow (potencia)

// La función main es el punto de entrada de todo programa C++
int main() {
    // --- Ejercicio 1: Operaciones básicas y mostrar resultados ---

    std::cout << "--- Ejercicio 1: Operaciones basicas ---" << std::endl;

    // a. La suma de 45 + 34
    std::cout << "a. Suma de 45 + 34 = " << (45 + 34) << std::endl;

    // b. La resta de 45 - 40
    std::cout << "b. Resta de 45 - 40 = " << (45 - 40) << std::endl;

    // c. La division de 46 y 3
    // Nota: La division de enteros truncara el resultado. Para un resultado decimal,
    // al menos uno de los operandos debe ser de tipo flotante (double o float).
    std::cout << "c. Division de 46 y 3 (entera) = " << (46 / 3) << std::endl;
    std::cout << "c. Division de 46 y 3 (decimal) = " << (static_cast<double>(46) / 3) << std::endl;

    // d. Un programa que multiplique 65 * 3
    std::cout << "d. Multiplicacion de 65 * 3 = " << (65 * 3) << std::endl;

    std::cout << std::endl; // Salto de linea para separar los ejercicios

    // --- Ejercicio 2: Uso de variables y operadores ---

    std::cout << "--- Ejercicio 2: Uso de variables y operadores ---" << std::endl;

    // a. Calcula el volumen de una habitacion
    // Declaracion e inicializacion de variables para las dimensiones de la habitacion
    double largo_habitacion = 5.0;  // metros
    double ancho_habitacion = 4.0;  // metros
    double alto_habitacion = 2.5;   // metros

    // Calculo del volumen
    double volumen_habitacion = largo_habitacion * ancho_habitacion * alto_habitacion;

    // Mostrar el resultado
    std::cout << "a. El volumen de la habitacion es: " << volumen_habitacion << " metros cubicos." << std::endl;

    std::cout << std::endl; // Salto de linea para separar los ejercicios

    // b. Calcula el volumen de un cono
    // Declaracion e inicializacion de variables para el cono
    double radio_base_cono = 14.5;  // unidades
    double altura_cono = 26.79;     // unidades
    const double PI = 3.14;         // Definicion de la constante PI

    // Formula para el volumen del cono: (Pi * (radio)^2 * altura) / 3
    // Usamos pow(base, exponente) de la libreria cmath para calcular el radio al cuadrado
    double volumen_cono = (PI * pow(radio_base_cono, 2) * altura_cono) / 3;

    // Mostrar el resultado
    std::cout << "b. El volumen del cono es: " << volumen_cono << " unidades cubicas." << std::endl;

    std::cout << std::endl; // Salto de linea para separar los ejercicios

    // c. Modificar el programa anterior para que usen variables Dobles
    // En este caso, ya hemos usado variables de tipo 'double' para los calculos del cono
    // en el apartado 'b'. Esto asegura una mayor precision en los resultados decimales.

    std::cout << "c. Modificacion para usar variables Dobles:" << std::endl;
    std::cout << "   Para el calculo del volumen del cono en el apartado 'b', ya se utilizaron" << std::endl;
    std::cout << "   variables de tipo 'double' (radio_base_cono, altura_cono, PI, volumen_cono)." << std::endl;
    std::cout << "   La principal diferencia al usar 'double' en lugar de 'float' (o enteros para divisiones)" << std::endl;
    std::cout << "   es la PRECISION. 'double' almacena numeros de punto flotante con doble precision," << std::endl;
    std::cout << "   lo que significa que puede representar un rango mas amplio de valores y con mas" << std::endl;
    std::cout << "   decimales significativos. Esto es crucial para calculos cientificos o de ingenieria" << std::endl;
    std::cout << "   donde la exactitud es fundamental." << std::endl;
    std::cout << "   Por ejemplo, si hubieramos usado 'float' para PI (3.14f) o para las dimensiones," << std::endl;
    std::cout << "   el resultado del volumen podria tener una ligera diferencia debido a la menor precision." << std::endl;
    std::cout << "   Con 'double', el resultado es mas cercano al valor matematicamente exacto." << std::endl;

    return 0; // Indica que el programa finalizo correctamente
}

#include <iostream> // Para entrada y salida (cin, cout)
#include <string>   // Para usar std::string
#include <iomanip>  // Para formatear la salida (setprecision, fixed)

// --- Definición de tipos con typedef ---
typedef double Medida;
typedef double Salario;
typedef int OpcionMenu;

// --- Prototipos de Funciones ---

// Consigna 1.a: Conversiones de unidades
Medida centimetrosAPulgadas(Medida cm);
Medida celsiusAFahrenheit(Medida celsius);
Medida librasAKilogramos(Medida libras);

// Consigna 1.b: Incremento de salarios
Salario calcularSalarioConIncremento(Salario salarioActual);

// Consigna 1.c: Aplicación de toma de pedidos
void tomarPedidoApp();
std::string obtenerNombreProducto(OpcionMenu producto);
std::string obtenerNombreTipoEnvio(OpcionMenu tipoEnvio);

// Consigna 1.d: Diferencia entre dos números y listado condicional
void diferenciaNumerosYListado();


int main() {
    int opcion;

    do {
        std::cout << "\n--- MENU PRINCIPAL - TP Unidad 3.2 ---" << std::endl;
        std::cout << "1. Conversiones de Unidades (cm a pulgadas, C a F, lb a kg)" << std::endl;
        std::cout << "2. Calculo de Salario con Incremento" << std::endl;
        std::cout << "3. Aplicacion de Toma de Pedidos" << std::endl;
        std::cout << "4. Diferencia entre Numeros y Listado Condicional" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: { // Consigna 1.a: Conversiones de unidades
                int subOpcion;
                Medida valor;
                std::cout << "\n--- Conversiones de Unidades ---" << std::endl;
                std::cout << "1. Centimetros a Pulgadas" << std::endl;
                std::cout << "2. Celsius a Fahrenheit" << std::endl;
                std::cout << "3. Libras a Kilogramos" << std::endl;
                std::cout << "Ingrese su opcion: ";
                std::cin >> subOpcion;

                std::cout << "Ingrese el valor a convertir: ";
                std::cin >> valor;

                switch (subOpcion) {
                    case 1:
                        std::cout << valor << " cm son " << centimetrosAPulgadas(valor) << " pulgadas." << std::endl;
                        break;
                    case 2:
                        std::cout << valor << " C son " << celsiusAFahrenheit(valor) << " F." << std::endl;
                        break;
                    case 3:
                        std::cout << valor << " lb son " << librasAKilogramos(valor) << " kg." << std::endl;
                        break;
                    default:
                        std::cout << "Opcion invalida." << std::endl;
                        break;
                }
                break;
            }
            case 2: { // Consigna 1.b: Incremento de salarios
                Salario salarioActual;
                std::cout << "\n--- Calculo de Salario con Incremento ---" << std::endl;
                std::cout << "Ingrese el salario actual del trabajador: $";
                std::cin >> salarioActual;
                std::cout << "El nuevo salario es: $" << std::fixed << std::setprecision(2) << calcularSalarioConIncremento(salarioActual) << std::endl;
                break;
            }
            case 3: { // Consigna 1.c: Aplicación de toma de pedidos
                tomarPedidoApp();
                break;
            }
            case 4: { // Consigna 1.d: Diferencia entre dos números y listado condicional
                diferenciaNumerosYListado();
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

// Consigna 1.a: Conversiones de unidades
Medida centimetrosAPulgadas(Medida cm) {
    return cm * 0.393701;
}

Medida celsiusAFahrenheit(Medida celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

Medida librasAKilogramos(Medida libras) {
    return libras * 0.453592;
}

// Consigna 1.b: Incremento de salarios
Salario calcularSalarioConIncremento(Salario salarioActual) {
    double incrementoPorcentaje;
    if (salarioActual <= 9000) {
        incrementoPorcentaje = 0.20; // 20%
    } else if (salarioActual <= 15000) {
        incrementoPorcentaje = 0.10; // 10%
    } else if (salarioActual <= 20000) {
        incrementoPorcentaje = 0.05; // 5%
    } else {
        incrementoPorcentaje = 0.03; // 3%
    }
    return salarioActual * (1 + incrementoPorcentaje);
}

// Consigna 1.c: Aplicación de toma de pedidos
void tomarPedidoApp() {
    OpcionMenu productoElegido;
    OpcionMenu tipoEnvioElegido;

    std::cout << "\n--- Toma de Pedidos ---" << std::endl;
    std::cout << "Menu de Productos:" << std::endl;
    std::cout << "1) Simple" << std::endl;
    std::cout << "2) Medio" << std::endl;
    std::cout << "3) Calidad" << std::endl;
    std::cout << "4) Premium" << std::endl;
    std::cout << "Seleccione un producto: ";
    std::cin >> productoElegido;

    std::cout << "\nMenu de Tipo de Envio:" << std::endl;
    std::cout << "1) Normal" << std::endl;
    std::cout << "2) Express" << std::endl;
    std::cout << "3) Fast Delivery" << std::endl;
    std::cout << "Seleccione un tipo de envio: ";
    std::cin >> tipoEnvioElegido;

    std::cout << "\n--- Resumen del Pedido ---" << std::endl;
    std::cout << "Producto seleccionado: " << obtenerNombreProducto(productoElegido) << std::endl;
    std::cout << "Tipo de envio elegido: " << obtenerNombreTipoEnvio(tipoEnvioElegido) << std::endl;
}

// Helper para obtener el nombre del producto (Consigna 1.c)
std::string obtenerNombreProducto(OpcionMenu producto) {
    switch (producto) {
        case 1: return "Simple";
        case 2: return "Medio";
        case 3: return "Calidad";
        case 4: return "Premium";
        default: return "Desconocido";
    }
}

// Helper para obtener el nombre del tipo de envío (Consigna 1.c)
std::string obtenerNombreTipoEnvio(OpcionMenu tipoEnvio) {
    switch (tipoEnvio) {
        case 1: return "Normal";
        case 2: return "Express";
        case 3: return "Fast Delivery";
        default: return "Desconocido";
    }
}

// Consigna 1.d: Diferencia entre dos números y listado condicional
void diferenciaNumerosYListado() {
    int x, y;
    std::cout << "\n--- Diferencia de Numeros y Listado Condicional ---" << std::endl;
    std::cout << "Ingrese el primer numero (x): ";
    std::cin >> x;
    std::cout << "Ingrese el segundo numero (y): ";
    std::cin >> y;

    int diferencia = x - y;
    std::cout << "La diferencia (x - y) es: " << diferencia << std::endl;

    if (diferencia <= 10) {
        std::cout << "La diferencia es menor o igual a 10. Numeros comprendidos entre y y x:" << std::endl;
        // Asegurarse de que el bucle vaya del menor al mayor
        if (y <= x) {
            for (int i = y; i <= x; ++i) {
                std::cout << i << " ";
            }
        } else { // Si y es mayor que x, iterar de x a y
            for (int i = x; i <= y; ++i) {
                std::cout << i << " ";
            }
        }
        std::cout << std::endl;
    } else {
        std::cout << "La diferencia es mayor a 10. No se listaran los numeros." << std::endl;
    }
}

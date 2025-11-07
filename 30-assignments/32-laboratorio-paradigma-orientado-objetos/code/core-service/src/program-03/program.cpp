#include "homework/utils.h"
#include "program-03/program.h"
#include <iostream>
#include <fstream>
#include <limits>

namespace program03 {

// Implementación de Rectangulo
Rectangulo::Rectangulo() : altura(0.0f), base(0.0f) {}

void Rectangulo::SetAltura(float al) { altura = al; }
float Rectangulo::GetAltura() const { return altura; }
void Rectangulo::SetBase(float ba) { base = ba; }
float Rectangulo::GetBase() const { return base; }

float Rectangulo::area() const {
    return base * altura;
}

float Rectangulo::perimetro() const {
    return 2 * base + 2 * altura;
}

// Implementación de ArchivoRectangulos
void ArchivoRectangulos::guardar(const Rectangulo* rectangulos, int cantidad) const {
    std::ofstream archivo("rectangulos.dat", std::ios::binary);
    if (archivo.is_open()) {
        archivo.write(reinterpret_cast<const char*>(&cantidad), sizeof(int));
        archivo.write(reinterpret_cast<const char*>(rectangulos), cantidad * sizeof(Rectangulo));
        archivo.close();
    }
}

void ArchivoRectangulos::cargar(Rectangulo*& rectangulos, int& cantidad) {
    std::ifstream archivo("rectangulos.dat", std::ios::binary);
    if (archivo.is_open()) {
        archivo.read(reinterpret_cast<char*>(&cantidad), sizeof(int));
        delete[] rectangulos;
        rectangulos = new Rectangulo[cantidad];
        archivo.read(reinterpret_cast<char*>(rectangulos), cantidad * sizeof(Rectangulo));
        archivo.close();
    } else {
        cantidad = 0;
        rectangulos = nullptr;
    }
}

// Implementación de GestionRectangulos
GestionRectangulos::GestionRectangulos() : rectangulos(nullptr), cantidadRectangulos(0) {
    cargarDatos();
}

GestionRectangulos::~GestionRectangulos() {
    delete[] rectangulos;
}

void GestionRectangulos::crearRectangulo(float base, float altura) {
    Rectangulo* nuevos = new Rectangulo[cantidadRectangulos + 1];
    for (int i = 0; i < cantidadRectangulos; ++i) {
        nuevos[i] = rectangulos[i];
    }
    nuevos[cantidadRectangulos].SetBase(base);
    nuevos[cantidadRectangulos].SetAltura(altura);
    delete[] rectangulos;
    rectangulos = nuevos;
    cantidadRectangulos++;
    guardarDatos();
}

Rectangulo GestionRectangulos::leerRectangulo(int id) const {
    if (id >= 0 && id < cantidadRectangulos) {
        return rectangulos[id];
    }
    return Rectangulo();
}

void GestionRectangulos::actualizarRectangulo(int id, float base, float altura) {
    if (id >= 0 && id < cantidadRectangulos) {
        rectangulos[id].SetBase(base);
        rectangulos[id].SetAltura(altura);
        guardarDatos();
    }
}

void GestionRectangulos::eliminarRectangulo(int id) {
    if (id >= 0 && id < cantidadRectangulos) {
        Rectangulo* nuevos = new Rectangulo[cantidadRectangulos - 1];
        for (int i = 0, j = 0; i < cantidadRectangulos; ++i) {
            if (i != id) {
                nuevos[j++] = rectangulos[i];
            }
        }
        delete[] rectangulos;
        rectangulos = nuevos;
        cantidadRectangulos--;
        guardarDatos();
    }
}

void GestionRectangulos::cargarDatos() {
    archivo.cargar(rectangulos, cantidadRectangulos);
}

void GestionRectangulos::guardarDatos() const {
    archivo.guardar(rectangulos, cantidadRectangulos);
}

int GestionRectangulos::getCantidadRectangulos() const {
    return cantidadRectangulos;
}

const Rectangulo* GestionRectangulos::getRectangulos() const {
    return rectangulos;
}

// Implementación de Programa
void Programa::mostrarMenu() {
    std::cout << "\n--- Programa 03: Gestión de Rectángulos ---\n";
    std::cout << "1. Alta de Rectángulo\n";
    std::cout << "2. Baja de Rectángulo\n";
    std::cout << "3. Modificación de Rectángulo\n";
    std::cout << "4. Listar Rectángulos\n";
    std::cout << "0. Volver al Menú Principal\n";
    std::cout << "Ingrese su opción: ";
}

void Programa::altaRectangulo() {
    float base, altura;
    std::cout << "Ingrese base: ";
    std::cin >> base;
    std::cout << "Ingrese altura: ";
    std::cin >> altura;
    gestion.crearRectangulo(base, altura);
    std::cout << "Rectángulo creado exitosamente.\n";
}

void Programa::bajaRectangulo() {
    int id;
    std::cout << "Ingrese el ID del rectángulo a eliminar: ";
    std::cin >> id;
    if (id > 0 && id <= gestion.getCantidadRectangulos()) {
        gestion.eliminarRectangulo(id - 1);
        std::cout << "Rectángulo eliminado exitosamente.\n";
    } else {
        std::cout << "ID de rectángulo inválido.\n";
    }
}

void Programa::modificacionRectangulo() {
    int id;
    float base, altura;
    std::cout << "Ingrese el ID del rectángulo a modificar: ";
    std::cin >> id;
    if (id > 0 && id <= gestion.getCantidadRectangulos()) {
        std::cout << "Ingrese nueva base: ";
        std::cin >> base;
        std::cout << "Ingrese nueva altura: ";
        std::cin >> altura;
        gestion.actualizarRectangulo(id - 1, base, altura);
        std::cout << "Rectángulo modificado exitosamente.\n";
    } else {
        std::cout << "ID de rectángulo inválido.\n";
    }
}

void Programa::listarRectangulos() {
    std::cout << "\n--- Lista de Rectángulos ---\n";
    const Rectangulo* rectangulos = gestion.getRectangulos();
    for (int i = 0; i < gestion.getCantidadRectangulos(); ++i) {
        std::cout << "ID: " << i + 1 << \
        " | Base: " << rectangulos[i].GetBase() << \
        " | Altura: " << rectangulos[i].GetAltura() << \
        " | Área: " << rectangulos[i].area() << \
        " | Perímetro: " << rectangulos[i].perimetro() << std::endl;
    }
}

void Programa::ejecutar() {
    int choice;
    do {
        mostrarMenu();
        
        // Get user's choice
        if (!(std::cin >> choice)) {
            Homework::clearInputBuffer();
        }

        // Clears the screen before executing the selected task (except Exit/Invalid)
        if (choice != 0 && choice != -1) {
            Homework::clearInputBuffer();
        }

        switch (choice) {
            case 1:
                altaRectangulo();
                break;
            case 2:
                bajaRectangulo();
                break;
            case 3:
                modificacionRectangulo();
                break;
            case 4:
                listarRectangulos();
                break;
            case 0:
                std::cout << "Volviendo al menú principal...\n";
                break;
            default:
                std::cout << "Opción inválida. Intente de nuevo.\n";
        }

        // Pause after the task (except on exit or if it's an invalid option)
        if (choice >= 0 && choice <= 4) {
            // Pause 
            Homework::pause("\n\nPresione ENTER para continuar...\n");
            // Clear screen
            //Homework::clearScreen();
        }

    } while (choice != 0);
}

} // namespace program03

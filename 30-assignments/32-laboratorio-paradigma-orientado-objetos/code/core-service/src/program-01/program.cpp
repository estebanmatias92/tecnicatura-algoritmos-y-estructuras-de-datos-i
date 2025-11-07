#include "homework/utils.h"
#include "program-01/program.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

namespace program01 {

// Implementación de Articulo
Articulo::Articulo() : costoBase(0.0f) {}

void Articulo::SetCostoBase(float CB) {
    costoBase = CB;
}

float Articulo::GetCostoBase() const {
    return costoBase;
}

float Articulo::PVPMayor() const {
    return costoBase * 1.15f;
}

float Articulo::PVPDetal() const {
    return costoBase * 1.30f;
}

void Articulo::SetNombre(const std::string& n) {
    nombre = n;
}

std::string Articulo::GetNombre() const {
    return nombre;
}

// Implementación de ArchivoArticulos
void ArchivoArticulos::guardar(const Articulo* articulos, int cantidad) const {
    std::ofstream archivo("articulos.dat", std::ios::binary);
    if (archivo.is_open()) {
        archivo.write(reinterpret_cast<const char*>(&cantidad), sizeof(int));
        for (int i = 0; i < cantidad; ++i) {
            size_t len = articulos[i].GetNombre().length();
            archivo.write(reinterpret_cast<const char*>(&len), sizeof(size_t));
            archivo.write(articulos[i].GetNombre().c_str(), len);
            float costo = articulos[i].GetCostoBase();
            archivo.write(reinterpret_cast<const char*>(&costo), sizeof(float));
        }
        archivo.close();
    }
}

void ArchivoArticulos::cargar(Articulo*& articulos, int& cantidad) {
    std::ifstream archivo("articulos.dat", std::ios::binary);
    if (archivo.is_open()) {
        archivo.read(reinterpret_cast<char*>(&cantidad), sizeof(int));
        delete[] articulos;
        articulos = new Articulo[cantidad];
        for (int i = 0; i < cantidad; ++i) {
            size_t len;
            archivo.read(reinterpret_cast<char*>(&len), sizeof(size_t));
            char* buffer = new char[len + 1];
            archivo.read(buffer, len);
            buffer[len] = '\0';
            articulos[i].SetNombre(buffer);
            delete[] buffer;
            float costo;
            archivo.read(reinterpret_cast<char*>(&costo), sizeof(float));
            articulos[i].SetCostoBase(costo);
        }
        archivo.close();
    } else {
        cantidad = 0;
        articulos = nullptr;
    }
}

// Implementación de GestionArticulos
GestionArticulos::GestionArticulos() : articulos(nullptr), cantidadArticulos(0) {
    cargarDatos();
}

GestionArticulos::~GestionArticulos() {
    delete[] articulos;
}

void GestionArticulos::crearArticulo(const std::string& nombre, float costoBase) {
    Articulo* nuevos = new Articulo[cantidadArticulos + 1];
    for (int i = 0; i < cantidadArticulos; ++i) {
        nuevos[i] = articulos[i];
    }
    nuevos[cantidadArticulos].SetNombre(nombre);
    nuevos[cantidadArticulos].SetCostoBase(costoBase);
    delete[] articulos;
    articulos = nuevos;
    cantidadArticulos++;
    guardarDatos();
}

Articulo GestionArticulos::leerArticulo(int id) const {
    if (id >= 0 && id < cantidadArticulos) {
        return articulos[id];
    }
    return Articulo(); // Devuelve un articulo vacío si el id es inválido
}

void GestionArticulos::actualizarArticulo(int id, const std::string& nombre, float costoBase) {
    if (id >= 0 && id < cantidadArticulos) {
        articulos[id].SetNombre(nombre);
        articulos[id].SetCostoBase(costoBase);
        guardarDatos();
    }
}

void GestionArticulos::eliminarArticulo(int id) {
    if (id >= 0 && id < cantidadArticulos) {
        Articulo* nuevos = new Articulo[cantidadArticulos - 1];
        for (int i = 0, j = 0; i < cantidadArticulos; ++i) {
            if (i != id) {
                nuevos[j++] = articulos[i];
            }
        }
        delete[] articulos;
        articulos = nuevos;
        cantidadArticulos--;
        guardarDatos();
    }
}

void GestionArticulos::cargarDatos() {
    archivo.cargar(articulos, cantidadArticulos);
}

void GestionArticulos::guardarDatos() const {
    archivo.guardar(articulos, cantidadArticulos);
}

int GestionArticulos::getCantidadArticulos() const {
    return cantidadArticulos;
}

const Articulo* GestionArticulos::getArticulos() const {
    return articulos;
}

// Implementación de Programa
void Programa::mostrarMenu() {
    std::cout << "\n--- Programa 01: Gestión de Artículos ---\n";
    std::cout << "1. Alta de Artículo\n";
    std::cout << "2. Baja de Artículo\n";
    std::cout << "3. Modificación de Artículo\n";
    std::cout << "4. Listar Artículos\n";
    std::cout << "0. Volver al Menú Principal\n";
    std::cout << "Ingrese su opción: ";
}

void Programa::altaArticulo() {
    std::string nombre;
    float costoBase;
    std::cout << "Ingrese nombre del artículo: ";
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, nombre);
    std::cout << "Ingrese costo base: ";
    std::cin >> costoBase;
    gestion.crearArticulo(nombre, costoBase);
    std::cout << "Artículo creado exitosamente.\n";
}

void Programa::bajaArticulo() {
    int id;
    std::cout << "Ingrese el ID del artículo a eliminar: ";
    std::cin >> id;
    if (id > 0 && id <= gestion.getCantidadArticulos()) {
        gestion.eliminarArticulo(id - 1);
        std::cout << "Artículo eliminado exitosamente.\n";
    } else {
        std::cout << "ID de artículo inválido.\n";
    }
}

void Programa::modificacionArticulo() {
    int id;
    std::string nombre;
    float costoBase;
    std::cout << "Ingrese el ID del artículo a modificar: ";
    std::cin >> id;
    if (id > 0 && id <= gestion.getCantidadArticulos()) {
        std::cout << "Ingrese nuevo nombre del artículo: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, nombre);
        std::cout << "Ingrese nuevo costo base: ";
        std::cin >> costoBase;
        gestion.actualizarArticulo(id - 1, nombre, costoBase);
        std::cout << "Artículo modificado exitosamente.\n";
    } else {
        std::cout << "ID de artículo inválido.\n";
    }
}

void Programa::listarArticulos() {
    std::cout << "\n--- Lista de Artículos ---\n";
    const Articulo* articulos = gestion.getArticulos();
    for (int i = 0; i < gestion.getCantidadArticulos(); ++i) {
        std::cout << "ID: " << i + 1 << \
        " | Nombre: " << articulos[i].GetNombre() << \
        " | Costo Base: " << articulos[i].GetCostoBase() << \
        " | PVP Detal: " << articulos[i].PVPDetal() << \
        " | PVP Mayor: " << articulos[i].PVPMayor() << std::endl;
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
                altaArticulo();
                break;
                case 2:
                bajaArticulo();
                break;
                case 3:
                modificacionArticulo();
                break;
                case 4:
                listarArticulos();
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

} // namespace program01

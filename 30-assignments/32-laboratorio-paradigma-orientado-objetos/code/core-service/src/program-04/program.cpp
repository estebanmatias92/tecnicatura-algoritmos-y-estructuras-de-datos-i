#include "homework/utils.h"
#include "program-04/program.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

namespace program04 {

// Implementación de Persona
Persona::Persona() : dia(0), mes(0), anno(0), diaact(0), mesact(0), annoact(0) {}

void Persona::SetNombre(const std::string& nom) { nombre = nom; }
std::string Persona::GetNombre() const { return nombre; }
void Persona::SetDia(int d) { dia = d; }
int Persona::GetDia() const { return dia; }
void Persona::SetMes(int m) { mes = m; }
int Persona::GetMes() const { return mes; }
void Persona::SetAnno(int a) { anno = a; }
int Persona::GetAnno() const { return anno; }
void Persona::SetDiaact(int da) { diaact = da; }
int Persona::GetDiaact() const { return diaact; }
void Persona::SetMesact(int ma) { mesact = ma; }
int Persona::GetMesact() const { return mesact; }
void Persona::SetAnnoact(int aa) { annoact = aa; }
int Persona::GetAnnoact() const { return annoact; }

int Persona::obtenerEdad() const {
    int edad = annoact - anno;
    if (mesact < mes || (mesact == mes && diaact < dia)) {
        edad--;
    }
    return edad;
}

// Implementación de ArchivoPersonas
void ArchivoPersonas::guardar(const Persona* personas, int cantidad) const {
    std::ofstream archivo("personas.dat", std::ios::binary);
    if (archivo.is_open()) {
        archivo.write(reinterpret_cast<const char*>(&cantidad), sizeof(int));
        for (int i = 0; i < cantidad; ++i) {
            size_t len = personas[i].GetNombre().length();
            archivo.write(reinterpret_cast<const char*>(&len), sizeof(size_t));
            archivo.write(personas[i].GetNombre().c_str(), len);
            int d = personas[i].GetDia();
            int m = personas[i].GetMes();
            int a = personas[i].GetAnno();
            archivo.write(reinterpret_cast<const char*>(&d), sizeof(int));
            archivo.write(reinterpret_cast<const char*>(&m), sizeof(int));
            archivo.write(reinterpret_cast<const char*>(&a), sizeof(int));
        }
        archivo.close();
    }
}

void ArchivoPersonas::cargar(Persona*& personas, int& cantidad) {
    std::ifstream archivo("personas.dat", std::ios::binary);
    if (archivo.is_open()) {
        archivo.read(reinterpret_cast<char*>(&cantidad), sizeof(int));
        delete[] personas;
        personas = new Persona[cantidad];
        for (int i = 0; i < cantidad; ++i) {
            size_t len;
            archivo.read(reinterpret_cast<char*>(&len), sizeof(size_t));
            char* buffer = new char[len + 1];
            archivo.read(buffer, len);
            buffer[len] = '\0';
            personas[i].SetNombre(buffer);
            delete[] buffer;
            int d, m, a;
            archivo.read(reinterpret_cast<char*>(&d), sizeof(int));
            archivo.read(reinterpret_cast<char*>(&m), sizeof(int));
            archivo.read(reinterpret_cast<char*>(&a), sizeof(int));
            personas[i].SetDia(d);
            personas[i].SetMes(m);
            personas[i].SetAnno(a);
        }
        archivo.close();
    } else {
        cantidad = 0;
        personas = nullptr;
    }
}

// Implementación de GestionPersonas
GestionPersonas::GestionPersonas() : personas(nullptr), cantidadPersonas(0) {
    cargarDatos();
}

GestionPersonas::~GestionPersonas() {
    delete[] personas;
}

void GestionPersonas::crearPersona(const std::string& nom, int d, int m, int a) {
    Persona* nuevas = new Persona[cantidadPersonas + 1];
    for (int i = 0; i < cantidadPersonas; ++i) {
        nuevas[i] = personas[i];
    }
    nuevas[cantidadPersonas].SetNombre(nom);
    nuevas[cantidadPersonas].SetDia(d);
    nuevas[cantidadPersonas].SetMes(m);
    nuevas[cantidadPersonas].SetAnno(a);
    delete[] personas;
    personas = nuevas;
    cantidadPersonas++;
    guardarDatos();
}

Persona GestionPersonas::leerPersona(int id) const {
    if (id >= 0 && id < cantidadPersonas) {
        return personas[id];
    }
    return Persona();
}

void GestionPersonas::actualizarPersona(int id, const std::string& nom, int d, int m, int a) {
    if (id >= 0 && id < cantidadPersonas) {
        personas[id].SetNombre(nom);
        personas[id].SetDia(d);
        personas[id].SetMes(m);
        personas[id].SetAnno(a);
        guardarDatos();
    }
}

void GestionPersonas::eliminarPersona(int id) {
    if (id >= 0 && id < cantidadPersonas) {
        Persona* nuevas = new Persona[cantidadPersonas - 1];
        for (int i = 0, j = 0; i < cantidadPersonas; ++i) {
            if (i != id) {
                nuevas[j++] = personas[i];
            }
        }
        delete[] personas;
        personas = nuevas;
        cantidadPersonas--;
        guardarDatos();
    }
}

void GestionPersonas::cargarDatos() {
    archivo.cargar(personas, cantidadPersonas);
}

void GestionPersonas::guardarDatos() const {
    archivo.guardar(personas, cantidadPersonas);
}

int GestionPersonas::getCantidadPersonas() const {
    return cantidadPersonas;
}

const Persona* GestionPersonas::getPersonas() const {
    return personas;
}

// Implementación de Programa
void Programa::mostrarMenu() {
    std::cout << "\n--- Programa 04: Gestión de Personas ---\n";
    std::cout << "1. Alta de Persona\n";
    std::cout << "2. Baja de Persona\n";
    std::cout << "3. Modificación de Persona\n";
    std::cout << "4. Listar Personas\n";
    std::cout << "5. Mostrar Edad de Persona\n";
    std::cout << "0. Volver al Menú Principal\n";
    std::cout << "Ingrese su opción: ";
}

void Programa::altaPersona() {
    std::string nombre;
    int d, m, a;
    std::cout << "Ingrese nombre: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, nombre);
    std::cout << "Ingrese día de nacimiento: ";
    std::cin >> d;
    std::cout << "Ingrese mes de nacimiento: ";
    std::cin >> m;
    std::cout << "Ingrese año de nacimiento: ";
    std::cin >> a;
    gestion.crearPersona(nombre, d, m, a);
    std::cout << "Persona creada exitosamente.\n";
}

void Programa::bajaPersona() {
    int id;
    std::cout << "Ingrese el ID de la persona a eliminar: ";
    std::cin >> id;
    if (id > 0 && id <= gestion.getCantidadPersonas()) {
        gestion.eliminarPersona(id - 1);
        std::cout << "Persona eliminada exitosamente.\n";
    } else {
        std::cout << "ID de persona inválido.\n";
    }
}

void Programa::modificacionPersona() {
    int id;
    std::string nombre;
    int d, m, a;
    std::cout << "Ingrese el ID de la persona a modificar: ";
    std::cin >> id;
    if (id > 0 && id <= gestion.getCantidadPersonas()) {
        std::cout << "Ingrese nuevo nombre: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, nombre);
        std::cout << "Ingrese nuevo día de nacimiento: ";
        std::cin >> d;
        std::cout << "Ingrese nuevo mes de nacimiento: ";
        std::cin >> m;
        std::cout << "Ingrese nuevo año de nacimiento: ";
        std::cin >> a;
        gestion.actualizarPersona(id - 1, nombre, d, m, a);
        std::cout << "Persona modificada exitosamente.\n";
    } else {
        std::cout << "ID de persona inválido.\n";
    }
}

void Programa::listarPersonas() {
    std::cout << "\n--- Lista de Personas ---\n";
    const Persona* personas = gestion.getPersonas();
    for (int i = 0; i < gestion.getCantidadPersonas(); ++i) {
        std::cout << "ID: " << i + 1 << \
        " | Nombre: " << personas[i].GetNombre() << \
        " | Fecha de Nacimiento: " << personas[i].GetDia() << "/" << personas[i].GetMes() << "/" << personas[i].GetAnno() << std::endl;
    }
}

void Programa::mostrarEdadPersona() {
    int id, da, ma, aa;
    std::cout << "Ingrese el ID de la persona: ";
    std::cin >> id;
    if (id > 0 && id <= gestion.getCantidadPersonas()) {
        std::cout << "Ingrese día actual: ";
        std::cin >> da;
        std::cout << "Ingrese mes actual: ";
        std::cin >> ma;
        std::cout << "Ingrese año actual: ";
        std::cin >> aa;
        Persona p = gestion.leerPersona(id - 1);
        p.SetDiaact(da);
        p.SetMesact(ma);
        p.SetAnnoact(aa);
        std::cout << "La edad de " << p.GetNombre() << " es: " << p.obtenerEdad() << " años.\n";
    } else {
        std::cout << "ID de persona inválido.\n";
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
                altaPersona();
                break;
            case 2:
                bajaPersona();
                break;
            case 3:
                modificacionPersona();
                break;
            case 4:
                listarPersonas();
                break;
            case 5:
                mostrarEdadPersona();
                break;
            case 0:
                std::cout << "Volviendo al menú principal...\n";
                break;
            default:
                std::cout << "Opción inválida. Intente de nuevo.\n";
        }

        // Pause after the task (except on exit or if it's an invalid option)
        if (choice >= 0 && choice <= 5) {
            // Pause 
            Homework::pause("\n\nPresione ENTER para continuar...\n");
            // Clear screen
            //Homework::clearScreen();
        }

    } while (choice != 0);
}

} // namespace program04

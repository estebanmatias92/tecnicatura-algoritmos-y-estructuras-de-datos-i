#include "homework/utils.h"
#include "program-02/program.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

namespace program02 {

// Implementación de Alumno
Alumno::Alumno() : nota1(0.0f), nota2(0.0f), nota3(0.0f) {}

void Alumno::SetCedula(const std::string& ced) { cedula = ced; }
std::string Alumno::GetCedula() const { return cedula; }
void Alumno::SetNombre(const std::string& nom) { nombre = nom; }
std::string Alumno::GetNombre() const { return nombre; }
void Alumno::SetNota1(float n1) { nota1 = n1; }
float Alumno::GetNota1() const { return nota1; }
void Alumno::SetNota2(float n2) { nota2 = n2; }
float Alumno::GetNota2() const { return nota2; }
void Alumno::SetNota3(float n3) { nota3 = n3; }
float Alumno::GetNota3() const { return nota3; }

float Alumno::NotaFinal() const {
    return (nota1 + nota2 + nota3) / 3.0f;
}

std::string Alumno::AproRepro() const {
    return NotaFinal() >= 48.0f ? "Aprobado" : "Reprobado";
}

// Implementación de ArchivoAlumnos
void ArchivoAlumnos::guardar(const Alumno* alumnos, int cantidad) const {
    std::ofstream archivo("alumnos.dat", std::ios::binary);
    if (archivo.is_open()) {
        archivo.write(reinterpret_cast<const char*>(&cantidad), sizeof(int));
        for (int i = 0; i < cantidad; ++i) {
            size_t len_ced = alumnos[i].GetCedula().length();
            archivo.write(reinterpret_cast<const char*>(&len_ced), sizeof(size_t));
            archivo.write(alumnos[i].GetCedula().c_str(), len_ced);

            size_t len_nom = alumnos[i].GetNombre().length();
            archivo.write(reinterpret_cast<const char*>(&len_nom), sizeof(size_t));
            archivo.write(alumnos[i].GetNombre().c_str(), len_nom);

            float n1 = alumnos[i].GetNota1();
            float n2 = alumnos[i].GetNota2();
            float n3 = alumnos[i].GetNota3();
            archivo.write(reinterpret_cast<const char*>(&n1), sizeof(float));
            archivo.write(reinterpret_cast<const char*>(&n2), sizeof(float));
            archivo.write(reinterpret_cast<const char*>(&n3), sizeof(float));
        }
        archivo.close();
    }
}

void ArchivoAlumnos::cargar(Alumno*& alumnos, int& cantidad) {
    std::ifstream archivo("alumnos.dat", std::ios::binary);
    if (archivo.is_open()) {
        archivo.read(reinterpret_cast<char*>(&cantidad), sizeof(int));
        delete[] alumnos;
        alumnos = new Alumno[cantidad];
        for (int i = 0; i < cantidad; ++i) {
            size_t len_ced;
            archivo.read(reinterpret_cast<char*>(&len_ced), sizeof(size_t));
            char* buffer_ced = new char[len_ced + 1];
            archivo.read(buffer_ced, len_ced);
            buffer_ced[len_ced] = '\0';
            alumnos[i].SetCedula(buffer_ced);
            delete[] buffer_ced;

            size_t len_nom;
            archivo.read(reinterpret_cast<char*>(&len_nom), sizeof(size_t));
            char* buffer_nom = new char[len_nom + 1];
            archivo.read(buffer_nom, len_nom);
            buffer_nom[len_nom] = '\0';
            alumnos[i].SetNombre(buffer_nom);
            delete[] buffer_nom;

            float n1, n2, n3;
            archivo.read(reinterpret_cast<char*>(&n1), sizeof(float));
            archivo.read(reinterpret_cast<char*>(&n2), sizeof(float));
            archivo.read(reinterpret_cast<char*>(&n3), sizeof(float));
            alumnos[i].SetNota1(n1);
            alumnos[i].SetNota2(n2);
            alumnos[i].SetNota3(n3);
        }
        archivo.close();
    } else {
        cantidad = 0;
        alumnos = nullptr;
    }
}

// Implementación de GestionAlumnos
GestionAlumnos::GestionAlumnos() : alumnos(nullptr), cantidadAlumnos(0) {
    cargarDatos();
}

GestionAlumnos::~GestionAlumnos() {
    delete[] alumnos;
}

void GestionAlumnos::crearAlumno(const std::string& ced, const std::string& nom, float n1, float n2, float n3) {
    Alumno* nuevos = new Alumno[cantidadAlumnos + 1];
    for (int i = 0; i < cantidadAlumnos; ++i) {
        nuevos[i] = alumnos[i];
    }
    nuevos[cantidadAlumnos].SetCedula(ced);
    nuevos[cantidadAlumnos].SetNombre(nom);
    nuevos[cantidadAlumnos].SetNota1(n1);
    nuevos[cantidadAlumnos].SetNota2(n2);
    nuevos[cantidadAlumnos].SetNota3(n3);
    delete[] alumnos;
    alumnos = nuevos;
    cantidadAlumnos++;
    guardarDatos();
}

Alumno GestionAlumnos::leerAlumno(int id) const {
    if (id >= 0 && id < cantidadAlumnos) {
        return alumnos[id];
    }
    return Alumno();
}

void GestionAlumnos::actualizarAlumno(int id, const std::string& ced, const std::string& nom, float n1, float n2, float n3) {
    if (id >= 0 && id < cantidadAlumnos) {
        alumnos[id].SetCedula(ced);
        alumnos[id].SetNombre(nom);
        alumnos[id].SetNota1(n1);
        alumnos[id].SetNota2(n2);
        alumnos[id].SetNota3(n3);
        guardarDatos();
    }
}

void GestionAlumnos::eliminarAlumno(int id) {
    if (id >= 0 && id < cantidadAlumnos) {
        Alumno* nuevos = new Alumno[cantidadAlumnos - 1];
        for (int i = 0, j = 0; i < cantidadAlumnos; ++i) {
            if (i != id) {
                nuevos[j++] = alumnos[i];
            }
        }
        delete[] alumnos;
        alumnos = nuevos;
        cantidadAlumnos--;
        guardarDatos();
    }
}

void GestionAlumnos::cargarDatos() {
    archivo.cargar(alumnos, cantidadAlumnos);
}

void GestionAlumnos::guardarDatos() const {
    archivo.guardar(alumnos, cantidadAlumnos);
}

int GestionAlumnos::getCantidadAlumnos() const {
    return cantidadAlumnos;
}

const Alumno* GestionAlumnos::getAlumnos() const {
    return alumnos;
}

// Implementación de Programa
void Programa::mostrarMenu() {
    std::cout << "\n--- Programa 02: Gestión de Alumnos ---\n";
    std::cout << "1. Alta de Alumno\n";
    std::cout << "2. Baja de Alumno\n";
    std::cout << "3. Modificación de Alumno\n";
    std::cout << "4. Listar Alumnos\n";
    std::cout << "0. Volver al Menú Principal\n";
    std::cout << "Ingrese su opción: ";
}

void Programa::altaAlumno() {
    std::string cedula, nombre;
    float n1, n2, n3;
    std::cout << "Ingrese cédula: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, cedula);
    std::cout << "Ingrese nombre: ";
    std::getline(std::cin, nombre);
    std::cout << "Ingrese nota 1: ";
    std::cin >> n1;
    std::cout << "Ingrese nota 2: ";
    std::cin >> n2;
    std::cout << "Ingrese nota 3: ";
    std::cin >> n3;
    gestion.crearAlumno(cedula, nombre, n1, n2, n3);
    std::cout << "Alumno creado exitosamente.\n";
}

void Programa::bajaAlumno() {
    int id;
    std::cout << "Ingrese el ID del alumno a eliminar: ";
    std::cin >> id;
    if (id > 0 && id <= gestion.getCantidadAlumnos()) {
        gestion.eliminarAlumno(id - 1);
        std::cout << "Alumno eliminado exitosamente.\n";
    } else {
        std::cout << "ID de alumno inválido.\n";
    }
}

void Programa::modificacionAlumno() {
    int id;
    std::string cedula, nombre;
    float n1, n2, n3;
    std::cout << "Ingrese el ID del alumno a modificar: ";
    std::cin >> id;
    if (id > 0 && id <= gestion.getCantidadAlumnos()) {
        std::cout << "Ingrese nueva cédula: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, cedula);
        std::cout << "Ingrese nuevo nombre: ";
        std::getline(std::cin, nombre);
        std::cout << "Ingrese nueva nota 1 (0 - 100): ";
        std::cin >> n1;
        std::cout << "Ingrese nueva nota 2 (0 - 100): ";
        std::cin >> n2;
        std::cout << "Ingrese nueva nota 3 (0 - 100): ";
        std::cin >> n3;
        gestion.actualizarAlumno(id - 1, cedula, nombre, n1, n2, n3);
        std::cout << "Alumno modificado exitosamente.\n";
    } else {
        std::cout << "ID de alumno inválido.\n";
    }
}

void Programa::listarAlumnos() {
    std::cout << "\n--- Lista de Alumnos ---\n";
    const Alumno* alumnos = gestion.getAlumnos();
    for (int i = 0; i < gestion.getCantidadAlumnos(); ++i) {
        std::cout << "ID: " << i + 1 << \
        " | Cédula: " << alumnos[i].GetCedula() << \
        " | Nombre: " << alumnos[i].GetNombre() << \
        " | Nota Final: " << alumnos[i].NotaFinal() << \
        " | Estado: " << alumnos[i].AproRepro() << std::endl;
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
                altaAlumno();
                break;
            case 2:
                bajaAlumno();
                break;
            case 3:
                modificacionAlumno();
                break;
            case 4:
                listarAlumnos();
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

} // namespace program02

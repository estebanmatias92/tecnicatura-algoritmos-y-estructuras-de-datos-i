#pragma once

#include <string>

namespace program02 {

// RNF-01, RNF-03: Separación de responsabilidades (Modelo de Datos)
class Alumno {
private:
    std::string cedula;
    std::string nombre;
    float nota1, nota2, nota3;

public:
    Alumno();
    void SetCedula(const std::string& ced);
    std::string GetCedula() const;
    void SetNombre(const std::string& nom);
    std::string GetNombre() const;
    void SetNota1(float n1);
    float GetNota1() const;
    void SetNota2(float n2);
    float GetNota2() const;
    void SetNota3(float n3);
    float GetNota3() const;
    float NotaFinal() const;
    std::string AproRepro() const;
};

// RNF-01, RNF-03: Separación (Persistencia)
class ArchivoAlumnos {
public:
    void guardar(const Alumno* alumnos, int cantidad) const;
    void cargar(Alumno*& alumnos, int& cantidad);
};

// RNF-01, RNF-03: Separación (Lógica de Negocio)
class GestionAlumnos {
private:
    Alumno* alumnos;
    int cantidadAlumnos;
    ArchivoAlumnos archivo;

public:
    GestionAlumnos();
    ~GestionAlumnos();
    void crearAlumno(const std::string& ced, const std::string& nom, float n1, float n2, float n3);
    Alumno leerAlumno(int id) const;
    void actualizarAlumno(int id, const std::string& ced, const std::string& nom, float n1, float n2, float n3);
    void eliminarAlumno(int id);
    void cargarDatos();
    void guardarDatos() const;
    int getCantidadAlumnos() const;
    const Alumno* getAlumnos() const;
};

// RNF-01, RNF-03: Separación (Interfaz de Usuario)
class Programa {
private:
    GestionAlumnos gestion;

    void mostrarMenu();
    void altaAlumno();
    void bajaAlumno();
    void modificacionAlumno();
    void listarAlumnos();

public:
    void ejecutar();
};

} // namespace program02
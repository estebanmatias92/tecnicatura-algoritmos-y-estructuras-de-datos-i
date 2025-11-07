#pragma once

#include <string>

namespace program04 {

// RNF-01, RNF-03: Separación de responsabilidades (Modelo de Datos)
class Persona {
private:
    std::string nombre;
    int dia, mes, anno;
    int diaact, mesact, annoact;

public:
    Persona();
    void SetNombre(const std::string& nom);
    std::string GetNombre() const;
    void SetDia(int d);
    int GetDia() const;
    void SetMes(int m);
    int GetMes() const;
    void SetAnno(int a);
    int GetAnno() const;
    void SetDiaact(int da);
    int GetDiaact() const;
    void SetMesact(int ma);
    int GetMesact() const;
    void SetAnnoact(int aa);
    int GetAnnoact() const;
    int obtenerEdad() const;
};

// RNF-01, RNF-03: Separación (Persistencia)
class ArchivoPersonas {
public:
    void guardar(const Persona* personas, int cantidad) const;
    void cargar(Persona*& personas, int& cantidad);
};

// RNF-01, RNF-03: Separación (Lógica de Negocio)
class GestionPersonas {
private:
    Persona* personas;
    int cantidadPersonas;
    ArchivoPersonas archivo;

public:
    GestionPersonas();
    ~GestionPersonas();
    void crearPersona(const std::string& nom, int d, int m, int a);
    Persona leerPersona(int id) const;
    void actualizarPersona(int id, const std::string& nom, int d, int m, int a);
    void eliminarPersona(int id);
    void cargarDatos();
    void guardarDatos() const;
    int getCantidadPersonas() const;
    const Persona* getPersonas() const;
};

// RNF-01, RNF-03: Separación (Interfaz de Usuario)
class Programa {
private:
    GestionPersonas gestion;

    void mostrarMenu();
    void altaPersona();
    void bajaPersona();
    void modificacionPersona();
    void listarPersonas();
    void mostrarEdadPersona();

public:
    void ejecutar();
};

} // namespace program04
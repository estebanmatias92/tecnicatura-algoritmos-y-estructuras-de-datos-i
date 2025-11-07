#pragma once

#include <string>

namespace program01 {

// RNF-01, RNF-03: Separación de responsabilidades (Modelo de Datos)
class Articulo {
private:
    float costoBase;
    std::string nombre;

public:
    Articulo();
    void SetCostoBase(float CB);
    float GetCostoBase() const;
    float PVPMayor() const;
    float PVPDetal() const;
    void SetNombre(const std::string& n);
    std::string GetNombre() const;
};

// RNF-01, RNF-03: Separación (Persistencia)
class ArchivoArticulos {
public:
    void guardar(const Articulo* articulos, int cantidad) const;
    void cargar(Articulo*& articulos, int& cantidad);
};

// RNF-01, RNF-03: Separación (Lógica de Negocio)
class GestionArticulos {
private:
    Articulo* articulos;
    int cantidadArticulos;
    ArchivoArticulos archivo;

public:
    GestionArticulos();
    ~GestionArticulos();
    void crearArticulo(const std::string& nombre, float costoBase);
    Articulo leerArticulo(int id) const;
    void actualizarArticulo(int id, const std::string& nombre, float costoBase);
    void eliminarArticulo(int id);
    void cargarDatos();
    void guardarDatos() const;
    int getCantidadArticulos() const;
    const Articulo* getArticulos() const;
};

// RNF-01, RNF-03: Separación (Interfaz de Usuario)
class Programa {
private:
    GestionArticulos gestion;

    void mostrarMenu();
    void altaArticulo();
    void bajaArticulo();
    void modificacionArticulo();
    void listarArticulos();

public:
    void ejecutar();
};

} // namespace program01
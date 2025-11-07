#pragma once

namespace program03 {

// RNF-01, RNF-03: Separación de responsabilidades (Modelo de Datos)
class Rectangulo {
private:
    float altura;
    float base;

public:
    Rectangulo();
    void SetAltura(float al);
    float GetAltura() const;
    void SetBase(float ba);
    float GetBase() const;
    float area() const;
    float perimetro() const;
};

// RNF-01, RNF-03: Separación (Persistencia)
class ArchivoRectangulos {
public:
    void guardar(const Rectangulo* rectangulos, int cantidad) const;
    void cargar(Rectangulo*& rectangulos, int& cantidad);
};

// RNF-01, RNF-03: Separación (Lógica de Negocio)
class GestionRectangulos {
private:
    Rectangulo* rectangulos;
    int cantidadRectangulos;
    ArchivoRectangulos archivo;

public:
    GestionRectangulos();
    ~GestionRectangulos();
    void crearRectangulo(float base, float altura);
    Rectangulo leerRectangulo(int id) const;
    void actualizarRectangulo(int id, float base, float altura);
    void eliminarRectangulo(int id);
    void cargarDatos();
    void guardarDatos() const;
    int getCantidadRectangulos() const;
    const Rectangulo* getRectangulos() const;
};

// RNF-01, RNF-03: Separación (Interfaz de Usuario)
class Programa {
private:
    GestionRectangulos gestion;

    void mostrarMenu();
    void altaRectangulo();
    void bajaRectangulo();
    void modificacionRectangulo();
    void listarRectangulos();

public:
    void ejecutar();
};

} // namespace program03
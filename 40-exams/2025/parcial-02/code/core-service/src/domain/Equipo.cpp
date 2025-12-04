#include "domain/Equipo.h"

namespace app::domain
{

    // --- Implementación de Equipo ---
    Equipo::Equipo(const std::string &id, const std::string &nombre, float precio)
        : ID(id), nombre(nombre), precio(precio) {}

    Equipo::~Equipo() {}

    std::string Equipo::getID() const { return ID; }
    std::string Equipo::getNombre() const { return nombre; }
    float Equipo::getPrecio() const { return precio; }

    // --- Implementación de Ropa ---
    Ropa::Ropa(const std::string &id, const std::string &nombre, float precio, const std::string &talle, const std::string &color)
        : Equipo(id, nombre, precio), talle(talle), color(color) {}

    void Ropa::mostrar()
    {
        std::cout << "  - ID: " << ID << ", Nombre: " << nombre << ", Precio: $" << precio
                  << ", Talle: " << talle << ", Color: " << color << " (Ropa)" << std::endl;
    }

    // --- Implementación de Zapatos ---
    Zapatos::Zapatos(const std::string &id, const std::string &nombre, float precio, int numero, const std::string &tipoPuntera)
        : Equipo(id, nombre, precio), numero(numero), tipoPuntera(tipoPuntera) {}

    void Zapatos::mostrar()
    {
        std::cout << "  - ID: " << ID << ", Nombre: " << nombre << ", Precio: $" << precio
                  << ", Numero: " << numero << ", Puntera: " << tipoPuntera << " (Zapatos)" << std::endl;
    }

    // --- Implementación de Antiparras ---
    Antiparras::Antiparras(const std::string &id, const std::string &nombre, float precio)
        : Equipo(id, nombre, precio) {}

    void Antiparras::mostrar()
    {
        std::cout << "  - ID: " << ID << ", Nombre: " << nombre << ", Precio: $" << precio
                  << " (Antiparras)" << std::endl;
    }

} // namespace app::domain

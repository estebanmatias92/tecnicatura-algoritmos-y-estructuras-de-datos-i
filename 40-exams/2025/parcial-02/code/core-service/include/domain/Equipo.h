#ifndef EQUIPO_H
#define EQUIPO_H

#include <string>
#include <iostream>

namespace app::domain {

    // Clase Base Abstracta (NFR-A3)
    class Equipo {
    protected:
        std::string ID;
        std::string nombre;
        float precio;

    public:
        Equipo(const std::string& id, const std::string& nombre, float precio);
        virtual ~Equipo();

        virtual void mostrar() = 0; // Método virtual puro

        std::string getID() const;
        std::string getNombre() const;
        float getPrecio() const;
    };

    // Clases Derivadas (NFR-A3)
    class Ropa : public Equipo {
    private:
        std::string talle;
        std::string color;

    public:
        Ropa(const std::string& id, const std::string& nombre, float precio, const std::string& talle, const std::string& color);
        void mostrar() override;
    };

    class Zapatos : public Equipo {
    private:
        int numero;
        std::string tipoPuntera;

    public:
        Zapatos(const std::string& id, const std::string& nombre, float precio, int numero, const std::string& tipoPuntera);
        void mostrar() override;
    };

    class Antiparras : public Equipo {
    public:
        Antiparras(const std::string& id, const std::string& nombre, float precio);
        void mostrar() override;
    };

} // namespace app::domain

#endif // EQUIPO_H

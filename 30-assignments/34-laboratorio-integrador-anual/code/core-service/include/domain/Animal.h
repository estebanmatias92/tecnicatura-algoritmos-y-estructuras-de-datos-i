#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

namespace app::domain {

    class Animal {
    protected:
        std::string ID;
        std::string nombre;
        float precio;
        std::string corte;

    public:
        Animal(const std::string& id, const std::string& nombre, float precio, const std::string& corte);
        virtual ~Animal();

        virtual void comer() = 0;
        virtual void dormir() = 0;
        virtual void mostrar() = 0;

        std::string getID() const;
        std::string getNombre() const;
        float getPrecio() const;
        std::string getCorte() const;
    };

    class Pollo : public Animal {
    private:
        bool esOrganico;
        float pesoPromedio;

    public:
        Pollo(const std::string& id, const std::string& nombre, float precio, const std::string& corte, bool esOrganico, float pesoPromedio);
        void comer() override;
        void dormir() override;
        void mostrar() override;
    };

    class Vacuno : public Animal {
    private:
        std::string corteEspecifico;
        std::string origen;

    public:
        Vacuno(const std::string& id, const std::string& nombre, float precio, const std::string& corte, const std::string& corteEspecifico, const std::string& origen);
        void comer() override;
        void dormir() override;
        void mostrar() override;
    };

    class Cerdo : public Animal {
    private:
        std::string tipoCorte;
        bool esPorkBelly;

    public:
        Cerdo(const std::string& id, const std::string& nombre, float precio, const std::string& corte, const std::string& tipoCorte, bool esPorkBelly);
        void comer() override;
        void dormir() override;
        void mostrar() override;
    };

} // namespace app::domain

#endif // ANIMAL_H

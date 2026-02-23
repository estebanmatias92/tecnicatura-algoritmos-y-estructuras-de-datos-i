#include "domain/Animal.h"

namespace app::domain {

    Vacuno::Vacuno(const std::string& id, const std::string& nombre, float precio, const std::string& corte, const std::string& corteEspecifico, const std::string& origen)
        : Animal(id, nombre, precio, corte), corteEspecifico(corteEspecifico), origen(origen) {
    }

    void Vacuno::comer() {
        std::cout << "El vacuno esta comiendo pasto y alfalfa." << std::endl;
    }

    void Vacuno::dormir() {
        std::cout << "El vacuno esta durmiendo en el campo." << std::endl;
    }

    void Vacuno::mostrar() {
        std::cout << "[VACUNO] ID: " << ID 
                  << " | Nombre: " << nombre 
                  << " | Precio: $" << precio 
                  << " | Corte: " << corte
                  << " | Corte Especifico: " << corteEspecifico
                  << " | Origen: " << origen 
                  << std::endl;
    }

} // namespace app::domain

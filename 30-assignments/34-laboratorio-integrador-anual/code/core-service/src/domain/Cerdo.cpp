#include "domain/Animal.h"

namespace app::domain {

    Cerdo::Cerdo(const std::string& id, const std::string& nombre, float precio, const std::string& corte, const std::string& tipoCorte, bool esPorkBelly)
        : Animal(id, nombre, precio, corte), tipoCorte(tipoCorte), esPorkBelly(esPorkBelly) {
    }

    void Cerdo::comer() {
        std::cout << "El cerdo esta comiendo restos de cocina y maiz." << std::endl;
    }

    void Cerdo::dormir() {
        std::cout << "El cerdo esta durmiendo en el chiquero." << std::endl;
    }

    void Cerdo::mostrar() {
        std::cout << "[CERDO] ID: " << ID 
                  << " | Nombre: " << nombre 
                  << " | Precio: $" << precio 
                  << " | Corte: " << corte
                  << " | Tipo: " << tipoCorte
                  << " | Pork Belly: " << (esPorkBelly ? "Si" : "No")
                  << std::endl;
    }

} // namespace app::domain

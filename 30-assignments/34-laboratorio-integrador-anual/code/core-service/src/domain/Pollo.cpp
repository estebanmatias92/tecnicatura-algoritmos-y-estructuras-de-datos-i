#include "domain/Animal.h"

namespace app::domain {

    Pollo::Pollo(const std::string& id, const std::string& nombre, float precio, const std::string& corte, bool esOrganico, float pesoPromedio)
        : Animal(id, nombre, precio, corte), esOrganico(esOrganico), pesoPromedio(pesoPromedio) {
    }

    void Pollo::comer() {
        std::cout << "El pollo esta comiendo grano de maiz." << std::endl;
    }

    void Pollo::dormir() {
        std::cout << "El pollo esta durmiendo en el gallinero." << std::endl;
    }

    void Pollo::mostrar() {
        std::cout << "[POLLO] ID: " << ID 
                  << " | Nombre: " << nombre 
                  << " | Precio: $" << precio 
                  << " | Corte: " << corte
                  << " | Organico: " << (esOrganico ? "Si" : "No")
                  << " | Peso: " << pesoPromedio << " kg" 
                  << std::endl;
    }

} // namespace app::domain

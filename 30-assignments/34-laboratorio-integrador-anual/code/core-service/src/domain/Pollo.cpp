#include "domain/Animal.h"

namespace app::domain {

    /**
     * @brief Constructor
     * @details Derived class from Animal. Initializer list calls base constructor
     *          first, then initializes derived class members.
     *          Syntax: Derived(params) : Base(params), member(value) { }
     * @param[in] id Unique identifier
     * @param[in] nombre Product name
     * @param[in] precio Price in Argentine pesos
     * @param[in] corte Cut type
     * @param[in] esOrganico Whether chicken is organic
     * @param[in] pesoPromedio Average weight in kg
     */
    Pollo::Pollo(const std::string& id, const std::string& nombre, float precio, const std::string& corte, bool esOrganico, float pesoPromedio)
        : Animal(id, nombre, precio, corte), esOrganico(esOrganico), pesoPromedio(pesoPromedio) {
    }

    /**
     * @brief Polymorphic eating behavior
     */
    void Pollo::comer() {
        std::cout << "El pollo esta comiendo grano de maiz." << std::endl;
    }

    /**
     * @brief Polymorphic sleeping behavior
     */
    void Pollo::dormir() {
        std::cout << "El pollo esta durmiendo en el gallinero." << std::endl;
    }

    /**
     * @brief Displays chicken details
     */
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

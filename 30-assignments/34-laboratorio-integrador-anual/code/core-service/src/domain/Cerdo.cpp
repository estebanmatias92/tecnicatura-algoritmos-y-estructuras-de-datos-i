#include "domain/Animal.h"

namespace app::domain {

    /**
     * @brief Constructor
     * @details Derived class from Animal. Initializer list calls base constructor first.
     * @param[in] id Unique identifier
     * @param[in] nombre Product name
     * @param[in] precio Price in Argentine pesos
     * @param[in] corte Cut type
     * @param[in] tipoCorte Specific cut type (Costilla, Lomo, etc.)
     * @param[in] esPorkBelly Whether it's pork belly cut
     */
    Cerdo::Cerdo(const std::string& id, const std::string& nombre, float precio, const std::string& corte, const std::string& tipoCorte, bool esPorkBelly)
        : Animal(id, nombre, precio, corte), tipoCorte(tipoCorte), esPorkBelly(esPorkBelly) {
    }

    /**
     * @brief Polymorphic eating behavior
     */
    void Cerdo::comer() {
        std::cout << "El cerdo esta comiendo restos de cocina y maiz." << std::endl;
    }

    /**
     * @brief Polymorphic sleeping behavior
     */
    void Cerdo::dormir() {
        std::cout << "El cerdo esta durmiendo en el chiquero." << std::endl;
    }

    /**
     * @brief Displays pork cut details
     */
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

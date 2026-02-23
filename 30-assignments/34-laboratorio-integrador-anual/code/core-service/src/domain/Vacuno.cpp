#include "domain/Animal.h"

namespace app::domain {

    /**
     * @brief Constructor
     * @details Derived class from Animal. Initializer list calls base constructor first.
     * @param[in] id Unique identifier
     * @param[in] nombre Product name
     * @param[in] precio Price in Argentine pesos
     * @param[in] corte Cut type
     * @param[in] corteEspecifico Specific cut (Asado, Cuadril, etc.)
     * @param[in] origen Origin location
     */
    Vacuno::Vacuno(const std::string& id, const std::string& nombre, float precio, const std::string& corte, const std::string& corteEspecifico, const std::string& origen)
        : Animal(id, nombre, precio, corte), corteEspecifico(corteEspecifico), origen(origen) {
    }

    /**
     * @brief Polymorphic eating behavior
     */
    void Vacuno::comer() {
        std::cout << "El vacuno esta comiendo pasto y alfalfa." << std::endl;
    }

    /**
     * @brief Polymorphic sleeping behavior
     */
    void Vacuno::dormir() {
        std::cout << "El vacuno esta durmiendo en el campo." << std::endl;
    }

    /**
     * @brief Displays beef cut details
     */
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

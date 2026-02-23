#include "domain/Animal.h"

namespace app::domain {

    /**
     * @brief Constructor
     * @details Base class for all animal types.
     *          Uses initializer list: member(param) - more efficient than assignment.
     *          Syntax: ClassName() : member1(value1), member2(value2) { ... }
     * @param[in] id Unique identifier
     * @param[in] nombre Product name
     * @param[in] precio Price in Argentine pesos
     * @param[in] corte Cut type (Pollo, Vacuno, Cerdo)
     */
    Animal::Animal(const std::string& id, const std::string& nombre, float precio, const std::string& corte)
        : ID(id), nombre(nombre), precio(precio), corte(corte) {
    }

    /**
     * @brief Virtual destructor
     * @details Required for proper cleanup of derived classes via base pointer
     */
    Animal::~Animal() {
    }

    /**
     * @brief Gets the animal ID
     * @return ID as string
     */
    std::string Animal::getID() const {
        return ID;
    }

    /**
     * @brief Gets the product name
     * @return Nombre as string
     */
    std::string Animal::getNombre() const {
        return nombre;
    }

    /**
     * @brief Gets the price
     * @return Precio as float
     */
    float Animal::getPrecio() const {
        return precio;
    }

    /**
     * @brief Gets the cut type
     * @return Corte as string
     */
    std::string Animal::getCorte() const {
        return corte;
    }

} // namespace app::domain

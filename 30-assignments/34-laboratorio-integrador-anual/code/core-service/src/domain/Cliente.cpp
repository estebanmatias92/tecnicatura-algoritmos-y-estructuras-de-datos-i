#include "domain/Cliente.h"

namespace app::domain {

    /**
     * @brief Default constructor
     * @details Initializes Cliente with empty values.
     *          Uses initializer list syntax: member(param)
     *          This is more efficient than assignment inside body.
     */
    Cliente::Cliente() : ID_CUIT(""), razonSocial("") {}

    /**
     * @brief Parameterized constructor
     * @param[in] cuit CUIT identifier for the client
     * @param[in] razonSocial Business name of the client
     */
    Cliente::Cliente(const std::string& cuit, const std::string& razonSocial)
        : ID_CUIT(cuit), razonSocial(razonSocial) {}

    /**
     * @brief Displays client information to console
     */
    void Cliente::mostrar() {
        std::cout << "  - CUIT: " << ID_CUIT << ", Razon Social: " << razonSocial << std::endl;
    }

    /**
     * @brief Gets the CUIT identifier
     * @return Client CUIT as string
     */
    std::string Cliente::getID_CUIT() const {
        return ID_CUIT;
    }

    /**
     * @brief Gets the business name
     * @return Client razon social as string
     */
    std::string Cliente::getRazonSocial() const {
        return razonSocial;
    }

} // namespace app::domain

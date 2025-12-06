#include "domain/Cliente.h"

namespace app::domain {

    Cliente::Cliente() : ID_CUIT(""), razonSocial("") {}

    Cliente::Cliente(const std::string& cuit, const std::string& razonSocial)
        : ID_CUIT(cuit), razonSocial(razonSocial) {}

    void Cliente::mostrar() {
        std::cout << "  - CUIT: " << ID_CUIT << ", Razon Social: " << razonSocial << std::endl;
    }

    std::string Cliente::getID_CUIT() const {
        return ID_CUIT;
    }

    std::string Cliente::getRazonSocial() const {
        return razonSocial;
    }

} // namespace app::domain

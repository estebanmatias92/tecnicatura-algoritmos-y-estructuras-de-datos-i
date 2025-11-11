#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <iostream>

namespace app::domain {

    class Cliente {
    private:
        std::string ID_CUIT;
        std::string razonSocial;

    public:
        Cliente();
        Cliente(const std::string& cuit, const std::string& razonSocial);
        
        void mostrar();

        std::string getID_CUIT() const;
        std::string getRazonSocial() const;
    };

} // namespace app::domain

#endif // CLIENTE_H

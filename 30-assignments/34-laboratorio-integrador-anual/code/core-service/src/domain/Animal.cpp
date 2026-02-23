#include "domain/Animal.h"

namespace app::domain {

    Animal::Animal(const std::string& id, const std::string& nombre, float precio, const std::string& corte)
        : ID(id), nombre(nombre), precio(precio), corte(corte) {
    }

    Animal::~Animal() {
    }

    std::string Animal::getID() const {
        return ID;
    }

    std::string Animal::getNombre() const {
        return nombre;
    }

    float Animal::getPrecio() const {
        return precio;
    }

    std::string Animal::getCorte() const {
        return corte;
    }

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

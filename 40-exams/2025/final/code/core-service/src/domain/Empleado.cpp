#include "domain/Empleado.h"

namespace app::domain {

    Empleado::Empleado() : name(""), salary(0.0f), area(""), contact_info("") {}

    Empleado::Empleado(const std::string& name, float salary, const std::string& area, const std::string& contact_info)
        : name(name), salary(salary), area(area), contact_info(contact_info) {}

    std::string Empleado::getName() const {
        return name;
    }

    float Empleado::getSalary() const {
        return salary;
    }

    std::string Empleado::getArea() const {
        return area;
    }

    std::string Empleado::getContactInfo() const {
        return contact_info;
    }

    void Empleado::setName(const std::string& name) {
        this->name = name;
    }

    void Empleado::setSalary(float salary) {
        this->salary = salary;
    }

    void Empleado::setArea(const std::string& area) {
        this->area = area;
    }

    void Empleado::setContactInfo(const std::string& contact) {
        this->contact_info = contact;
    }

    Empleado::~Empleado() {
        // Virtual destructor implementation
    }

} // namespace app::domain
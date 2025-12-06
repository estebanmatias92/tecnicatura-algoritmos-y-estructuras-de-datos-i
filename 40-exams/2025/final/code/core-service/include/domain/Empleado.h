#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
#include <iostream>

namespace app::domain {

    class Empleado {
    protected:
        std::string name;
        float salary;
        std::string area;
        std::string contact_info;

    public:
        Empleado();
        Empleado(const std::string& name, float salary, const std::string& area, const std::string& contact_info);

        // Pure virtual functions making this class abstract (RNF-02)
        virtual void trabajar() = 0;
        virtual void displayInfo() = 0;

        // Getters
        std::string getName() const;
        float getSalary() const;
        std::string getArea() const;
        std::string getContactInfo() const;

        // Virtual setters for modification
        virtual void setName(const std::string& name);
        virtual void setSalary(float salary);
        virtual void setArea(const std::string& area);
        virtual void setContactInfo(const std::string& contact);

        // Virtual destructor for proper inheritance
        virtual ~Empleado();
    };

} // namespace app::domain

#endif // EMPLEADO_H
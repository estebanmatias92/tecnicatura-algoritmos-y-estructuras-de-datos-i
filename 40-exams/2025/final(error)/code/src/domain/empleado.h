#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>

class Empleado {
protected:
    std::string name;
    float salary;
    std::string area;
    std::string contact_info;

public:
    // Constructor
    Empleado(const std::string& n, float s, const std::string& a, const std::string& c);

    // Virtual destructor for proper polymorphism
    virtual ~Empleado();

    // Pure virtual methods (abstract methods)
    virtual void trabajar() = 0;
    virtual void displayInfo() = 0;

    // Getters
    std::string getName() const;
    float getSalary() const;
    std::string getArea() const;
    std::string getContactInfo() const;

    // Setters
    void setName(const std::string& newName);
    void setSalary(float newSalary);
    void setArea(const std::string& newArea);
    void setContactInfo(const std::string& newContactInfo);
};

#endif // EMPLEADO_H
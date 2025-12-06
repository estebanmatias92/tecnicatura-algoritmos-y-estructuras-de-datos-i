#include "empleado.h"
#include <iostream>

// Constructor implementation
Empleado::Empleado(const std::string& n, float s, const std::string& a, const std::string& c) 
    : name(n), salary(s), area(a), contact_info(c) {
}

// Virtual destructor implementation
Empleado::~Empleado() {
}

// Getter implementations
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

// Setter implementations
void Empleado::setName(const std::string& newName) {
    name = newName;
}

void Empleado::setSalary(float newSalary) {
    salary = newSalary;
}

void Empleado::setArea(const std::string& newArea) {
    area = newArea;
}

void Empleado::setContactInfo(const std::string& newContactInfo) {
    contact_info = newContactInfo;
}
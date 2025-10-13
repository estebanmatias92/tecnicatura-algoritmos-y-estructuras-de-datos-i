#ifndef ALUMNO_TYPES_H
#define ALUMNO_TYPES_H

#include <string>

namespace StudentManagement {
namespace Types {

// ----------------------------------------------------------------------------------
// --- Global Constants and Type Definitions ---
// ----------------------------------------------------------------------------------

const int MAX_ALUMNOS = 100;
const std::string NOMBRE_ARCHIVO = "Alumnos.txt";

// Column width definition for the table (for printing format)
const int W_LEGAJO = 10;
const int W_NOMBRE = 25;
const int W_CARRERA = 20;
const int W_ANIO = 5;

// Structure for the Student Record
struct tRegistro {
    int legajo;
    std::string nombre;
    std::string carrera;
    int anio;

    tRegistro() : legajo(0), nombre(""), carrera(""), anio(0) {}
    
    tRegistro(int l, const std::string& n, const std::string& c, int a)
        : legajo(l), nombre(n), carrera(c), anio(a) {}
};

// DYNAMIC STRUCTURE (tStudentList)
struct tListaAlumnos {
    tRegistro alumnos[MAX_ALUMNOS]; // The array of elements
    int contador;                   // The current element counter

    tListaAlumnos() : contador(0) {} // Counter initialization
};

// Operator Overloading for Comparison (to sort by enrollment number)
bool operator>(const tRegistro& opIzq, const tRegistro& opDer);
bool operator<(const tRegistro& opIzq, const tRegistro& opDer);

} // namespace Types
} // namespace StudentManagement

#endif // ALUMNO_TYPES_H

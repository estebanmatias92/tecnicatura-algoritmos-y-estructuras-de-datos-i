#ifndef ALUMNO_MANAGER_H
#define ALUMNO_MANAGER_H

#include "types/alumno_types.h" // Includes structures and constants

namespace StudentManagement {
namespace Domain {

// ----------------------------------------------------------------------------------
// --- EXECUTION AND BUSINESS FUNCTION PROTOTYPES ---
// ----------------------------------------------------------------------------------

// Domain Utility
void mostrarAlumno(const StudentManagement::Types::tRegistro& alumno);
int buscarAlumnoPorLegajo(const StudentManagement::Types::tListaAlumnos& lista, int legajo);
void ordenarAlumnos(StudentManagement::Types::tListaAlumnos& lista, bool ascendente);

// Program tasks (Menu)
void mostrarListado(const StudentManagement::Types::tListaAlumnos& lista); 
void buscarYMostrarAlumno(const StudentManagement::Types::tListaAlumnos& lista);               
void insertarAlumno(StudentManagement::Types::tListaAlumnos& lista);                     
void eliminarAlumno(StudentManagement::Types::tListaAlumnos& lista);                     
void ordenarYMostrar(const StudentManagement::Types::tListaAlumnos& lista);

} // namespace Domain
} // namespace StudentManagement                    

#endif // ALUMNO_MANAGER_H

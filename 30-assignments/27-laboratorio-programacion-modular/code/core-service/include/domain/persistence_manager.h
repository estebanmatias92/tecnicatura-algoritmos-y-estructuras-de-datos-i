#ifndef PERSISTENCE_MANAGER_H
#define PERSISTENCE_MANAGER_H

#include "types/alumno_types.h"

namespace StudentManagement {
namespace Domain {

/**
 * @brief Loads student data from the file.
 * @param lista The list of students to populate.
 */
void cargarDesdeArchivo(StudentManagement::Types::tListaAlumnos& lista);

/**
 * @brief Saves the content of the student list to the file.
 * @param lista The list of students to save.
 */
void guardarEnArchivo(const StudentManagement::Types::tListaAlumnos& lista);

} // namespace Domain
} // namespace StudentManagement

#endif // PERSISTENCE_MANAGER_H

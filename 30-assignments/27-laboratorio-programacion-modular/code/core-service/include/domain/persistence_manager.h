#ifndef PERSISTENCE_MANAGER_H
#define PERSISTENCE_MANAGER_H

#include <filesystem>
#include "types/alumno_types.h"

namespace StudentManagement {
namespace Domain {

// Connection string for service
const std::string DATABASE_URL = std::filesystem::absolute("data/"  + StudentManagement::Types::NOMBRE_ARCHIVO);

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

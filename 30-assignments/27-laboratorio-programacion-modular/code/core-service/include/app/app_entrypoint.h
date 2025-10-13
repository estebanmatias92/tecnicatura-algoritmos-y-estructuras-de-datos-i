#ifndef APP_ENTRYPOINT_H
#define APP_ENTRYPOINT_H

#include "types/alumno_types.h"

namespace StudentManagement {
namespace App {

/**
 * @brief Function containing the main application loop and menu.
 * @param lista The list of students to manage.
 */
void ejecutarAplicacion(StudentManagement::Types::tListaAlumnos& lista);

} // namespace App
} // namespace StudentManagement

#endif // APP_ENTRYPOINT_H

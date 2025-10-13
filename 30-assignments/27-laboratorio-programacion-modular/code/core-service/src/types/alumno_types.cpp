#include "types/alumno_types.h"

namespace StudentManagement {
namespace Types {

// ----------------------------------------------------------------------------------
// --- Operator Overloading for Comparison (Implementation) ---
// ----------------------------------------------------------------------------------

bool operator>(const tRegistro& opIzq, const tRegistro& opDer) {
    return opIzq.legajo > opDer.legajo;
}

bool operator<(const tRegistro& opIzq, const tRegistro& opDer) {
    return opIzq.legajo < opDer.legajo;
}

} // namespace Types
} // namespace StudentManagement

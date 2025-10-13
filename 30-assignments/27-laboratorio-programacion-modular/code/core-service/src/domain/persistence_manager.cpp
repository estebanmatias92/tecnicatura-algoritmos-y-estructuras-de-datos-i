#include "domain/persistence_manager.h"
#include "types/alumno_types.h"
#include "utils/helpers.h" // For using pausaConsola
#include <fstream>
#include <iostream>

// Using declarations for convenience
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using StudentManagement::Types::tListaAlumnos;
using StudentManagement::Types::tRegistro;
using StudentManagement::Types::MAX_ALUMNOS;
using StudentManagement::Types::NOMBRE_ARCHIVO;
using StudentManagement::Utils::limpiarPantalla;
using StudentManagement::Utils::pausaConsola;


namespace StudentManagement {
namespace Domain {

// ----------------------------------------------------------------------------------
// --- PERSISTENCE IMPLEMENTATION ---
// ----------------------------------------------------------------------------------

/**
 * @brief Loads student data from the file.
 * @param lista The list of students to populate.
 */
void cargarDesdeArchivo(tListaAlumnos& lista) {
    ifstream archivo(NOMBRE_ARCHIVO);
    tRegistro nuevoAlumno;
    
    lista.contador = 0; // Reset the list before loading

    if (archivo.is_open()) {
        cout << "📂 Archivo " << NOMBRE_ARCHIVO << " encontrado. Cargando datos...\n";
        
        // Reading records
        while (lista.contador < MAX_ALUMNOS && 
               archivo >> nuevoAlumno.legajo && 
               archivo >> nuevoAlumno.nombre && 
               archivo >> nuevoAlumno.carrera && 
               archivo >> nuevoAlumno.anio) {
            
            lista.alumnos[lista.contador] = nuevoAlumno;
            lista.contador++;
        }
        archivo.close();
        cout << "✅ " << lista.contador << " alumnos cargados correctamente.\n";
    } else {
        cout << "⚠️ Archivo " << NOMBRE_ARCHIVO << " no encontrado. Se iniciará una lista vacía.\n";
    }

    pausaConsola("Presione ENTER para continuar...");
    limpiarPantalla();
}

/**
 * @brief Saves the content of the student list to the file.
 * @param lista The list of students to save.
 */
void guardarEnArchivo(const tListaAlumnos& lista) {
    ofstream archivo(NOMBRE_ARCHIVO);

    if (archivo.is_open()) {
        for (int i = 0; i < lista.contador; ++i) {
            archivo << lista.alumnos[i].legajo << " "
                    << lista.alumnos[i].nombre << " "
                    << lista.alumnos[i].carrera << " "
                    << lista.alumnos[i].anio << endl;
        }
        archivo.close();
        cout << "\n✅ Cambios guardados en " << NOMBRE_ARCHIVO << ".\n";
    } else {
        cout << "❌ Error al abrir el archivo " << NOMBRE_ARCHIVO << " para guardar.\n";
    }
}

} // namespace Domain
} // namespace StudentManagement

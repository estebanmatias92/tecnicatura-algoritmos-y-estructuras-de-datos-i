#include "domain/alumno_manager.h"
#include "types/alumno_types.h"
#include "utils/helpers.h" // For using pausaConsola and mostrarMenu
#include <algorithm> // Required for std::sort
#include <iomanip>   // For printing formats
#include <iostream>
#include <limits>

// Using declarations for convenience
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::left;
using std::numeric_limits;
using std::setw;
using std::streamsize;
using std::string;
using StudentManagement::Types::tListaAlumnos;
using StudentManagement::Types::tRegistro;
using StudentManagement::Types::MAX_ALUMNOS;
using StudentManagement::Types::W_ANIO;
using StudentManagement::Types::W_CARRERA;
using StudentManagement::Types::W_LEGAJO;
using StudentManagement::Types::W_NOMBRE;

namespace StudentManagement {
namespace Domain {

// ----------------------------------------------------------------------------------
// --- DOMAIN UTILITIES IMPLEMENTATION ---
// ----------------------------------------------------------------------------------

/**
 * @brief Displays student details in a table format.
 * @param alumno The student record to display.
 */
void mostrarAlumno(const tRegistro &alumno) {
  cout << left << setw(W_LEGAJO) << alumno.legajo << setw(W_NOMBRE)
       << alumno.nombre << setw(W_CARRERA) << alumno.carrera << setw(W_ANIO)
       << alumno.anio << endl;
}

/**
 * @brief Searches for a student's position by their enrollment number.
 * @param lista The list of students.
 * @param legajo The enrollment number to search for.
 * @return The index of the student in the list, or -1 if not found.
 */
int buscarAlumnoPorLegajo(const tListaAlumnos &lista, int legajo) {
  for (int i = 0; i < lista.contador; ++i) {
    if (lista.alumnos[i].legajo == legajo) {
      return i;
    }
  }
  return -1;
}

/**
 * @brief Sorts the list of students by enrollment number.
 * @param lista The list of students (modified).
 * @param ascendente True for ascending order, false for descending order.
 */
void ordenarAlumnos(tListaAlumnos &lista, bool ascendente) {
  if (ascendente) {
    std::sort(lista.alumnos, lista.alumnos + lista.contador,
              StudentManagement::Types::operator<);
  } else {
    std::sort(lista.alumnos, lista.alumnos + lista.contador,
              StudentManagement::Types::operator>);
  }
}

// ----------------------------------------------------------------------------------
// --- MENU TASK IMPLEMENTATION ---
// ----------------------------------------------------------------------------------

/**
 * @brief Displays the complete list of students.
 * @param lista The list of students.
 */
void mostrarListado(const tListaAlumnos &lista) {
  cout << "\n========== LISTADO DE ALUMNOS (Total: " << lista.contador
       << ") ==========\n";

  if (lista.contador == 0) {
    cout << "La lista está vacía.\n";
    return;
  }

  // Table headers
  cout << left << setw(W_LEGAJO) << "LEGAJO" << setw(W_NOMBRE) << "NOMBRE"
       << setw(W_CARRERA) << "CARRERA" << setw(W_ANIO) << "ANIO" << endl;
  cout << string(W_LEGAJO + W_NOMBRE + W_CARRERA + W_ANIO, '-') << endl;

  // Table content
  for (int i = 0; i < lista.contador; ++i) {
    mostrarAlumno(lista.alumnos[i]);
  }
  cout << "==========================================================\n";
}

/**
 * @brief Prompts for an enrollment number and displays student information if
 * found.
 * @param lista The list of students.
 */
void buscarYMostrarAlumno(const tListaAlumnos &lista) {
  int legajo;
  cout << "🔍 Ingrese el Legajo del alumno a buscar: ";
  if (!(cin >> legajo)) {
    cout << "❌ Entrada inválida.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return;
  }
  cin.ignore(numeric_limits<streamsize>::max(),
             '\n'); // Consume the rest of the line

  int indice = buscarAlumnoPorLegajo(lista, legajo);

  if (indice != -1) {
    cout << "\n✅ Alumno encontrado:\n";
    cout << left << setw(W_LEGAJO) << "LEGAJO" << setw(W_NOMBRE) << "NOMBRE"
         << setw(W_CARRERA) << "CARRERA" << setw(W_ANIO) << "ANIO" << endl;
    cout << string(W_LEGAJO + W_NOMBRE + W_CARRERA + W_ANIO, '-') << endl;
    mostrarAlumno(lista.alumnos[indice]);
  } else {
    cout << "\n❌ Alumno con Legajo " << legajo << " NO encontrado.\n";
  }
}

/**
 * @brief Prompts for data and adds a new student to the list.
 * @param lista The list of students (modified).
 */
void insertarAlumno(tListaAlumnos &lista) {
  if (lista.contador >= MAX_ALUMNOS) {
    cout << "❌ La lista está llena. No se pueden insertar más alumnos (Máx: "
         << MAX_ALUMNOS << ").\n";
    return;
  }

  tRegistro nuevoAlumno;
  int legajo;
  bool legajoValido = false;

  // Enrollment number validation
  while (!legajoValido) {
    cout << "\n➕ Ingrese Legajo del nuevo alumno: ";
    if (!(cin >> legajo)) {
      cout << "❌ Entrada inválida. Debe ser un número entero.\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (buscarAlumnoPorLegajo(lista, legajo) != -1) {
      cout << "❌ Error: Ya existe un alumno con el legajo " << legajo
           << ". Intente con otro.\n";
    } else {
      nuevoAlumno.legajo = legajo;
      legajoValido = true;
    }
  }

  // Request other data
  cout << "Ingrese Nombre: ";
  getline(cin, nuevoAlumno.nombre);

  cout << "Ingrese Carrera: ";
  getline(cin, nuevoAlumno.carrera);

  cout << "Ingrese Año de ingreso: ";
  while (!(cin >> nuevoAlumno.anio)) {
    cout << "❌ Entrada inválida. Debe ser un número entero para el Año.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Ingrese Año de ingreso: ";
  }
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  // Insertion
  lista.alumnos[lista.contador] = nuevoAlumno;
  lista.contador++;
  cout << "\n✅ Alumno con legajo " << nuevoAlumno.legajo
       << " insertado correctamente.\n";
}

/**
 * @brief Prompts for an enrollment number and removes the corresponding student
 * from the list.
 * @param lista The list of students (modified).
 */
void eliminarAlumno(tListaAlumnos &lista) {
  if (lista.contador == 0) {
    cout << "\nLa lista está vacía. No hay alumnos para eliminar.\n";
    return;
  }

  int legajo;
  cout << "\n🗑️ Ingrese el Legajo del alumno a ELIMINAR: ";
  if (!(cin >> legajo)) {
    cout << "❌ Entrada inválida.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return;
  }
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  int indice = buscarAlumnoPorLegajo(lista, legajo);

  if (indice != -1) {
    // Moves the last element to the position of the deleted element
    lista.alumnos[indice] = lista.alumnos[lista.contador - 1];
    lista.contador--;
    cout << "\n✅ Alumno con legajo " << legajo
         << " eliminado correctamente.\n";
  } else {
    cout << "\n❌ Alumno con Legajo " << legajo
         << " NO encontrado para eliminar.\n";
  }
}

/**
 * @brief Displays sorting options, sorts, and then displays the list.
 * @param lista The list of students (temporarily modified for sorting).
 */
void ordenarYMostrar(tListaAlumnos &lista) {
  if (lista.contador == 0) {
    cout << "\nLa lista está vacía. No hay nada que ordenar.\n";
    return;
  }

  int opcion;
  cout << "\n\n--- Opciones de Ordenamiento (por Legajo) ---\n";
  cout << "1. Orden Ascendente\n";
  cout << "2. Orden Descendente\n";
  cout << "Ingrese su opción: ";

  if (!(cin >> opcion) || (opcion != 1 && opcion != 2)) {
    cout << "❌ Opción inválida. Volviendo al menú principal.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return;
  }
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  bool ascendente = (opcion == 1);
  ordenarAlumnos(lista, ascendente);

  cout << "\n✅ Lista ordenada (" << (ascendente ? "Ascendente" : "Descendente")
       << ").\n";
  mostrarListado(lista);
}

} // namespace Domain
} // namespace StudentManagement

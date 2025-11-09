#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <string>

namespace Geometria {
namespace Utils {

/**
 * @brief Helper function to clear the console screen.
 */
void limpiarPantalla();

/**
 * @brief Clears any leftover input in the standard input buffer.
 */
void limpiarBufferEntrada();

/**
 * @brief Helper function to pause execution and wait for user input.
 * @param mensaje Message to display to the user.
 */
void pausaConsola(const std::string& mensaje);

/**
 * @brief Displays the main menu and asks the user for an option.
 * @return The chosen option number (0-4) or -1 if the input is invalid.
 */
int mostrarMenu();

} // namespace Utils
} // namespace Geometria

#endif // HELPERS_H

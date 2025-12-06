#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <string>

namespace app {
namespace utils {

/**
 * @brief Helper function to clear the console screen.
 */
void clearScreen();

/**
 * @brief Clears any leftover input in the standard input buffer.
 */
void clearInputBuffer();

/**
 * @brief Helper function to pause execution and wait for user input.
 * @param message Message to display to the user.
 */
void pauseConsole(const std::string& message);

/**
 * @brief Displays the main menu and asks the user for an option.
 * @return The chosen option number (0-4) or -1 if the input is invalid.
 */
int displayMenu();

} // namespace utils
} // namespace app

#endif // HELPERS_H

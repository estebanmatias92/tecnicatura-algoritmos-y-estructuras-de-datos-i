#ifndef HOMEWORK_UTILS_H
#define HOMEWORK_UTILS_H

#include <iostream>
#include <string> // Added for std::string

namespace Homework {

/**
 * @brief Helper function to clear the console screen.
 * * Uses operating system specific commands.
 */
void clearScreen();

/**
 * @brief Clears any leftover input in the standard input buffer.
 */
void clearInputBuffer();

/**
 * @brief Helper function to pause execution and wait for user input.
 * @param mensaje Message to display to the user.
 */
void pause(const std::string& mensaje);

} // namespace Homework

#endif // HOMEWORK_UTILS_H

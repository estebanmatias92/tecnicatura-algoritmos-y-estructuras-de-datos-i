#include "utils/InputHandler.h"
#include <iostream>
#include <string>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::string;

namespace app {
namespace utils {

    std::string InputHandler::getStringInput(const std::string& prompt) {
        std::string input;
        cout << prompt;
        std::getline(std::cin, input);
        return input;
    }

    float InputHandler::getFloatInput(const std::string& prompt) {
        float input;
        cout << prompt;
        cin >> input;
        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return input;
    }

    int InputHandler::getIntInput(const std::string& prompt) {
        int input;
        cout << prompt;
        cin >> input;
        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return input;
    }

} // namespace utils
} // namespace app
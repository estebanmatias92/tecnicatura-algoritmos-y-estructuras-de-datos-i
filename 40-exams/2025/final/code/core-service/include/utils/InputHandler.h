#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <string>

namespace app {
namespace utils {

    class InputHandler {
    public:
        static std::string getStringInput(const std::string& prompt);
        static float getFloatInput(const std::string& prompt);
        static int getIntInput(const std::string& prompt);
    };

} // namespace utils
} // namespace app

#endif // INPUTHANDLER_H
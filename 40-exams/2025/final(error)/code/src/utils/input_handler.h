#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <string>

class InputHandler {
public:
    // Get string input with validation
    static std::string getStringInput(const std::string& prompt);
    
    // Get float input with validation
    static float getFloatInput(const std::string& prompt);
    
    // Get int input with validation
    static int getIntInput(const std::string& prompt);
};

#endif // INPUT_HANDLER_H
#include "input_handler.h"
#include <iostream>
#include <string>
#include <sstream>

std::string InputHandler::getStringInput(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    
    // Validate input is not empty
    if (input.empty()) {
        std::cout << "Input cannot be empty. Please try again." << std::endl;
        return getStringInput(prompt);  // Recursive call to get valid input
    }
    
    return input;
}

float InputHandler::getFloatInput(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    
    std::stringstream ss(input);
    float value;
    if (ss >> value && ss.eof()) {  // Ensure complete conversion with no trailing characters
        if (value >= 0) {  // Validate non-negative for salary
            return value;
        } else {
            std::cout << "Value must be non-negative. Please try again." << std::endl;
            return getFloatInput(prompt);  // Recursive call to get valid input
        }
    } else {
        std::cout << "Invalid number format. Please try again." << std::endl;
        return getFloatInput(prompt);  // Recursive call to get valid input
    }
}

int InputHandler::getIntInput(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    
    std::stringstream ss(input);
    int value;
    if (ss >> value && ss.eof()) {  // Ensure complete conversion with no trailing characters
        return value;
    } else {
        std::cout << "Invalid integer format. Please try again." << std::endl;
        return getIntInput(prompt);  // Recursive call to get valid input
    }
}
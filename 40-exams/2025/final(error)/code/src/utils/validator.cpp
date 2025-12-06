#include "validator.h"
#include <regex>
#include <algorithm>
#include <cctype>
#include <sstream>

bool Validator::validateRequired(const std::string& input) {
    // Check if the input is not empty and not just whitespace
    return !input.empty() && input.find_first_not_of(" \t\n\r\f\v") != std::string::npos;
}

bool Validator::validateNumeric(const std::string& input) {
    if (input.empty()) return false;
    
    // Check if the input is a valid number (integer or float)
    std::istringstream iss(input);
    double d;
    iss >> std::noskipws >> d; // noskipws considers leading whitespace invalid
    return iss.eof() && !iss.fail();
}

bool Validator::validateEmail(const std::string& input) {
    // Simple regex for basic email validation
    std::regex emailPattern(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    return std::regex_match(input, emailPattern);
}

bool Validator::validateRange(double value, double min, double max) {
    return value >= min && value <= max;
}

bool Validator::validateLength(const std::string& input, int minLength, int maxLength) {
    return input.length() >= static_cast<size_t>(minLength) && 
           input.length() <= static_cast<size_t>(maxLength);
}

bool Validator::validateAlphaWithSpaces(const std::string& input) {
    if (input.empty()) return false;
    
    for (char c : input) {
        if (!std::isalpha(c) && c != ' ' && c != '-') {
            return false;
        }
    }
    return true;
}

bool Validator::validateAlphaNumWithSpaces(const std::string& input) {
    if (input.empty()) return false;
    
    for (char c : input) {
        if (!std::isalnum(c) && c != ' ' && c != '-' && c != '_') {
            return false;
        }
    }
    return true;
}
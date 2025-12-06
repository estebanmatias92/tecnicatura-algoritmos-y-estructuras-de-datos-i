#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>

class Validator {
public:
    // Validate required fields are not empty
    static bool validateRequired(const std::string& input);
    
    // Validate numeric input
    static bool validateNumeric(const std::string& input);
    
    // Validate email format
    static bool validateEmail(const std::string& input);
    
    // Validate range for numeric values
    static bool validateRange(double value, double min, double max);
    
    // Validate string length
    static bool validateLength(const std::string& input, int minLength, int maxLength);
    
    // Validate if string contains only alphabetic characters (with spaces)
    static bool validateAlphaWithSpaces(const std::string& input);
    
    // Validate if string contains only alphanumeric characters (with spaces)
    static bool validateAlphaNumWithSpaces(const std::string& input);
};

#endif // VALIDATOR_H
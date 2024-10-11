#include "personType.h"

// Default constructor
personType::personType() : firstName(""), lastName("") {}

// Parameterized constructor
personType::personType(const std::string& firstName, const std::string& lastName) {
    this->firstName = firstName;
    this->lastName = lastName;
}

// Print function
void personType::print() const {
    std::cout << firstName << " " << lastName;
}

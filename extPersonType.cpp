#include "extPersonType.h"
#include <iostream>

// Parameterized constructor
extPersonType::extPersonType(std::string firstName, std::string lastName, int month, int day, int year,
    std::string street, std::string city, std::string state, int zip,
    std::string phoneNumber, std::string relationshipTag)
    : personType(firstName, lastName), birthDate(month, day, year), address(street, city, state, zip), phoneNumber(phoneNumber), relationship(relationshipTag) {}

// Print function
void extPersonType::print() const {
    personType::print(); // Call base class print
    std::cout << " Birth Date: ";
    birthDate.print(); // Assuming you have a print function in dateType
    std::cout << " Address: ";
    address.print(); // Assuming you have a print function in addressType
    std::cout << " Phone Number: " << phoneNumber << std::endl;
    std::cout << " Relationship: " << relationship << std::endl;
}

// Getter for last name
std::string extPersonType::getLastName() const {
    return lastName; // Directly access lastName
}

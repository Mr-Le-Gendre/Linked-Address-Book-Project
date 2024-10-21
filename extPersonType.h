#ifndef EXTPERSONTYPE_H
#define EXTPERSONTYPE_H

#include <string>
#include "personType.h" // Include personType header
#include "addressType.h"
#include "dateType.h"

class extPersonType : public personType {
private:
    dateType birthDate; // Assuming you have a dateType class
    addressType address; // Assuming you have an addressType class
    std::string phoneNumber;
    std::string relationship;

public:
    // Default constructor
    extPersonType() : birthDate(), address() {}
    // Parameterized constructor
    extPersonType(std::string firstName, std::string lastName, int month, int day, int year,
        std::string street, std::string city, std::string state, int zip,
        std::string phoneNumber, std::string relationshipTag);

    // Getters
    dateType getBirthDate() const { return birthDate; } // Add this method
    std::string getRelationship() const { return relationship; } // Add this method

    void print() const; // Print function to display the person's details
    std::string getLastName() const; // Getter for last name
    // Other methods...
};

#endif // EXTPERSONTYPE_H

#include "addressType.h"
#include <iostream>

// Set the address using the provided parameters
void addressType::setAddress(const std::string& street, const std::string& city, const std::string& state, int zip)
{
    streetAddress = street; // Correctly assigning parameter to member variable
    this->city = city;      // Use 'this' to refer to the member variable
    this->state = state;    // Use 'this' to refer to the member variable
    zipCode = zip;          // Correctly assigning parameter to member variable
}

// Get the street address
std::string addressType::getStreetAddress() const
{
    return streetAddress;
}

// Get the city
std::string addressType::getCity() const
{
    return city;
}

// Get the state
std::string addressType::getState() const
{
    return state;
}

// Get the ZIP code
int addressType::getZipCode() const
{
    return zipCode;
}

// Print the address in a formatted way
void addressType::printAddress() const
{
    std::cout << streetAddress << ", " << city << ", " << state << " " << zipCode << std::endl; // Added newline for clarity
}

// Constructor for the addressType class
addressType::addressType(const std::string& street, const std::string& city, const std::string& state, int zip)
{
    streetAddress = street; // Correctly assigning parameter to member variable
    this->city = city;      // Use 'this' to refer to the member variable
    this->state = state;    // Use 'this' to refer to the member variable
    zipCode = zip;          // Correctly assigning parameter to member variable
}

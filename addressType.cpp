#include "addressType.h"

// Default constructor
addressType::addressType() : street(""), city(""), state("XX"), zipCode(10000) {}

// Parameterized constructor
addressType::addressType(const std::string& street, const std::string& city, const std::string& state, int zipCode) {
    this->street = street;
    this->city = city;
    this->state = state;
    this->zipCode = zipCode;
}

// Print function
void addressType::print() const {
    std::cout << street << ", " << city << ", " << state << " " << zipCode << std::endl;
}

// Setter function
void addressType::setAddress(const std::string& street, const std::string& city, const std::string& state, int zipCode) {
    this->street = street;
    this->city = city;
    this->state = state;
    this->zipCode = zipCode;
}

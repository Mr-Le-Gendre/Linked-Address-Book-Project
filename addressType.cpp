#include "addressType.h"
#include <iostream>

void addressType::setAddress(const std::string& street, const std::string& city, const std::string& state, int zip)
{
    streetAddress = street;
    this->city = city;
    this->state = state;
    zipCode = zip;
}

std::string addressType::getStreetAddress() const
{
    return streetAddress;
}

std::string addressType::getCity() const
{
    return city;
}

std::string addressType::getState() const
{
    return state;
}

int addressType::getZipCode() const
{
    return zipCode;
}

void addressType::printAddress() const
{
    std::cout << streetAddress << ", " << city << ", " << state << " " << zipCode;
}

addressType::addressType(const std::string& street, const std::string& city, const std::string& state, int zip)
{
    streetAddress = street;
    this->city = city;
    this->state = state;
    zipCode = zip;
}

#include "personType.h"
#include <iostream>

void personType::setName(const std::string& first, const std::string& last)
{
    firstName = first;
    lastName = last;
}

std::string personType::getFirstName() const
{
    return firstName;
}

std::string personType::getLastName() const
{
    return lastName;
}

void personType::printName() const
{
    std::cout << firstName << " " << lastName;
}

personType::personType(const std::string& first, const std::string& last)
{
    firstName = first;
    lastName = last;
}

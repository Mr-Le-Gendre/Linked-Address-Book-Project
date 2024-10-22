#include "extPersonType.h"
#include <iostream>

bool extPersonType::operator==(const extPersonType& other) const
{
    return (lastName + " " + firstName) == (other.lastName + " " + other.firstName);
}

bool extPersonType::operator!=(const extPersonType& other) const
{
    return !(*this == other);
}

bool extPersonType::operator>=(const extPersonType& other) const
{
    return (lastName + " " + firstName) >= (other.lastName + " " + other.firstName);
}

void extPersonType::print() const
{
    std::cout << firstName << " " << lastName << " Birth Date: " << birthDate.getMonth() << "/" << birthDate.getDay() << "/" << birthDate.getYear() << std::endl;
    std::cout << " Address: " << address.getStreetAddress() << ", " << address.getCity() << ", " << address.getState() << " " << address.getZipCode() << std::endl;
    std::cout << " Phone Number: " << phoneNumber << std::endl;
    std::cout << " Relationship: " << relationship << std::endl;
    std::cout << std::endl; // Add a blank line after each entry
}

void extPersonType::setInfo(const std::string& first, const std::string& last, const dateType& bDate, const addressType& addr, const std::string& phone, const std::string& rel)
{
    firstName = first;
    lastName = last;
    birthDate = bDate;
    address = addr;
    phoneNumber = phone;
    relationship = rel;
}

std::string extPersonType::getFirstName() const
{
    return firstName;
}

std::string extPersonType::getLastName() const
{
    return lastName;
}

int extPersonType::getBirthMonth() const
{
    return birthDate.getMonth();
}

int extPersonType::getBirthDay() const
{
    return birthDate.getDay();
}

int extPersonType::getBirthYear() const
{
    return birthDate.getYear();
}

std::string extPersonType::getRelationship() const
{
    return relationship;
}

addressType extPersonType::getAddress() const
{
    return address;
}

std::string extPersonType::getPhoneNumber() const
{
    return phoneNumber;
}

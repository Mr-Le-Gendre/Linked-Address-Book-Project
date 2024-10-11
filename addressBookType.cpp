#include "addressBookType.h"
#include <iostream>
#include <algorithm> // Include for transform

void addressBookType::addPerson(const extPersonType& person) {
    addressBook.push_back(person);
}

void addressBookType::displayAll() const {
    for (const auto& person : addressBook) {
        person.print();
        std::cout << std::endl; // Add a space between entries
    }
}

void addressBookType::displayByName(const std::string& lastName) const {
    for (const auto& person : addressBook) {
        std::string personLastName = person.getLastName();
        transform(personLastName.begin(), personLastName.end(), personLastName.begin(), ::tolower); // Convert to lowercase
        if (personLastName == lastName) {
            person.print();
            std::cout << std::endl; // Add a space between entries
        }
    }
}

void addressBookType::displayByMonth(int month) const {
    for (const auto& person : addressBook) {
        if (person.getBirthDate().getMonth() == month) { // Assuming getMonth() method in dateType
            person.print();
            std::cout << std::endl; // Add a space between entries
        }
    }
}

void addressBookType::displayByRelationship(const std::string& relationship) const {
    for (const auto& person : addressBook) {
        std::string personRelationship = person.getRelationship();
        transform(personRelationship.begin(), personRelationship.end(), personRelationship.begin(), ::tolower); // Convert to lowercase
        if (personRelationship == relationship) {
            person.print();
            std::cout << std::endl; // Add a space between entries
        }
    }
}

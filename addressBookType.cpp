#include "addressBookType.h"
#include <iostream>
#include <algorithm> // Include for transform
#include <fstream> // Include for file handling

void addressBookType::addEntry(const extPersonType& newEntry)
{
    insert(newEntry);
}

void addressBookType::displayAllEntries() const
{
    nodeType<extPersonType>* current = first;
    while (current != nullptr)
    {
        current->info.print();
        current = current->link;
    }
}

void addressBookType::displayEntryByLastName(const std::string& lastName, const std::string& firstName) const
{
    std::string searchLastName = lastName;
    std::string searchFirstName = firstName;
    std::transform(searchLastName.begin(), searchLastName.end(), searchLastName.begin(), ::tolower);
    std::transform(searchFirstName.begin(), searchFirstName.end(), searchFirstName.begin(), ::tolower);

    nodeType<extPersonType>* current = first;
    while (current != nullptr)
    {
        std::string currentLastName = current->info.getLastName();
        std::string currentFirstName = current->info.getFirstName();
        std::transform(currentLastName.begin(), currentLastName.end(), currentLastName.begin(), ::tolower);
        std::transform(currentFirstName.begin(), currentFirstName.end(), currentFirstName.begin(), ::tolower);

        if (currentLastName == searchLastName && currentFirstName == searchFirstName)
        {
            current->info.print();
            return;
        }
        current = current->link;
    }
    std::cout << "Entry not found." << std::endl;
}

void addressBookType::displayEntriesByBirthMonth(int month) const
{
    nodeType<extPersonType>* current = first;
    while (current != nullptr)
    {
        if (current->info.getBirthMonth() == month)
        {
            current->info.print();
        }
        current = current->link;
    }
}

void addressBookType::displayEntriesByRelationship(const std::string& relationship) const
{
    std::string searchRelationship = relationship;
    std::transform(searchRelationship.begin(), searchRelationship.end(), searchRelationship.begin(), ::tolower);

    nodeType<extPersonType>* current = first;
    while (current != nullptr)
    {
        std::string currentRelationship = current->info.getRelationship();
        std::transform(currentRelationship.begin(), currentRelationship.end(), currentRelationship.begin(), ::tolower);

        if (currentRelationship == searchRelationship)
        {
            current->info.print();
        }
        current = current->link;
    }
}

void addressBookType::getNewEntry()
{
    std::string firstName, lastName, street, city, state, relationship, phoneNumber;
    int month, day, year, zip;

    std::cout << "Enter first name: ";
    std::cin >> firstName;
    std::cout << "Enter last name: ";
    std::cin >> lastName;
    std::cout << "Enter birth month: ";
    std::cin >> month;
    std::cout << "Enter birth day: ";
    std::cin >> day;
    std::cout << "Enter birth year: ";
    std::cin >> year;
    std::cin.ignore(); // Ignore the newline character left in the input buffer
    std::cout << "Enter street address: ";
    std::getline(std::cin, street);
    std::cout << "Enter city: ";
    std::getline(std::cin, city);
    std::cout << "Enter state: ";
    std::getline(std::cin, state);
    std::cout << "Enter ZIP code: ";
    std::cin >> zip;
    std::cout << "Enter phone number: ";
    std::cin >> phoneNumber;
    std::cin.ignore(); // Ignore the newline character left in the input buffer
    std::cout << "Enter relationship: ";
    std::getline(std::cin, relationship);

    extPersonType newPerson;
    newPerson.setInfo(firstName, lastName, dateType(month, day, year), addressType(street, city, state, zip), phoneNumber, relationship);
    addEntry(newPerson);
}

void addressBookType::removeEntry(const std::string& lastName, const std::string& firstName)
{
    nodeType<extPersonType>* current = first;
    while (current != nullptr)
    {
        if (current->info.getLastName() == lastName && current->info.getFirstName() == firstName)
        {
            deleteNode(current->info);
            return;
        }
        current = current->link;
    }
    std::cout << "Entry not found." << std::endl;
}

void addressBookType::saveToFile(const std::string& filename) const
{
    std::ofstream outputFile(filename);
    if (outputFile.is_open())
    {
        nodeType<extPersonType>* current = first;
        while (current != nullptr)
        {
            outputFile << current->info.getFirstName() << " "
                << current->info.getLastName() << " "
                << current->info.getBirthMonth() << " "
                << current->info.getBirthDay() << " "
                << current->info.getBirthYear() << " "
                << current->info.getAddress().getStreetAddress() << " "
                << current->info.getAddress().getCity() << " "
                << current->info.getAddress().getState() << " "
                << current->info.getAddress().getZipCode() << " "
                << current->info.getPhoneNumber() << " "
                << current->info.getRelationship() << std::endl;
            current = current->link;
        }
        outputFile.close();
    }
    else
    {
        std::cout << "Unable to open file for writing." << std::endl;
    }
}

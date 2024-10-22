#include "addressBookType.h"
#include <iostream>
#include <algorithm> // Include for transform

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

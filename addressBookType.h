#ifndef ADDRESSBOOKTYPE_H
#define ADDRESSBOOKTYPE_H

#include <vector>
#include "extPersonType.h"

class addressBookType {
private:
    std::vector<extPersonType> addressBook;

public:
    void addPerson(const extPersonType& person);
    void displayAll() const;
    void displayByName(const std::string& lastName) const;
    void displayByMonth(int month) const; // Add this line
    void displayByRelationship(const std::string& relationship) const; // Add this line
    // Other methods...
};

#endif // ADDRESSBOOKTYPE_H

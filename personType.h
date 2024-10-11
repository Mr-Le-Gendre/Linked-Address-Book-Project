#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <iostream>
#include <string>

class personType {
protected:
    std::string firstName;
    std::string lastName;

public:
    // Constructors
    personType();
    personType(const std::string& firstName, const std::string& lastName);

    // Accessor function
    void print() const;
};

#endif // PERSONTYPE_H

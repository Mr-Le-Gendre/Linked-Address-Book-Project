#ifndef ADDRESSTYPE_H
#define ADDRESSTYPE_H

#include <iostream>
#include <string>

class addressType {
private:
    std::string street;
    std::string city;
    std::string state;
    int zipCode;

public:
    // Constructors
    addressType();
    addressType(const std::string& street, const std::string& city, const std::string& state, int zipCode);

    // Accessor function
    void print() const;

    // Setter functions
    void setAddress(const std::string& street, const std::string& city, const std::string& state, int zipCode);
};

#endif // ADDRESSTYPE_H

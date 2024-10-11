#ifndef DATETYPE_H
#define DATETYPE_H

#include <iostream>

class dateType {
public:
    // Constructors
    dateType(); // Default constructor
    dateType(int month, int day, int year); // Parameterized constructor

    // Methods
    int getMonth() const { return month; } // Add this method
    void print() const; // Declare the print method

private:
    int month, day, year; // Example members, adjust as necessary
};

#endif // DATETYPE_H

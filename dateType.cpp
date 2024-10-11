#include "dateType.h"

// Default constructor
dateType::dateType() : month(1), day(1), year(2000) {}

// Parameterized constructor
dateType::dateType(int m, int d, int y) : month(m), day(d), year(y) {}

void dateType::print() const {
    std::cout << month << "/" << day << "/" << year << std::endl;
}

#include "dateType.h"
#include <iostream>

void dateType::setDate(int month, int day, int year)
{
    dMonth = month;
    dDay = day;
    dYear = year;
}

int dateType::getMonth() const
{
    return dMonth;
}

int dateType::getDay() const
{
    return dDay;
}

int dateType::getYear() const
{
    return dYear;
}

void dateType::printDate() const
{
    std::cout << dMonth << "-" << dDay << "-" << dYear;
}

dateType::dateType(int month, int day, int year)
{
    dMonth = month;
    dDay = day;
    dYear = year;
}

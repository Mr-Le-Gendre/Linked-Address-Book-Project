#ifndef H_personType
#define H_personType

#include <string>

class personType
{
public:
    void setName(const std::string& first, const std::string& last);
    std::string getFirstName() const;
    std::string getLastName() const;
    void printName() const;

    personType(const std::string& first = "", const std::string& last = "");

protected:
    std::string firstName;
    std::string lastName;
};

#endif

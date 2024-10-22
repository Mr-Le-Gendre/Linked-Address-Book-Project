#ifndef H_addressType
#define H_addressType

#include <string>

class addressType
{
public:
    void setAddress(const std::string& street, const std::string& city, const std::string& state, int zip);
    std::string getStreetAddress() const;
    std::string getCity() const;
    std::string getState() const;
    int getZipCode() const;
    void printAddress() const;

    addressType(const std::string& street = "", const std::string& city = "", const std::string& state = "", int zip = 0);

private:
    std::string streetAddress{ "" };
    std::string city{ "" };
    std::string state{ "" };
    int zipCode{ 0 };
};

#endif

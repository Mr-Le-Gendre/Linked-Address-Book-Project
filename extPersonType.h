#ifndef H_extPersonType
#define H_extPersonType

#include "personType.h"
#include "dateType.h"
#include "addressType.h"
#include <string>

class extPersonType : public personType
{
public:
    bool operator==(const extPersonType& other) const;
    bool operator!=(const extPersonType& other) const;
    bool operator>=(const extPersonType& other) const;
    void print() const;
    void setInfo(const std::string& first, const std::string& last, const dateType& bDate, const addressType& addr, const std::string& phone, const std::string& rel);
    std::string getFirstName() const;
    std::string getLastName() const;
    int getBirthMonth() const;
    int getBirthDay() const;
    int getBirthYear() const;
    std::string getRelationship() const;
    addressType getAddress() const;
    std::string getPhoneNumber() const;

private:
    dateType birthDate;
    addressType address;
    std::string phoneNumber;
    std::string relationship;
};

#endif

#ifndef H_addressBookType
#define H_addressBookType

#include "orderedLinkedList.h"
#include "extPersonType.h"

class addressBookType : public orderedLinkedList<extPersonType>
{
public:
    void addEntry(const extPersonType& newEntry);
    void displayAllEntries() const;
    void displayEntryByLastName(const std::string& lastName, const std::string& firstName) const;
    void displayEntriesByBirthMonth(int month) const;
    void displayEntriesByRelationship(const std::string& relationship) const;
    void getNewEntry();
    void removeEntry(const std::string& lastName, const std::string& firstName);
    void saveToFile(const std::string& filename) const;
};

#endif

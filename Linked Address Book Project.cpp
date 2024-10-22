#include <iostream>
#include <string>
#include <algorithm> // Include for transform
#include <fstream> // Include for file handling
#include "addressBookType.h"
#include "extPersonType.h" // Ensure this is included

using namespace std;

void loadAddressBook(addressBookType& addressBook) {
    ifstream inputFile("AddressBookData.txt");
    if (inputFile.is_open()) {
        string firstName, lastName, street, city, state, relationship, phoneNumber;
        int month, day, year, zip;

        while (inputFile >> firstName >> lastName >> month >> day >> year >> ws && getline(inputFile, street) && getline(inputFile, city) && getline(inputFile, state) && inputFile >> zip >> ws && inputFile >> phoneNumber >> ws && getline(inputFile, relationship)) {
            extPersonType person;
            person.setInfo(firstName, lastName, dateType(month, day, year), addressType(street, city, state, zip), phoneNumber, relationship);
            addressBook.addEntry(person);
        }
        inputFile.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }
}

int main() {
    addressBookType addressBook;

    // Load address book from file
    loadAddressBook(addressBook);

    int choice;
    do {
        cout << "On-line Address Book" << endl;
        cout << "Select an option:" << endl;
        cout << "1 - Display all entries in the address book." << endl;
        cout << "2 - Display an entry by a person's last name." << endl;
        cout << "3 - Display all entries with a given birth month." << endl;
        cout << "4 - Display all entries with a given relationship tag (Business, Friend, Family)." << endl;
        cout << "5 - Add a new entry." << endl;
        cout << "6 - Remove an entry." << endl;
        cout << "7 - Quit." << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addressBook.displayAllEntries(); // Display all entries
            break;
        case 2: {
            string lastName, firstName;
            cout << "Enter last name: ";
            cin >> lastName;
            cout << "Enter first name: ";
            cin >> firstName;
            addressBook.displayEntryByLastName(lastName, firstName); // Display entry by last name
            break;
        }
        case 3: {
            int month;
            cout << "Enter birth month: ";
            cin >> month;
            addressBook.displayEntriesByBirthMonth(month); // Display entries by birth month
            break;
        }
        case 4: {
            string relationship;
            cout << "Enter relationship tag: ";
            cin >> relationship;
            addressBook.displayEntriesByRelationship(relationship); // Display entries by relationship
            break;
        }
        case 5:
            addressBook.getNewEntry(); // Add a new entry
            break;
        case 6: {
            string lastName, firstName;
            cout << "Enter last name: ";
            cin >> lastName;
            cout << "Enter first name: ";
            cin >> firstName;
            addressBook.removeEntry(lastName, firstName); // Remove an entry
            break;
        }
        case 7:
            addressBook.saveToFile("AddressBookData.txt"); // Save updated information to file
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
            break;
        }
    } while (choice != 7);

    return 0;
}

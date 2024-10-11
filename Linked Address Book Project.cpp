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

        while (inputFile >> firstName >> lastName >> month >> day >> year >> ws && getline(inputFile, street) && getline(inputFile, city) && getline(inputFile, state) && inputFile >> zip >> phoneNumber >> ws && getline(inputFile, relationship)) {
            extPersonType person(firstName, lastName, month, day, year, street, city, state, zip, relationship);
            addressBook.addPerson(person);
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
        cout << "5 - Quit." << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addressBook.displayAll(); // Display all entries
            break;
        case 2: {
            string lastName;
            cout << "Enter last name: ";
            cin >> lastName;
            transform(lastName.begin(), lastName.end(), lastName.begin(), ::tolower); // Convert to lowercase
            addressBook.displayByName(lastName); // Display entry by last name
            break;
        }
        case 3: {
            int month;
            cout << "Enter birth month: ";
            cin >> month;
            addressBook.displayByMonth(month); // Assuming you have this method
            break;
        }
        case 4: {
            string relationship;
            cout << "Enter relationship tag: ";
            cin >> relationship;
            transform(relationship.begin(), relationship.end(), relationship.begin(), ::tolower); // Convert to lowercase
            addressBook.displayByRelationship(relationship); // Assuming you have this method
            break;
        }
        case 5:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}

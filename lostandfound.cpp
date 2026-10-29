#include <iostream>
#include <string>
using namespace std;

struct Item {
    string itemName;
    string location;
    string reporterName;
    string contactNumber;
    string status;
    Item* next;
};

class LostFoundSystem {
    Item* head;
public:
    LostFoundSystem() {
        head = NULL;
    }

    void addRecord() {
        Item* newItem = new Item;
        cout << "\nEnter Item Name: ";
        cin >> newItem->itemName;
        cout << "Enter Location: ";
        cin >> newItem->location;
        cout << "Enter Your Name: ";
        cin >> newItem->reporterName;
        cout << "Enter Contact Number: ";
        cin >> newItem->contactNumber;
        cout << "Status (Lost/Found): ";
        cin >> newItem->status;
        newItem->next = head;
        head = newItem;
        cout << "\nRecord Added Successfully!\n";
    }

    void displayRecords() {
        if (head == NULL) {
            cout << "\nNo records available.\n";
            return;
        }
        Item* temp = head;
        cout << "\n--- Lost & Found Records - KBT College Nashik ---\n";
        while (temp != NULL) {
            cout << "\nItem: " << temp->itemName;
            cout << "\nLocation: " << temp->location;
            cout << "\nReported by: " << temp->reporterName;
            cout << "\nContact: " << temp->contactNumber;
            cout << "\nStatus: " << temp->status;
            cout << "\n---------------------------";
            temp = temp->next;
        }
    }

    void searchAndMatch() {
        if (head == NULL) {
            cout << "\nNo records to check.\n";
            return;
        }

        Item* i = head;
        int foundMatch = 0;

        while (i != NULL) {
            if (i->status == "Lost") {
                Item* j = head;
                while (j != NULL) {
                    if (j->status == "Found" && j->itemName == i->itemName && j->location == i->location) {
                        cout << "\nMatch Found!";
                        cout << "\nItem: " << i->itemName;
                        cout << "\nLocation: " << i->location;
                        cout << "\nLost by: " << i->reporterName << " (Ph: " << i->contactNumber << ")";
                        cout << "\nFound by: " << j->reporterName << " (Ph: " << j->contactNumber << ")";
                        cout << "\n---------------------------";
                        foundMatch = 1;
                    }
                    j = j->next;
                }
            }
            i = i->next;
        }

        if (foundMatch == 0)
            cout << "\nNo matching items found.\n";
    }
};

int main() {
    LostFoundSystem system;
    int choice;
    while (true) {
        cout << "\n\n--- Lost & Found Report System - KBT College Nashik ---";
        cout << "\n1. Add Record";
        cout << "\n2. Display Records";
        cout << "\n3. Search Matching Lost & Found";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: system.addRecord(); break;
            case 2: system.displayRecords(); break;
            case 3: system.searchAndMatch(); break;
            case 4: cout << "\nExiting..."; return 0;
            default: cout << "\nInvalid choice! Try again.\n";
        }
    }
}
// *****OUTPUT*****
// PS C:\Users\SHRINIVAS\myfolder\DSA> cd "c:\Users\SHRINIVAS\myfolder\DSA\" ; if ($?) { g++ lostandfound.cpp -o lostandfound } ; if ($?) { .\lostandfound }


// --- Lost & Found Report System - KBT College Nashik ---
// 1. Add Record
// 2. Display Records
// 3. Search Matching Lost & Found
// 4. Exit
// Enter choice: 1

// Enter Item Name: laptop
// Enter Location: 501
// Enter Your Name: Shri
// Enter Contact Number: 9373561955
// Status (Lost/Found): Found

// Record Added Successfully!


// --- Lost & Found Report System - KBT College Nashik ---
// 1. Add Record
// 2. Display Records
// 3. Search Matching Lost & Found
// 4. Exit
// Enter choice: 1

// Enter Item Name: laptop
// Enter Location: 501
// Enter Your Name: Vadje
// Enter Contact Number: 9623110412
// Status (Lost/Found): Lost

// Record Added Successfully!


// --- Lost & Found Report System - KBT College Nashik ---
// 1. Add Record
// 2. Display Records
// 3. Search Matching Lost & Found
// 4. Exit
// Enter choice: 3

// Match Found!
// Item: laptop
// Location: 501
// Lost by: Vadje (Ph: 9623110412)
// Found by: Shri (Ph: 9373561955)
// ---------------------------

// --- Lost & Found Report System - KBT College Nashik ---
// 1. Add Record
// 2. Display Records
// 3. Search Matching Lost & Found
// 4. Exit
// Enter choice: 4

// Exiting...

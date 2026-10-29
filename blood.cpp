#include <iostream>
#include <string>
using namespace std;

struct Donor {
    string name;
    string blood;
    string contact;
    Donor* next;
};

class BloodBank {
    Donor* head;
public:
    BloodBank() { head = NULL; }

    void addDonor() {
        Donor* d = new Donor;
        cout << "\nEnter Donor Name: ";
        cin.ignore();
        getline(cin, d->name);
        cout << "Enter Blood Group: ";
        cin >> d->blood;
        cout << "Enter Contact Number: ";
        cin >> d->contact;
        d->next = NULL;

        if (head == NULL) head = d;
        else {
            Donor* t = head;
            while (t->next != NULL) t = t->next;
            t->next = d;
        }
        cout << "\nDonor Added Successfully \n";
    }

    void showDonors() {
        if (head == NULL) {
            cout << "\nNo Donors Registered \n";
            return;
        }

        cout << "\n--- Donor List ---\n";
        Donor* t = head;
        while (t != NULL) {
            cout << "Name: " << t->name
                 << " | Blood: " << t->blood
                 << " | Contact: " << t->contact << endl;
            t = t->next;
        }
    }

    void searchBlood() {
        if (head == NULL) {
            cout << "\nNo Donors in Database \n";
            return;
        }

        string bg;
        cout << "\nEnter Required Blood Group: ";
        cin >> bg;

        Donor* t = head;
        int found = 0;

        while (t != NULL) {
            if (t->blood == bg) {
                if (!found) {
                    cout << "\nBlood Group Available!\n";
                    cout << "Contact Donors:\n";
                }
                cout << "- " << t->name << " | " << t->contact << endl;
                found = 1;
            }
            t = t->next;
        }

        if (!found)
            cout << "\nBlood Group Not Available\n";
    }
};

int main() {
    BloodBank b;
    int choice;

    while (true) {
        cout << "\n====== Blood Donation Availability System ======\n";
        cout << "1. Add Donor\n";
        cout << "2. Show Donors\n";
        cout << "3. Search Blood Group\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: b.addDonor(); break;
            case 2: b.showDonors(); break;
            case 3: b.searchBlood(); break;
            case 4: return 0;
            default: cout << "\nInvalid Choice!\n";
        }
    }
}
// *****OUTPUT****
// ====== Blood Donation Availability System ======
// 1. Add Donor
// 2. Show Donors
// 3. Search Blood Group
// 4. Exit
// Enter Choice: 1

// Enter Donor Name: sayali
// Enter Blood Group: O+
// Enter Contact Number: 98899999

// Donor Added Successfully

// ====== Blood Donation Availability System ======
// 1. Add Donor
// 2. Show Donors
// 3. Search Blood Group
// 4. Exit
// Enter Choice: 1

// Enter Donor Name: Sanap
// Enter Blood Group: A
// Enter Contact Number: 9786868

// Donor Added Successfully

// ====== Blood Donation Availability System ======
// 1. Add Donor
// 2. Show Donors
// 3. Search Blood Group
// 4. Exit
// Enter Choice: 3

// Enter Required Blood Group: O+

// Blood Group Available!
// Contact Donors:
// - sayali | 98899999

// ====== Blood Donation Availability System ======
// 1. Add Donor
// 2. Show Donors
// 3. Search Blood Group
// 4. Exit
// Enter Choice: 4

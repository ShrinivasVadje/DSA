#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 10;

struct Employee {
    int empID;
    string name;
    string department;
    float salary;
    bool isEmpty;

    Employee() {
        empID = -1;
        name = "";
        department = "";
        salary = 0.0;
        isEmpty = true;
    }
};

class HashTable {
    Employee table[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    void insert(Employee e) {
        int index = hashFunction(e.empID);
        while (!table[index].isEmpty) {
            index = (index + 1) % TABLE_SIZE;
        }
        table[index] = e;
        table[index].isEmpty = false;
        cout << "Employee record inserted at index " << index << endl;
    }

    void search(int empID) {
        int index = hashFunction(empID);
        int start = index;
        while (!table[index].isEmpty) {
            if (table[index].empID == empID) {
                cout << "Employee Found → ID: " << table[index].empID
                     << ", Name: " << table[index].name
                     << ", Department: " << table[index].department
                     << ", Salary: " << table[index].salary << endl;
                return;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == start) break;
        }
        cout << "Employee not found!" << endl;
    }

    void remove(int empID) {
        int index = hashFunction(empID);
        int start = index;
        while (!table[index].isEmpty) {
            if (table[index].empID == empID) {
                table[index].isEmpty = true;
                cout << "Employee record deleted successfully." << endl;
                return;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == start) break;
        }
        cout << "Employee not found!" << endl;
    }

    void display() {
        cout << "\n--- Employee Hash Table ---\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << i << ": ";
            if (!table[i].isEmpty)
                cout << "[ID: " << table[i].empID
                     << ", Name: " << table[i].name
                     << ", Dept: " << table[i].department
                     << ", Salary: " << table[i].salary << "]";
            else
                cout << "[Empty]";
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;
    Employee e;
    int choice;

    do {
        cout << "\n--- Employee Record System using Hashing ---\n";
        cout << "1. Insert Employee\n2. Search Employee\n3. Delete Employee\n4. Display Table\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Employee ID, Name, Department, Salary: ";
                cin >> e.empID >> e.name >> e.department >> e.salary;
                ht.insert(e);
                break;
            case 2:
                int id;
                cout << "Enter Employee ID to search: ";
                cin >> id;
                ht.search(id);
                break;
            case 3:
                cout << "Enter Employee ID to delete: ";
                cin >> id;
                ht.remove(id);
                break;
            case 4:
                ht.display();
                break;
        }
    } while (choice != 5);

    return 0;
}
// ************OUTPUT***********
// --- Employee Record System using Hashing ---
// 1. Insert Employee
// 2. Search Employee
// 3. Delete Employee
// 4. Display Table
// 5. Exit
// Enter your choice: 1
// Enter Employee ID, Name, Department, Salary: 101 Rohan IT 45000
// Employee record inserted at index 1

// --- Employee Record System using Hashing ---
// 1. Insert Employee
// 2. Search Employee
// 3. Delete Employee
// 4. Display Table
// 5. Exit
// Enter your choice: 1
// Enter Employee ID, Name, Department, Salary: 102 Priya HR 50000
// Employee record inserted at index 2

// --- Employee Record System using Hashing ---
// 1. Insert Employee
// 2. Search Employee
// 3. Delete Employee
// 4. Display Table
// 5. Exit
// Enter your choice: 1
// Enter Employee ID, Name, Department, Salary: 103 Aarav Finance 55000
// Employee record inserted at index 3

// --- Employee Record System using Hashing ---
// 1. Insert Employee
// 2. Search Employee
// 3. Delete Employee
// 4. Display Table
// 5. Exit
// Enter your choice: 4

// --- Employee Hash Table ---
// Index 0: [Empty]
// Index 1: [ID: 101, Name: Rohan, Dept: IT, Salary: 45000]
// Index 2: [ID: 102, Name: Priya, Dept: HR, Salary: 50000]
// Index 3: [ID: 103, Name: Aarav, Dept: Finance, Salary: 55000]
// Index 4: [Empty]
// Index 5: [Empty]
// Index 6: [Empty]
// Index 7: [Empty]
// Index 8: [Empty]
// Index 9: [Empty]

// --- Employee Record System using Hashing ---
// 1. Insert Employee
// 2. Search Employee
// 3. Delete Employee
// 4. Display Table
// 5. Exit
// Enter your choice: 2
// Enter Employee ID to search: 102
// Employee Found → ID: 102, Name: Priya, Department: HR, Salary: 50000

// --- Employee Record System using Hashing ---
// 1. Insert Employee
// 2. Search Employee
// 3. Delete Employee
// 4. Display Table
// 5. Exit
// Enter your choice: 3
// Enter Employee ID to delete: 101
// Employee record deleted successfully.

// --- Employee Record System using Hashing ---
// 1. Insert Employee
// 2. Search Employee
// 3. Delete Employee
// 4. Display Table
// 5. Exit
// Enter your choice: 4

// --- Employee Hash Table ---
// Index 0: [Empty]
// Index 1: [Empty]
// Index 2: [ID: 102, Name: Priya, Dept: HR, Salary: 50000]
// Index 3: [ID: 103, Name: Aarav, Dept: Finance, Salary: 55000]
// Index 4: [Empty]
// Index 5: [Empty]
// Index 6: [Empty]
// Index 7: [Empty]
// Index 8: [Empty]
// Index 9: [Empty]

// --- Employee Record System using Hashing ---
// 1. Insert Employee
// 2. Search Employee
// 3. Delete Employee
// 4. Display Table
// 5. Exit
// Enter your choice: 5

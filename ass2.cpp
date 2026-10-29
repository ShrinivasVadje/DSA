#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string name;
    int salary;
};

void display(Employee emp[], int n) {
    cout << "\n----- Employee Records -----\n";
    for (int i = 0; i < n; i++) {
        cout << i+1 << ". " << emp[i].name << "  | Salary: " << emp[i].salary << endl;
    }
    cout << "------------------------------\n";
}

void bubbleSort(Employee emp[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (emp[j].salary > emp[j+1].salary) {
                swap(emp[j], emp[j+1]);
            }
        }
    }
    cout << "\nBubble Sort Done!";
}

void insertionSort(Employee emp[], int n) {
    for (int i = 1; i < n; i++) {
        Employee key = emp[i];
        int j = i - 1;
        while (j >= 0 && emp[j].salary > key.salary) {
            emp[j+1] = emp[j];
            j--;
        }
        emp[j+1] = key;
    }
    cout << "\nInsertion Sort Done!";
}

void selectionSort(Employee emp[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (emp[j].salary < emp[minIndex].salary)
                minIndex = j;
        }
        swap(emp[i], emp[minIndex]);
    }
    cout << "\nSelection Sort Done!";
}

int partition(Employee emp[], int low, int high) {
    int pivot = emp[high].salary;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (emp[j].salary <= pivot) {
            i++;
            swap(emp[i], emp[j]);
        }
    }
    swap(emp[i+1], emp[high]);
    return i + 1;
}

void quickSort(Employee emp[], int low, int high) {
    if (low < high) {
        int pi = partition(emp, low, high);
        quickSort(emp, low, pi - 1);
        quickSort(emp, pi + 1, high);
  }
}

int main() {
    int n, choice;

    cout << "Enter number of employees: ";
    cin >> n;
    cin.ignore();

    Employee emp[50];
    for (int i = 0; i < n; i++) {
        cout << "\nEnter Employee " << i+1 << " Name: ";
        getline(cin, emp[i].name);
        cout << "Enter Salary: ";
        cin >> emp[i].salary;
        cin.ignore();
    }

    do {
        cout << "\n\n----- MENU -----";
        cout << "\n1. Bubble Sort"
             << "\n2. Insertion Sort"
             << "\n3. Selection Sort"
             << "\n4. Quick Sort"
             << "\n5. Display All Records"
             << "\n6. Exit"
             << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            bubbleSort(emp, n);
            break;

        case 2:
            insertionSort(emp, n);
            break;

        case 3:
            selectionSort(emp, n);
            break;

        case 4:
            quickSort(emp, 0, n - 1);
            cout << "\nQuick Sort Done!";
            break;

        case 5:
            display(emp, n);
            break;

        case 6:
            cout << "\nExiting...";
            break;

        default:
            cout << "\nInvalid Choice!";
        }

    } while (choice != 6);

    return 0;
}
// *******OUTPUT******
// Enter number of employees: 3

// Enter Employee 1 Name: rakesh
// Enter Salary: 40000

// Enter Employee 2 Name: jayesh
// Enter Salary: 50000

// Enter Employee 3 Name: mahesh 345342
// Enter Salary: 233453


// ----- MENU -----
// 1. Bubble Sort
// 2. Insertion Sort
// 3. Selection Sort
// 4. Quick Sort
// 5. Display All Records
// 6. Exit
// Enter your choice: 1

// Bubble Sort Done!

// ----- MENU -----
// 1. Bubble Sort
// 2. Insertion Sort
// 3. Selection Sort
// 4. Quick Sort
// 5. Display All Records
// 6. Exit
// Enter your choice: 5

// ----- Employee Records -----
// 1. rakesh  | Salary: 40000
// 2. jayesh  | Salary: 50000
// 3. mahesh 345342  | Salary: 233453
// ------------------------------


// ----- MENU -----
// 1. Bubble Sort
// 2. Insertion Sort
// 3. Selection Sort
// 4. Quick Sort
// 5. Display All Records
// 6. Exit
// Enter your choice: 6

// Exiting...

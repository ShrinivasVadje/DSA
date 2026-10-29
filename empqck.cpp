#include <iostream>
using namespace std;

struct Employee {
    string name;
    int salary;
};

int partition(Employee arr[], int low, int high) {
    int pivot = arr[high].salary;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].salary < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Employee arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;

    cout << "Enter number of employees: ";
    cin >> n;

    Employee emp[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter name and salary: ";
        cin >> emp[i].name >> emp[i].salary;
    }

    quickSort(emp, 0, n - 1);

    cout << "\nEmployees sorted by salary:\n";

    for (int i = 0; i < n; i++) {
        cout << emp[i].name << " " << emp[i].salary << endl;
    }

    return 0;
}
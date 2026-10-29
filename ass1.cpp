#include<iostream>
#include<string>
using namespace std;

void display(int n, string bkn[], int id[]) {
    if (n == 0) {
        cout << "No books in the system.\n";
        return;
    }
    cout << "\n--- Book List ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Book ID: " << id[i] << " | Title: " << bkn[i] << endl;
    }
    cout << "------------------\n";
}

void linearSearch(int n, string bkn[], int id[]) {
    cin.ignore();
    string title;
    cout << "Enter book title to search: ";
    getline(cin, title);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (bkn[i] == title) {
            cout << "\nBook Found!\n";
            cout << "Book Name: " << bkn[i] << "\n";
            cout << "Book ID: " << id[i] << "\n";
            found = 1;
            break;
        }
    }
    if (!found)
        cout << "\nBook not found!\n";
}

void binarySearch(int n, string bkn[], int id[]) {
    int key;
    cout << "Enter book ID to search: ";
    cin >> key;

    int start = 0, end = n - 1, found = 0;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (id[mid] == key) {
            cout << "\nBook  Found!\n";
            cout << "Book ID: " << id[mid] << "\n";
            cout << "Book Name: " << bkn[mid] << "\n";
            found = 1;
            break;
        } else if (key > id[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    if (!found)
        cout << "\nBook not found!\n";
}

int main() {
    const int MAX = 100;
    string bkn[MAX];
    int id[MAX];
    int n = 0;

    int choice;
    do {
        cout << "\n----- Book Search System Menu -----\n";
        cout << "1. Input book list\n";
        cout << "2. Display book list\n";
        cout << "3. Search by Book Title (Linear Search)\n";
        cout << "4. Search by Book ID (Binary Search)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "How many books do you want to enter? ";
            cin >> n;
            cin.ignore();
            for (int i = 0; i < n; i++) {
                cout << "Enter title of book " << i + 1 << ": ";
                getline(cin, bkn[i]);
                cout << "Enter book ID: ";
                cin >> id[i];
                cin.ignore();
            }
            cout << "Books added successfully!\n";
            break;
        case 2:
            display(n, bkn, id);
            break;
        case 3:
            linearSearch(n, bkn, id);
            break;
        case 4:
            binarySearch(n, bkn, id);
            break;
        case 5:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
/* OUTPUT
----- Book Search System Menu -----
1. Input book list
2. Display book list
3. Search by Book Title (Linear Search)
4. Search by Book ID (Binary Search)
5. Exit
Enter your choice: 1
How many books do you want to enter? 3
Enter title of book 1: c
Enter book ID: 101
Enter title of book 2: python
Enter book ID: 102
Enter title of book 3: c++
Enter book ID: 103
Books added successfully!

----- Book Search System Menu -----
1. Input book list
2. Display book list
3. Search by Book Title (Linear Search)
4. Search by Book ID (Binary Search)
5. Exit
Enter your choice: 3
Enter book title to search: c

Book Found!
Book Name: c
Book ID: 101

----- Book Search System Menu -----
1. Input book list
2. Display book list
3. Search by Book Title (Linear Search)
4. Search by Book ID (Binary Search)
5. Exit
Enter your choice: 4
Enter book ID to search: 102

Book Found!
Book ID: 102
Book Name: python

----- Book Search System Menu -----
1. Input book list
2. Display book list
3. Search by Book Title (Linear Search)
4. Search by Book ID (Binary Search)
5. Exit
Enter your choice: 2

--- Book List ---
Book ID: 101 | Title: c
Book ID: 102 | Title: python
Book ID: 103 | Title: c++
------------------

----- Book Search System Menu -----
1. Input book list
2. Display book list
3. Search by Book Title (Linear Search)
4. Search by Book ID (Binary Search)
5. Exit
Enter your choice: 5
Exiting the program.*/



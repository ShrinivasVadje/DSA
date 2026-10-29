#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
    Node* head;
public:
    List() {
        head = NULL;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) temp = temp->next;
            temp->next = newNode;
        }
    }

    void traverse() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void search(int val) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        int i = 0;
        while (temp != NULL) {
            if (temp->data == val) {
                cout << "Element found at index " << i << "\n";
                return;
            }
            temp = temp->next;
            i++;
        }
        cout << "Element not found\n";
    }

    void deleteValue(int val) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        if (head->data == val) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            cout << "Deleted successfully\n";
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != val) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            cout << "Value not found\n";
            return;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        cout << "Deleted successfully\n";
    }

    void sort() {
        if (head == NULL || head->next == NULL) return;
        for (Node* i = head; i != NULL; i = i->next) {
            for (Node* j = head; j->next != NULL; j = j->next) {
                if (j->data > j->next->data) {
                    swap(j->data, j->next->data);
                }
            }
        }
        cout << "List sorted successfully\n";
    }

    void concatenate(List& list1) {
        if (head == NULL) {
            head = list1.head;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = list1.head;
        }
        cout << "Lists concatenated\n";
    }
};

int main() {
    List l1, l2;
    int choice, val;

    do {
        cout << "\n--- Linked List ADT Menu ---\n";
        cout << "1. Insert\n2. Traverse\n3. Search\n4. Delete\n5. Sort\n6. Concatenate\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            l1.insert(val);
            break;
        case 2:
            l1.traverse();
            break;
        case 3:
            cout << "Enter value to search: ";
            cin >> val;
            l1.search(val);
            break;
        case 4:
            cout << "Enter value to delete: ";
            cin >> val;
            l1.deleteValue(val);
            break;
        case 5:
            l1.sort();
            break;
        case 6:
            cout << "Enter values for second list (-1 to stop):\n";
            do {
                cin >> val;
                if (val != -1) {
                    l2.insert(val);
                }
            } while (val != -1);
            l1.concatenate(l2);
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 7);

    return 0;
}
// *****OUTPUT*****
// PS C:\Users\SHRINIVAS\myfolder\DSA> cd "c:\Users\SHRINIVAS\myfolder\DSA\" ; if ($?) { g++ linkedlist.cpp -o linkedlist } ; if ($?) { .\linkedlist }

// --- Linked List ADT Menu ---
// 1. Insert
// 2. Traverse
// 3. Search
// 4. Delete
// 5. Sort
// 6. Concatenate
// 7. Exit
// Enter choice: 1
// Enter value: 10

// --- Linked List ADT Menu ---
// 1. Insert
// 2. Traverse
// 3. Search
// 4. Delete
// 5. Sort
// 6. Concatenate
// 7. Exit
// Enter choice: 1
// Enter value: 11

// --- Linked List ADT Menu ---
// 1. Insert
// 2. Traverse
// 3. Search
// 4. Delete
// 5. Sort
// 6. Concatenate
// 7. Exit
// Enter choice: 1
// Enter value: 12

// --- Linked List ADT Menu ---
// 1. Insert
// 2. Traverse
// 3. Search
// 4. Delete
// 5. Sort
// 6. Concatenate
// 7. Exit
// Enter choice: 2
// 10 -> 11 -> 12 -> NULL

// --- Linked List ADT Menu ---
// 1. Insert
// 2. Traverse
// 3. Search
// 4. Delete
// 5. Sort
// 6. Concatenate
// 7. Exit
// Enter choice: 3
// Enter value to search: 11
// Element found at index 1

// --- Linked List ADT Menu ---
// 1. Insert
// 2. Traverse
// 3. Search
// 4. Delete
// 5. Sort
// 6. Concatenate
// 7. Exit
// Enter choice: 4
// Enter value to delete: 13
// Value not found

// --- Linked List ADT Menu ---
// 1. Insert
// 2. Traverse
// 3. Search
// 4. Delete
// 5. Sort
// 6. Concatenate
// 7. Exit
// Enter choice: 5
// List sorted successfully

// --- Linked List ADT Menu ---
// 1. Insert
// 2. Traverse
// 3. Search
// 4. Delete
// 5. Sort
// 6. Concatenate
// 7. Exit
// Enter choice: 2
// 10 -> 11 -> 12 -> NULL

// --- Linked List ADT Menu ---
// 1. Insert
// 2. Traverse
// 3. Search
// 4. Delete
// 5. Sort
// 6. Concatenate
// 7. Exit
// Enter choice: 6
// Enter values for second list (-1 to stop):
// 9
// 8
// 7
// 6
// 5
// 4
// 3
// 2
// 1
// -1
// Lists concatenated

// --- Linked List ADT Menu ---
// 1. Insert
// 2. Traverse
// 3. Search
// 4. Delete
// 5. Sort
// 6. Concatenate
// 7. Exit
// Enter choice: 2
// 10 -> 11 -> 12 -> 9 -> 8 -> 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1 -> NULL

// --- Linked List ADT Menu ---
// 1. Insert
// 2. Traverse
// 3. Search
// 4. Delete
// 5. Sort
// 6. Concatenate
// 7. Exit
// Enter choice: 5
// List sorted successfully

// --- Linked List ADT Menu ---
// 1. Insert
// 2. Traverse
// 3. Search
// 4. Delete
// 5. Sort
// 6. Concatenate
// 7. Exit
// Enter choice: 2
// 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> 11 -> 12 -> NULL

// --- Linked List ADT Menu ---
// 1. Insert
// 2. Traverse
// 3. Search
// 4. Delete
// 5. Sort
// 6. Concatenate
// 7. Exit
// Enter choice: 7
// Exiting...

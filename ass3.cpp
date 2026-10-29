#include <iostream>
#include <string>
using namespace std;

struct Node {
    string url;
    Node* next;
};

class Stack {
public:
    Node* top;
    Stack() { top = NULL; }

    void push(string url) {
        Node* newNode = new Node();
        newNode->url = url;
        newNode->next = top;
        top = newNode;
    }

    string pop() {
        if (top == NULL)
            return "NULL";
        Node* temp = top;
        string val = temp->url;
        top = top->next;
        delete temp;
        return val;
    }

    bool empty() {
        return top == NULL;
    }

    void display() {
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->url << endl;
            temp = temp->next;
        }
    }

    void clear() {
        while (!empty()) pop();
    }
};

int main() {
    Stack backStack;
    Stack forwardStack;
    string current = "Home";
    int choice;
    string url;

    do {
        cout << "\n=== Browser Navigation System ===";
        cout << "\nCurrent Page: " << current;
        cout << "\n1. Visit New Page";
        cout << "\n2. Back";
        cout << "\n3. Forward";
        cout << "\n4. Show Back History";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            cout << "Enter URL: ";
            cin >> url;
            backStack.push(current);
            current = url;
            forwardStack.clear();
            break;

        case 2:
            if (!backStack.empty()) {
                forwardStack.push(current);
                current = backStack.pop();
            } else {
                cout << "\nNo pages behind!";
            }
            break;

        case 3:
            if (!forwardStack.empty()) {
                backStack.push(current);
                current = forwardStack.pop();
            } else {
                cout << "\nNo forward pages!";
            }
            break;

        case 4:
            cout << "\n--- Back History ---\n";
            backStack.display();
            break;

        case 5:
            cout << "\nExiting...";
            break;

        default:
            cout << "\nInvalid choice!";
        }

    } while(choice != 5);

    return 0;
}
// ********OUTPUT***********
// === Browser Navigation System ===
// Current Page: Home
// 1. Visit New Page
// 2. Back
// 3. Forward
// 4. Show Back History
// 5. Exit
// Enter your choice: 1
// Enter URL: goggle

// === Browser Navigation System ===
// Current Page: goggle
// 1. Visit New Page
// 2. Back
// 3. Forward
// 4. Show Back History
// 5. Exit
// Enter your choice: 1
// Enter URL: hotstar  

// === Browser Navigation System ===
// Current Page: hotstar
// 1. Visit New Page
// 2. Back
// 3. Forward
// 4. Show Back History
// 5. Exit
// Enter your choice: 4

// --- Back History ---
// goggle
// Home

// === Browser Navigation System ===
// Current Page: hotstar
// 1. Visit New Page
// 2. Back
// 3. Forward
// 4. Show Back History
// 5. Exit
// Enter your choice: 2

// === Browser Navigation System ===
// Current Page: goggle
// 1. Visit New Page
// 2. Back
// 3. Forward
// 4. Show Back History
// 5. Exit
// Enter your choice: 3

// === Browser Navigation System ===
// Current Page: hotstar
// 1. Visit New Page
// 2. Back
// 3. Forward
// 4. Show Back History
// 5. Exit
// Enter your choice: 5

// Exiting...
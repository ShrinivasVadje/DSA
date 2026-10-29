#include <iostream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    Student* left;
    Student* right;

    Student(int r, string n) : roll(r), name(n), left(NULL), right(NULL) {}
};

class BST {
private:
    Student* root;

    Student* insert(Student* node, int roll, string name) {
        if (!node) return new Student(roll, name);
        if (roll < node->roll)
            node->left = insert(node->left, roll, name);
        else if (roll > node->roll)
            node->right = insert(node->right, roll, name);
        else
            cout << "Duplicate Roll Number not allowed!\n";
        return node;
    }

    Student* search(Student* node, int roll) {
        if (!node || node->roll == roll) return node;
        if (roll < node->roll)
            return search(node->left, roll);
        return search(node->right, roll);
    }

    Student* findMin(Student* node) {
        while (node && node->left)
            node = node->left;
        return node;
    }

    Student* deleteNode(Student* node, int roll) {
        if (!node) return node;
        if (roll < node->roll)
            node->left = deleteNode(node->left, roll);
        else if (roll > node->roll)
            node->right = deleteNode(node->right, roll);
        else {
            if (!node->left) {
                Student* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Student* temp = node->left;
                delete node;
                return temp;
            }
            Student* temp = findMin(node->right);
            node->roll = temp->roll;
            node->name = temp->name;
            node->right = deleteNode(node->right, temp->roll);
        }
        return node;
    }

    void inorder(Student* node) {
        if (node) {
            inorder(node->left);
            cout << node->roll << " - " << node->name << "  ";
            inorder(node->right);
        }
    }

    void preorder(Student* node) {
        if (node) {
            cout << node->roll << " - " << node->name << "  ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Student* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->roll << " - " << node->name << "  ";
        }
    }

public:
    BST() : root(NULL) {}

    void insert(int roll, string name) {
        root = insert(root, roll, name);
    }

    void search(int roll) {
        Student* res = search(root, roll);
        if (res)
            cout << "Found: " << res->roll << " - " << res->name << "\n";
        else
            cout << "Student not found!\n";
    }

    void deleteStudent(int roll) {
        root = deleteNode(root, roll);
    }

    void displayInorder() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << "\n";
    }

    void displayPreorder() {
        cout << "Preorder Traversal: ";
        preorder(root);
        cout << "\n";
    }

    void displayPostorder() {
        cout << "Postorder Traversal: ";
        postorder(root);
        cout << "\n";
    }

    void displayLevelOrder() {
        if (!root) return;

        Student* arr[100];
        int front = 0, rear = 0;

        arr[rear++] = root;

        cout << "Level Order Traversal: ";

        while (front < rear) {
            Student* curr = arr[front++];
            cout << curr->roll << " - " << curr->name << "  ";

            if (curr->left) arr[rear++] = curr->left;
            if (curr->right) arr[rear++] = curr->right;
        }
        cout << "\n";
    }
};

int main() {
    BST bst;
    int choice, roll;
    string name;

    do {
        cout << "\n--- Student Record System using BST ---\n";
        cout << "1. Insert Student\n";
        cout << "2. Search Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Display Inorder Traversal\n";
        cout << "5. Display Preorder Traversal\n";
        cout << "6. Display Postorder Traversal\n";
        cout << "7. Display Level Order Traversal\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Roll Number: ";
                cin >> roll;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                bst.insert(roll, name);
                break;
            case 2:
                cout << "Enter Roll Number to search: ";
                cin >> roll;
                bst.search(roll);
                break;
            case 3:
                cout << "Enter Roll Number to delete: ";
                cin >> roll;
                bst.deleteStudent(roll);
                break;
            case 4:
                bst.displayInorder();
                break;
            case 5:
                bst.displayPreorder();
                break;
            case 6:
                bst.displayPostorder();
                break;
            case 7:
                bst.displayLevelOrder();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
// *********OUTPUT**********
// --- Student Record System using BST ---
// 1. Insert Student
// 2. Search Student
// 3. Delete Student
// 4. Display Inorder Traversal
// 5. Display Preorder Traversal
// 6. Display Postorder Traversal
// 7. Display Level Order Traversal
// 0. Exit
// Enter choice: 1
// Enter Roll Number: 33
// Enter Name: Sayali

// --- Student Record System using BST ---
// 1. Insert Student
// 2. Search Student
// 3. Delete Student
// 4. Display Inorder Traversal
// 5. Display Preorder Traversal
// 6. Display Postorder Traversal
// 7. Display Level Order Traversal
// 0. Exit
// Enter choice: 1
// Enter Roll Number: 62
// Enter Name: sanap

// --- Student Record System using BST ---
// 1. Insert Student
// 2. Search Student
// 3. Delete Student
// 4. Display Inorder Traversal
// 5. Display Preorder Traversal
// 6. Display Postorder Traversal
// 7. Display Level Order Traversal
// 0. Exit
// Enter choice: 2
// Enter Roll Number to search: 33
// Found: 33 - Sayali

// --- Student Record System using BST ---
// 1. Insert Student
// 2. Search Student
// 3. Delete Student
// 4. Display Inorder Traversal
// 5. Display Preorder Traversal
// 6. Display Postorder Traversal
// 7. Display Level Order Traversal
// 0. Exit
// Enter choice: 3
// Enter Roll Number to delete: 62

// --- Student Record System using BST ---
// 1. Insert Student
// 2. Search Student
// 3. Delete Student
// 4. Display Inorder Traversal
// 5. Display Preorder Traversal
// 6. Display Postorder Traversal
// 7. Display Level Order Traversal
// 0. Exit
// Enter choice: 4
// Inorder Traversal: 33 - Sayali  

// --- Student Record System using BST ---
// 1. Insert Student
// 2. Search Student
// 3. Delete Student
// 4. Display Inorder Traversal
// 5. Display Preorder Traversal
// 6. Display Postorder Traversal
// 7. Display Level Order Traversal
// 0. Exit
// Enter choice: 0
// Exiting...
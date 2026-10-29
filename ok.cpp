 #include <iostream>
 #include <string>
 using namespace std;
 class Node {
 public:
    int id;
    string name;
    float salary;
    Node *left, *right;
    Node(int i, string n, float s) {
        id = i; name = n; salary = s; left = right = NULL;
    }
 };
 class BST {
    Node* root;
    Node* insert(Node* root, int id, string name, float salary) {
        if (root == NULL) return new Node(id, name, salary);
        if (id < root->id) root->left = insert(root->left, id, name, salary);
        else root->right = insert(root->right, id, name, salary);
        return root;
    }
    void inorder(Node* root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->id << "\t" << root->name << "\t" << root->salary << endl;
            inorder(root->right);
        }
    }
 public:
    BST() { root = NULL; }
    void insert(int id, string name, float salary) { root = insert(root, id, name, salary); }
    void display() { inorder(root); }
 };
 int main() {
    BST bst;
    bst.insert(101, "Raj", 50000);
    bst.insert(105, "Neha", 62000);
    bst.display();
    return 0;
 }
#include <iostream>   // इनपुट-आउटपुट के लिए लाइब्रेरी (cout, cin)
#include <string>     // string टाइप (नाम रखने के लिए)
using namespace std;  // हर बार std:: लिखने से बचने के लिए

// ------------------- STUDENT NODE CLASS -------------------
class student {
public:
    int roll;          // रोल नंबर स्टोर करने के लिए
    string name;       // छात्र का नाम स्टोर करने के लिए
    student *left, *right; // लेफ्ट और राइट चाइल्ड (ट्री के लिए)

    // ✅ Constructor (fix: reverse assignment)
    student(int r, string n) {
        roll = r;          // दिए गए रोल नंबर को इस नोड में डालना
        name = n;          // दिए गए नाम को इस नोड में डालना
        left = right = NULL; // शुरू में कोई बच्चा नहीं होता (NULL)
    }
};

// ------------------- BST CLASS -------------------
class BST {
private:
    student *root;     // ट्री का root pointer (शुरुआत का नोड)

    // ✅ Node को insert करने का recursive function
    student* insertnode(student* node, int roll, string name) {
        if (!node) {   // अगर current node NULL है मतलब यहां नया नोड लगेगा
            return new student(roll, name);  // नया student नोड बनाओ और रिटर्न करो
        }
        else if (roll < node->roll) { // अगर रोल छोटा है तो left side में जाओ
            node->left = insertnode(node->left, roll, name);
        }
        else if (roll > node->roll) { // अगर रोल बड़ा है तो right side में जाओ
            node->right = insertnode(node->right, roll, name);
        }
        else { // अगर रोल नंबर पहले से मौजूद है
            cout << "Duplicate roll number not allowed!\n"; // डुप्लिकेट नहीं चलेगा
        }
        return node;   // हर बार अपडेटेड node वापस भेजो
    }

    // ✅ Search function (recursive)
    student* searchnode(student* node, int roll) {
        if (!node || node->roll == roll)  // अगर NULL या रोल मिल गया
            return node; // तो वही node वापस करो
        if (roll < node->roll) // अगर छोटा रोल है तो left में ढूंढो
            return searchnode(node->left, roll);
        else                   // वरना right में ढूंढो
            return searchnode(node->right, roll);
    }
    // ✅ Minimum value (सबसे छोटा रोल नंबर वाला नोड ढूंढना)
    student* findmin(student* node) {
        while (node && node->left) // जब तक left child है, चलते रहो
            node = node->left;     // सबसे बाएं वाला नोड सबसे छोटा होता है
        return node;               // वही नोड रिटर्न करो
    }

    // ✅ Delete function (तीनों cases handle करता है)
    student* todelete(student* node, int roll) {
        if (!node) // अगर node NULL है तो वापस लौटो
            return node;

        if (roll < node->roll) // अगर रोल छोटा है तो left में जाओ
            node->left = todelete(node->left, roll);
        else if (roll > node->roll) // अगर बड़ा है तो right में जाओ
            node->right = todelete(node->right, roll);
        else { // अब रोल मिल गया, delete करना है
            // Case 1: कोई left child नहीं है
            if (!node->left) {
                student* temp = node->right; // right child संभालेगा
                delete node; // पुराना node delete करो
                return temp; // नया root बनाओ
            }
            // Case 2: कोई right child नहीं है
            else if (!node->right) {
                student* temp = node->left;
                delete node;
                return temp;
            }
            // Case 3: दोनो बच्चे हैं (left & right)
            student* temp = findmin(node->right); // right subtree का सबसे छोटा नोड लो
            node->roll = temp->roll;   // उसी का रोल और नाम कॉपी करो
            node->name = temp->name;
            node->right = todelete(node->right, temp->roll); // उस नोड को हटाओ
        }
        return node; // अपडेटेड node वापस भेजो
    }

    // ✅ Inorder Traversal (Left → Root → Right)
    void inorder(student* node) {
        if (node) {
            inorder(node->left); // पहले left subtree
            cout << node->roll << "-" << node->name << " "; // फिर current node
            inorder(node->right); // फिर right subtree
        }
    }

    // ✅ Preorder Traversal (Root → Left → Right)
    void preorder(student* node) {
        if (node) {
            cout << node->roll << "-" << node->name << " "; // पहले current node
            preorder(node->left); // फिर left
            preorder(node->right); // फिर right
        }
    }

    // ✅ Postorder Traversal (Left → Right → Root)
    void postorder(student* node) {
        if (node) {
            postorder(node->left);  // पहले left
            postorder(node->right); // फिर right
            cout << node->roll << "-" << node->name << " "; // अंत में root
        }
    }
public:
    // ✅ Constructor (root NULL से शुरू)
    BST() { root = NULL; }

    // ✅ Public insert (user के लिए)
    void insert(int roll, string name) {
        root = insertnode(root, roll, name);
    }

    // ✅ Search function (user के लिए)
    void search(int roll) {
        student* s = searchnode(root, roll); // recursive call से खोजो
        if (s) // अगर मिला
            cout << "Student Found: " << s->roll << " - " << s->name << "\n";
        else   // नहीं मिला
            cout << "Student not found!\n";
    }

    // ✅ Delete function (user के लिए)
    void deleteStudent(int roll) {
        root = todelete(root, roll); // recursive delete
    }

    // ✅ Display traversals
    void displayInorder() {
        cout << "Inorder: ";
        inorder(root);  // inorder traversal print करना
        cout << "\n";
    }

    void displayPreorder() {
        cout << "Preorder: ";
        preorder(root);
        cout << "\n";
    }

    void displayPostorder() {
        cout << "Postorder: ";
        postorder(root);
        cout << "\n";
    }

    // ✅ Level Order Traversal (BFS)
    void BFS() {
        if (!root) return; // अगर ट्री खाली है तो कुछ मत करो
        student* que[100]; // एक simple array queue के लिए
        int front = 0, rear = 0;
        que[rear++] = root; // root को enqueue करो

        while (front < rear) { // जब तक queue खाली न हो
            student* temp = que[front++]; // एक नोड निकालो (dequeue)
            cout << temp->roll << "-" << temp->name << " "; // प्रिंट करो
            if (temp->left)  // अगर left child है तो उसे queue में डालो
                que[rear++] = temp->left;
            if (temp->right) // अगर right child है तो उसे भी queue में डालो
                que[rear++] = temp->right;
        }
        cout << "\n";
    }
};

// ------------------- MAIN FUNCTION -------------------
int main() {
    BST b; // BST का object बनाना

    b.insert(10, "Vishal");     // root node
    b.insert(5, "Shrinivas");   // left child
    b.insert(15, "Amit");       // right child

    b.displayInorder();   // inorder traversal
    b.displayPreorder();  // preorder traversal
    b.displayPostorder(); // postorder traversal

    b.search(5);          // 5 वाले student को खोजो
    b.deleteStudent(10);  // रोल नंबर 10 वाला नोड हटाओ
    b.displayInorder();   // delete के बाद inorder traversal

    b.BFS(); // Level order traversal (BFS)
    return 0;
}

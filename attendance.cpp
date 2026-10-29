#include<iostream>
using namespace std;

class Node {
public:
    int roll;
    string name;
    int total, present;
    float percent;
    Node* next;

    Node(int r, string n, int t, int p) {
        roll = r;
        name = n;
        total = t;
        present = p;
        percent = (float)present / total * 100;
        next = NULL;
    }
};

class Attendance {
    Node* head;
public:
    Attendance() {
        head = NULL;
    }

    void addStudent(int roll, string name, int total, int present) {
        Node* newNode = new Node(roll, name, total, present);
        if(head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << "Record Added.\n";
    }

    void display() {
        if(head == NULL) {
            cout << "No Records.\n";
            return;
        }
        Node* temp = head;
        while(temp != NULL) {
            cout << "Roll: " << temp->roll << ", Name: " << temp->name 
                 << ", Percentage: " << temp->percent << "%\n";
            temp = temp->next;
        }
    }

    void searchStudent(int r) {
        Node* temp = head;
        while(temp != NULL) {
            if(temp->roll == r) {
                cout << "Record Found\n";
                cout << "Roll: " << temp->roll << ", Name: " << temp->name
                     << ", Att %: " << temp->percent << "%\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Not Found.\n";
    }

    void showDefaulters() {
        if(head == NULL) {
            cout << "No Records.\n";
            return;
        }
        Node* temp = head;
        int flag = 0;
        while(temp != NULL) {
            if(temp->percent < 75) {
                cout << "Roll: " << temp->roll << ", Name: " << temp->name
                     << ", Att %: " << temp->percent << "%\n";
                flag = 1;
            }
            temp = temp->next;
        }
        if(flag == 0) cout << "No Defaulters.\n";
    }
};

int main() {
    Attendance obj;
    int ch;
    do {
        cout << "\n1.Add Attendance\n2.Display\n3.Search\n4.Defaulters\n5.Exit\n";
        cin >> ch;
        if(ch == 1) {
            int r, t, p;
            string n;
            cout << "Enter Roll: ";
            cin >> r;
            cout << "Name: ";
            cin >> n;
            cout << "Total Lectures: ";
            cin >> t;
            cout << "Present: ";
            cin >> p;
            obj.addStudent(r, n, t, p);
        }
        else if(ch == 2) obj.display();
        else if(ch == 3) {
            int r;
            cout << "Enter Roll: ";
            cin >> r;
            obj.searchStudent(r);
        }
        else if(ch == 4) obj.showDefaulters();
    } while(ch != 5);

    return 0;
}

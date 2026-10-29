#include <iostream>
using namespace std;

struct Node {
    string name;
    int priority;
    Node* next;
    Node(string n, int p=0) : name(n), priority(p), next(nullptr) {}
};


class Queue {
    Node* front;
    Node* rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(string name) {
        Node* temp = new Node(name);
        if (!rear) front = rear = temp;
        else { rear->next = temp; rear = temp; }
    }

    void dequeue() {
        if (!front) { cout << "Queue empty\n"; return; }
        cout << front->name << " served\n";
        Node* temp = front; front = front->next;
        if (!front) rear = nullptr;
        delete temp;
    }

    void display() {
        Node* temp = front;
        while (temp) { cout << temp->name << " -> "; temp = temp->next; }
        cout << "NULL\n";
    }
};

class PriorityQueue {
    Node* front;
public:
    PriorityQueue() : front(nullptr) {}

    void enqueue(string name, int pr) {
        Node* temp = new Node(name, pr);
        if (!front || pr < front->priority) {
            temp->next = front; front = temp;
        } else {
            Node* curr = front;
            while (curr->next && curr->next->priority <= pr) curr = curr->next;
            temp->next = curr->next;
            curr->next = temp;
        }
    }

    void dequeue() {
        if (!front) { cout << "Priority queue empty\n"; return; }
        cout << front->name << " served (priority=" << front->priority << ")\n";
        Node* temp = front; front = front->next;
        delete temp;
    }

    void display() {
        Node* temp = front;
        while (temp) { cout << temp->name << "(" << temp->priority << ") -> "; temp = temp->next; }
        cout << "NULL\n";
    }
};

class CircularQueue {
    Node* rear;
public:
    CircularQueue() : rear(nullptr) {}

    void enqueue(string name) {
        Node* temp = new Node(name);
        if (!rear) {
            rear = temp;
            rear->next = rear;
        } else {
            temp->next = rear->next;
            rear->next = temp;
            rear = temp;
        }
    }

    void dequeue() {
        if (!rear) { cout << "Circular queue empty\n"; return; }
        Node* front = rear->next;
        cout << front->name << " served\n";
        if (rear == front) {
            delete front;
            rear = nullptr;
        } else {
            rear->next = front->next;
            delete front;
        }
    }

    void display() {
        if (!rear) { cout << "Circular queue empty\n"; return; }
        Node* temp = rear->next;
        do {
            cout << temp->name << " -> ";
            temp = temp->next;
        } while (temp != rear->next);
        cout << "(back to front)\n";
    }
};

int main() {
    Queue q;
    PriorityQueue pq;
    CircularQueue cq;

    cout << "===== Normal Queue Demo =====\n";
    q.enqueue("modi");
    q.enqueue("gandhi");
    q.display();
    q.dequeue();
    q.display();

    cout << "\n===== Priority Queue Demo =====\n";
    pq.enqueue("kohli", 1);
    pq.enqueue("dhoni", 3);
    pq.enqueue("sharma", 2);
    pq.display();
    pq.dequeue();
    pq.display();

    cout << "\n===== Circular Queue Demo =====\n";
    cq.enqueue("Bhide");
    cq.enqueue("ayyer");
    cq.enqueue("jethalal");
    cq.display();
    cq.dequeue();
    cq.display();

    return 0;
}
// *****OUTPUT*****
// ===== Normal Queue Demo =====
// modi -> gandhi -> NULL
// modi served
// gandhi -> NULL

// ===== Priority Queue Demo =====
// kohli(1) -> sharma(2) -> dhoni(3) -> NULL
// kohli served (priority=1)
// sharma(2) -> dhoni(3) -> NULL

// ===== Circular Queue Demo =====
// Bhide -> ayyer -> jethalal -> (back to front)
// Bhide served
// ayyer -> jethalal -> (back to front)

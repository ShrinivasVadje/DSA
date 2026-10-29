#include <iostream>
using namespace std;

class TicketQueue {
private:
    int front, rear, capacity;
    string* queue;

public:
    TicketQueue(int size) {
        capacity = size;
        front = rear = -1;
        queue = new string[capacity];
    }

    ~TicketQueue() {
        delete[] queue;
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void bookTicket(string name) {
        if (isFull()) {
            cout << "Booking Full! No more tickets available.\n";
            return;
        }

        if (isEmpty()) {
            front = 0;
        }

        rear++;
        queue[rear] = name;
        cout << "Ticket booked for " << name << ".\n";
    }

    void cancelTicket() {
        if (isEmpty()) {
            cout << "No bookings to cancel.\n";
            return;
        }

        cout << "Ticket cancelled for " << queue[front] << ".\n";
        front++;
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "No current bookings.\n";
            return;
        }

        cout << "Current Bookings:\n";
        for (int i = front; i <= rear; i++) {
            cout << " - " << queue[i] << "\n";
        }
    }
};

int main() {
    int choice;
    string name;
    TicketQueue tq(5);  // Set capacity to 5

    do {
        cout << "\n--- Ticket Booking Menu ---\n";
        cout << "1. Book Ticket\n";
        cout << "2. Cancel Ticket\n";
        cout << "3. View Bookings\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name to book ticket: ";
                cin >> name;
                tq.bookTicket(name);
                break;
            case 2:
                tq.cancelTicket();
                break;
            case 3:
                tq.displayQueue();
                break;
            case 4:
                cout << "Exiting Ticket Booking System.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

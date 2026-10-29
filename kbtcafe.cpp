#include <iostream>
#include <string>
using namespace std;

struct Order {
    int orderID;
    string itemName;
    int quantity;
    Order* next;
};

class CanteenQueue {
public:
    Order* front;
    Order* rear;

    CanteenQueue() {
        front = rear = NULL;
    }

    void placeOrder(int id, string name, int qty) {
        Order* newOrder = new Order;
        newOrder->orderID = id;
        newOrder->itemName = name;
        newOrder->quantity = qty;
        newOrder->next = NULL;

        if (rear == NULL) {
            front = rear = newOrder;
        } else {
            rear->next = newOrder;
            rear = newOrder;
        }
        cout << "Order Placed Successfully\n";
    }

    void serveOrder() {
        if (front == NULL) {
            cout << "No orders available\n";
            return;
        }
        Order* temp = front;
        cout << "Serving Order:\n";
        cout << "Order ID: " << temp->orderID << endl;
        cout << "Item: " << temp->itemName << endl;
        cout << "Quantity: " << temp->quantity << endl;

        front = front->next;
        if (front == NULL) rear = NULL;
        delete temp;
    }

    void displayOrders() {
        if (front == NULL) {
            cout << "No pending orders\n";
            return;
        }
        Order* temp = front;
        cout << "\nPending Orders:\n";
        while (temp != NULL) {
            cout << "Order ID: " << temp->orderID
                 << "  Item: " << temp->itemName
                 << "  Qty: " << temp->quantity << endl;
            temp = temp->next;
        }
    }
};

int main() {
    CanteenQueue cafe;
    int choice, id, qty;
    string item;

    while (true) {
        cout << "\n--- KBT Cafe Menu ---\n";
        cout << "1. Place Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display All Orders\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Order ID: ";
            cin >> id;
            cout << "Enter Item Name: ";
            cin >> item;
            cout << "Enter Quantity: ";
            cin >> qty;
            cafe.placeOrder(id, item, qty);
        }
        else if (choice == 2) {
            cafe.serveOrder();
        }
        else if (choice == 3) {
            cafe.displayOrders();
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Invalid Choice\n";
        }
    }
    return 0;
}

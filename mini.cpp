#include <iostream>
#include <string>
using namespace std;

struct Order {
    int orderID;
    string farmerName;
    string fertilizerType;
    int quantity;
    Order* next;
};

class FertilizerDeliveryChain {
private:
    Order* last;

public:
    FertilizerDeliveryChain() {
        last = nullptr;
    }

    void addOrder(int id, string name, string type, int qty) {
        Order* newOrder = new Order;
        newOrder->orderID = id;
        newOrder->farmerName = name;
        newOrder->fertilizerType = type;
        newOrder->quantity = qty;
        newOrder->next = nullptr;

        if (last == nullptr) {
            last = newOrder;
            last->next = last;
        } else {
            newOrder->next = last->next;
            last->next = newOrder;
            last = newOrder;
        }
        cout << "Order Added Successfully!\n";
    }

    void displayOrders() {
        if (last == nullptr) {
            cout << "No Orders in the System.\n";
            return;
        }

        cout << "\nFertilizer Delivery Orders:\n";
        Order* temp = last->next;
        do {
            cout << "------------------------------\n";
            cout << "Order ID: " << temp->orderID << endl;
            cout << "Farmer Name: " << temp->farmerName << endl;
            cout << "Fertilizer Type: " << temp->fertilizerType << endl;
            cout << "Quantity: " << temp->quantity << " kg\n";
            temp = temp->next;
        } while (temp != last->next);
        cout << "------------------------------\n";
    }

    void searchOrder(int id) {
        if (last == nullptr) {
            cout << "No Orders to Search.\n";
            return;
        }

        Order* temp = last->next;
        bool found = false;
        do {
            if (temp->orderID == id) {
                cout << "\nOrder Found:\n";
                cout << "Farmer: " << temp->farmerName << endl;
                cout << "Fertilizer: " << temp->fertilizerType << endl;
                cout << "Quantity: " << temp->quantity << " kg\n";
                found = true;
                break;
            }
            temp = temp->next;
        } while (temp != last->next);

        if (!found)
            cout << "Order ID " << id << " not found.\n";
    }

    void deliverOrder(int id) {
        if (last == nullptr) {
            cout << "No Orders to Deliver.\n";
            return;
        }

        Order* curr = last->next;
        Order* prev = last;
        bool found = false;

        do {
            if (curr->orderID == id) {
                found = true;
                if (curr == last && curr->next == last) {
                    last = nullptr;
                } else {
                    if (curr == last->next)
                        last->next = curr->next;
                    else if (curr == last)
                        last = prev;
                    prev->next = curr->next;
                }
                delete curr;
                cout << "Order ID " << id << " Delivered Successfully!\n";
                break;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != last->next);

        if (!found)
            cout << "Order ID " << id << " not found for delivery.\n";
    }
};

int main() {
    FertilizerDeliveryChain fdc;
    int choice, id, qty;
    string name, type;

    do {
        cout << "\n====== Fertilizer Delivery Chain Menu ======\n";
        cout << "1. Add New Order\n";
        cout << "2. Display All Orders\n";
        cout << "3. Search Order by ID\n";
        cout << "4. Deliver an Order\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Order ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Farmer Name: ";
            getline(cin, name);
            cout << "Enter Fertilizer Type: ";
            getline(cin, type);
            cout << "Enter Quantity (kg): ";
            cin >> qty;
            fdc.addOrder(id, name, type, qty);
            break;

        case 2:
            fdc.displayOrders();
            break;

        case 3:
            cout << "Enter Order ID to Search: ";
            cin >> id;
            fdc.searchOrder(id);
            break;

        case 4:
            cout << "Enter Order ID to Deliver: ";
            cin >> id;
            fdc.deliverOrder(id);
            break;

        case 5:
            cout << "Exiting System.\n";
            break;

        default:
            cout << "Invalid Choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

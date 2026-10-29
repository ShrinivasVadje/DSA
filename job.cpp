#include <iostream>
using namespace std;

class Job {
public:
    char id;
    int deadline;
    int profit;
};

int main() {
    int n;

    cout << "Enter number of jobs: ";
    cin >> n;

    Job job[20];

    cout << "Enter Job ID, Deadline and Profit:\n";

    for (int i = 0; i < n; i++) {
        cin >> job[i].id >> job[i].deadline >> job[i].profit;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (job[i].profit < job[j].profit) {
                Job temp = job[i];
                job[i] = job[j];
                job[j] = temp;
            }
        }
    }

    int slot[20];

    for (int i = 0; i < 20; i++) {
        slot[i] = -1;
    }

    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = job[i].deadline; j >= 1; j--) {
            if (slot[j] == -1) {
                slot[j] = i;
                totalProfit = totalProfit + job[i].profit;
                break;
            }
        }
    }

    cout << "\nScheduled Jobs: ";

    for (int i = 1; i < 20; i++) {
        if (slot[i] != -1) {
            cout << job[slot[i]].id << " ";
        }
    }

    cout << "\nMaximum Profit = " << totalProfit;

    return 0;
}
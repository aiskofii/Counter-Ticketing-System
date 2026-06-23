#include <iostream>
#include <string>
#include "BankQueue.h"

using namespace std;

void printMenu() {
    cout << "\n";
    cout << "  =========================================\n";
    cout << "       BANK QUEUE MANAGEMENT SYSTEM\n";
    cout << "  =========================================\n";
    cout << "  1. Add new customer to queue  (Enqueue)\n";
    cout << "  2. Call next customer         (Dequeue)\n";
    cout << "  3. View front of queue        (Peek)\n";
    cout << "  4. Display full queue\n";
    cout << "  5. Exit\n";
    cout << "  -----------------------------------------\n";
    cout << "  Enter choice: ";
}

int main() {
    BankQueue queue;
    int choice;
    string name;

    while (true) {
        printMenu();
        cin >> choice;

        // Guard against invalid (non-integer) input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\n  [ERROR] Invalid input. Please enter a number (1-5).\n";
            continue;
        }
        cin.ignore(); // Clear leftover newline before getline

        cout << "\n";

        switch (choice) {

            // ---- Option 1: Enqueue -------------------------
        case 1:
            cout << "  Enter customer name: ";
            getline(cin, name);
            if (name.empty()) {
                cout << "  [ERROR] Name cannot be empty.\n";
            }
            else if (queue.enqueue(name)) {
                cout << "  [OK] \"" << name << "\" has been added to the queue.\n";
                cout << "  Queue size: " << queue.getSize() << " customer(s).\n";
            }
            break;

            // ---- Option 2: Dequeue -------------------------
        case 2:
            if (queue.isEmpty()) {
                cout << "  [ERROR] The queue is empty. No customers to serve.\n";
            }
            else {
                string served = queue.dequeue();
                cout << "  [OK] Now serving: \"" << served << "\". Please proceed to the counter.\n";
                cout << "  Remaining in queue: " << queue.getSize() << " customer(s).\n";
            }
            break;

            // ---- Option 3: Peek ----------------------------
        case 3:
            if (queue.isEmpty()) {
                cout << "  [INFO] The queue is empty.\n";
            }
            else {
                cout << "  [INFO] Next customer at the front: \"" << queue.peek() << "\"\n";
            }
            break;

            // ---- Option 4: Display full queue --------------
        case 4:
            queue.displayQueue();
            break;

            // ---- Option 5: Exit ----------------------------
        case 5:
            cout << "  Thank you for using the Bank Queue System. Goodbye!\n\n";
            return 0;

            // ---- Default: Invalid choice -------------------
        default:
            cout << "  [ERROR] Invalid choice. Please enter a number between 1 and 5.\n";
            break;
        }
    }

    return 0;
}
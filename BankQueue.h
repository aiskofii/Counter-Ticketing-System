#pragma once

#include <iostream>
using namespace std;

class BankQueue {
private:
    static const int MAX_SIZE = 100;
    string customers[MAX_SIZE];
    int front;
    int rear;
    int count;

public:
    // Constructor
    BankQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == MAX_SIZE;
    }

    int getSize() const {
        return count;
    }

    bool enqueue(const string& customerName) {
        if (isFull()) {
            cout << "\n  [ERROR] Queue is full. Cannot add more customers.\n";
            return false;
        }
        // Circular index wrap-around
        rear = (rear + 1) % MAX_SIZE;
        customers[rear] = customerName;
        count++;
        return true;
    }

    string dequeue() {
        if (isEmpty()) {
            return "";   // Signals underflow to the caller
        }
        string served = customers[front];
        // Circular index wrap-around
        front = (front + 1) % MAX_SIZE;
        count--;
        return served;
    }

    string peek() const {
        if (isEmpty()) {
            return "";
        }
        return customers[front];
    }

    void displayQueue() const {
        if (isEmpty()) {
            cout << "\n  The queue is currently empty.\n";
            return;
        }
        cout << "\n  Customers in queue (" << count << " waiting):\n";
        cout << "  [FRONT] ";
        for (int i = 0; i < count; i++) {
            int index = (front + i) % MAX_SIZE;
            cout << customers[index];
            if (i < count - 1) cout << " -> ";
        }
        cout << " [REAR]\n";
    }
};
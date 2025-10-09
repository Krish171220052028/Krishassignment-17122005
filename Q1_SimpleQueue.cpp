// Q1: Simple Queue Implementation (Menu Driven)
// UCS301 - Data Structures (Week 4)

#include <iostream>
#define SIZE 5
using namespace std;

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == SIZE - 1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is Full!\n";
            return;
        }
        if (front == -1)
            front = 0;
        arr[++rear] = value;
        cout << value << " inserted into queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return;
        }
        cout << arr[front] << " removed from queue.\n";
        if (front == rear)
            front = rear = -1;
        else
            front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }
};

int main() {
    Queue q;
    int choice, value;
    cout << "----- Simple Queue Menu -----\n";
    cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit\n";

    while (true) {
        cout << "\nEnter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            q.peek();
            break;
        case 5:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}

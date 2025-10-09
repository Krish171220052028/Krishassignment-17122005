// Q2: Circular Queue Implementation (Menu Driven)

#include <iostream>
#define SIZE 5
using namespace std;

class CircularQueue {
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % SIZE == front;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Circular Queue is Full!\n";
            return;
        }
        if (isEmpty())
            front = 0;
        rear = (rear + 1) % SIZE;
        arr[rear] = value;
        cout << value << " inserted.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Circular Queue is Empty!\n";
            return;
        }
        cout << arr[front] << " removed.\n";
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }

    void display() {
        if (isEmpty()) {
            cout << "Circular Queue is Empty!\n";
            return;
        }
        cout << "Circular Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
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
    CircularQueue cq;
    int choice, value;

    cout << "----- Circular Queue Menu -----\n";
    cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit\n";

    while (true) {
        cout << "\nEnter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            cq.enqueue(value);
            break;
        case 2:
            cq.dequeue();
            break;
        case 3:
            cq.display();
            break;
        case 4:
            cq.peek();
            break;
        case 5:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}

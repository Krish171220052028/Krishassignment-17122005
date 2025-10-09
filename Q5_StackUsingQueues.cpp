// Q5: Implement a stack using (a) Two Queues and (b) One Queue
#include <iostream>
#include <queue>
using namespace std;

// (a) Stack using Two Queues
class StackTwoQueues {
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is Empty!\n";
            return;
        }
        cout << q1.front() << " popped.\n";
        q1.pop();
    }

    void display() {
        queue<int> temp = q1;
        cout << "Stack (top to bottom): ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

// (b) Stack using One Queue
class StackOneQueue {
    queue<int> q;

public:
    void push(int x) {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is Empty!\n";
            return;
        }
        cout << q.front() << " popped.\n";
        q.pop();
    }

    void display() {
        queue<int> temp = q;
        cout << "Stack (top to bottom): ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    StackTwoQueues s1;
    StackOneQueue s2;
    int choice, value;

    cout << "Choose Implementation:\n1. Two Queues\n2. One Queue\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Stack using Two Queues\n";
        while (true) {
            cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter choice: ";
            cin >> choice;
            switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s1.push(value);
                break;
            case 2:
                s1.pop();
                break;
            case 3:
                s1.display();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice!\n";
            }
        }
    } else {
        cout << "Stack using One Queue\n";
        while (true) {
            cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter choice: ";
            cin >> choice;
            switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s2.push(value);
                break;
            case 2:
                s2.pop();
                break;
            case 3:
                s2.display();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice!\n";
            }
        }
    }
}

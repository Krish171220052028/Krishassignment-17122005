
#include<iostream>
using namespace std;
#define SIZE 100
class Stack {
    int arr[SIZE];
    int top;
public:
    Stack() { top = -1; }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == SIZE - 1; }
    void push(int x) {
        if (isFull()) { cout << "Stack Overflow\n"; return; }
        arr[++top] = x;
    }
    void pop() {
        if (isEmpty()) { cout << "Stack Underflow\n"; return; }
        top--;
    }
    int peek() {
        if (isEmpty()) { cout << "Stack is empty\n"; return -1; }
        return arr[top];
    }
    void display() {
        if (isEmpty()) { cout << "Stack is empty\n"; return; }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) cout << arr[i] << " ";
        cout << endl;
    }
};
int main() {
    Stack st;
    int choice, value;
    do {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice) {
            case 1: cout << "Enter value: "; cin >> value; st.push(value); break;
            case 2: st.pop(); break;
            case 3: cout << "Top element: " << st.peek() << endl; break;
            case 4: st.display(); break;
        }
    } while(choice != 5);
    return 0;
}

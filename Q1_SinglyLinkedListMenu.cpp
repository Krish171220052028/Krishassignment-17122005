// Q1: Menu-driven program for singly linked list operations
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;
public:
    LinkedList() { head = NULL; }

    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, head};
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node{value, NULL};
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    void insertBefore(int target, int value) {
        if (head == NULL) return;
        if (head->data == target) {
            insertAtBeginning(value);
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != target)
            temp = temp->next;
        if (temp->next == NULL)
            cout << "Node not found!\n";
        else {
            Node* newNode = new Node{value, temp->next};
            temp->next = newNode;
        }
    }

    void insertAfter(int target, int value) {
        Node* temp = head;
        while (temp && temp->data != target)
            temp = temp->next;
        if (temp == NULL)
            cout << "Node not found!\n";
        else {
            Node* newNode = new Node{value, temp->next};
            temp->next = newNode;
        }
    }

    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }

    void deleteSpecific(int value) {
        if (head == NULL) return;
        if (head->data == value) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != value)
            temp = temp->next;
        if (temp->next == NULL)
            cout << "Node not found!\n";
        else {
            Node* delNode = temp->next;
            temp->next = temp->next->next;
            delete delNode;
        }
    }

    void search(int value) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == value) {
                cout << "Element found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Element not found!\n";
    }

    void display() {
        Node* temp = head;
        if (!temp) {
            cout << "List is empty!\n";
            return;
        }
        cout << "Linked List: ";
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    int choice, value, target;

    cout << "----- Singly Linked List Menu -----\n";
    cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert Before Node\n4. Insert After Node\n5. Delete from Beginning\n6. Delete from End\n7. Delete Specific Node\n8. Search\n9. Display\n10. Exit\n";

    while (true) {
        cout << "\nEnter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtEnd(value);
            break;
        case 3:
            cout << "Enter target and new value: ";
            cin >> target >> value;
            list.insertBefore(target, value);
            break;
        case 4:
            cout << "Enter target and new value: ";
            cin >> target >> value;
            list.insertAfter(target, value);
            break;
        case 5:
            list.deleteFromBeginning();
            break;
        case 6:
            list.deleteFromEnd();
            break;
        case 7:
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteSpecific(value);
            break;
        case 8:
            cout << "Enter value to search: ";
            cin >> value;
            list.search(value);
            break;
        case 9:
            list.display();
            break;
        case 10:
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}

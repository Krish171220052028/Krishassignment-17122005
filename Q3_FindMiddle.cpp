// Q3: Find the middle of a linked list
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
    void insert(int value) {
        Node* newNode = new Node{value, NULL};
        if (!head) head = newNode;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    void findMiddle() {
        Node *slow = head, *fast = head;
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle element: " << slow->data << endl;
    }
};

int main() {
    LinkedList list;
    int n, val;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insert(val);
    }
    list.findMiddle();
    return 0;
}

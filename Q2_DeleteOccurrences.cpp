// Q2: Count and delete all occurrences of a given key in singly linked list
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

    int deleteOccurrences(int key) {
        int count = 0;
        while (head && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            count++;
        }
        Node* curr = head;
        while (curr && curr->next) {
            if (curr->next->data == key) {
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
                count++;
            } else curr = curr->next;
        }
        return count;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int n, val, key;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insert(val);
    }
    cout << "Enter key to delete: ";
    cin >> key;

    cout << "Original List: ";
    list.display();
    int count = list.deleteOccurrences(key);
    cout << "Count: " << count << "\nUpdated List: ";
    list.display();
    return 0;
}

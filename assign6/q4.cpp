#include <iostream>
using namespace std;

class DoublyList {
    struct Node {
        int data;
        Node *prev, *next;
        Node(int x) {
            data = x;
            prev = next = NULL;
        }
    };
    Node* head;

public:
    DoublyList() { head = NULL; }

    void insertLast(int x) {
        Node* n = new Node(x);
        if (!head) { head = n; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }

    int size() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class CircularList {
    struct Node {
        int data;
        Node* next;
        Node(int x) { data = x; next = NULL; }
    };
    Node* head;

public:
    CircularList() { head = NULL; }

    void insertLast(int x) {
        Node* n = new Node(x);
        if (!head) {
            head = n;
            head->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = n;
        n->next = head;
    }

    int size() {
        if (!head) return 0;
        int count = 0;
        Node* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }

    void display() {
        if (!head) { cout << endl; return; }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    DoublyList dl;
    CircularList cl;

    dl.insertLast(10);
    dl.insertLast(20);
    dl.insertLast(30);

    cl.insertLast(11);
    cl.insertLast(22);
    cl.insertLast(33);
    cl.insertLast(44);

    cout << "Doubly list: ";
    dl.display();
    cout << "Size: " << dl.size() << endl;

    cout << "Circular list: ";
    cl.display();
    cout << "Size: " << cl.size() << endl;

    return 0;
}

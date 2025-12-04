#include <iostream>
using namespace std;

/* ===========================
     DOUBLY LINKED LIST
=============================*/

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
        cout << "Doubly List: ";
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};


/* ===========================
     CIRCULAR LINKED LIST
=============================*/

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
        if (!head) { cout << "Circular List empty\n"; return; }

        Node* temp = head;
        cout << "Circular List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)\n";
    }
};


/* ===========================
            MAIN
=============================*/

int main() {
    DoublyList dl;
    CircularList cl;

    // INSERT SAMPLE DATA
    dl.insertLast(10);
    dl.insertLast(20);
    dl.insertLast(30);

    cl.insertLast(11);
    cl.insertLast(22);
    cl.insertLast(33);
    cl.insertLast(44);

    // DISPLAY LISTS
    dl.display();
    cl.display();

    // SHOW SIZES
    cout << "\nSize of Doubly Linked List: " << dl.size() << endl;
    cout << "Size of Circular Linked List: " << cl.size() << endl;

    return 0;
}

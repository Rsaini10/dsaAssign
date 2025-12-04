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

    void insertFirst(int x) {
        Node* n = new Node(x);
        if (!head) { head = n; return; }
        n->next = head;
        head->prev = n;
        head = n;
    }

    void insertLast(int x) {
        Node* n = new Node(x);
        if (!head) { head = n; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }

    void insertAfter(int key, int x) {
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) { cout << "Node not found\n"; return; }

        Node* n = new Node(x);
        n->next = temp->next;
        n->prev = temp;
        if (temp->next) temp->next->prev = n;
        temp->next = n;
    }

    void insertBefore(int key, int x) {
        if (!head) { cout << "List empty\n"; return; }
        if (head->data == key) {
            insertFirst(x);
            return;
        }
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) { cout << "Node not found\n"; return; }

        Node* n = new Node(x);
        n->prev = temp->prev;
        n->next = temp;
        temp->prev->next = n;
        temp->prev = n;
    }

    void deleteNode(int key) {
        if (!head) { cout << "List empty\n"; return; }

        Node* temp = head;

        while (temp && temp->data != key) temp = temp->next;
        if (!temp) { cout << "Node not found\n"; return; }

        if (temp == head) head = head->next;
        if (temp->next) temp->next->prev = temp->prev;
        if (temp->prev) temp->prev->next = temp->next;
        delete temp;
    }

    void search(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) {
                cout << "Node found at position " << pos << "\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node not found\n";
    }

    void display() {
        Node* temp = head;
        cout << "List: ";
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};


/* ================================
      CIRCULAR LINKED LIST
==================================*/

class CircularList {
    struct Node {
        int data;
        Node* next;
        Node(int x) { data = x; next = NULL; }
    };
    Node* head;
public:
    CircularList() { head = NULL; }

    void insertFirst(int x) {
        Node* n = new Node(x);
        if (!head) {
            head = n;
            head->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        n->next = head;
        temp->next = n;
        head = n;
    }

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

    void insertAfter(int key, int x) {
        Node* temp = head;
        if (!head) { cout << "List empty\n"; return; }
        do {
            if (temp->data == key) {
                Node* n = new Node(x);
                n->next = temp->next;
                temp->next = n;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node not found\n";
    }

    void deleteNode(int key) {
        if (!head) { cout << "List empty\n"; return; }
        Node *curr = head, *prev = NULL;

        // find node
        do {
            if (curr->data == key) break;
            prev = curr;
            curr = curr->next;
        } while (curr != head);

        if (curr->data != key) { cout << "Node not found\n"; return; }

        if (curr == head && curr->next == head) {  // single node
            head = NULL;
            delete curr;
            return;
        }

        if (curr == head) {
            prev = head;
            while (prev->next != head) prev = prev->next;
            head = head->next;
            prev->next = head;
        }
        else {
            prev->next = curr->next;
        }
        delete curr;
    }

    void search(int key) {
        if (!head) { cout << "List empty\n"; return; }

        Node* temp = head;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << "Node found at position " << pos << "\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Node not found\n";
    }

    void display() {
        if (!head) { cout << "List empty\n"; return; }
        Node* temp = head;
        cout << "List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)\n";
    }
};




int main() {
    DoublyList dl;
    CircularList cl;
    int choice, listType, x, key;

    while (true) {
        cout << "\n\n1. Circular Linked List\n2. Doubly Linked List\n3. Exit\nEnter list type: ";
        cin >> listType;

        if (listType == 3) break;

        cout << "1. Insert First\n2. Insert Last\n3. Insert After\n4. Insert Before (Doubly only)\n";
        cout << "5. Delete\n6. Search\n7. Display\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: "; cin >> x;
            (listType == 1 ? cl.insertFirst(x) : dl.insertFirst(x));
            break;

        case 2:
            cout << "Enter value: "; cin >> x;
            (listType == 1 ? cl.insertLast(x) : dl.insertLast(x));
            break;

        case 3:
            cout << "Enter key and value: "; cin >> key >> x;
            (listType == 1 ? cl.insertAfter(key, x) : dl.insertAfter(key, x));
            break;

        case 4:
            if (listType == 1) {
                cout << "Not supported in circular list\n";
            }
            else {
                cout << "Enter key and value: "; cin >> key >> x;
                dl.insertBefore(key, x);
            }
            break;

        case 5:
            cout << "Enter key to delete: "; cin >> key;
            (listType == 1 ? cl.deleteNode(key) : dl.deleteNode(key));
            break;

        case 6:
            cout << "Enter key to search: "; cin >> key;
            (listType == 1 ? cl.search(key) : dl.search(key));
            break;

        case 7:
            (listType == 1 ? cl.display() : dl.display());
            break;

        default:
            cout << "Invalid choice\n";
        }
    }
    return 0;
}

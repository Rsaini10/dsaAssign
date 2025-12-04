#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertBeg(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->next = head;
    head = temp;
}

void insertEnd(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->next = NULL;

    if(head == NULL) {
        head = temp;
        return;
    }
    Node* p = head;
    while(p->next != NULL) p = p->next;
    p->next = temp;
}

void insertAfter(int key, int val) {
    Node* p = head;
    while(p != NULL && p->data != key)
        p = p->next;

    if(p == NULL) return;

    Node* temp = new Node;
    temp->data = val;
    temp->next = p->next;
    p->next = temp;
}

void insertBefore(int key, int val) {
    if(head == NULL) return;
    if(head->data == key) {
        insertBeg(val);
        return;
    }
    Node* p = head;
    while(p->next != NULL && p->next->data != key)
        p = p->next;

    if(p->next == NULL) return;

    Node* temp = new Node;
    temp->data = val;
    temp->next = p->next;
    p->next = temp;
}

void deleteBeg() {
    if(head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteEnd() {
    if(head == NULL) return;
    if(head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* p = head;
    while(p->next->next != NULL)
        p = p->next;
    delete p->next;
    p->next = NULL;
}

void deleteNode(int key) {
    if(head == NULL) return;
    if(head->data == key) {
        deleteBeg();
        return;
    }
    Node* p = head;
    while(p->next != NULL && p->next->data != key)
        p = p->next;
    if(p->next == NULL) return;
    Node* temp = p->next;
    p->next = temp->next;
    delete temp;
}

int searchNode(int key) {
    Node* p = head;
    int pos = 1;
    while(p != NULL) {
        if(p->data == key) return pos;
        p = p->next;
        pos++;
    }
    return -1;
}

void display() {
    Node* p = head;
    while(p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    int choice, val, key;

    while(true) {
        cout << "\n1. Insert at beginning";
        cout << "\n2. Insert at end";
        cout << "\n3. Insert after a node";
        cout << "\n4. Insert before a node";
        cout << "\n5. Delete at beginning";
        cout << "\n6. Delete at end";
        cout << "\n7. Delete a specific node";
        cout << "\n8. Search a node";
        cout << "\n9. Display list";
        cout << "\n10. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                insertBeg(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                insertEnd(val);
                break;
            case 3:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> val;
                insertAfter(key,val);
                break;
            case 4:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> val;
                insertBefore(key,val);
                break;
            case 5:
                deleteBeg();
                break;
            case 6:
                deleteEnd();
                break;
            case 7:
                cout << "Enter key: ";
                cin >> key;
                deleteNode(key);
                break;
            case 8:
                cout << "Enter key: ";
                cin >> key;
                val = searchNode(key);
                if(val == -1) cout << "Not found\n";
                else cout << "Found at position " << val << endl;
                break;
            case 9:
                display();
                break;
            case 10:
                return 0;
        }
    }
}

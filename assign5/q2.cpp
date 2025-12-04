#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

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

int deleteOccurrences(int key) {
    int count = 0;

    while(head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    Node* p = head;
    while(p != NULL && p->next != NULL) {
        if(p->next->data == key) {
            Node* temp = p->next;
            p->next = temp->next;
            delete temp;
            count++;
        } else {
            p = p->next;
        }
    }
    return count;
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
    int arr[] = {1,2,1,2,1,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++)
        insertEnd(arr[i]);

    int key = 1;

    cout << "Original List: ";
    display();

    int count = deleteOccurrences(key);

    cout << "Count: " << count << endl;
    cout << "Updated List: ";
    display();

    return 0;
}

#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, size;
    int *arr;

public:
    Queue(int s) {
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear == size - 1);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is FULL! Cannot insert.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }
        arr[rear] = value;
        cout << value << " inserted into queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! Cannot delete.\n";
            return;
        }
        cout << "Deleted element: " << arr[front] << endl;

        if (front == rear) { 
            // Queue becomes empty
            front = rear = -1;
        }
        else {
            front++;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!\n";
        }
        else {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter size of Queue: ";
    cin >> size;

    Queue q(size);
    int choice, value;

    while (true) {
        cout << "\n----- Queue Menu -----\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        case 5:
            if (q.isEmpty()) cout << "Queue is EMPTY.\n";
            else cout << "Queue is NOT empty.\n";
            break;
        case 6:
            if (q.isFull()) cout << "Queue is FULL.\n";
            else cout << "Queue is NOT full.\n";
            break;
        case 7:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}

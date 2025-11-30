#include <iostream>
using namespace std;

class Queue {
    int front, rear, size;
    int *arr;

public:
    Queue(int s) {
        size = s;
        arr = new int[size];
        front = rear = -1;
    }

    bool isempty() {
        return (front == -1 && rear == -1);
    }

    bool isfull() {
        return ((rear + 1) % size == front);
    }

    void enqueue(int val) {
        if (isfull()) {
            cout << "Queue is FULL. Cannot enqueue!\n";
            return;
        }

        if (isempty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = val;
        cout << val << " inserted.\n";
    }

    void dequeue() {
        if (isempty()) {
            cout << "Queue is EMPTY!\n";
            return;
        }

        cout << "Dequeued: " << arr[front] << endl;

        if (front == rear) {
            front = rear = -1;    // Queue becomes empty
        } else {
            front = (front + 1) % size;
        }
    }

    void peek() {
        if (isempty()) {
            cout << "Queue is EMPTY!\n";
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    void display() {
        if (isempty()) {
            cout << "Queue is EMPTY!\n";
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
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
            if (q.isempty()) cout << "Queue is EMPTY\n";
            else cout << "Queue is NOT empty\n";
            break;

        case 6:
            if (q.isfull()) cout << "Queue is FULL\n";
            else cout << "Queue is NOT full\n";
            break;

        case 7:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice, try again!\n";
        }
    }
}

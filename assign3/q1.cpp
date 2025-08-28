#include <iostream>
using namespace std;

#define MAX 5  

struct Stack {
    int arr[MAX];
    int top;
};

void push(Stack *s, int value);
void pop(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
void display(Stack *s);
void peek(Stack *s);

int main() {
    Stack s;   
    s.top = -1;        
    
    int choice, value;
    
    while (true) {
        cout << "\n==== Stack Menu ====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Display\n";
        cout << "6. Peek (top element)\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(&s, value);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                if (isEmpty(&s))
                    cout << "Stack is EMPTY\n";
                else
                    cout << "Stack is NOT empty\n";
                break;
            case 4:
                if (isFull(&s))
                    cout << "Stack is FULL\n";
                else
                    cout << "Stack is NOT full\n";
                break;
            case 5:
                display(&s);
                break;
            case 6:
                peek(&s);
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        cout << "Stack Overflow! Cannot push " << value << endl;
    } else {
        s->top++;
        s->arr[s->top] = value;
        cout << value << " pushed into stack." << endl;
    }
}

void pop(Stack *s) {
    if (isEmpty(s)) {
        cout << "Stack Underflow! Nothing to pop." << endl;
    } else {
        cout << "Popped element: " << s->arr[s->top] << endl;
        s->top--;
    }
}

int isEmpty(Stack *s) {
    if (s->top == -1)
        return 1;
    else
        return 0;
}

int isFull(Stack *s) {
    if (s->top == MAX - 1)
        return 1;
    else
        return 0;
}

void display(Stack *s) {
    if (isEmpty(s)) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack elements are:" << endl;
        for (int i = s->top; i >= 0; i--) {
            cout << s->arr[i] << endl;
        }
    }
}

void peek(Stack *s) {
    if (isEmpty(s)) {
        cout << "Stack is empty. Nothing to peek." << endl;
    } else {
        cout << "Top element is: " << s->arr[s->top] << endl;
    }
}

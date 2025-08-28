#include <iostream>
#include <string.h>   // using string.h instead of cstring
using namespace std;

#define MAX 100   

struct Stack {
    char arr[MAX];
    int top;
};

void push(Stack *s, char c);
char pop(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);

int main() {
    Stack s;
    s.top = -1;

    char str[MAX];
    cout << "Enter a string: ";
    cin.getline(str, MAX);  

    int len = strlen(str);  // strlen from string.h

    for (int i = 0; i < len; i++) {
        push(&s, str[i]);
    }

    cout << "Reversed string: ";
    while (!isEmpty(&s)) {
        cout << pop(&s);
    }
    cout << endl;

    return 0;
}

void push(Stack *s, char c) {
    if (isFull(s)) {
        cout << "Stack Overflow!" << endl;
    } else {
        s->top++;
        s->arr[s->top] = c;
    }
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        cout << "Stack Underflow!" << endl;
        return '\0';
    } else {
        char c = s->arr[s->top];
        s->top--;
        return c;
    }
}

int isEmpty(Stack *s) {
    return (s->top == -1);
}

int isFull(Stack *s) {
    return (s->top == MAX - 1);
}

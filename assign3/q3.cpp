#include <iostream>
#include <string.h>   
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
int match(char a, char b);
int checkBalanced(char exp[]);

int main() {
    char exp[MAX];
    cout << "Enter an expression: ";
    cin.getline(exp, MAX);

    if (checkBalanced(exp))
        cout << "Expression is BALANCED." << endl;
    else
        cout << "Expression is NOT balanced." << endl;

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

int match(char a, char b) {
    if (a == '(' && b == ')') return 1;
    if (a == '[' && b == ']') return 1;
    if (a == '{' && b == '}') return 1;
    return 0;
}

int checkBalanced(char exp[]) {
    Stack s;
    s.top = -1;

    for (int i = 0; i < strlen(exp); i++) {
        char ch = exp[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            push(&s, ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (isEmpty(&s)) {
                return 0; 
            }
            char top = pop(&s);
            if (!match(top, ch)) {
                return 0; 
            }
        }
    }

    return isEmpty(&s); 
}
